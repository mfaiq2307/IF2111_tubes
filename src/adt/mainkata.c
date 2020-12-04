#include <stdlib.h>
#include "mesinkata.h"


int main() {
    char filename[] = "config.txt";
    STARTKATA_File(filename);
    while (!EndKata) { 
        for (int i=0;i<CKata.Length;i++) {
            printf("%c",CKata.TabKata[i]);
        } 
        printf("\n"); 
        ADVKATA_File(); 
    } 
    return 0; 
} 

