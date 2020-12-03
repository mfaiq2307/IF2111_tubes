#ifndef __MESINKATA1_H__ 
#define __MESINKATA1_H__ 

#include "mesin_kar.h" 
#define NMax 50 
#define BLANK ' ' 

typedef struct { 
char TabKata[NMax]; 
int Length; 
} Kata; 

/* State Mesin Kata */ 
extern boolean EndKata; 
extern Kata CKata; 

void IgnoreBlank_File(); 
/* Mengabaikan satu atau beberapa BLANK 
I.S.: CC sembarang 
F.S.: CC ≠ BLANK atau CC = MARK */ 

void STARTKATA_File(); 
/* I.S.: CC sembarang 
F.S.: EndKata = true, dan CC = Mark;  
atau EndKata = false, 
CKata adalah kata yang sudah diakuisisi, 
CC karakter pertama sesudah karakter terakhir kata */ 
void ADVKATA_File(); 
/* I.S.: CC adalah karakter pertama kata yang akan diakuisisi 
F.S.: CKata adalah kata terakhir yang sudah diakuisisi,  
CC adalah karakter pertama dari kata berikutnya, mungkin MARK  
Proses: Akuisisi kata menggunakan procedure SalinKata */ 
void SalinKata_File(); 
/* Mengakuisisi kata, menyimpan dalam CKata 
I.S.: CC adalah karakter pertama dari kata 
F.S.: CKata berisi kata yang sudah diakuisisi;  
CC = BLANK atau CC = MARK;  
CC adalah karakter sesudah karakter terakhir yang diakuisisi */ 

void SalinKata_Input(Kata *CKata, char *command);

boolean IsKataSama(Kata string1, Kata string2);
#endif 
