#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define  STRING_SIZE 20

void compareFiles(FILE *file1, FILE *file2){
    char ch1 = getc(file1);
    char ch2 = getc(file2);
    int error = 0, pos = 0, line = 1;
    while (ch1 != EOF && ch2 != EOF){
        pos++;
        if (ch1 == '\n' && ch2 == '\n'){
            line++;
            pos = 0;
        }
        if (ch1 != ch2)
            error++;

        ch1 = getc(file1);
        ch2 = getc(file2);
    }
    if (error>0)
        printf("Tiedostot eivät ole sisällöltään identtiset.");
    else
        printf("Tiedostot ovat sisällöltään identtiset.");
}

int main(){
    char input[STRING_SIZE] = {'\0'},*p;
    char input2[STRING_SIZE] = {'\0'},*f;
    fgets(input, sizeof(input), stdin);
    fgets(input2, sizeof(input2), stdin);

    input[strcspn(input, "\n")] = 0;
    input2[strcspn(input2, "\n")] = 0;

    FILE *file1 = fopen(input, "r");
    FILE *file2 = fopen(input2, "r");
    if (file1 == NULL || file2 == NULL){
        printf("Töttöröö");
        exit(0);
    }
    compareFiles(file1, file2);
    fclose(file1);
    fclose(file2);
    return 0;
}