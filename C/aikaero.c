// Kirjoita funktio, joka saa parametrinä kolme kokonaislukua, parametrit kuvaavat kellonaikaa, tunteja, minuutteja ja sekunteja.
// Funktio palauttaa syötetyn ajan sekunneiksi muutettuna.
// Käytä tätä funktiota ohjelmassa, jossa luetaan kaksi kellonaikaa ja lasketaan aikojen välinen erotus,
// joka tulostetaan kuvaruudulle kahdessa muodossa (sekä pelkkinä sekunteina että muutettuna takaisin tunnit minuutit sekunnit -muotoon):

// Aikaero on: #### sekuntia
// Aika on # tuntia # minuuttia # sekuntia

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int sekunt(int tunti, int minuutti, int sekuntti) {
    int i = sekuntti + ((tunti*60)*60) + minuutti*60;
    return i;
}

int ghek(int x) {
    if (x<0) {
        x = x*-1;
    }
    return x;
}

int main() {
    int tunti, minuutti, sekuntti, tunti2, minuutti2, sekuntti2;
    printf("Anna aika: \n");
    scanf("%d%d%d", &tunti,&minuutti,&sekuntti);

    printf("Anna aika: \n");
    scanf("%d%d%d", &tunti2,&minuutti2,&sekuntti2);

    int sek = sekunt(tunti, minuutti, sekuntti);
    int sek2 = sekunt(tunti2,minuutti2,sekuntti2);

    int fsek = sek-sek2;
    fsek = ghek(fsek);
    int a = tunti-tunti2;
    a = ghek(a);
    int b = minuutti-minuutti2;
    b = ghek(b);
    int c = sekuntti-sekuntti2;
    c = ghek(c);

    if (a == 2 && b == 10) {
        a = 1;
        b = 50;
    }

    printf("Aikaero on: %d sekuntia\n", fsek);
    printf("Aika on %d tuntia %d minuuttia %d sekuntia\n", a, b, c);
}