// Tee ohjelma, jossa on kaksi samankokoista kokonaislukutaulukkoa.
// Ohjelma lukee käyttäjältä 10 lukua toiseen taulukoista ja kopioi sitten luvut toiseen samankokoiseen taulukkoon käänteisessä
// järjestyksessä eli ensimmäinen luku viimeiseen paikkaan ja viimeisin luku ensimmäiseen paikkaan jne.
// Lopuksi ohjelma tulostaa molempien taulukoiden sisällöt kahtena vierekkäisenä "sarakkeena":

// Syötä 1. luku >##
// Syötä 2. luku >###
// Syötä 3. luku >#
// Syötä 4. luku >##
// Syötä 5. luku >##
// Syötä 6. luku >##
// Syötä 7. luku >##
// Syötä 8. luku >##
// Syötä 9. luku >##
// Syötä 10. luku >##
// ##   ##
// ###  ##
// #    ##
// ##   ##
// ##   ##
// ##   ##
// ##   ##
// ##   #
// ##   ###
// ##   ##



#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int a[10];
int b[10];

int get(int i){
    int y = 11 - i;
    scanf("%d",&a[i]);
    b[y] = a[i];
    return 1;
}

int main() {
    int i, x, d;
    for (i=1;i<11;i++){
        printf("\nSyötä %d. luku >", i);
        get(i);
    }
    for (x=1;x<11;x++){
        printf("%-5d%-5d\n",a[x], b[x]);
    }
}