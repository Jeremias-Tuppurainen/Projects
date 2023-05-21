def main():
    list = []
    print("Give 5 numbers:")
    for numbers in range(5):
        a = input("Next number: ")
        list.append(a)

    print("The numbers you entered that were greater than zero were:")

    for i in list:
        if i > str(0):
            print(i)




main()

'''
Give 5 numbers:
Next number: 0
Next number: 1
Next number: -2
Next number: 3
Next number: -4
The numbers you entered that were greater than zero were:
1
3
'''