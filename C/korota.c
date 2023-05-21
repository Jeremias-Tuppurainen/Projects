// Kirjoita funktio 

// korotaKokonaislukuPotenssiin (luku, potenssi)

// siten, että se laskee arvon lukupotenssi ja palauttaa arvon kutsujalle. 

// Esimerkiksi korotaKokonaislukuPotenssiin(3, 4) laskee tulon 3 * 3 * 3 * 3. Oleta että potenssi on positiivinen nollaa suurempi kokonaisluku
// ja luku on kokonaisluku. Älä käytä valmiita kirjastofunktioita potenssiin korotuksessa. Ohjelman tulee toimia int-tietotyypeillä.

// Tee myös pääohjelma, jossa luetaan luku ja potenssi ja kutsutaan sitten em. funktiota. Lopuksi tulostetaan tulos muotoiltuna seuraavasti:

// Luku # korotettuna potenssiin # on #


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int korotaKokonaislukuPotenssiin (int luku, int potenssi) {
    int i, f = luku;
    potenssi = potenssi -1;
    for (i=potenssi; i>0; i--) {
        f = f*luku;
    }
    return f;
}

int main() {
    int luku, potenssi;
    printf("Anna luku: \n");
    scanf("%d", &luku);
    
    printf("Anna potenssi: \n");
    scanf("%d", &potenssi);

    printf("Luku %d korotettuna potenssiin %d on %d \n", luku, potenssi, korotaKokonaislukuPotenssiin(luku, potenssi));
}