// Suunnittele ja toteuta ohjelma, joka lukee käyttäjältä viisinumeroisen kokonaisluvun. 
// Ohjelma tulostaa luvun numerot välilyönneillä erotettuna. Esim. luku 42769 tulostuisi

// Luku 42769 eroteltuna: 4 2 7 6 9 

// Huomaa, että nollalla alkavat luvut pitää myös huomioida, esim. luku 00123 tulostuisi

// Luku 123 eroteltuna: 0 0 1 2 3 

// Negatiivisten lukujen kohdalla miinusmerkki tulostuu jokaisen numeron eteen: Esim. -52525 tulostuisi

// Luku -52525 eroteltuna: -5 -2 -5 -2 -5 

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define  STRING_SIZE 7

void main(){
    char str[STRING_SIZE] = {0};

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    printf("Luku ");
    
    int miinusviirus = 1, nollalaskuri = 0;
    if (str[0] == '-')
        miinusviirus = 0;
    
    for (int i = 0; i <= STRING_SIZE-miinusviirus  && str[i] != '\n'; i++){
        if (str[i] != '0'){
            printf("%c", str[i]);
            nollalaskuri++;
        }
    }
    if (nollalaskuri == 0)
        printf("0");

    printf(" eroteltuna: ");

    for (int i = 0; i < 5; i++)
        if (str[i]==0)
            printf("%d ", str[i]);

    for (unsigned int i = 0; str[i] != '\n' && i < STRING_SIZE-1; i++){
        if (miinusviirus == 0 && i > 0)
            printf("-");
        if (str[i] != '-')
            printf("%c ", str[i]);
    }
}