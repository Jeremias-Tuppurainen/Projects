#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main()
{
    FILE * file;
    char path[100];

    char ch;
    int characters, words, lines;

    file = fopen("teksti.txt", "r");

    if (file == NULL)
    {
        printf("\nTöttöröö\n");
        exit(EXIT_FAILURE);
    }

    characters = words = lines = 0;
    while ((ch = fgetc(file)) != EOF)
    {
        characters++;

        if (ch == '\n' || ch == '\0')
            lines++;

        // if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\0')
        //     words++;
    }

    /* Increment words and lines for last word */
    if (characters > 0)
    {
        //words++;
        lines++;
    }

    /* Print file statistics */
    printf("\n");
    printf("Merkit: %d\n", characters);
    //printf("Total words      = %d\n", words);
    printf("Rivit: %d\n", lines);

    fclose(file);

    return 0;
}