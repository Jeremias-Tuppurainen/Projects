def main():
    list = []
    r = int(input("How many numbers do you want to process: "))
    print("Enter", r, "numbers:")
    for numbers in range(r):
        a = input()
        list.append(a)

    s = input("Enter the number to be searched: ")
    count = list.count(s)
    if count == 0:
        print(s, "is not among the numbers you have entered.")
    else:
        print(s, "shows up", count, "times among the numbers you have entered.")


main()

'''
How many numbers do you want to process: 5
Enter 5 numbers:
7
3
2
7
7
Enter the number to be searched: 7
7 shows up 3 times among the numbers you have entered.

How many numbers do you want to process: 3
Enter 3 numbers:
5
6
7
Enter the number to be searched: 3
3 is not among the numbers you have entered.
'''
