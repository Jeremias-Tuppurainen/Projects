// Tee ohjelma, joka täyttää 20 alkion taulukon satunnaisluvuilla, joiden arvot ovat välillä 1 - 20 siten,
// että sama luku ei esiinny useammin kuin kerran taulukossa. Tulosta taulukon sisältö. Käytä funktioita.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define ARRLEN 20

int rand_range(int min, int max) {
    // rand() palauttaa arvon [0, RAND_MAX] välillä. Normalisoi satunnailuku ensin [0, 1] välille
    // ja kerro se sen jälkeen halutun välin maksimiarvolla ja lisää minimiarvo,
    // jotta saadaan satunnaisluku halutulla välillä:
    // / RAND_MAX:    -> [0,             1]
    // * (max - min): -> [0,   (max - min)]
    // + min:         -> [min,         max]
    return (int)((float)rand() / RAND_MAX * (max - min) + min);
}
void grandi(int *a){
    for(int i = 0; i < ARRLEN; i++) {
        a[i] = rand_range(1, 20);
        for (int y = 0; y < i; y++) {
            if (a[y] == a[i]) {
                i -= 1;
                break;
            }
        }
    }
}

// Ohjelma käytännössä sekoittaa 20 pitkän listan elementit, joten nopeammin pääsee lopputulokseen sekoitettamalla listan
void sekoita(int *a)
{
    // Luo lista arvoilla 1-20
    for(int i = 0; i < ARRLEN; i++) {
        a[i] = i;
    }
    // Sekoita listaa 20 kertaa
    for(int i = 0; i < ARRLEN; i++) {
        int v = rand_range(1, 20);

        // Vaihda listan indeksien i ja v paikkaa
        int temp = a[i];
        a[i] = a[v];
        a[v] = temp;        
    }
}


int main(){
    int a[ARRLEN];
//    grandi(a);
    sekoita(a);
    for (int i = 0; i < ARRLEN; i++){
        printf("%d\n", a[i]);
    }
}