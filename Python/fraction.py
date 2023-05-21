class Fraction:
    """
    This class represents one single fraction that consists of
    numerator (osoittaja) and denominator (nimittäjä).
    """

    def __init__(self, numerator, denominator):
        """
        Constructor. Checks that the numerator and denominator are of
        correct type and initializes them.

        :param numerator: int, fraction's numerator
        :param denominator: int, fraction's denominator
        """

        # isinstance is a standard function which can be used to check if
        # a value is an object of a certain class.  Remember, in Python
        # all the data types are implemented as classes.
        # ``isinstance(a, b´´) means more or less the same as ``type(a) is b´´
        # So, the following test checks that both parameters are ints as
        # they should be in a valid fraction.
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

    def __lt__(self, frac2):
        temp1, temp2 = self.expand(self, frac2)

        if temp1.__numerator < temp2.__numerator:
            return True
        else:
            return False

    def __gt__(self, frac2):
        temp1, temp2 = self.expand(self, frac2)

        if temp1.__numerator > temp2.__numerator:
            return True
        else:
            return False

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

    def complement(self):
        return Fraction(self.__numerator * -1, self.__denominator)

    def reciprocal(self):
        return Fraction(self.__denominator, self.__numerator)

    def multiply(self, frac2):
        return Fraction(self.__numerator * frac2.__numerator, self.__denominator * frac2.__denominator)

    def divide(self, frac2):
        return Fraction(self.__numerator * frac2.__denominator, self.__denominator * frac2.__numerator)

    def add(self, frac2):
        temp1, temp2 = self.expand(self, frac2)
        return Fraction(temp1.__numerator + temp2.__numerator, temp1.__denominator)

    def deduct(self, frac2):
        temp1, temp2 = self.expand(self, frac2)
        return Fraction(temp1.__numerator - temp2.__numerator, temp1.__denominator)


    def expand(self, frac1, frac2):
        temp1 = Fraction(frac1.__numerator * frac2.__denominator, frac1.__denominator * frac2.__denominator)
        temp2 = Fraction(frac2.__numerator * frac1.__denominator, frac2.__denominator * frac1.__denominator)
        return temp1, temp2


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

    frac = Fraction(int(a), int(b))
    frac2 = Fraction(int(d), int(e))

    sum = frac.add(frac2)
    print(sum.return_string())

    sum.simplify()
    print(sum.return_string())

    difference = frac.deduct(frac2)
    print(difference.return_string())

    difference.simplify()
    print(difference.return_string())

    quotient = frac.divide(frac2)
    quotient.return_string()
    quotient.simplify()
    print(quotient.return_string())

    product = frac.multiply(frac2)
    product.return_string()
    product.simplify()
    print(product.return_string())

    frac.return_string()
    complement = frac.complement()
    print(complement.return_string())

    reciprocal = frac.reciprocal()
    print(reciprocal.return_string())

    frac.simplify()
    print(frac.return_string())


main()
