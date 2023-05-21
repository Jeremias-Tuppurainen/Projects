// Täydellinen luku on positiivinen kokonaisluku, joka on positiivisten tekijöidensä summa.
// Tekijöihin ei tällöin lueta lukua itse. Täydellisia lukuja ovat esimerkiksi 6 ja 28, koska 1 + 2 + 3 = 6 ja 1 + 2 + 4 + 7 + 14 = 28. 

// Muokkaa ohjelmakoodia ja lisää siihen funktio onkoLukuTaydellinen, joka tutkii onko sen parametrina saama positiivinen kokonaisluku täydellinen luku.
// Funktio palauttaa arvon 1 tai 0, riippuen siitä, onko luku täydellinen vai ei. 

// Käytä funktiota pääohjelmassa, joka tutkii luvut 1 - 10000 ja ilmoittaa, mitkä em. luvuista ovat täydellisiä lukuja. 

// Ps. jakojäännösoperaattorista % on hyötyä. 

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int onkoLukuTaydellinen(unsigned int luku)
{
    unsigned int tekijat[100] = {0};
    unsigned int num_tekijat = 0;
    for (unsigned int jakaja = 1; jakaja <= luku; jakaja++)
    {
        if ((luku % jakaja) == 0)
        {
            tekijat[num_tekijat] = luku / jakaja;
            num_tekijat++;
        }
    }

    // tekijät -listan ensimmäinen arvo on aina itse tutkittava luku
    // tekijät -listan viimeinen arvo on aina 1
    // Alusta sum_tekijat viimeisellä arvolla 1, jotta myöhemmin tarkistus (luku == sum_tekijat) ottaa huomioon tilanteen kun luku = 1
    unsigned int sum_tekijat = 1;
    if (num_tekijat > 1)
    {
        // Jätä silmukasssa laskematta ensimmäinen (luku) ja viimeinen (1) arvo lukematta
        for (unsigned int i = 1; i < num_tekijat - 1; i++)
        {
            sum_tekijat += tekijat[i];
        }
    }
    else
    {
        if (luku != 1){
            printf("\nNumeroa %d ei voi jakaa tekijöihin", luku);
        }
    }

    if (luku == sum_tekijat)
    {   if (luku != 1){
            printf("\nLuku %d on taydellinen luku", luku);
        }
        return 1;
    }
    return 0;
}

int main(void) {
    for (int i=1;i<10000;i++) {
        onkoLukuTaydellinen(i);
    }
}