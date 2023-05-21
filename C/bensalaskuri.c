// Suunnittele ja toteuta ohjelma, joka lukee autoilijan tankkaamia bensiinimääriä ja ajokilometrit ko.
// tankkaukseen. Ohjelma laskee paljonko bensiiniä kului per kilometriä.
// Ohjelma lukee tankatun polttoaineen määrän ja sillä ajetut kilometrit jokaiselle tankkauskerralle ja laskee yksittäiselle tankkaukselle kulutuslukeman
// ("litraa satasella"), kunnes käyttäjä syöttää bensiinin määrän luvun -1.
// Lopuksi ohjelma laskee ja tulostaa kaikkien tankkausten ja ajettujen kilometrien perusteella keskikulutuksen. Esimerkki ohjelman toiminnasta:

// Anna tankatun bensiinin maara ( -1 lopettaa ) > ##

// Ajetut kilometrit > ###

// Keskikulutus talla tankkauksella on #.### litraa satasella

// Anna tankatun bensiinin maara ( -1 lopettaa ) > ##

// Ajetut kilometrit > ###

// Keskikulutus talla tankkauksella on #.### litraa satasella

// Anna tankatun bensiinin maara ( -1 lopettaa ) > -1

// kokonaiskeskikulutus on #.### litraa satasella

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(){
    float bensan_maara=0, ajettu_matka=0, kokb=0, kokm=0;
    float yht=0, final=0;
    while("Nglung"){
        printf("\nAnna tankatun bensiinin maara ( -1 lopettaa ) > ");
        scanf("%f", &bensan_maara);
        if (bensan_maara == -1)
            break;
        kokb += bensan_maara;
        printf("\nAjetut kilometrit > ");
        scanf("%f", &ajettu_matka);
        kokm += ajettu_matka;
        yht = bensan_maara/ajettu_matka;
        printf("\nKeskikulutus talla tankkauksella on %.3lf litraa satasella", yht*100);
    }
    final = kokb/kokm;
    printf("\nkokonaiskeskikulutus on %.3lf litraa satasella", final*100);
}