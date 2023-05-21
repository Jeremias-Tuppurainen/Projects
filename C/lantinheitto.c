// Kirjoita ohjelma, joka simuloi rahan heittoa. Ohjelma "heittää" rahaa 100 kertaa ja kirjaa tulokset ylös ja tulostaa kruunujen ja klaavojen lukumäärät.
// Rahan heitto tulee toteuttaa funktiolla, joka palauttaa luvun 0, jos heiton tulos on kruunu ja luvun 1, jos heiton tulos on klaava.
// Rahan heittoon voi käyttää satunnaislukufunktiota rand, joka löytyy kirjastosta stdlib.h.
// Satunnaislukufunktio "alustetaan" ennen käyttöä komennolla srand (time(NULL)), jossa time -löytyy kirjastosta time.h.
// Tulosta heittojen tulokset yhdellä rivillä muodossa:

// Heittojen tulos: ### kruunua ja ### klaavaa


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

int heitto(){
    srand(time(NULL));
    return rand()>(RAND_MAX/2);
}

int main() {
    int a=0, b=0, i; 

    for (i=0;i<100;i++) {   // 100 kertaa
        int x = heitto();   // funktio arpoo ja palauttaa joko 1 tai 0
        printf("%d", x);
            if (x == 0) {   // jos palauttaa 0, se oli kruuna
                a++;        // lisätään kruunalle piste
            }
            else {          // jos palauttaa jotakin muuta kuin 0 se oli klaava
                b++;        // lisätään klaavalle piste
            }
    }
    printf("\nHeittojen tulos: %d kruunua ja %d klaavaa", a, b);
}
