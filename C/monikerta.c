// Suunnittele ja toteuta ohjelma, joka lukee kaksi kokonaislukua. Ohjelma tutkii onko ensiksi syötetty luku toiseksi työtetyn luvun monikerta.

// Ohjelma ilmoittaa käyttäjälle lopputuloksen joko muodossa

// Luku # on luvun # monikerta.

// tai

// Luku # ei ole luvun # monikerta.

// Vihje: "luku on toisen luvun monikerta" on sama asia kuin "luku jaettuna toisella luvulla menee tasan" eli ei jää jakojäännöstä. Jakojäännösoperaattori % auttaa tämän selvittämisessä.

// Ekstra: pidä huoli ettei ohjelmasi kaadu jos toiseksi syötetty luku on 0

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main() {
    int a;
    printf("luku 1 \n");
    scanf("%d", &a);
    int b;
    printf("luku 2 \n");
    scanf("%d", &b);

    if (a == 0 || b == 0) {
        exit(printf("Luku %d on luvun %d monikerta. \n", a, b));
    }

    int x = 0;

    if (x == a % b) {
        printf("Luku %d on luvun %d monikerta. \n", a, b);
    }
    
    else {
        printf("Luku %d ei ole luvun %d monikerta \n", a, b);
    }
}
