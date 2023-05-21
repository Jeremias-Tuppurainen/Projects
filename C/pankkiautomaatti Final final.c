#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define HISTORY_SIZE 200                                    // Määrittää historian koon
#define STRING_SIZE 100                                     // määrittää inputtien koon

typedef struct account                                      // Strutsi 
{
    char name[STRING_SIZE];
    char password[STRING_SIZE];
    int money;
    int limit;
    char History[HISTORY_SIZE];
    size_t history_length;
} account_t;

// Tarkoitus:           Mikäli historiaa pitää poistaa, tällä funktiolla sitä poistetaan
// Toimintaperiaate:    Funktio tarkistaa tarvitseeko ja poistaa vanhaa historiaa, jotta uusi historian osa mahtuu historiaan.
// Parametrit:          char *start_ptr, char *found_at_ptr, HISTORY_SIZE, size_t remove_text_size, 
//                      account_t *my_account, my_account->zhistory_length, my_account->history
// Paluuarvo:           0 tai 1, riippuen siitä poistettiinko historiaa.
int  remove_oldest_history(account_t *my_account)
{
    char *start_ptr = my_account->History;
    char *found_at_ptr = strchr(start_ptr, '\n');
    if (found_at_ptr) {
        found_at_ptr += 1;
        size_t remove_text_size = found_at_ptr - start_ptr;
        memmove(
            start_ptr,
            found_at_ptr,
            HISTORY_SIZE - remove_text_size);

        my_account->history_length -= remove_text_size; 
        return 0;
    }
    return 1; 
}

// Tarkoitus:           Hoitaa tapahtumien lisäämisen historiaan
// Toimintaperiaate:    Tarkistaa mahtuuko uusi historiaan lisättävä teksti historiaan ja lähettää
//                      remove_oldest_history-funktioon tarkistettavaksi
// Parametrit:          char *text, size_t text_length, HISTORY_SIZE, account_t *my_account,
//                      my_account->history_length, my_account->History
// Paluuarvo:           0 tai 1 riippuen siitä, voiko historiaan lisätä.
int append_history(account_t *my_account, char *text)
{
    size_t text_length = strlen(text);
    if (text_length >= HISTORY_SIZE)
        return 1;                                                       

    while ((HISTORY_SIZE - my_account->history_length) <= text_length)      
    {
        if (remove_oldest_history(my_account))
        {
            return 1;
        }
    }

    my_account->history_length +=                                      
        snprintf(                                                       
            my_account->History + my_account->history_length,           
            sizeof(my_account->History) - my_account->history_length,   
            "%s\n", text);                                              

    return 0;                                                           
}

// Tarkoitus:           Funktio, millä otetaan float arvoja
// Toimintaperiaate:    Funktio ottaa float arvoja sitten palauttaa ne, sinne mistä funktiota kutsuttiin.
// Parametrit:          STRING_SIZE, char line_buf, char *line_end, float value
// Paluuarvo:           palauttaa otetun luvun, mikäli se on oikeanlainen, jos sokin meni vikaan, palauttaa -1
float get_input() {
    char line_buf[STRING_SIZE];
    char *line_end;
    while (fgets(line_buf, sizeof(line_buf), stdin)) {
        float value = strtof(line_buf, &line_end);
        if (value > -1.0f && strchr(line_buf, ',') == NULL)
            return value;

        printf("Virheellinen syöttö, Anna uusi\n");
    }
    return -1;
}

// Tarkoitus:           poistumisnäyttö
// Toimintaperiaate:    kiittää käynnistä ja poistuu ohjelmasta
// Parametrit:          ei parametrejä
// Paluuarvo:           ei palauta mitään
int tuomio() {
    printf("\nPotta. \n");
    printf("kiitos käynnistä \n");
    printf("Tervetuloa uudelleen \n");
    exit(0);
}

