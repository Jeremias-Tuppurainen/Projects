class Fraction:

    def __init__(self, numerator, denominator):

        if not isinstance(numerator, int) or not isinstance(denominator, int):
            raise TypeError

        # Denominator can't be zero, not in mathematics, and not here either.
        elif denominator == 0:
            raise ValueError

        self.__numerator = numerator
        self.__denominator = denominator

    def __lt__(self, frac2):

    # def wich_biggeh(self, frac):
    #     if self.__frac1 < frac.__frac2:
    #         return True
    #     else:
    #         return False

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

    def which_is_bigger(self, frac):
        if self.__numerator/self.__denominator < frac.__numerator/frac.__denominator:
            return True
        else:
            return False


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
    x = input("frac1: ")
    c = input("frac2: ")

    a, b = x.split(",")
    d, e = c.split(",")

    frac1 = Fraction(int(a), int(b))
    frac2 = Fraction(int(d), int(e))

    print(frac1.return_string())
    print(frac2.return_string())

    print(frac1.simplify())
    print(frac2.simplify())

    frac1.which_is_bigger(frac2)
main()
'''
frac1 = Fraction(1, 2)
>>> frac2 = Fraction(2, 3)
>>> frac1 < frac2
True
>>> frac1 > frac2
False
'''
