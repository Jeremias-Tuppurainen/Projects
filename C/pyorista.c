// Funktio floor pyöristää luvun alaspäin lähimmäksi kokonaisluvuksi. Lause 

// y = floor(x + 0.5);

// pyöristää luvun lähimmäksi kokonaisluvuksi (double tyyppisenä kylläkin) ja tallettaa tuloksen muuttujaan y.
// Tee ohjelma, joka lukee viisi lukua ja tulostaa kunkin luvun alkuperäisenä ja pyöristettynä.
// Toteuta ohjelma omana funktiona, jota kutsutaan main-funktiosta. 

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

float pyoristaKokonaisluvuksi(float luku)
{
    float y = (float)floor(luku +0.5);
    printf("%f %f\n", luku, y);
    return y;
}

float pyoristaKymmenesosat(float luku)
{
    float y = (float)floor(luku * 10 + 0.5)/10;
    printf("%f %f\n", luku, y);
    return y;
}

float pyoristaSadasosat(float luku)
{
    float y = (float)floor(luku * 100 + 0.5)/100;
    printf("%f %f\n", luku, y);
    return y;
}

float pyoristaTuhannesosat(float luku)
{
    float y = (float)floor(luku * 1000 + 0.5)/1000;
    printf("%f %f\n", luku, y);
    return y;   
}

int main(void) 
{
    float x;
    int i = 0;
    for (i=0;i<5;i++) 
    {
        scanf("%f", &x);
        pyoristaKokonaisluvuksi(x);
        pyoristaKymmenesosat(x);
        pyoristaSadasosat(x);
        pyoristaTuhannesosat(x);
    }
}