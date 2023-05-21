// Kirjoita ohjelma, joka tallettaa tietoja jääkiekkojoukkueista. Ohjelma kysyy ensiksi käyttäjältä joukkueiden määrän.
// Sen jälkeen jokaisesta joukkueesta luetaan seuraavat tiedot:

//     Joukkueen nimi, sisältäen kotipaikan nimen (esim. Oulun Kärpät)
//     Voittojen määrä
//     Tappioiden määrä

// Ohjelma lukee tiedot ja tallettaa ne tietueeseen. Tämän jälkeen ohjelma lajittelee listan joukkueiden voittojen ja häviöiden perusteella
// (= voittojen määrä - häviöitten määrä) ja tulostaa tiedot paremmuusjärjestyksessä seuraavasti muotoiltuna:

// ****************************************
//          TULOSLISTA
// ****************************************

//  1. joukkue:          Tiimi1 tilanne: # voittoa ja # tappiota
//  2. joukkue:          Tiimi2 tilanne: # voittoa ja # tappiota
    

// Järjestelyyn voit käyttää erillistä funktiota, josta on malli annettu tehtävän 62 yhteydessä (voit joutua hieman sitä muokkaamaan tämän tehtävän tarkoitukseen).



// #define  STRING_SIZE 200

// typedef struct tiedot
// {
//     char nimi[STRING_SIZE];
//     int voitot;
//     int tappiot;
//     int voitolla;
// } tiedot_t;

// int md_comparator(const void *v1, const void *v2)
// {
//     const tiedot *p1 = (tiedot *)v1;
//     const tiedot *p2 = (tiedot *)v2;
//     if (p1->id < p2->id)
//         return -1;
//     else if (p1->id > p2->id)
//         return +1;
//     else
//         return 0;
// }

// int main(tiedot_t *tiedot){
//     char nimi[STRING_SIZE] = {0};
//     int maara, voitot[STRING_SIZE], tappiot[STRING_SIZE], voitolla[STRING_SIZE];
//     printf("Joukkueiden maara: ");
//     scanf("%d", &maara);
//     tiedot_t *joukkue = malloc(joukkue, maara * sizeof(tiedot_t));
//     for (int i = 0; i < maara; i++)
//     {
//         joukkue = realloc(joukkue, maara * sizeof(tiedot_t));
//         tiedot_t *uusi_joukkue = &joukkue[maara - 1];
//         memset(uusi_joukkue, 0, sizeof(tiedot_t));

//         printf("\nJoukkueen nimi, sisältäen kotipaikan nimen (esim. Oulun Kärpät): ");
//         scanf("%c", &tiedot->nimi);
//         printf("\nVoittojen määrä: ");
//         scanf("%d", &tiedot->voitot);
//         printf("\nTappioiden määrä: ");
//         scanf("%d", &tiedot->tappiot);
//         tiedot->voitolla = voitot-tappiot;
//     }
//     void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*));
//     for (int i = 0; i < maara; i++)
//     {
//         joukkue = &joukkue[i];
//         printf("%d. joukkue:        Tiimi%d tilanne: %d voittoa ja %d tappiota", i+1, i+1, tiedot->voitot, tiedot->tappiot);
//     }
// }

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

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
                char temp;
	            scanf("%c",&temp); // temp statement to clear buffer
                scanf("%[^\n]", joukkueet[i].nimi);
                printf("Voitot: ");
                scanf("%u", &joukkueet[i].voitot);
                printf("Häviöt: ");
                scanf("%u", &joukkueet[i].haviot);
                joukkueet[i].pisteet = joukkueet[i].voitot - joukkueet[i].haviot;
            }
            // qsort käy läpi annetun listan (joukkueet) järjestyksessä ja järjestää ne käyttäen vertailufunktiota (compare_joukkue)
            // ks. https://en.cppreference.com/w/c/algorithm/qsort
            qsort(joukkueet, num_joukkue, sizeof(joukkue_t), compare_joukkue);

            printf("\n****************************************\n              TULOSLISTA\n****************************************\n");

            for (unsigned int i = 0; i < num_joukkue; i++)
            {
                printf("%d. joukkue: %s tilanne: %d voittoa ja %d tappiota\n", i+1, joukkueet[i].nimi, joukkueet[i].voitot, joukkueet[i].haviot);
            }

            free(joukkueet);
        }
    }
}