// Tee ohjelma, joka lukee käyttäjältä lainasumman, lainakoron ja lainapäivien määrän, tässä järjestyksessä .
// Ohjelma laskee paljonko asiakas joutuu maksamaan korkoalaina-ajalta. 

// Kaava: kokonaiskorko = laina * korko * lainapäivät/365

// jossa "korko" on käyttäjän syöttämä luku (esim. 15 viidentoista prosentin korolle) jaettuna 100:lla, eli muutettuna prosenteiksi.

// Tulosta vastaus muodossa:

// Lainapaaoman #.## euroa korko # päivälta korkoprosentilla #.## on yhteensa #.## euroa.


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
            exit(printf("Lainapaaoman 0.00 euroa korko 0 paivalta korkoprosentilla 0.00 on yhteensa 0.00 euroa \n"));
        }
        // if (value < 0.0f)
        //     exit(printf("Lainapaaoman 0.00 euroa korko 0 paivalta korkoprosentilla 0.00 on yhteensa 0.00 euroa \n"));

        // if (value > -1.0f)
        //     return value;
        return value;
        // exit(printf("Lainapaaoman 0.00 euroa korko 0 paivalta korkoprosentilla 0.00 on yhteensa 0.00 euroa \n"));
    }
    return -1;
}

int main() {

    printf("Lainasumma: ");
    float laina = get_input();

    printf("lainakorko: ");
    float korko = get_input();

    float korko2 = korko/100;

    printf("lainapaivien maara: ");
    float lainapaivat = get_input();

    float kokonaiskorko = laina * korko2 * lainapaivat/365;

    printf("Lainapaaoman %.2lf euroa korko %.0lf paivalta korkoprosentilla %.2lf on yhteensa %.2lf euroa. \n", laina, lainapaivat, korko, kokonaiskorko); 

}