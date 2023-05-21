class Fraction:

    def __init__(self, numerator, denominator):
        if not isinstance(numerator, int) or not isinstance(denominator, int):
            raise TypeError

        # Denominator can't be zero, not in mathematics, and not here either.
        elif denominator == 0:
            raise ValueError

        self.__numerator = numerator
        self.__denominator = denominator
        if (self.__numerator < 0 and self.__denominator < 0) or (self.__denominator < 0):
            self.__numerator *= -1
            self.__denominator *= -1

    def __str__(self):
        return self.return_string()

    def return_string(self):
        """
        :returns: str, a string-presentation of the fraction in the format
                       numerator/denominator.
        """

        if self.__numerator * self.__denominator < 0:
            sign = "-"

        else:
            sign = ""

        return f"{sign}{abs(self.__numerator)}/{abs(self.__denominator)}"

    def simplify(self):
        divisor = greatest_common_divisor(self.__numerator, self.__denominator)
        self.__numerator = int(self.__numerator / divisor)
        self.__denominator = int(self.__denominator / divisor)


def greatest_common_divisor(a, b):
    """
    Euclidean algorithm. Returns the greatest common
    divisor (suurin yhteinen tekijä).  When both the numerator
    and the denominator is divided by their greatest common divisor,
    the result will be the most reduced version of the fraction in question.
    """

    while b != 0:
        a, b = b, a % b

    return a


def main():
    murt = []
    i = 1
    final = []

    print("Enter fractions in the format integer/integer.")
    print("One fraction per line. Stop by entering an empty line.")

    while i != "":
        i = input()
        if i != "":
            a, b = i.split("/")
            frac = Fraction(int(a), int(b))
            murt.append(frac)
            frac = Fraction(int(a), int(b))
            frac.simplify()
            final.append(frac)

    print("The given fractions in their simplified form:")
    for x, fraction in enumerate(final):
        print(murt[x], "=", fraction)


main()
'''
ongelma:
-2/-4 = 1/2
kun sen pitäisi olla
2/4 = 1/2
'''