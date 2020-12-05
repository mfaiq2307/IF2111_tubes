#include <stdlib.h>
#include "mesinkata.h"


int main() {
    char filename[] = "aku.txt"; /*test*/
    STARTKATA_File(filename);
    while (!EndKata) { 
        /*for (int i=0;i<CKata.Length;i++) {
            printf("%s",CKata.TabKata);
        */
        printf("%s",CKata.TabKata); /*printf("\n");*/ 
        ADVKATA_File();
        printf("\n");
    } 
    return 0; 
} 
