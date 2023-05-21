// Täydennä ohjelmakoodi ja lisää siihen funktio laskeHypotenuusa, joka laskee suorakulmaisen kolmion hypotenuusan pituuden.
// Funktio saa parametrinä kaksi reaalilukua, jotka esittävät kolmion kahta muuta sivua.
// Funktio palauttaa reaalilukuna laskemansa hypotenuusan arvon, joka tulostetaan main-funktiossa.

// Hypotenuusan laskemista ei saa toteuttaa main-funktiossa.


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

double laskeHypotenuusa(double a, double b) {
    double c = sqrt(pow(a, 2) + pow(b, 2));
    return c;
}
int main() {
    
    double sivu1 = 0.0;
    double sivu2 = 0.0;
    double hypotenuusa = 0.0;
    
    printf("\nAnna ensimmäinen sivu: ");
    scanf("%lf", &sivu1);
    
    printf("\nAnna toinen sivu: ");
    scanf("%lf", &sivu2);

    hypotenuusa = laskeHypotenuusa(sivu1, sivu2);
    
    printf("Hypotenuusan pituus on %lf", hypotenuusa);

    return 0;
}