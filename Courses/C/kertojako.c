// Kirjoita ohjelma, joka arpoo satunnaisesti ala-asteen oppilaille joko kertolaskutehtäviä (luvuilla 1-9) tai jakolaskutehtäviä.
// Kerto- vai jakolasku -valinta pitää ohjelman arpoa satunnaisesti. Jakolaskutehtävien tulee olla sellaisia, että tuloksena on kokonaisluku
// (hyödynnä kertolaskualgoritmia edellisestä kohdasta). Ohjelma esittää kysymyksen, johon käyttäjä vastaa. Kysymykset ovat muotoa:

// Anna luku -1 lopettaaksesi
// Paljonko on 5 kertaa 3? 15
// Oikein!

// Anna luku -1 lopettaaksesi
// Paljonko on 9 kertaa 7? 62
// Väärin, yritä uudelleen > 63
// Oikein!

// Ohjelma tutkii onko vastaus oikein vai väärin ja antaa palautteen. Jos vastaus on väärä, ohjelma esittää saman kysymyksen uudelleen, kunnes vastaus on oikea.
// Käytä satunnaislukuja tehtävien tuottamiseen. Ohjelman suoritus päättyy, kun käyttäjä syöttää luvun -1. 

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>


int luvut(){
    return rand() %9 + 1;
}

int jako(int x, int a, int b){
    printf("Paljonko on %d jaettuna %d?\n", a, b);
    while ("Stupid") {
        scanf("%d", &x);
        if (x == -1){
            exit(0);
        }
        else if (x ==(a/b)){
            printf("Oikein!\n\n");
            return x;
        }
        else{
            printf("\nVäärin, yritä uudelleen > ");
        }
    }
    return x;
}

int kerto(int x, int a ,int b){
    printf("Paljonko on %d kertaa %d?\n", a, b);
    while ("Stupid") {
        scanf("%d", &x);
        if (x == -1){
            exit(0);
        }
        else if (x ==(a*b)){
            printf("Oikein!\n\n");
            return x;
        }
        else {
            printf("\nVäärin, yritä uudelleen > ");
        }
    }
    return x;
}

int main() {
    int x = 0, a = 0, b = 0, c = 0;
    while ("No Life") {
        printf("Anna luku -1 lopettaaksesi\n");
        a = luvut();
        b = luvut();
        c = luvut();
        if (c <=5){
            kerto(x, a, b);
        }
        else {
            jako(x, a, b);
        }
    }
}