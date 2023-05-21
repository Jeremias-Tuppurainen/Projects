// Suunnittele ja toteuta ohjelma, joka tulostaa alla olevan taulukon hyödyntäen toistorakennetta (do-while, while, tai for-rakennetta).
// Taulukkoa ei siis saa "kovakoodata",
// eli ohjelmassa saa olla vain yksi printf-lause otsikkorivin tulostusta varten ja vain yksi printf-lause kaikkien taulukkorivien tulostukseen!

// Huomaa, että...

//     Tehtävä katsotaan hyväksytyksi vasta, kun se täyttää yllä annetut ehdot (vaikka tarkastin hyväksyisi kovakoodatun ratkaisun).
//     Arvojen tulostukseen varataan tilaa seitsemälle numerolle.
//     Tulostus tulee tasata vasempaan reunaan (katso tarkasti esimerkkitaulukkoa).


// N      10*N   100*N  1000*N
// 1      10     100    1000
// 2      20     200    2000
// 3      30     300    3000
// 4      40     400    4000
// 5      50     500    5000
// 6      60     600    6000
// 7      70     700    7000
// 8      80     800    8000
// 9      90     900    9000
// 10     100    1000   10000

// #include <stdio.h>

// int main(void){

//   printf("\n%-7s%-7s%-7s%-7s","N", "10*N", "100*N", "1000*N");
  
// }




#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(void) {
    printf("\n%-7s%-7s%-7s%-7s\n","N", "10*N", "100*N", "1000*N");
    int a;
    for (a = 1; a < 11; a++){
        printf("%-7d%-7d%-7d%-7d\n",a, a*10, a*100, a*1000);
    }
}