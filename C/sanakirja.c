// Kirjoita suomi - englanti atk-sanakirjaohjelma, joka käyttää tiedostoksi tallennettua sanakirjaa. Ohjelma pyytää sanan, joka voi olla suomeksi tai englanniksi.
// Ohjelma tulostaa sanan vastineen toisella kielellä muodossa

// Sana sana1 englanniksi on word1

// tai

// Sana word2 suomeksi on sana2

// Mikäli sanaa ei löydy sanakirjasta, tulostetaan virheilmoitus:

//  Sanaa haettavasana ei loytynyt sanakirjasta

// Sanat sijaitsevat tiedostossa sanakirja.txt jonka rakenne on seuraavanlainen:

// sana1suomeksi;sana1englanniksi
// sana2suomeksi;sana2englanniksi
// ...
// sanaNsuomeksi;sanaNenglanniksi


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define STRING_SIZE 100

int main()
{
    FILE *file = fopen("sanakirja.txt", "r");
    if (file == NULL){
        printf("Töttöröö");
        exit(0);
    }
    
    char input[STRING_SIZE] = {0};
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;
    
    char line[STRING_SIZE] =  {0};
    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = 0;
        // Ensimmäinen kutsu antaa tekstin rivin alusta aina ";" merkkiin asti (suomenkielinen sana).
        // strtok() muokkaa annettua tekstiä korvaamalla ";" merkin 0 (NULL) merkillä
        char *suomi = strtok(line, ";");

        // Annetaan toiselle kutsulle NULL inputtina:
        // Alternativelly, a null pointer may be specified, in which case the function continues scanning where a previous successful call to the function ended.
        // Toinen kutsu antaa tekstin ";" merkistä rivin loppuun (tai seuraavaan ";" merkkiin)
        char *english = strtok(NULL, ";");

        // strcmp() palauttaa 0, jos annetut tekstit ovat samat
        if (strcmp(suomi, input) == 0) {
            printf("Sana %s englanniksi on %s", input, english);
            exit(0);
        }
        else if (strcmp(english, input) == 0)
        {
            printf("Sana %s suomeksi on %s", input, suomi);
            exit(0);
        }
    }
    printf("Sanaa %s ei loytynyt sanakirjasta", input);
    fclose(file);
}