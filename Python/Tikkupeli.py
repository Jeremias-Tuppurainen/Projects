'''
Tämän sotkun aiheutti: Jeremias Tuppurainen
Tämä koodi mahdollistaa tikkupelin toimimisen.
'''
def main():
    i = 21                                                                    #tikkujen määrä
    p = 0                                                                     # portti, jotta tiedetään, että kumpi voitti
    print("Game of sticks")
    while i > 0:                                                            # tarkistetaan että tikkuja on vielä jäljellä.
        miinus = int(input("Player 1 enter how many sticks to remove: "))
        if miinus != 1 and miinus != 2 and miinus != 3:                     # pelaaja 1 tavarat
            print("Must remove between 1-3 sticks!")
        else:
            tulos = i = i - miinus                                        # tarkistetaan että tikkuja on vielä jäljellä
            if i < 1:
                print("Player 1 lost the game!")
                break
            else:                                                    # jos input on väliltä 1-3 ja tikkuja on vielä jäljellä.
                print("There are",tulos,"sticks left")
            while i > 0:
                miinus = int(input("Player 2 enter how many sticks to remove: "))
                if miinus != 1 and miinus != 2 and miinus != 3:                 # tarkistetaan, että numero on 1-3 väliltä.
                    print("Must remove between 1-3 sticks!")
                else:
                    tulos = i = i - miinus
                    if i < 1:                   # tarkistetaan, että onko tikkuja jäljellä
                        p = 1                     # portti, jotta tunnistetaan kumpi voitti, koska jos 1 voitti p = 0
                        break
                    elif i > 0:
                        print("There are", tulos, "sticks left")
                        break

                    else:
                        break

    else:                                   # tikkuja ei ollut jäljellä, joten jompi kumpi pelaajista hävisi.
        if p == 1:
            print("Player 2 lost the game!")
        else:
            print("Player 1 lost the game!")







main()
