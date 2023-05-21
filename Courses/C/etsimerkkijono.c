// Muokkaa ohjelmaa ja tee siihen funktio nimeltä etsiMerkkijonoAlusta,
// joka etsii kahden sanan alusta mahdollisimman pitkiä yhteisiä merkkijonoja ja palauttaa tämän yhteisen merkkijonon kutsujalle.
// Esimerkiksi: "global" ja "glossary",
// pisin yhteinen merkkijono molempien alusta on "glo", ja merkkijonojen "dove" ja "glove" tapauksessa on tuloksena tyhjä merkkijono.

// Lue merkkijonot pääohjelmassa käyttäen scanf -metodia ja tulosta funktion etsiMerkkijonoAlusta palauttama merkkijono pääohjelmassa.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void etsiMerkkijonoAlusta(char *mjono1, char *mjono2, char *loydetty) {
    for (int i = 0; mjono1[i] == mjono2[i]; i++)
        loydetty[i] = mjono1[i];
}

int main(void) {
    char mjono1[100];
    char mjono2[100];
    char loydetty[10]={'\0'}; 
    char *loydetty_ptr = loydetty;

    printf("Anna merkkijono 1: ");
    fgets(mjono1, sizeof(mjono1), stdin);
    printf("Anna merkkijono 2: ");
    fgets(mjono2, sizeof(mjono2), stdin);
    
    
    etsiMerkkijonoAlusta(mjono1, mjono2, loydetty);
    
    for (int i = 0; loydetty[i] != '\0'; i++)
        printf("%c", loydetty[i]);
    
    return 0;
}
