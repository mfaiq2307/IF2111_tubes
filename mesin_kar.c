
#include "mesin_kar.h"


/* State Mesin */
char CC;
boolean EOP;

/*
  pada implementasi (mesin_kar.c), perlu ditambahkan variabel static 
  global yang menyimpan pembacaan file pita.
*/
static int retval;
static FILE *pita;

void START_File(char *filename){
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
Karakter pertama yang ada pada pita posisinya adalah pada jendela.
filename merupakan nama file yang berisi pita karakter
I.S. : sembarang
F.S. : CC adalah karakter pertama pada pita */
    pita = fopen(filename, "r");
}


/*
Jika CC != MARK maka EOP akan padam (false)
Jika CC = MARK maka EOP akan menyala (true) */

void ADV_File(){
/* Pita dimajukan satu karakter.
I.S. : Karakter pada jendela = CC, CC != MARK
F.S. : CC adalah karakter berikutnya dari CC yang lama,

CC mungkin = MARK
Jika CC = MARK maka EOP akan menyala (true) */
    retval = fscanf(pita, "%c", &CC);
    if (IsEOP()){
        fclose(pita);
    }
}

char GetCC(){
/* Mengembalikan karakter yang sedang terbaca di jendela.
I.S. : Karakter pada jendela = CC, CC != MARK
F.S. : mengembalikan karakter yang sedang terbaca di jendela
*/
    return CC;
}

boolean IsEOP(){
/* Mengecek apakah pita telah selesai dibaca
I.S. : Pita telah terbaca
F.S. : Menegmbalikan true jika pita telah selesai terbaca, false jika sebaliknya
*/
    return (CC == MARK);
}

boolean ADV_Input(){
    
}