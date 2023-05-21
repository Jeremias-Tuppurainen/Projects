// Suunnittele ja toteuta ohjelma, joka kysyy kokeesta saadun pistemäärän ja tulostaa vastaavan arvosanan. Käytä hyväksesi if -valintarakennetta. 
// Arvosanat määräytyvät seuraavasti:
// 0 - 11  Hylatty
// 12 - 13  1
// 14 - 16  2
// 17 - 19  3
// 20 - 22  4
// 23 - 24  5
// muut: Virheellinen pistemaara

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main() {
    int arvosana;
    printf("Anna Arvosana: ");
    scanf("%d", &arvosana);

    // tämä on sinun syysi
    
    if (arvosana <= 11 && arvosana >= 0) {
        arvosana = 0;
    }
    else if (arvosana < 0) {
    }
    else if (arvosana <= 16) {
        arvosana = 2;
    }
    else if (arvosana <= 19) {
        arvosana = 3;
    }
    else if (arvosana <= 22) {
        arvosana = 4;
    }
    else if (arvosana <= 24) {
        arvosana = 5;
    }

    switch (arvosana)
    {
    default:
        printf("Virheellinen pistemaara \n");
        break;
    case 0:
        printf("Hylatty \n");
        break;
    case 1:
        printf("1 \n");
        break;
    case 2:
        printf("2 \n");
        break;
    case 3:
        printf("3 \n");
        break;
    case 4:
        printf("4 \n");
        break;
    case 5:
        printf("5 \n");
        break;
    }
}