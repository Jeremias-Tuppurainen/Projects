// Kirjoita oma versio funktiosta strcmp, joka saa parametrinaan kaksi merkkiosoitinta. Nimeä oma funktiosi nimellä omaStrcmp().
// Älä käytä siinä valmista kirjastofunktiota merkkijonojen vertailuun.

// Tee ohjelma, jossa luetaan kaksi merkkijonoa (esimerkissä alla abcd tai abce tai abcf), joita sitten verrataan aakkosjärjestyksen suhteen ko.
// funktiolla. Vastauksena tulostetaan käyttäjän syöttämät merkkijonot yhdistettynä sopivalla vertailuoperaatorimerkillä:

// abcd == abcd

// tai

// abce > abcd

// tai

// abcd < abcf

// tai

// abYikE < abZiiA

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int omaStrcmp(const char *a, const char *b){
    while (*a && *a == *b) { ++a; ++b; }
    return (int)(unsigned char)(*a) - (int)(unsigned char)(*b);
}

void remove_extras(char* s) {
    char* d = s;
    do {
        while (*d == '\n' || *d == ' ') {
            ++d;
        }
    } while (*s++ = *d++);
}

int main(){
    char a[100] = {'\0'}, b[100] = {'\0'};
    printf("Anna tavaraa: ");
    fgets(a, sizeof(a), stdin);
    printf("Anna tavaraa 2: ");
    fgets(b, sizeof(b), stdin);

    //printf("\na: %s\nb: %s\n", a, b);

    remove_extras(a);
    remove_extras(b);
    int tulos = omaStrcmp(a,b);

    if (tulos == 0)
        printf("%s == %s", a, b);
    else if (tulos < 0)
        printf("%s < %s", a, b);
    else if (tulos > 0)
        printf("%s > %s", a, b);
    else
        printf("%s == %s", a, b);
}