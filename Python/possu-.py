def main():
    list = []
    print("Give 5 numbers:")
    for numbers in range(5):
        a = input("Next number: ")
        list.append(a)

    print("The numbers you entered, in reverse order:")
    for o in reversed(list):
        print(o)




main()



'''
Give 5 numbers:
Next number: 2
Next number: 7
Next number: 3
Next number: -8
Next number: 6
The numbers you entered, in reverse order:
6
-8
3
7
2
'''