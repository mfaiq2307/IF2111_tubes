#ifndef MATRIKS_H
#define MATRIKS_H

#include "boolean.h"

/* Ukuran minimum dan maksimum baris dan kolom */
#define BarisMin 1
#define BarisMax 50
#define KolomMin 1
#define KolomMax 50

typedef int indeks; /* indeks baris, kolom */
typedef char ElType; 
typedef struct { 
	ElType Mem[BarisMax+1][KolomMax+1];
   int Baris; /* banyaknya/ukuran baris yg terdefinisi */
	int Kolom; /* banyaknya/ukuran kolom yg terdefinisi */
} MATRIKS;
/* NBrsEff >= 1 dan NKolEff >= 1 */
/* Indeks matriks yang digunakan: [BrsMin..BrsMax][KolMin..KolMax] */
/* Memori matriks yang dipakai selalu di "ujung kiri atas" */

/* *** Selektor *** */
#define Baris(M) (M).Baris
#define Kolom(M) (M).Kolom
#define Elmt(M,i,j) (M).Mem[(i)][(j)]

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */              
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NBaris, int NKolom, MATRIKS *M); 
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NBaris x NKolom di "ujung kiri" memori */
/* I.S. Baris dan Kolom adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
/* (Baris dan Kolom dibaca melalui file eksternal konfigurasi) */

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid (int i, int j);
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks BarisPertama (MATRIKS M);
/* Mengirimkan indeks baris terkecil M */

indeks KolomPertama (MATRIKS M); 
/* Mengirimkan indeks kolom terkecil M */

indeks BarisTerakhir(MATRIKS M);
/* Mengirimkan indeks baris terbesar M */

indeks KolomTerakhir(MATRIKS M);
/* Mengirimkan indeks kolom terbesar M */

ElType GetElmtDiagonal (MATRIKS M, indeks i);
/* Mengirimkan elemen M(i,i) */

/* ADT TAMBAHAN UNTUK KEPERLUAN GAME */
void WriteMap (MATRIKS M,indeks X, indeks Y);
/* Membuat Matriks Map */

void InsertSpasi (MATRIKS *M);
/* Setelah MakeMATRIKS, isi elemen M mula-mula dengan spasi saja */

void WriteBuilding (MATRIKS *M, char C, int X, int Y);
/* Char C yang merupakan Jenis Bangunan ditulis di M dengan koordinat X dan Y */


#endif