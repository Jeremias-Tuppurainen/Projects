// Kirjoita funktio, joka saa parametrinä kuukauden järjestysnumeron (1-12), funktio laskee ko.
// kuukauden päivien lukumäärän ja palauttaa arvon kutsujalle. Virheellisen kuukauden numeron yhteydessä funktio palauttaa arvon -1. Funktion esittely on:

// int paivienLukumaaraKuukaudessa (int kk);

// Kuukaudessa on päiviä seuraavasti:


// Tammikuu 	31
// Maaliskuu 	31
//  Toukokuu 	 31
//  Heinäkuu 	 31
//  Elokuu 	 31
//  Lokakuu 	 31
//  Joulukuu 	 31
//  Helmikuu 	 28
//  Huhtikuu 	 30
//  Kesäkuu 	 30
//  Syyskuu 	 30
//  Marraskuu 	 30

// (Toistaiseksi unohdetaan karkausvuosien helmikuut.)

// Kirjoita funktiolle pääohjelma, joka kysyy käyttäjältä kuukauden ja tulostaa annetun kuukauden päivien lukumäärän muodossa

// Kuukaudessa ## on ## paivaa

// tai

// Kuukautta ## ei ole olemassa


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

int a[10] = {1,3,5,7,8,10,12};
int b[10] = {4,6,9,11};

int ghek(int m){
    int arrLen = sizeof a / sizeof a[0];
    int isElementPresent = 0;
     
    for (int i = 0; i < arrLen; i++) {
        if (a[i] == m) {
            isElementPresent = 1;
            return 1;
        }
        if (b[i] == m) {
            isElementPresent = 2;
            return 2;
        }
    }
    return -1;
}

int checmont(int x) {
    if (x<13&&x>0){
        return x;
    }
    return -1;
}

int main(){

    int i, x, y;
    printf("anna kuuta\n");
    scanf("%d", &x);
    if (x == 2){
        exit(printf("Kuukaudessa %d on 28 paivaa\n", x));
    }
    int m = checmont(x);
    if (m == -1){
        exit(printf("Kuukautta %d ei ole olemassa\n", x));
    }
    

    int g = ghek(m);

    if (g == 1){
        y = 31;
    }
    else if (g == 2){
        y = 30;
    }

    printf("Kuukaudessa %d on %d paivaa\n", m, y);
}