// Tarkoitus:           Antaa käyttäjälle mahdollisuuden lisätä puheaikaa.
// Toimintaperiaate:    Käyttäjä voi valita paljonko haluaa listä puheaikaa tietylle puhelinnumerolle ja sitten
//                      ottaa oikean määrän rahaa pois.
// Parametrit:          account_t *my_account, my_account->money, float liittyma, int puh, int ll_summa, float palaa
// Paluuarvo:           0 ja 2, millä ei pitäisi olla mitään merkitystä.
int puhe(account_t *my_account) {
    printf("Liittymän lataus \n");
    printf("Valitse palvelu \n");
    printf(" 1. Saunalahti \n 2. dna \n 3. Go Mobile \n");
    float liittyma = 0;
    while ("Saunavahti"){
        float liittyma = get_input();
        if (liittyma == 1) {
            printf("Liittymän lataus \n");
            printf("Syötä Saunalahti puhelinnumero \n (esim. 041987...) \n ja paina Enter \n");
            break;
            }
        else if (liittyma == 2) {
            printf("Liittymän lataus \n");
            printf("Syötä DNA puhelinnumero \n (esim. 041987...) \n ja paina Enter \n");
            break;
            }
        else if (liittyma == 3) {
            printf("Liittymän lataus \n");
            printf("Syötä Go Mobile puhelinnumero \n (esim. 041987...) \n ja paina Enter \n");
            break;
            }
        else {
            printf("Mitä jos opettelisit laskemaan\n");
        }
    }
    int puh = (int)get_input();
    
    printf("Liittymän lataus \n");
    printf(" 1. 10 euroa \n 2. 15 euroa \n 3. 20 euroa \n 4. 25 euroa \n 5. 30 euroa \n 6. 50 euroa \n 7. 100 euroa \n");
    int ll_summa = -1;
    while ("Saunavahti") {
        ll_summa = (int)get_input();
        if (ll_summa == 1) {
            ll_summa = 1000;
            break;
        }
        else if (ll_summa == 2) {
            ll_summa = 1500;
            break;
        }
        else if (ll_summa == 3) {
            ll_summa = 2000;
            break;
        }
        else if (ll_summa == 4) {
            ll_summa = 2500;
            break;
        }
        else if (ll_summa == 5) {
            ll_summa = 3000;
            break;
        }
        else if (ll_summa == 6) {
            ll_summa = 5000;
            break;
        }
        else if (ll_summa == 7) {
            ll_summa = 10000;
            break;
        }
        else {
            printf("Mitä jos opettelisit laskemaan\n");
        }
    }
    printf("Liittymän lataus \n");
    printf("Hyväksy maksu \n");
    printf("Puhelinnumero: %d \n", puh);
    printf("Ladattava Summa %.2lf + \n", ll_summa/100.0f);
    printf("Otto tililtä %.2lf - \n", ll_summa/100.0f);
    printf("1. Hyväksy \n 2. Stop \n");
    int a = (int)get_input();
    if (a = 1) {
        if (my_account->money < ll_summa) {
            printf("Sinulla ei ole tarpeeksi rahaa! \n");
        }
        else {
            printf("Ota kortti, ole hyvä \n");
            printf("Puheaika maksettu \n");
            printf("Latausvahvistus tekstiviestillä \n");
            append_history(my_account, "Puheaikaa lisätty\n");
            my_account->money -= ll_summa;
            printf("\nOletko valmis poistumaan (1), vai onko vielä asioitavaa? (2)\n");
            float palaa = get_input();
            if (palaa == 2) {
                return 2;
            }
            else {
                tuomio(); 
            }
        }
    }
    else {
        printf("Maksutapahtuma pysäytetty, palataan valikkoon\n");
    }
    return 0;
}

