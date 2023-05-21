// Suunnittele ja toteuta ohjelma, joka lukee 10 kokonaislukua (int) ja ilmoittaa lopuksi mikä syötetyistä luvuista oli suurin.
// Tulosta käyttäjälle kehote syöttää luku erikseen jokaisen luvun kohdalla, sekä lopputuloksena rivi muotoa:

// Suurin syottamasi luku oli #


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main() {

int a[10];
    int i;
    int greatest;
    printf("anna 10 numeroa:\n");
    for (i = 0; i < 10; i++) {
        scanf("%d", &a[i]);
    }
    greatest = a[0];
    for (i = 0; i < 10; i++) {
        if (a[i] > greatest) {
        greatest = a[i];
    }
    }
    printf("Suurin syottamasi luku oli %d", greatest);
}