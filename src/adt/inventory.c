#include <stdio.h>
#include <stdlib.h>
#include "inventory.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeInventoryEmpty(TabInventory *T, int MaxElInventory)
{
    /* I.S. T sembarang, MaxElInventory > 0 */
    /* F.S. Terbentuk tabel T kosong dengan kapasitas MaxElInventory + 1 */
    TInv(*T) = (ElInventoryType *)malloc((MaxElInventory + 1) * sizeof(ElInventoryType));
    NeffInventory(*T) = 0;
    MaxElInventory(*T) = MaxElInventory;
}

void DealokasiInventory(TabInventory *T)
{
    /* I.S. T terdefinisi; */
    /* F.S. TInv(T) dikembalikan ke system, MaxElInventory(T)=0; NeffInventory(T)=0 */
    free(TInv(*T));
    NeffInventory(*T) = 0;
    MaxElInventory(*T) = 0;
}

IdxInventoryType GetFirstIdx(TabInventory T)
{
    /* Prekondisi : Tabel T tidak kosong */
    /* Mengirimkan indeks elemen T pertama */
    return IdxMin;
}
IdxInventoryType GetLastIdx(TabInventory T)
{
    /* Prekondisi : Tabel T tidak kosong */
    /* Mengirimkan indeks elemen T terakhir */
    return NeffInventory(T) - GetFirstIdx(T) + 1;
}




/* ********** Test Indeks yang valid ********** */
boolean IsIdxValidInventory(TabInventory T, IdxInventoryType i)
{
    /* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
    /* yaitu antara indeks yang terdefinisi utk container*/
    return ((i >= IdxMin) && (i <= MaxElInventory(T)));
}
boolean IsIdxEffInventory(TabInventory T, IdxInventoryType i)
{
    /* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
    /* yaitu antara FirstIdx(T)..LastIdx(T) */
    return ((i >= GetFirstIdx(T)) && (i <= GetLastIdx(T)));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmptyInventory(TabInventory T)
{
    /* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
    return (NeffInventory(T) == 0);
}
boolean IsFullInventory(TabInventory T)
{
    /* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
    return (NeffInventory(T) == MaxElInventory(T) - IdxMin + 1);
}

/* ********** BACA dan TULIS dengan INPUT/OUTInvUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void TulisIsiTabInventory(TabInventory T)
{
    /* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
    /* I.S. T boleh kosong */
    /* F.S. Jika T tidak kosong: [e1,e2,...,en] */
    /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
    /* Jika tabel kosong : menulis [] */
    if (IsEmptyInventory(T))
    {
        printf("inventory kosong");
    }
    else
    {
        for (IdxInventoryType i = GetFirstIdx(T); i <= GetLastIdx(T); i++)
        {
            if(BanyakInventory(T,i) != 0){
            printf("%s. ", i);
            printf("%s ", NamaInventory(T, i).TabKata);
            printf("\n");
            }
            
        }
    }
}
/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxInventoryType Search1Inventory(TabInventory T, Kata NamaInventorys)
{
    /* Search apakah ada elemen tabel T yang bernilai X */
    /* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
    /* Jika tidak ada, mengirimkan IdxUndef */
    /* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
    /* Skema Searching yang digunakan bebas */
    for (IdxInventoryType i = IdxMin; i <= NeffInventory(T)-IdxMin+1; i++)
    {
        if ((IsStringSama(NamaInventory(T,i).TabKata, NamaInventorys.TabKata)))
        {
            return i;
        }
    }
    //
    return IdxUndef;
}
boolean SearchBInventory(TabInventory T, Kata NamaInventorys)
{
    /* Search apakah ada elemen tabel T yang bernilai X */
    /* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
    /* Skema searching yang digunakan bebas */
    boolean Found = false;
    IdxInventoryType i = IdxMin;
    //
    while ((!Found) && (i <= NeffInventory(T)-IdxMin+1))
    {
        if ((IsStringSama(NamaInventory(T,i).TabKata, NamaInventorys.TabKata)))
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
void CopyTabInventory(TabInventory Tin, TabInventory *Tout)
{
    /* I.S. Tin terdefinisi tidak kosong, Tout sembarang */
    /* F.S. Tout berisi salinan dari Tin (identik, NeffInventory dan MaxElInventory sama) */
    /* Proses : Menyalin isi Tin ke Tout */
    TabInventory ToutT;
    MakeInventoryEmpty(&ToutT, MaxElInventory(Tin));
    NeffInventory(ToutT) = NeffInventory(Tin);
    //
    for (IdxInventoryType i = GetFirstIdx(Tin); i <= GetLastIdx(Tin); i++)
    {
        ElmtInventory(ToutT, i) = ElmtInventory(Tin, i);
    }
    *Tout = ToutT;
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastElInventory(TabInventory *T, ElInventoryType X)
{
    /* Proses: Menambahkan X sebagai elemen terakhir tabel */
    /* I.S. Tabel T boleh kosong, tetapi tidak penuh */
    /* F.S. X adalah elemen terakhir T yang baru */
    NeffInventory(*T)++;
    ElmtInventory(*T, GetLastIdx(*T)) = X;
}

void AmbilPart(TabInventory *T, Kata NamaInventory)
{
    IdxInventoryType indeksinventory;
    indeksinventory = Search1Inventory(*T,NamaInventory);
    if(indeksinventory == IdxUndef){
        printf("error part tidak tersedia");
    }
    else{
        if(BanyakInventory(*T,indeksinventory) == 0){
            printf("error part tidak tersedia");
        }
        else{
            BanyakInventory(*T,indeksinventory)--;

        }
    }


}

void SimpanPart(TabInventory *T, Kata NamaInventory, Kata JenisInventory)
{
    int adapart;
    adapart = Search1Inventory(*T, NamaInventory);
    if(adapart==IdxUndef){
        ElInventoryType inventorybaru;
        inventorybaru.NamaInventory=NamaInventory;
        inventorybaru.BanyakInventory=1;
        inventorybaru.JenisInventory=JenisInventory;
        AddAsLastElInventory(T,inventorybaru);
    }
    else{
        BanyakInventory(*T,adapart)++;
    }
    
}