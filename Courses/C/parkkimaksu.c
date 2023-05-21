// Kallioparkki veloittaa 2 euroa yhteensä kolmelta ensimmäiseltä pysäköintitunnilta (Huom! ei siis 2€/h, vaan 2€/3h).
// Yli kolmen tunnin pysäköinnistä veloitetaan lisäksi 0.5 euroa jokaiselta yli menevältä tunnilta (eli +0,5€/h).
// Kuitenkin maksimiveloitus on 10 euroa 24 tunnilta.
// Tee ohjelma, joka kysyy kolmen asiakkaan pysäköintiajat, laskee kunkin veloitukset ja tulostaa tulokset alla olevassa muodossa:


//     Asiakas      Tunnit    Veloitus
//           1        #.##        #.##
//           2        #.##        #.##
//           3        #.##        #.##
//    YHTEENSA        #.##        #.##


// Ohjelmassa on käytettävä funktiota laskeParkkiMaksu laskemaan kunkin asiakkaan maksu. 

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void main() {
    float a, b, c;
    printf("1:\n");
    scanf("%f", &a);
    printf("2:\n");
    scanf("%f", &b);
    printf("3:\n");
    scanf("%f", &c);
    // ensimmäiset 3h = 2€ 
    // x>3 = 0.5€/h 
    // max 10€/24h
    // kysyy kolmen henkinlön pysäköintiajat 
    printf("\n%-10s%-10s%-10s\n","Asiakas", "Tunnit", "Veloitus");
    int i = 1; 
    float x, xf, tun, vel = 0;
    tun = a + b + c;
    for (i = 1; i<=3; i++) {
        if (i == 1) {
            x = a;
            xf = (a - 3)*0.5 + 2;
            if (x>=24) {
                xf = (x - 24)*0.5 + 10;
            }
        }
        else if (i == 2) {
            x = b;
            xf = (b - 3)*0.5 + 2;
            if (x>=24) {
                xf = (x - 24)*0.5 + 10;
            }
        }
        else if (i == 3) {
            x = c;
            xf = (c - 3)*0.5 + 2;
            if (x>=24) {
                xf = (x - 24)*0.5 + 10;
            }
        }
        if (xf<2) {
            xf = 2;
        }
        vel = vel + xf;
        printf("%-10d%-10.2lf%-10.2lf\n",i , x, xf);
    }
    printf("%-10s%-10.2lf%-10.2lf\n","YHTEENSA" , tun, vel);
}