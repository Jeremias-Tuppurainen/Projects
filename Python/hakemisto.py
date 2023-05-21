def main():
    hakemisto = {}
    print("syötä")
    while True:
        rivi = input()
        if rivi == "":
            break

        tiedot = rivi.split()
        hakusana = tiedot[0]
        sivunumero = int(tiedot[1])

        if hakusana not in hakemisto:
            hakemisto[hakusana] = []
        hakemisto[hakusana].append(sivunumero)

    for sana in sorted(hakemisto):
        print(sana, "", end="")
        for numero in sorted(hakemisto[sana]):
            print(numero, "", end="")
        print()


main()