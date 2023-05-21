// Tee ohjelma, joka tulostaa seuraavanlaisen pyramidin toistorakenteiden (do-while, while tai for) avulla.


//        	1
//         232
//        34543       
//       4567654
//      567898765
//     67890109876
//    7890123210987
//   890123454321098 
//  90123456765432109
// 0123456789876543210


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(void) {
    int width=9, length=1, number=1, z=0, rigged=0;
    for (int i = 0; i < 10; i++){
        printf("\n");
        for (int y = 0; y < width; y++)
            printf(" ");
            z = number;
            rigged = 0;
        for (int x = 0; x < length; x++){
            if (z > 9)
                printf("%d", z-10);
            else
                printf("%d", z);
            if (z==length || rigged !=0){
                z--;
                rigged++;
            }
            else
                z++;
        }
        number += 1;
        width -= 1;
        length += 2;
    }
}