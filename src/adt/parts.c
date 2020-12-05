#include <stdio.h>
#include <stdlib.h>
#include "parts.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakePartEmpty(TabPart *T, int MaxElPart)
{
    /* I.S. T sembarang, MaxElPart > 0 */
    /* F.S. Terbentuk tabel T kosong dengan kapasitas MaxElPart + 1 */
    TP(*T) = (ElPartType *)malloc((MaxElPart + 1) * sizeof(ElPartType));
    NeffPart(*T) = 0;
    MaxElPart(*T) = MaxElPart;
}

void DealokasiPart(TabPart *T)
{
    /* I.S. T terdefinisi; */
    /* F.S. TP(T) dikembalikan ke system, MaxElPart(T)=0; NeffPart(T)=0 */
    free(TP(*T));
    NeffPart(*T) = 0;
    MaxElPart(*T) = 0;
}

IdxPartType FirstIdx(TabPart T)
{
    /* Prekondisi : Tabel T tidak kosong */
    /* Mengirimkan indeks elemen T pertama */
    return IdxMin;
}
IdxPartType LastIdx(TabPart T)
{
    /* Prekondisi : Tabel T tidak kosong */
    /* Mengirimkan indeks elemen T terakhir */
    return NeffPart(T) - FirstIdx(T) + 1;
}




/* ********** Test Indeks yang valid ********** */
boolean IsIdxValidPart(TabPart T, IdxPartType i)
{
    /* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
    /* yaitu antara indeks yang terdefinisi utk container*/
    return ((i >= IdxMin) && (i <= MaxElPart(T)));
}
boolean IsIdxEffPart(TabPart T, IdxPartType i)
{
    /* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
    /* yaitu antara FirstIdx(T)..LastIdx(T) */
    return ((i >= FirstIdx(T)) && (i <= LastIdx(T)));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmptyPart(TabPart T)
{
    /* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
    return (NeffPart(T) == 0);
}
boolean IsFullPart(TabPart T)
{
    /* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
    return (NeffPart(T) == MaxElPart(T) - IdxMin + 1);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void TulisIsiTabPart(TabPart T)
{
    /* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
    /* I.S. T boleh kosong */
    /* F.S. Jika T tidak kosong: [e1,e2,...,en] */
    /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
    /* Jika tabel kosong : menulis [] */
   if (IsEmptyPart(T))
    {
        printf("[]");
    }
    else
    {
        for (IdxPartType i = FirstIdx(T); i <= LastIdx(T); i++)
        {
            printf("%s,", NamaPart(T, i).TabKata);
            printf("%s,", HargaPart(T, i).TabKata);
            printf("%s", JenisPart(T, i).TabKata);
            printf("\n");
        }
    }
}
/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxPartType Search1Part(TabPart T, Kata NamaParts)
{
    /* Search apakah ada elemen tabel T yang bernilai X */
    /* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
    /* Jika tidak ada, mengirimkan IdxUndef */
    /* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
    /* Skema Searching yang digunakan bebas */
    for (IdxPartType i = IdxMin; i <= NeffPart(T)-IdxMin+1; i++)
    {
        if ((IsStringSama(NamaPart(T,i).TabKata, NamaParts.TabKata)))
        {
            return i;
        }
    }
    //
    return IdxUndef;
}
boolean SearchBPart(TabPart T, Kata NamaParts)
{
    /* Search apakah ada elemen tabel T yang bernilai X */
    /* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
    /* Skema searching yang digunakan bebas */
    boolean Found = false;
    IdxPartType i = IdxMin;
    //
    while ((!Found) && (i <= NeffPart(T)-IdxMin+1))
    {
        if ((IsStringSama(NamaPart(T,i).TabKata, NamaParts.TabKata)))
        {
            Found = true;
        }
        else
        {
            i++;
        }
    }
    //
    return Found;
}

/* ********** OPERASI LAIN ********** */
void CopyTabPart(TabPart Tin, TabPart *Tout)
{
    /* I.S. Tin terdefinisi tidak kosong, Tout sembarang */
    /* F.S. Tout berisi salinan dari Tin (identik, NeffPart dan MaxElPart sama) */
    /* Proses : Menyalin isi Tin ke Tout */
    TabPart ToutT;
    MakePartEmpty(&ToutT, MaxElPart(Tin));
    NeffPart(ToutT) = NeffPart(Tin);
    //
    for (IdxPartType i = FirstIdx(Tin); i <= LastIdx(Tin); i++)
    {
        ElmtPart(ToutT, i) = ElmtPart(Tin, i);
    }
    *Tout = ToutT;
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastElPart(TabPart *T, ElPartType X)
{
    /* Proses: Menambahkan X sebagai elemen terakhir tabel */
    /* I.S. Tabel T boleh kosong, tetapi tidak penuh */
    /* F.S. X adalah elemen terakhir T yang baru */
    NeffPart(*T)++;
    ElmtPart(*T, LastIdx(*T)) = X;
}