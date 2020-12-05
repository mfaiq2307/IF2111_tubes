#include <stdlib.h>
#include "mesinkata.h"
#include "mesinkata.c"
#include "mesin_kar.h"
#include "mesin_kar.c"


int main() {
    char filename[] = "config.txt"; /*test*/
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
