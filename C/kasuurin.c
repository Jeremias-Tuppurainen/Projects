// Kirjoita ohjelma, jossa luetaan kokonaislukuja taulukkoon jossa on 10 paikkaa.

//     Luettu luku talletetaan taulukkoon, jos luettu luettu luku on välillä 0 - 100, muut arvot hylätään,
//     mutta tästä huolimatta taulukon jokaiseen soluun on talletettava luku.
//     Mikäli luettu luku hylätään, pyydetään uutta lukua niin kauan että annettu luku on hyväksyttävä.
//     Uuden luvun kysymisessä tulee tulostaa uudestaan kysyttävän luvun järjestysnumero:
//         Esimerkki:

//                 Anna 1. kokonaisluku > 123
//                   Ei kelpaa, anna 1. kokonaisluku uudestaan > 12
//                 Anna 2. kokonaisluku > 33
//                 ...jne
                


//     Ohjelma tulostaa taulukon sisällön kuvaruudulle vaakasuoraan yhdelle riville.
//     Ohjelmassa etsitään taulukosta suurimman arvon indeksinumero taulukossa ja tulostetaan suurin arvo ja indeksinumero kuvaruudulle omalle rivilleen. 
//     Ohjelma laskee taulukon arvojen keskiarvon ja tulostaa sen kolmen desimaalin tarkkuudella kuvaruudulle omalle rivilleen. 

// Toteuta taulukon täyttäminen, tulostaminen ja suurimman arvon indeksin haku ja keskiarvon laskenta omina funktioina. 
// Esimerkkiajo:


// Anna 1. kokonaisluku > #

// Anna 2. kokonaisluku > #

// Anna 3. kokonaisluku > #

// Anna 4. kokonaisluku > #

// Anna 5. kokonaisluku > #

// Anna 6. kokonaisluku > #

// Anna 7. kokonaisluku > #

// Anna 8. kokonaisluku > #

// Anna 9. kokonaisluku > ##

// Anna 10. kokonaisluku > #

// Taulukon:
// # # # # # # # # ## #

// Suurin arvo on ##, ja se sijaitsee paikassa #

// Taulukon arvojen keskiarvo on #.###


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define ARRLEN 10

int get(int i) {
    int v = -1;
    while(1){
        scanf("%d", &v);
        if (v > 100 || v < 0)
            printf("\nEi kelpaa, anna %d. kokonaisluku uudestaan > ", i+1);
        else
            break;
    }
    return v;
}

int main() {
    int a[ARRLEN];
    int sum = 0;
    int suurin_i = 0;
    int suurin_luku = 0;
    for (int i = 0; i < ARRLEN; i++) {
        printf("\nAnna %d. kokonaisluku > ", i + 1);
        int v = get(i);
        sum += v;
        a[i] = v;
        if (v > suurin_luku) {
            suurin_luku = v;
            suurin_i = i;
        }
    }
    printf("\nTaulukon:\n");
    for (int i = 0; i < ARRLEN; i++){
        printf("%d ",a[i]);
    }
    printf("\nSuurin arvo on %d, ja se sijaitsee paikassa %d\n",suurin_luku, suurin_i);
    printf("Taulukon arvojen keskiarvo on %.03f\b",(float)sum / ARRLEN);
}