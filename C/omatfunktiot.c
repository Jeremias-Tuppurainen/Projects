// Kirjoita vaadittuun tiedostoon omatfunktiot.c omat versiosi funktioista strcpy ja strcat, jotka saavat parametrinaan kaksi merkkiosoitinta.
// Nimeä funktiot nimillä mystrcpy ja mystrcat . Alkuperäisten funktioiden määritelmät: strcpy ja  strcat.

// Funktiota testaan kutsumalla niitä valmiista pääohjelmasta (tehtävässä valmiina).
// Toteuta vain nuo kaksi edellä mainittua omaa funktiotasi tiedostoon omatfunktiot.c.
// Jos haluat, niin voit tehdä omalle koneellesi testausta varten lyhyen main-funktion,
// mutta ÄLÄ PALAUTA TÄHÄN TEHTÄVÄÄN MAIN-FUNKTIOTA! Se tulee tarkastimelta automaattisesti.

// Omien funktioittesi esittelyt on mainin yhteydessä jo määritelty seuraavanlaisiksi:

// char* mystrcpy(char* kohde, const char* lahde);
// char* mystrcat(char* kohde, char* lahde);


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char* mystrcpy(char* kohde, const char* lahde)
{// kopioi
    if (kohde == NULL) 
        return NULL;

    char *palautus = kohde;
    while (*lahde != '\0')
    {
        *kohde = *lahde;
        kohde++;
        lahde++;
    }
    *kohde = '\0';
    return palautus;
}

char* mystrcat(char* kohde, const char* lahde)
{// liitä
    char* ptr = kohde + strlen(kohde);
    while (*lahde != '\0')
        *ptr++ = *lahde++;

    *ptr = '\0';
    return kohde;
}


#define  STRING_SIZE 140
#define  NUM_WORDS   5

int main()
{
    char input[STRING_SIZE] = {0};
    char output[STRING_SIZE * NUM_WORDS] = {0};
    char *output_ptr = output;
    char worder[40] = {"en-merkkijonoon paattyva merkkijono "};
    for (int i = 0; i < NUM_WORDS; i++)
    {
        printf("\nAnna merkkijono (max 100 merkkia) > ");
        fgets(input, sizeof(input), stdin);
        size_t input_size = strlen(input)+strlen(worder);
        if (strstr(input, "en\n") != NULL)
        {
            output_ptr = mystrcat(output_ptr, worder);
            output_ptr = mystrcat(output_ptr, input);
        }
    }
    printf("%s\n", output);
}