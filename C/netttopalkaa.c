
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

float get_input() {
    char line_buf[30];
    char *line_end;
    while (fgets(line_buf, sizeof(line_buf), stdin)) {
        float value = strtof(line_buf, &line_end);
        if(strchr(line_buf, ',') != NULL)
        {
            exit(printf("Nettopalkkasi on 0.00 euroa josta veron osuus on 0.00 euroa \n"));
        }
        if (value > -1.0f)
            return value;

        exit(printf("Nettopalkkasi on 0.00 euroa josta veron osuus on 0.00 euroa \n"));
    }
    return -1;
}

int main() {
    printf("Anna tuntipalkka: ");
    int pay_cents = (int)roundf(get_input() * 100);

    printf("Tehdyt tunnit: ");
    float hours = get_input();

    float bp_cents = pay_cents * hours;
    printf("Bruttopalkka: %.2lf\n", bp_cents / 100.0f);

    printf("Veroprosentti: ");
    float vero = get_input();

    int vo_cents = (int)roundf((vero / 100.0f) * bp_cents);
    int np_cents = (int)roundf(bp_cents - vo_cents);

    printf("Nettopalkkasi on %.2lf", np_cents / 100.0f);
    printf(" euroa josta veron osuus on %.2lf", vo_cents / 100.0f);
    printf(" euroa\n");
}

