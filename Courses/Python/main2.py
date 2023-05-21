def main():
    valinta1 = input("Player 1, enter your choice (R/P/S): ")
    valinta2 = input("Player 2, enter your choice (R/P/S): ")

    if valinta1.lower() == valinta2.lower():                # valinta 1/1
        print("It's a tie!")
    elif valinta1.lower() == "r" and valinta2.lower() == "p":              # valinta 1/2
        print("Player 2 won!")
    elif valinta1.lower() == "r" and valinta2.lower() == "s":              # valinta 1/3
        print("Player 1 won!")

    elif valinta1.lower() == "p" and valinta2.lower() == "r":              # valinta 2/1
        print("Player 1 won!")
    elif valinta1.lower() == "p" and valinta2.lower() == "s":              # valinta 2/3
        print("Player 2 won!")

    elif valinta1.lower() == "s" and valinta2.lower() == "r":              # valinta 3/1
        print("Player 2 won!")
    elif valinta1.lower() == "s" and valinta2.lower() == "p":              # valinta 3/2
        print("Player 1 won!")


main()

# Player 1, enter your choice (R/P/S): P
# Player 2, enter your choice (R/P/S): S
# Player 2 won!
