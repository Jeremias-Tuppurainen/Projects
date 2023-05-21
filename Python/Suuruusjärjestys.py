def is_the_list_in_order(listi):
    if len(listi) > 1:
        for i in range(len(listi) - 1):
            if listi[i] > listi[i+1]:
                return False

    return True

def main():
    listi = []
    i = int(input("Gimme many number!"))
    for numbers in range(i):
        a = int(input())
        listi.append(a)

    is_the_list_in_order(listi)



main()
