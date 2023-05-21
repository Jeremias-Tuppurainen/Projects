// Kirjoita ohjelma, joka lukee viisi merkkijonoa ja tulostaa ne merkkijonot, jotka alkavat kirjaimellä 'a' Tulosta vastaukset muodossa:

// "a"-merkilla alkava merkkijono "asdfghjk"

// Esimerkkiajo:

// Anna merkkjono (max 100 merkkia) > aku

// Anna merkkjono (max 100 merkkia) > ankka

// Anna merkkjono (max 100 merkkia) > Aku

// Anna merkkjono (max 100 merkkia) > Ankka

// Anna merkkjono (max 100 merkkia) > Roope

// "a"-merkilla alkava merkkijono "aku"

// "a"-merkilla alkava merkkijono "ankka"





#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define  STRING_SIZE 100
char a[STRING_SIZE] = {0};
char b[STRING_SIZE] = {0};
char c[STRING_SIZE] = {0};
char d[STRING_SIZE] = {0};
char e[STRING_SIZE] = {0};

void get(int i){
    switch (i)
    {
    case 0:
        fgets(a, sizeof(a), stdin);
    case 1:
        fgets(b, sizeof(b), stdin);
    case 2:
        fgets(c, sizeof(c), stdin);
    case 3:
        fgets(d, sizeof(d), stdin);
    case 4:
        fgets(e, sizeof(e), stdin);
    }
    return;
}

void print(int i){
    switch (i)
    {
    case 0:
        if (a[0] == 'a' || a[0] == 'A'){
            printf("\"a\"-merkilla alkava merkkijono \"");
            for (int i = 0; i<STRING_SIZE; i++)
                printf("%c", a[i]);
            printf("\"\n");
            return;
        }
    case 1:
        if (b[0] == 'a' || b[0] == 'A'){
            printf("\"a\"-merkilla alkava merkkijono \"");
            for (int i = 0; i<STRING_SIZE; i++)
                printf("%c", b[i]);
            printf("\"\n");
            return;
        }
    case 2:
        if (c[0] == 'a' || c[0] == 'A'){
            printf("\"a\"-merkilla alkava merkkijono \"");
            for (int i = 0; i<STRING_SIZE; i++)
                printf("%c", c[i]);
            printf("\"\n");
            return;
        }
    case 3:
        if (d[0] == 'a' || d[0] == 'A'){
            printf("\"a\"-merkilla alkava merkkijono \"");
            for (int i = 0; i<STRING_SIZE; i++)
                printf("%c", d[i]);
            printf("\"\n");
            return;
        }
    case 4:
        if (e[0] == 'a' || e[0] == 'A'){
            printf("\"a\"-merkilla alkava merkkijono \"");
            for (int i = 0; i<STRING_SIZE; i++)
                printf("%c", e[i]);
            printf("\"\n");
            return;
        }
    }
    return;
}

int main(){
    for (int i=0;i<5;i++){
        printf("\nAnna merkkjono (max 100 merkkia) > ");
        get(i);
    }
    for (int i = 0; i < 5; i++)
        print(i);
}