
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
    retval = fscanf(pita,"%c",&CC);
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

char READ_Input(){
    int c;
    char cc;
    if ((c = fgetc(stdin)) != EOF){
        cc = (char)fgetc(stdin);
    }
    return cc;
}

int CharToInt(char c){
    int angka;
    if (c == '1'){
        angka = 1;
    }
    else if (c == '2')
    {
        angka = 2;
    }
    else if (c == '3')
    {
        angka = 3;
    }
    else if (c == '4')
    {
        angka = 4;
    }
    else if (c == '5')
    {
        angka = 5;
    }
    else if (c == '6')
    {
        angka = 6;
    }
    else if (c == '7')
    {
        angka = 7;
    }
    else if (c == '8')
    {
        angka = 8;
    }
    else if (c == '9')
    {
        angka = 9;
    }
    else if (c == '0')
    {
        angka = 0;
    }
    
    return angka;
}

char IntToChar(int angka){
    char c;
    if (angka == 1){
        c = '1';
    }
    else if (angka == 2)
    {
        c = '2';
    }
    else if (angka == 3)
    {
        c = '3';
    }
    else if (angka == 4)
    {
        c = '4';
    }
    else if (angka == 5)
    {
        c = '5';
    }
    else if (angka == 6)
    {
        c = '6';
    }
    else if (angka == 7)
    {
        c = '7';
    }
    else if (angka == 8)
    {
        c = '8';
    }
    else if (angka == 9)
    {
        c = '9';
    }
    else if (angka == 0)
    {
        c = '0';
    }
    return c;
}

int Pangkat(int asli, int exponen){
    int result=1;
    for (exponen; exponen>0; exponen--)
    {
        result = result * asli;
    }
    return result;
}

boolean IsCharInt(char c){
    return ((c == 0) || (c == 1) || (c == 2) || (c == 3) || (c == 4) || (c == 5) || 
    (c == 6) || (c == 7) || (c == 8) || (c == 9));
}

void EndRead(){
    fclose(pita);
}