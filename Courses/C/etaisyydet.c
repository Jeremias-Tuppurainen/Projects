// Tee ohjelma, jossa talletetaan tason pisteiden koordinaatteja (5 kpl) tietuetaulukkoon.
// Talletetut pisteet kuvaavat toisiinsa liittyviä suoria,
// ohjelma laskee ja tulostaa suorien muodostaman ketjun pituuden sekä kuinka pitkä matka olisi "linnuntietä" alku- ja loppupisteiden välillä.

// Kahden pisteen välinen etäisyys voidaan laskea kaavalla

// Muotoile lopputulos seuraavasti:

// Etäisyys mutkitellen on #.###
// Alku ja loppupisteiden valinen etaisyys on #.###

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define NUM_WORDS 5

int main()
{
    double etaisyys = 0, linnuntie, piste_x[NUM_WORDS] = {0}, piste_y[NUM_WORDS] = {0}, tmp, lit;
    int last = 0;

    for (int i = 0; i < NUM_WORDS; i++)
    {
        scanf("%lf", &piste_x[i]);
        scanf("%lf", &piste_y[i]);
        last++;
        if (i>0)
        {
            tmp = pow((piste_x[i-1] - piste_x[i]), 2) + pow((piste_y[i-1] - piste_y[i]), 2);
                if (tmp < 0)
                    tmp *= -1;
            etaisyys += sqrt(tmp);
        }        
    }
    lit = pow((piste_x[0] - piste_x[last-1]), 2) + pow((piste_y[0] - piste_y[last-1]), 2);
    if (lit < 0)
        lit *= -1;
    linnuntie = sqrt(lit);

    printf("Etaisyys mutkitellen on %.3lf\nAlku ja loppupisteiden valinen etaisyys on %.3lf", etaisyys, linnuntie);
}