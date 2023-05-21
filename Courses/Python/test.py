def main():
    hakemisto = {}
    hakemisto[sivu] = []
    hakusana = input("syötä")

    if hakusana not in hakemisto:
        hakemisto[hakusana] = {}

    alakasite = hakusana[0]

    print(alakasite)

    if alakasite not in hakemisto[hakusana]:
        hakemisto[hakusana][alakasite] = []

    hakemisto[hakusana][alakasite].append(sivu)

    for hakusana in sorted(hakemisto):
        print(hakusana)
        for alakasite in sorted(hakemisto[hakusana]):
            print(" ", alakasite, end=" ")
            for sivu in sorted(hakemisto[hakusana][alakasite]):
                print(sivu, end=" ")
            print()
main()

'''
auto
  formula 10
  rekka 1 5 6
juna
  pendolino 7 9
  tavarajuna 3 7
mopo
  mopoauto 9
  viritetty 37
'''