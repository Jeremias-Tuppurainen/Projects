// Kirjoita ohjelma, joka lukee 3 riviä (max 100 merkkiä/rivi) tekstiä ja laskee tekstissä esiintyvien aakkosten lukumäärän ja tulostaa tulokset kuvaruudulle
// (skandeista ei tarvitse välittää). Tulosta vastaukset kahtena sarakkeena, allaolevan mukaisesti:

// Aakkonen        Kpl
// a               ##
// b               #
// c               #
// d               ##
// e               #
// f               ##
// g               #
// h               #
// i               #
// j               #
// k               #
// l               #
// m               #
// n               #
// o               #
// p               #
// q               #
// r               #
// s               #
// t               #
// u               #
// v               #
// w               #
// x               #
// y               #
// z               #

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define STRING_SIZE 100
#define  NUM_WORDS   3

int countString(const char *haystack, char *needle){
    int count = 0;
    const char *tmp = haystack;
    while(tmp = strstr(tmp, needle))
    {
        count++;
        tmp += strlen(needle);
    }
    return count;
}

int main(){
    char input[STRING_SIZE] = {0};
    char output[STRING_SIZE * NUM_WORDS] = {0};
    char *output_ptr = output;
    char letter;
    char c_str_letter[2] = {0};
    //c_str_letter[0] = letter;
    
    for (int i = 0; i < NUM_WORDS; i++)
    {
        printf("Anna rahaa: ");
        fgets(input, sizeof(input), stdin);
        size_t input_size = strlen(input);
        output_ptr = strncat(output_ptr, input, input_size);
    }
    printf("\n%-10s%-10s\n", "Aakkonen", "Kpl");
    for (letter = 'a'; letter <= 'z'; ++letter){
        c_str_letter[0] = letter;
        char *pChar = c_str_letter;
        int count = countString(output, pChar);
        printf("%-10c%-10d\n", letter, count);
    }
}