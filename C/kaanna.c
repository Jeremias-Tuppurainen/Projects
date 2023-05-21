// Kirjoita funktio, joka saa parametrinä positiivisen kokonaisluvun väliltä 1 - 9999 ja palauttaa luvun käännettynä. Esim. 1379 palautuisi lukuna 9731.
// Kirjoita pääohjelma, jossa luetaan käyttäjältä luku, joka välitetään funktiolle. Lopuksi tulostetaan alkuperäinen luku ja käännetty luku muodossa

// Luku ## kaannettyna on ##

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

void kaanna(char *str)
{
    int i, len, temp;
    len = strlen(str);

    for (i = 0; i < len/2; i++)
    {
        temp=str[i];
        str[i]=str[len-i-1];
        str[len-i-1]=temp;
    }
}
int main()
{
    char str[100];
    scanf ("%s", str);
    printf ("\nLuku %s ",str);
    kaanna(str);
    printf ("kaannettyna on %s", str);
}