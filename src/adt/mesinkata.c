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

void SalinKata_Input(Kata *CKata){
    char command[NMax];
    int c;
    int i = 0;
    while (((c = (char)fgetc(stdin)) != '\n') && (i < NMax)){
        command[i] = c;
        i++;
    }
    CKata->TabKata[i] = '\0'; 
    CKata->Length = i;
    int j = 0;
    while (j < NMax){
        CKata->TabKata[j] = command[j];
        j++;
    }
}
boolean IsStringSama(char* string1, char* string2){
    int i = 0;
    boolean sama = true;
    while((string1[i] != '\0') && (string2[i] != '\0') && (sama)){
        if(string1[i] != string2[i]){
            sama = false;
        }
        i++;
    }

    return sama;
}

void SalinKata_Item() { 
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
    while ((CC != MARK) && (CC != ',')) {
        /*printf("%c",CC);*/
        CKata.TabKata[i] = CC;
        /*printf("masuk%c",CKata.TabKata[i]);*/ 
        ADV_File(); 
        i++; 
    } /* CC = MARK or CC = BLANK */ 
    CKata.Length = i; 
}