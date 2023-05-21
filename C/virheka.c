// Tee ohjelma, joka laskee yhteen käyttäjän syöttämiä positiivisia reaalilukuja (double), kunnes käyttäjä syöttää negatiivisen luvun.
// Ohjelma laskee syötettyjen positiivisten lukujen keskiarvon ja tulostaa keskiarvon kahden desimaalin tarkkuudella.
// (Kokeile myös miten ohjelma käyttäytyy, kun "unohdat" tietojen lukemisessa &-merkin muuttujan nimen edestä.) Toteuta ohjelma while rakenteella.
// Ohjelmassa tarkastetaan syöttääkö käyttäjä tietoja, jotka voidaan tulkita numeeriseksi. Jos käyttäjä syöttää virheellistä tietoa, pyytää ohjelma lukua uudelleen.
// Jos käyttäjä antaa kolme kertaa virheellisen syötteen ohjelma ilmoittaa käyttäjälle syötteenluvun epäonnistumisesta ja ohjelman suoritus lopetetaan.
// Esimerkki virheellisten syötteiden ajosta (normaalitapaus on samanlainen kuin aiemmissa tehtävissä):

// Anna reaaliluku ( negat arvo lopetaa ) > adf

// Ei ollut reaaliluku
// Ei ollut reaaliluku
// Ei ollut  reaaliluku
// Virheellinen syote numero 1

// Ei kelpaa, yrita uudelleen! > d

// Ei ollut reaaliluku
// Virheellinen syote numero 2

// Ei kelpaa, yrita uudelleen! > g

// Ei ollut reaaliluku

// Virheellinen syote numero 3

// Virheellinen syote kolme kertaa. Ohjelma lopetetaan

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main(){
    double potti = 0, maara = 0, luku = 0, intpart;
    int warning = 0;
    while("Flase"){
        printf("\nAnna reaaliluku ( negat arvo lopetaa ) > ");
        while(scanf("%lf", &luku) != 1 && modf(luku, &intpart) == 0){
            warning++;
            printf("\nEi ollut reaaliluku\n");
            printf("Virheellinen syote numero %d\n", warning);
            if (warning > 2){
                printf("\nVirheellinen syote kolme kertaa. Ohjelma lopetetaan");
                exit(0);
            }
            printf("\nEi kelpaa, yrita uudelleen! > ");
            while((luku = getchar()) != '\n' && luku != EOF);
            
        }
        if (luku<0)
            break;
        potti += luku;
        maara++;
        while((luku = getchar()) != '\n' && luku != EOF);
    }
    printf("%.2lf", potti/maara);
}

// ongelma
// Anna reaaliluku ( negat arvo lopetaa ) > 12.3

// Anna reaaliluku ( negat arvo lopetaa ) > 23.4

// Anna reaaliluku ( negat arvo lopetaa ) > 34.5

// Anna reaaliluku ( negat arvo lopetaa ) > -321
// 23.00, kun pitäisi olla 23.40