// Tarkoitus:           Antaa käyttäjälle mahdollisuuden nostaa rahaa tililtään.
// Toimintaperiaate:    Kysyy käyttäjältä, paljonko rahaa haluaa nostaa ja mikäli käyttäjä haluaa tiedot,
//                      tulostaa paljonko eri seteileitä käyttäjä sai
// Parametrit:          account_t *my_account, my_account->limit, my_account->money, int otto, char otto_str,
//                      int kuitti, int x, int y, int  z, int j
// Paluuarvo:           0 ja 2, millä ei ole mitään merkitystä
int Otto(account_t *my_account) {
    printf("Otto \n");
    printf("1. 20 \n 2. 40 \n 3. 50 \n 4. 100 \n 5. 140 \n 6. 240 \n 7. Muu summa \n 8. Alkuun \n");
    int otto = 0;
    //rahamäärät ovat sentteinä, jotta pyöristys toimii oikein
    while ("OTTO!") {
        otto = (int)get_input();
        if (otto == 1){
            otto = 2000;
            break;
        }
        if (otto == 2){
            otto = 4000;
            break;
        }
        else if (otto == 3){
            otto = 5000;
            break;
        }
        else if (otto == 4){
            otto = 10000;
            break;
        }
        else if (otto == 5){
            otto = 14000;
            break;
        }
        else if (otto == 6){
            otto = 24000;
            break;
        }
        else if (otto == 7){
            printf("Anna nostettava summa\n");
            otto = ((int)get_input()*100);
            break;
        }
        else if (otto == 8){
            return 0;
        }
        else {
            printf("Mitä jos opettelisit laskemaan\n");
        }
    }
    if (my_account->limit < otto+1){
        printf("Käteisnostorajaasi on täynnä, nosta vähemmän! \n");
    }
    else if (my_account->money < otto) {
        printf("Sinulla ei ole tarpeeksi rahaa! \n");
    }
    else {
        char otto_str[100];
        snprintf(otto_str, 100, "Nosto %d euroa", (int)(otto / 100.0f));            // 7 ei toimi
        append_history(my_account, otto_str);

        printf("haluatko tiedot? \n");
        printf("1. Ei kiitos \n 2. näytölle \n");        
        int kuitti = (int)get_input();

        my_account->money -= otto;
        my_account->limit -= otto;

        if (kuitti == 2) {                              // vika korjaa!
            int y=0, z=0, j=0, x;
            for (x=otto;x>0;){
                if (x==5000||x>6999&&x!=8000){
                    x -= 5000;
                    y++;
                }
                else if (x>1999) {
                    x-=2000;
                    z++;
                }
                else if (x>0){
                    j++;
                    x = 0;
                }
            }

            if (z>0&&y>0&&j<1){
                printf("%d kpl 50€ ja %d kpl 20€\n", y, z);
            }
            else if (y>0&&z<=0&&j<1){
                printf("%d kpl 50€", y);
            }
            else if (z>0&&j<1){
                printf("%d kpl 20€", z);
            }
            else if (j>0){
                printf(otto_str);
            }
            else {
                printf("Hanki elämä!");
            }
        }
        
        printf("\nOta kortti, ole hyvä \n");
        printf("Rahat tulossa \n");
        printf("\n");
        printf("Ota rahat, ole hyvä \n");
        printf("\nOletko valmis poistumaan (1), vai onko vielä asioitavaa? (2)\n");     
        float palaa = get_input();
        if (palaa == 2) {
            return 2;
        }
        else {
            tuomio(); 
        }
        
    }
    return 0;
}

// Tarkoitus:           kertoo käyttäjälle, tietoja tilistään, kuten tilin saldo
//                      ja kortin käteisnostorajaa ja antaa mahdollisuuden muuttaa käteisnostorajaa
// Toimintaperiaate:    tulostaa käyttäjän tilitiedot ja kysyy haluaako käyttäjä sen jälkeen palata vai muuttaa käteisnostorajaansa.
// Parametrit:          account_t *my_account, my_account->money, my_account->limit, float raja, float kn
// Paluuarvo:           0
int saldo(account_t *my_account) {
    printf("Tilin tilanne \n");
    printf("Tilin saldo: %.2lf \n", my_account->money/100.0f);
    printf("Kortin käteisnostoraja: %.2lf \n", my_account->limit/100.0f);  
    printf("\nOletko valmis palaamaan?\nJos haluat muuttaa kortin käteisnostorajaa paina 2\n");
    float kn = get_input();    
    if (kn == 2) {
        printf("Anna uusi käteisnostoraja: ");
        int raja = (int)get_input();
        if (raja*100 < 0 || raja*100 > my_account->money){
            printf("Käteisnostorajasi on asetettu samaksi, kuin rahamääräsi, koska olet köyhä.\n");
            my_account->limit = my_account->money; 
        }
        else{
            my_account->limit = raja*100;
            append_history(my_account, "Käteisnostoraja vaihdettu");
        }
    }
    return 0;
}

