def main():
    sanat = {}
    y = str(1)
    print("Enter rows of text for word counting. Empty row to quit.")
    while y:
        y = input()
        lista = y.lower().strip().split(" ")
        if lista:
            for word in lista:
                if word in sanat:
                    sanat[word] += 1
                else:
                    sanat[word] = 1
    del sanat[""]
    for word in sorted(sanat):
        print(f"{word} : {sanat[word]}", "times")


main()
'''
Enter rows of text for word counting. Empty row to quit.

I'm on a high way to hell
I'm on a high way to hell
It's going really well
Well it's only hell

a : 2 times
going : 1 times
hell : 3 times
high : 2 times
i'm : 2 times
it's : 2 times
on : 2 times
only : 1 times
really : 1 times
to : 2 times
way : 2 times
well : 2 times
'''