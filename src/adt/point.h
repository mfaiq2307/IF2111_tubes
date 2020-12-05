/* File: point.h */
/* *** Definisi ABSTRACT DATA TYPE POINT *** */

#ifndef POINT_H
#define POINT_H

#include "boolean.h"

typedef struct { 
	int X;
	int Y; 
} POINT;

/*** TAMBAHAN UNTUK POINT.BANGUNAN ***/

#define MaxBangunan 20

typedef struct {
   POINT Lokasi;   
   char Simbol;
} BANGUNAN;

typedef struct {
   BANGUNAN ArrayOfBuilding[MaxBangunan+1]; 
   int NBangunan;  
} ListOfBangunan;

/* *** Notasi Akses: Selektor POINT *** */
#define Absis(P) (P).X
#define Ordinat(P) (P).Y
        
/* *** Notasi Akses: Selektor POINT.BANGUNAN *** */
#define NBangunan(L) (L).NBangunan
#define Point(L,i) (L).ArrayOfBuilding[(i)].Lokasi
#define CSimbol(L,i) (L).ArrayOfBuilding[(i)].Simbol

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (int X, int Y);
/* Membentuk sebuah POINT dari komponen-komponennya */

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */                                                 
void BacaPOINT (POINT * P); 
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk 
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2 
   akan membentuk POINT <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */

void TulisPOINT (POINT P);
/* Nilai P ditulis ke layar dengan format "(X,Y)" 
   tanpa spasi, enter, atau karakter lain di depan, belakang, 
   atau di antaranya */
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */                

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EqPOINT (POINT P1, POINT P2);
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */

boolean NEqPOINT (POINT P1, POINT P2);
/* Mengirimkan true jika P1 tidak sama dengan P2 */

/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin (POINT P);
/* Menghasilkan true jika P adalah titik origin */

boolean IsOnSbX (POINT P);
/* Menghasilkan true jika P terletak Pada sumbu X */

boolean IsOnSbY (POINT P);
/* Menghasilkan true jika P terletak pada sumbu Y */

int Kuadran (POINT P);
/* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
/* Prekondisi : P bukan titik origin, */
/*              dan P tidak terletak di salah satu sumbu */

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
POINT PlusDelta (POINT P, int deltaX, int deltaY);
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */

void Geser (POINT *P, int deltaX, int deltaY);
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */

float JarakToOrigin (POINT P);
/* Menghitung jarak P ke (0,0) */

float Panjang (POINT P1, POINT P2);
/* Menghitung panjang garis yang dibentuk P1 dan P2. */

/* ADT TAMBAHAN UNTUK KEPERLUAN GAME */
void PlayerPosition (POINT *P, int X, int Y);
/* Mengembalikan nilai posisi dari player untuk keperluan DELIVER COMMAND */

void CreateListBangunan(ListOfBangunan *L);
/* Membentuk penampungan dari Bangunan dalam representasi List */

void InsertListBangunan (ListOfBangunan *L, char B, int X, int Y);
/* Meng-assign list bangunan ke dalam point X dan Y, dan char tipe bangunan */
/* (Base, Shop, Customer) di B */

char SearchSymPoint(ListOfBangunan L, int x, int y);

POINT SearchPoint(ListOfBangunan L, char c);

char* SymToString(char c);

#endif