// Tarkoitus:           Tulostaa käyttäjän historian
// Toimintaperiaate:    tulostaa käyttäjän historian, minkä funtio ottaa structista
// Parametrit:          account_t *my_account, my_account->History
// Paluuarvo:           0
int tapahtumat(account_t *my_account) {
    printf("Historian alku:\n");
    printf("%s\n", my_account->History);
    printf("Paina mitä tahansa näppäintä palataksesi.");
    get_input();
    return 0;
}

// Tarkoitus:           Näyttää käyttäjälle käyttäjän tilien määrän mikäli niitä on enemmän kuin 1
// Toimintaperiaate:    tarkistaa tilien määrän ja jos niitä on tehty useampi, kysyy, mitä tiliä käyttäjä haluaa käyttää.
// Parametrit:          account_t *my_account, size_t num_accounts, account_t *accounts, int i, 
// Paluuarvo:           
account_t *tilit(size_t num_accounts, account_t *accounts, account_t *my_account)
{
    printf("Mitä tiliä haluat käyttää\n");
    for (unsigned int i = 0; i < num_accounts; i++)
    {
        printf("Tili %d\n", i+1);
    }

    int x = (int)get_input();
    if (x > 0 && x <= num_accounts)
    {
        printf("käytetään tiliä %d\n", x);
    //    my_account = &accounts[x];
        x -= 1;
        
    }
    else
    {
        printf("Et voi vaihtaa tiliä, koska sinulla on vain yksi tili\nOle hyvä ja tee uusi tili valitsemalla 7 aloitusvalikosta.\n");
        x = 0;
    }
    return &accounts[x];
}

// Tarkoitus:           Tulostaa päävalikon ohjeet
// Toimintaperiaate:    tulostaa ohjeet ja palaa valikkoon.  
// Parametrit:          ei parametrejä
// Paluuarvo:           ei palauta mitään
void tulosta_valikko()
{
    printf("Valitse \n");
    printf("voit lopettaa valitsemalla STOP \n");
    printf(" 1. Liittymän lataus, Puheaika \n 2. Otto \n 3. Saldo \n 4. Tapahtumat \n 5. Tilin valinta \n 6. Tee uusi tili \n 7. Stop \n");
}

// Tarkoitus:           tarkistaa käyttäjän salasanan ja antaa käyttäjälle rahat, mikäli tilillä on
// Toimintaperiaate:    vertaa annettua salasanaa tiedostossa olevaan, minkä jälkeen lisää tiedostossa olevan määrän rahaa
// Parametrit:          account_t *my_account, char *tilinumero, FILE *tili, my_account->limit, char tarkistus, STRING_SIZE,
//                      int mani, int tulos, my_account->money
// Paluuarvo:           0
int pcheck(account_t *my_account, char *tlnumero, FILE *tili)
{
    my_account->limit = 100000;                         // käteisnostoraja 1000€
    char tarkistus[STRING_SIZE];
    int mani;
    int tulos;
    if (tili == NULL) {
        tuomio();
    }
    fgets(tarkistus, STRING_SIZE, tili);

    if (tarkistus[strlen(tarkistus) - 1] == '\n')
        tarkistus[strlen(tarkistus) - 1] = '\0';

    if (tarkistus[strlen(tarkistus) - 1] == '\r')
        tarkistus[strlen(tarkistus) - 1] = '\0';

    if ((tulos = strcmp(my_account->password, tarkistus)) == 0){
        fscanf(tili, "%d", &mani);
        printf("Kirjauduttu sisään onnistuneesti.\n");
        my_account->money = mani*100;
    }
    else{
        printf("Väärä salasana!\n");
        tuomio();
    }
    return 0;
}

