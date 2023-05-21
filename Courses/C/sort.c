#include <stdio.h>
#include <stdlib.h>


#define NIMI_SIZE 100
#define STR_VALUE(x) STR(x)
#define STR(x) #x

typedef struct joukkue
{
    char nimi[NIMI_SIZE+1]; // +1 lisää tilla NULL merkille
    int voitot;
    int haviot;
    int pisteet;
} joukkue_t;

// Järjestä joukkueet laskevassa järjestyksessä (pisteet suurimmasta pienimpään)
// Jos haluat järjestää joukkueet nuusevassa järjestyksessä, vaihda paluuarvoja keskenään.
// @return >0, jos ensimmäinen argumentti on pienempi kuin toinen
//         <0, jos ensimmäinen argumentti on suurempi kuin toinen
//          0, jos argumentit ovat yhtä suuria
int compare_joukkue(const void *a, const void *b)
{
    const joukkue_t *i = (const joukkue_t*)a;
    const joukkue_t *j = (const joukkue_t*)b;
    int res = 0;
    if (i->pisteet < j->pisteet)
        res = 1;
    else if (i->pisteet > j->pisteet)
        res = -1;

    return res;
}

int main()
{
    unsigned int num_joukkue = 0;
    printf("Kuinka monta joukkuetta? : ");
    if (scanf("%u", &num_joukkue) > 0)
    {
        joukkue_t *joukkueet = (joukkue_t*)malloc(num_joukkue * sizeof(joukkue_t));
        if (joukkueet)
        {
            for (unsigned int i = 0; i < num_joukkue; i++)
            {
                printf("Nimi: ");
                //scanf("%"STR_VALUE(NIMI_SIZE)"s", &joukkueet[i].nimi);
                scanf("%s"STR_VALUE(NIMI_SIZE)"s", &joukkueet[i].nimi);
                printf("Voitot: ");
                scanf("%u", &joukkueet[i].voitot);
                printf("Häviöt: ");
                scanf("%u", &joukkueet[i].haviot);
                joukkueet[i].pisteet = joukkueet[i].voitot - joukkueet[i].haviot;
            }
            // qsort käy läpi annetun listan (joukkueet) järjestyksessä ja järjestää ne käyttäen vertailufunktiota (compare_joukkue)
            // ks. https://en.cppreference.com/w/c/algorithm/qsort
            qsort(joukkueet, num_joukkue, sizeof(joukkue_t), compare_joukkue);

            for (unsigned int i = 0; i < num_joukkue; i++)
            {
                printf("%d. Nimi: %s, Pisteet: %d\n", i + 1, joukkueet[i].nimi, joukkueet[i].pisteet);
            }

            free(joukkueet);
        }
    }
}