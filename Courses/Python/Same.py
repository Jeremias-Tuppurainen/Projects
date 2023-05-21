def are_all_members_same(list):
    for i in range(len(list)):
        if list[0] != list[i]:
            return False

    return True



def main():

    list = []
    r = int(input("How many numbers do you want to process: "))
    print("Enter", r, "numbers:")
    for numbers in range(r):
        a = input()
        list.append(a)

    are_all_members_same(list)
    print(are_all_members_same(list))



main()
'''
>>> are_all_members_same([42, 42, 42, 43, 42])
False
>>> are_all_members_same([42, 42, 42, 42])
True
'''