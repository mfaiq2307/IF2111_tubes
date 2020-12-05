#include <stdio.h>
#include <stdlib.h>

#include "matriks.h"


/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */              
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS(int NBaris, int NKolom, MATRIKS *M)
{
    indeks i;
    indeks j;
    (*M).Baris = NBaris;
    (*M).Kolom = NKolom;
    for (i = 0; i < NBaris; i++)
    {
        for (j = 0; j < NKolom; j++)
        {
            (*M).Mem[i][j] = 0;
        }
    }
}

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid (int i, int j)
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
{
    return (i >= BarisMin && i <= BarisMax && j >= KolomMin && j <= KolomMax);
   
}

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks BarisPertama (MATRIKS M)
/* Mengirimkan indeks baris terkecil M */
{
    return BarisMin;
}
indeks KolomPertama (MATRIKS M)
/* Mengirimkan indeks kolom terkecil M */
{
    return KolomMin;
}
indeks BarisTerakhir (MATRIKS M)
/* Mengirimkan indeks baris terbesar M */
{
    return Baris(M);
}
indeks KolomTerakhir (MATRIKS M)
/* Mengirimkan indeks kolom terbesar M */
{
    return Kolom(M);
}

ELTYPE GetElmtDiagonal (MATRIKS M, indeks i)
/* Mengirimkan elemen M(i,i) */
{
    return Elmt(M,i,i);
}

/* ADT TAMBAHAN UNTUK KEPERLUAN GAME */
void WriteMap (MATRIKS M, indeks X, indeks Y)
/* Membuat Matriks Map */
{
    indeks i;
    indeks j;

    //BORDER ATAS
    for (j = KolomPertama(M); j <= KolomTerakhir(M)+2; j++)
    {
        printf("*");
    }
    printf("\n");

    for (i = BarisPertama(M); i <= BarisTerakhir(M); i++)
    {
        printf("*");
        for (j = KolomPertama(M); j <= KolomTerakhir(M); j++)
        {
            if (i == X)
            {
                if (j == Y)
                {
                    printf("%c", 'P'); // Overwrite Base menjadi Player
                }
                else 
                {
                    printf("%c", Elmt(M,i,j)); // Tulis building di map berdasarkan koordinatnya
                }
            } 
            else 
            {
                printf("%c", Elmt(M,i,j)); // Tulis building di map berdasarkan koordinatnya
            }
        }
        printf("*\n");
    }
    //BORDER BAWAH
    for (j = KolomPertama(M); j <= KolomTerakhir(M)+2; j++)
    {
        printf("*");
    }
    printf("\n");  
}

void InsertSpasi (MATRIKS *M)
/* Setelah MakeMATRIKS, isi elemen M mula-mula dengan spasi saja */
{
    indeks i;
    indeks j;
    for (i = BarisPertama(*M); i <= BarisTerakhir(*M); i++)
    {
        for (j = KolomPertama(*M); j <= KolomTerakhir(*M); j++)
        {
            Elmt(*M,i,j) = ' '; // Isi elemen matriks dengan spasi
        }
    }
}

void WriteBuilding (MATRIKS *M, char C, indeks X, indeks Y)
/* Char C yang merupakan Jenis Bangunan ditulis di M dengan koordinat X dan Y */
{
    Elmt(*M,X,Y) = C;
}

