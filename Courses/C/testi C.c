#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define ARRLEN 20

int main()
{
    double etaisyys = 0, piste_x = 1, piste_y = 1, piste2_x = 4, piste2_y = 4;

    etaisyys = pow(piste_x - piste2_x);
    printf("%lf\n", etaisyys);
    etaisyys = etaisyys + pow(piste_y - piste2_y);
    printf("%lf\n", etaisyys);
    etaisyys = sqrt(etaisyys);
    printf("%lf\n", etaisyys);



}