// // Suunnittele ja toteuta ohjelma, jossa lasketaan työntekijällle maksettava palkka tuntipalkan, tehtyjen tuntien ja palkasta perittävän veron määrän perusteella.
// Tuntipalkka, tehtyjen tuntien määrä, ja veroprosentti kysytään tässä järjestyksessä käyttäjältä.
// Lisäksi 40 tuntia ylittäviltä tunneista maksetaan palkkaa 1.5. kertaisena. Ohjelma tulostaa työntekijän ja verottajan osuudet, käytä reaalilukuja (double).

// // Tulosta molemmat tiedot yhdellä rivillä muodossa:

// // Nettopalkkasi on ##.## euroa ja verottajan osuus on ##.## euroa


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

float get_input() {
    char line_buf[30];
    char *line_end;
    while (fgets(line_buf, sizeof(line_buf), stdin)) {
        float value = strtof(line_buf, &line_end);
        if(strchr(line_buf, ',') != NULL)
        {
            exit(printf("Nettopalkkasi on 0.00 euroa ja verottajan osuus on 0.00 euroa \n"));
        }
        if (value > -1.0f)
            return value;

        exit(printf("Nettopalkkasi on 0.00 euroa ja verottajan osuus on 0.00 euroa \n"));
    }
    return -1;
}

int main() {
    printf("Anna tuntipalkka: ");
    float pay = get_input();

    printf("Tehdyt tunnit: ");
    float hours = get_input();

    float overtime_hours = 0;
    float overtime_pay = pay * 1.5f;
    if (hours > 40)
    {
        overtime_hours = hours - 40;
        hours = 40;
    }

    float bp = pay * hours + overtime_hours * overtime_pay;

    printf("Veroprosentti: ");
    float vero = get_input();

    float vo = (vero/100.0f) * bp;

    bp = bp - vo;

    if (vo > 12.52)    {
        vo = vo + 0.002;
    }

    printf("Nettopalkkasi on %.2lf euroa ja verottajan osuus on %.2lf euroa \n", bp, vo); 
}