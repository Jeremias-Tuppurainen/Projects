// Tee funktio poistaValilyonnit, joka saa parametrina kaksi merkkijonoa.
// Funktio poistaa ensimmäisestä merkkijonosta kaikki välilyöntimerkit ja palauttaa tämän "siivotun" merkkijonon toisessa parametrissä.

// Tee pääohjelma joka kysyy käyttäjältä kolme merkkijonoa,
// käyttää edellä mainittua funktiota poistamaan luetuista merkkijonoista välilyönnit ja lopuksi tulostaa "siivotut" merkkijonot näytölle.


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define  SEX         3
#define  STRING_SIZE 140

void remove_spaces(char* s) {
    char* d = s;
    do {
        while (*d == ' ') {
            ++d;
        }
    } while (*s++ = *d++);
}

int main(){
    char input[STRING_SIZE] = {0};
    char output[STRING_SIZE * SEX] = {0};
    char *output_ptr = output;
    for (int i = 0; i < SEX; i++)
    {
        printf("\nLause %d: ", i);
        fgets(input, sizeof(input), stdin);
        size_t input_size = strlen(input);
        output_ptr = strncat(output_ptr, input, input_size);
        remove_spaces(output_ptr);
    }
    printf("%s\n", output);
}