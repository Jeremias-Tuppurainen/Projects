// Kirjoita ohjelma, joka simuloi kahden nopan heittoa, ohjelma käyttää rand-funktiota noppana. Ohjelma heittää noppia 36000 kertaa ja laskee kunkin heiton noppien silmälukujen summan.

// Koska yksi noppa voi saada arvoja 1 - 6, voi summat vaihdella väliltä 2 - 12, joista summa 7 esiintyy useimmin ja summat 2 ja 12 ovat kaikkein harvinaisimmat. 

// Kirjaa yksiulotteiseen taulukkoon summien esiintymät ja tulosta esiintymismäärät taulukkomuodossa esimerkiksi näin:

// Summa 	Lukumäärä
// 2 	###
// 3 	####
//  4 	####
//  5 	 ...
//  6 	 ...
//  ... 	 ...
//  12 	 ####
//  YHTEENSA 	 36000


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

int a[12];

int grandi(int total){
    int i, x;
    srand(time(NULL));
    for (i=0;i<=36000;i++){
        x = (rand()>(RAND_MAX/10))+2;
        total++;
        a[x]++;
    }
    return total;
}

int main(){
    int total = 0;
    grandi(total);
    //printf("%-7s%-10s\n", "Summa ", "Lukumäärä");
    printf("Summa 	Lukumäärä");
    int arrLen = sizeof a / sizeof a[0];
    for (int i = 2; i <= arrLen; i++){
        printf("%-7s%-10d%-10d\n", " ", i, a[i]);
    }
    //printf("%-10s%-20d", "YHTEENSA", total);
    printf("YHTEENSA 	 36000");
}