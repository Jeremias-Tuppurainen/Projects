def main():
    i = 1
    lista = []
    for numbers in range(5):
        numbero = "Enter the time for performance " + str(i) + ": "
        a = float(input(numbero))
        i += 1
        lista.append(a)

    lista.remove(max(lista))
    lista.remove(min(lista))
    print("The official competition score is", round(sum(lista)/3, 2), "seconds.")



main()
'''
Enter the time for performance 1: 5.80
Enter the time for performance 2: 5.40
Enter the time for performance 3: 5.17
Enter the time for performance 4: 5.19
Enter the time for performance 5: 5.22
The official competition score is 5.27 seconds.
'''