// Tarkoitus:           pää fungelo
// Toimintaperiaate:    kysyä salasanaa, tulostaa valikko ja tehdä uusia tilejä, sekä haukkua käyttäjän älykkyyttä
//                      antaessaan väärän numeron
// Parametrit:          char tlnumero, STRING_SIZE, size_t num_accounts, account_t *my_account, account_t accounts, FILE *tili,
//                      my_account->password, int valikko1, account_t new_account
// Paluuarvo:           ei palauta mitään
int main() {
    char tlnumero[STRING_SIZE];                         // tiedoston nimi, mitä haetaan.

    size_t num_accounts = 1;
    account_t *accounts = malloc(num_accounts * sizeof(account_t));
    account_t *my_account = &accounts[0];               //luo käyttäjälle tilin
    memset(my_account, 0, sizeof(account_t));

    printf("Tervetuloa! \n");
    while ("TRUU") {
        printf("Anna tilin numero, ole hyvä.\n Mikäli haluat poistua paina 0.\n");
        fgets(tlnumero, sizeof(tlnumero), stdin);       // kysyy tilinumeroa
        tlnumero[strcspn(tlnumero, "\n")] = 0;
        if (tlnumero[0] == '0')
            tuomio();

        strcat(tlnumero, ".tili");                      // yhdistää tilinumeron ja sen tiedostopäätteen
        FILE *tili = fopen(tlnumero, "r");              // testaa, löytyykö/voiko tiedostoa avata
        if ((tili != NULL)) {
            
            printf("Näppäile tunnusluku \n");
            printf("Suojaa tunnuslukusi \n");
            printf("Lopuksi paina Enter \n");
            printf("Anna tunnusluku \n");
            fgets(my_account->password, sizeof(my_account->password), stdin);   
            my_account->password[strcspn(my_account->password, "\n")] = 0;
            pcheck(my_account, tlnumero, tili);         // salasanan tarkistus ja rahojen lisäys
            break;
        }
        else
            printf("Tuntematon tilinumero\n"); 
    }
    
    append_history(my_account, "Kirjautui sisään");
    tulosta_valikko();                                  //tuo esiin valikon, missä nappuloita painamalla voi valita mitä haluaa tehdä
    int valikko1;
    while ((valikko1 = (int)get_input()) < 9)           //saldo, ottaa rahaa, valita tili tai ladata liittymään puheaikaa jne...
    {
        if (valikko1 == 1) {
            puhe(my_account);                           //liittymän lataaaminen kysyy liittymää ja paljonko haluaa ladata.
        }
        else if (valikko1 == 2) {
            Otto(my_account);                           //kun otetaan rahaa, kysyy paljonko haluaa ottaa, mihin voi kirjoittaa itse miten paljon haluaa ottaa, valitsemalla muu summa, tai voi valita valmiista arvoista.
        }
        else if (valikko1 == 3) {
            saldo(my_account);                          //saldo antaa käyttäjälle tilien saldon ja näyttää paljonko tileiltä voi nostaa.
        }
        else if (valikko1 == 4) {
            tapahtumat(my_account);                     //näyttää historian
        }
        else if (valikko1 == 5) {
            my_account = tilit(num_accounts, accounts, my_account);  //näyttää tilit jos on enemmän kuin 1
        }
        else if (valikko1 == 7) {
            tuomio();                                   //poistuu
        }
        else if (valikko1 == 6) {                       //tee uusi tili
            num_accounts += 1;
            accounts = realloc(accounts, num_accounts * sizeof(account_t));  
            account_t *new_account = &accounts[num_accounts - 1];            
            memset(new_account, 0, sizeof(account_t));
            append_history(my_account, "Uusi tili luotu");
            printf("Uusi tili luotu onnistuneesti\n");
            printf("Paina mitä tahansa näppäintä palataksesi.");
            get_input();
        }
        else {
            printf("Mitä jos opettelisit laskemaan\n");
        }
        tulosta_valikko();
    }
    free(accounts);
}