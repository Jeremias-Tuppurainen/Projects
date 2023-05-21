// Kirjoita ohjelma, joka lukee rivin tekstiä funktiolla fgets merkkijonomuuttujaan, johon sopii enintään 100 merkkiä.
// Ohjelma tulostaa merkkijonon sekä pienillä kirjaimilla että suurilla kirjaimilla.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define  STRING_SIZE 100

int main(void){
    char str[STRING_SIZE] = {0};

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    int i;
    char c;

    // i = 0;
    // c = str[i++];
    // while (c != '\n' && i < STRING_SIZE)
    // {
    //     printf("%c%c", tolower(c), toupper(c));
    //     c = str[i++];
    // }
    // printf("\n");

    i = 0;
    c = str[i++];
    while (c != '\n' && i < STRING_SIZE)
    {
        printf("%c", tolower(c));
        c = str[i++];
    }
    printf("\n");

    i = 0;
    c = str[i++];
    while (c != '\n' && i < STRING_SIZE)
    {
        printf("%c", toupper(c));
        c = str[i++];
    }
}