// Binääriluku sisältää merkkejä 1 ja 0. Binääriluku muutetaan kymmenjärjestelmän luvuksi seuraavasti:

// binääriluvusta 1101 saadaan luku 13 laskemalla 

// 1 * 23 + 1 * 22 + 0 * 21 + 1 * 20, jossa 
// 23 = 8
// 22 = 4
// 21 = 2
// 20 = 1

// Suunnittele ja toteuta ohjelma, joka lukee viisinumeroisen binääriluvun ja muuttaa sen kymmenjärjestelmän luvuksi ja tulostaa tuloksen kuvaruudulle. 

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

void main()  {
    double Binaarius[5]; 
    double binary = 0, decimal = 0;
    printf(" Binaarius \n");  
    scanf("%1lf%1lf%1lf%1lf%1lf", &Binaarius[0], &Binaarius[1], &Binaarius[2], &Binaarius[3], &Binaarius[4]);
    decimal = Binaarius[0] * pow(2, 4) + Binaarius[1] * pow(2, 3) + Binaarius[2] * pow(2, 2) + Binaarius[3] * pow(2, 1) + Binaarius[4] * pow(2, 0);

    //printf ( "The binary number is "); 
    // int i;
    // for (i=0;i < (sizeof (Binaarius) /sizeof (Binaarius[0]));i++) {
    // printf("%1.0lf",Binaarius[i]);
    // }
    printf ("\nThe decimal number is %.0lf", decimal); // print the decimal   
}  