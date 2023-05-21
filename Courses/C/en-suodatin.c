// en-suodatin

// Kirjoita ohjelma, joka lukee viisi merkkijonoa ja tulostaa ne merkkijonot, jotka päättyvät kirjaimiin "en". Tulosta vastaukset muodossa:

// en-merkkijonoon paattyva merkkijono adfadsfasdnen

// Esimerkkiajo:

// Anna merkkjono (max 100 merkkia) > sana

// Anna merkkjono (max 100 merkkia) > sananen

// Anna merkkjono (max 100 merkkia) > jono

// Anna merkkjono (max 100 merkkia) > aurinkoinen

// Anna merkkjono (max 100 merkkia) > merkki

// en-merkkijonoon paattyva merkkijono sananen

// en-merkkijonoon paattyva merkkijono aurinkoinen

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

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
            output_ptr = strncat(output_ptr, worder, input_size);
            output_ptr = strncat(output_ptr, input, input_size);
        }
    }
    printf("%s\n", output);
}