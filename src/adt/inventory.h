/* MODUL TABEL INTEGER */
/* Berisi definisi dan semua primitif pemrosesan tabel integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi II : dengan banyaknya elemen didefinisikan secara eksplisit,
   memori tabel dinamik */

#ifndef INVENTORY_H
#define INVENTORY_H

#include "boolean.h"
#include "mesinkata.h"


/*  Kamus Umum */
#define IdxMin 1
/* Indeks minimum array */
#define IdxUndef -999
/* Indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int IdxInventoryType; /* type indeks */
typedef struct{
    Kata NamaInventory;
    int BanyakInventory;
    Kata JenisInventory;
} ElInventoryType;  /* type elemen tabel */
typedef struct
{
    ElInventoryType *TInv; /* memori tempat penyimpan elemen (container) */
    int NeffInventory;   /* >=0, banyaknya elemen efektif */
    int MaxElInventory;  /* ukuran elemen */
} TabInventory;
/* Indeks yang digunakan [IdxMin..MaxEl] */
/* Jika T adalah TabInventory, cara deklarasi dan akses: */
/* Deklarasi : T : TabInventory */
/* Maka cara akses:
   T.NeffInventory  untuk mengetahui banyaknya elemen
   T.TI    untuk mengakses seluruh nilai elemen tabel
   T.TI[i] untuk mengakses elemen ke-i */
/* Definisi :
  Tabel kosong: T.NeffInventory = 0
  Definisi elemen pertama : T.TI[i] dengan i=1
  Definisi elemen terakhir yang terdefinisi: T.TI[i] dengan i=T.NeffInventory */

/* ********** SELEKTOR ********** */
#define NeffInventory(T) (T).NeffInventory
#define TInv(T) (T).TInv
#define ElmtInventory(T, i) (T).TInv[(i)]
#define MaxElInventory(T) (T).MaxElInventory
#define NamaInventory(T, i) (T).TInv[(i)].NamaInventory
#define BanyakInventory(T, i) (T).TInv[(i)].BanyakInventory
#define JenisInventory(T, i) (T).TInv[(i)].JenisInventory

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeInventoryEmpty(TabInventory *T, int maxel);
/* I.S. T sembarang, maxel > 0 */
/* F.S. Terbentuk tabel T kosong dengan kapasitas maxel + 1 */

void DealokasiInventory(TabInventory *T);
/* I.S. T terdefinisi; */
/* F.S. TI(T) dikembalikan ke system, MaxEl(T)=0; NeffInventory(T)=0 */

IdxInventoryType GetFirstIdx(TabInventory T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
IdxInventoryType GetLastIdx(TabInventory T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValidInventory(TabInventory T, IdxInventoryType i);

    /* Mengirimkan banyaknya elemen efektif tabel */
    /* Mengirimkan nol jika tabel kosong */
    /* *** Daya tampung container *** */
boolean IsIdxEffInventory(TabInventory T, IdxInventoryType i);
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmptyInventory(TabInventory T);
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
boolean IsFullInventory(TabInventory T);
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTInvUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void TulisIsiTabInventory(TabInventory T);
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxInventoryType Search1Inventory(TabInventory T, Kata NamaInventory);
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Skema Searching yang digunakan bebas */
boolean SearchBInventory(TabInventory T, Kata NamaInventory);
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Skema searching yang digunakan bebas */

/* ********** OPERASI LAIN ********** */
void CopyTabInventory(TabInventory Tin, TabInventory *Tout);
/* I.S. Tin terdefinisi tidak kosong, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (identik, NeffInventory dan MaxEl sama) */
/* Proses : Menyalin isi Tin ke Tout */

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastElInventory(TabInventory *T, ElInventoryType X);
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
/* ********** MENGHAPUS ELEMEN ********** */

void AmbilPart(TabInventory *T, Kata NamaInventory);

void SimpanPart(TabInventory *T, Kata NamaInventory, Kata JenisInventory);

#endif