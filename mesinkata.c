#include "mesinkata.h" 

boolean EndKata; 
Kata CKata;


void IgnoreBlank_File() { 
/* Mengabaikan satu atau beberapa BLANK 
I.S.: CC sembarang 
F.S.: CC ≠ BLANK */ 
/* Kamus Lokal */ 
/* Algoritma */ 
    while (CC == BLANK) { 
        ADV_File(); 
    } /* CC != BLANK */ 
} 

void STARTKATA_File(char *filename) { 
/* I.S.: CC sembarang 
F.S.: EndKata = true, dan CC = Mark;  
atau EndKata = false, CKata adalah kata yang sudah 
diakuisisi, 
CC karakter pertama sesudah karakter terakhir kata */ 
/* Kamus Lokal */ 
/* Algoritma*/
    START_File(filename); 
    IgnoreBlank_File();
    if (CC == MARK) {
        EndKata = true; 
    } else /* CC != MARK */ {
        EndKata = false;
        SalinKata_File();
    } 
} 

void ADVKATA_File() { 
/* I.S.: CC adalah karakter pertama kata yang akan diakuisisi 
F.S.: CKata adalah kata terakhir yang sudah diakuisisi,  
CC adalah karakter pertama dari kata berikutnya,  
mungkin MARK  
Proses: Akuisisi kata menggunakan procedure SalinKata */ 
/* Kamus Lokal */ 
/* Algoritma*/ 
    IgnoreBlank_File(); 
    if (CC == MARK) { 
        EndKata = true; 
    } else /* CC != MARK */ { 
        SalinKata_File(); 
    } 
} 

void SalinKata_File() { 
/* Mengakuisisi kata, menyimpan dalam CKata 
I.S.: CC adalah karakter pertama dari kata 
F.S.: CKata berisi kata yang sudah diakuisisi;  
CC = BLANK atau CC = MARK;  
CC adalah karakter sesudah karakter terakhir yang  
diakuisisi */ 
/* Kamus Lokal */ 
    int i; /* definisi */ 
    /* Algoritma*/ 
    i = 0; /* inisialisasi */ 
    while ((CC != MARK) && (CC != BLANK)) {
        /*printf("%c",CC);*/
        CKata.TabKata[i] = CC;
        /*printf("masuk%c",CKata.TabKata[i]);*/ 
        ADV_File(); 
        i++; 
    } /* CC = MARK or CC = BLANK */ 
    CKata.Length = i; 
}

void SalinKata_Input(Kata *CKata, char *command){
       
}
boolean IsStringSama(char* string1, char* string2){
    boolean sama = true;
    if (string1.Length == string2.Length){
        int i = 0;
        while ((i < string1.Length) && sama){
            if ((string1.TabKata[i]) != (string2.TabKata[i])){
                sama = false;
            }
            i++;
        }
    }else{
        sama = false;
    }
    return sama;
}