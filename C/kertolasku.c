// Kirjoita ohjelma, joka auttaa ala-asteen oppilaita laskemaan kertolaskuja luvuilla 1 - 9. Ohjelma esittää kysymyksen, johon käyttäjä vastaa.
// Kysymykset ovat muotoa:

// Anna luku -1 lopettaaksesi
// Paljonko on 5 kertaa 3? 15
// Oikein!

// Anna luku -1 lopettaaksesi
// Paljonko on 9 kertaa 7? 62
// Väärin, yritä uudelleen > 63
// Oikein!


// Ohjelma tutkii onko vastaus oikein vai väärin ja antaa palautteen. Jos vastaus on väärä, ohjelma esittää saman kysymyksen uudelleen, kunnes vastaus on oikea.
// Käytä satunnaislukuja tehtävien tuottamiseen. Ohjelman suoritus päättyy, kun käyttäjä syöttää luvun -1.
// Huom! Lopetusmerkki pitää pystyä antamaan  missä vaiheessa ohjelmaa vain, kun syötteitä kysytään - myös väärin menneen vastauksen jälkeen.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

int luvut(){
    // srand(time(NULL));
    //return rand()>(RAND_MAX/9), rand()>(RAND_MAX/9);
    return rand() %9 + 1;
}

int main() {
    int x, a = 0, b = 0;
    while ("No Life") {
        printf("Anna luku -1 lopettaaksesi\n");
        a = luvut();
        b = luvut();
        printf("Paljonko on %d kertaa %d?\n", a, b);
        while ("Stupid") {
            scanf("%d", &x);
            if (x == -1){
                exit(0);
            }
            else if (x ==(a*b)){
                printf("Oikein!\n\n");
                break;
            }
            else{
                printf("\nVäärin, yritä uudelleen > ");
            }
        }
    }
}