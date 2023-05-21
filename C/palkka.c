//'''Suunnittele ja toteuta ohjelma, jossa lasketaan työntekijälle maksettava palkka tehtyjen tuntien ja tuntipalkan perusteella. Tehtyjen tuntien määrä ja tuntipalkka kysytään käyttäjältä, ohjelmassa käytetään kokonaislukuja.
//
//Esimerkki (#-merkit ovat joko käyttäjän syöttämiä tai ohjelman tulostamia numeroita):
//
//Anna tuntipalkka > ###
//Tehdyt tunnit > ##
//Bruttopalkkasi on ##### euroa'''

int main() {

    int pay;
    printf("Anna tuntipalkka ");
    scanf("%d", &pay);

    int hours;
    printf("Tehdyt tunnit ");
    scanf("%d", &hours);

    int bp = pay*hours;

    printf("Bruttopalkkasi on %d", bp);
    printf(" euroa");

}