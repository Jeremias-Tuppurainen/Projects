// Kirjoita ohjelma, jossa luetaan 20 lukua, joiden arvot ovat välillä 10 ... 100. Kun taulukko on täytetty,
// ohjelma tulostaa vain ne taulukon arvot, jotka esiintyvät vain kerran. Esimerkki ohjelman ajosta:

// Syötä 1. luku >##
// Syötä 2. luku >###

// Ei kelpaa!
// Yrita uudelleen > ##
// Syötä 3. luku >#

// Ei kelpaa!
// Yrita uudelleen > ##
// Syötä 4. luku >##
// Syötä 5. luku >##
// Syötä 6. luku >##
// Syötä 7. luku >##
// Syötä 8. luku >##
// Syötä 9. luku >##
// Syötä 10. luku >##
// Syötä 11. luku >##
// Syötä 12. luku >##
// Syötä 13. luku >##
// Syötä 14. luku >##
// Syötä 15. luku >##
// Syötä 16. luku >##
// Syötä 17. luku >##
// Syötä 18. luku >##
// Syötä 19. luku >##
// Syötä 20. luku >##
// ##
// ##
// ##
// ##
// ##
// ##

// ----   tarkistuksen palaute ----

// Incorrect program output
//  --- Input ---

// 99
// 11
// 11
// 11
// 11
// 11
// 11
// 11
// 11
// 21
// 21
// 21
// 21
// 21
// 21
// 21
// 31
// 31
// 31
// 41


//  --- Program output ---


// Syötä 1. luku >
// Syötä 2. luku >
// Syötä 3. luku >
// Syötä 4. luku >
// Syötä 5. luku >
// Syötä 6. luku >
// Syötä 7. luku >
// Syötä 8. luku >
// Syötä 9. luku >
// Syötä 10. luku >
// Syötä 11. luku >
// Syötä 12. luku >
// Syötä 13. luku >
// Syötä 14. luku >
// Syötä 15. luku >
// Syötä 16. luku >
// Syötä 17. luku >
// Syötä 18. luku >
// Syötä 19. luku >
// Syötä 20. luku >
// 99
// 11
// 21
// 31
// 41


//  --- Expected output (numbers)---

// 1. 2. 3. 4. 5. 6. 7. 8. 9. 10. 11. 12. 13. 14. 15. 16. 17. 18. 19. 20.
// 99
// 41

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int a[20];
// int b[20];

int shrex(int x){
    int arrLen = sizeof a / sizeof a[0];
    int isElementPresent = 0;
     
    for (int i = 1; i < arrLen; i++){
        if (a[i] == x) {
            isElementPresent++;
        }
    }
    return isElementPresent;
}


int get(int i){
    scanf("%d",&a[i]);
    return 1;
}

int main() {
    int i, x, d;
    for (i=1;i<21;i++){
        printf("\nSyötä %d. luku >", i);
        get(i);
        while (a[i]>100 || a[i]<10){
            printf("\nEi kelpaa!");
            printf("\nYrita uudelleen > ");
            get(i);
        }

    }
    printf("\n");
    for (x=1;x<21;x++){
        d = a[x];
        int c = shrex(d);
        if(c < 2){
            printf("%d\n", a[x]);
            //b[x] = a[x];
            //printf("%d\n", b[x]);
        }
        else{
            // printf("Hessu Homeless\n");
        }
    }
}