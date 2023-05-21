// Suunnittele ja toteuta ohjelma, joka laskee matemaattisen vakion e arvon käyttäen kaavaa:

// e = 1 + 1/1! + 1/2! + 1/3! + 1/4! + ...

// Laske luku (e) kymmenen termin tarkkuudella (termit ovat kaavassa summattavia lukuja).
// Tulosta välitulostus (pelkkä e:n arvo, kuuden desimaalin tarkkuudella) jokaisen termin jälkeen ja lopputulos jokainen omalle rivilleen.

// Ohjelman tulostuksen tulee siis näyttää tältä...

// 1.000000
// 2.000000
// 2.500000
// 2.666667
// 2.708333
// 2.716667
// 2.718056
// 2.718254
// 2.718279
// 2.718282


// Käytä ohjelmassa toistorakenteita (do-while, while tai for). Arvoja ei saa kovakoodata!


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define  NUM_LINES 10

int main()
{
    double e = 1, x = 0, y = 1;
    printf("%f\n", e);
    for (int i = 1; i < NUM_LINES; i++)
    {
        x++;
        if (i>2)
            y /= i-1;
        e += (y/x);
        printf("%lf\n", e);
    }
    printf("\n");
}