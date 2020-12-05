#include "boolean.h"
#include "point.h"
#include "point.c"
#include "mesinkata.h"
#include "mesinkata.c"
#include "mesin_kar.h"
#include "mesin_kar.c"
#include "matriks.h"
#include "matriks.c"
#include <stdio.h>
#include <stdlib.h>

ListOfBangunan Bangunan; 
POINT LokasiPlayer; 
MATRIKS Map; 

void LoadingMap(char *FileMap,MATRIKS *Map,ListOfBangunan *LBangunan, POINT *PLoc){
    int NBaris, NKolom; // Baris Kolom
    int MinNObjek, NObjek; // Minimal -> Maksimal Objek
    int X, Y; // Koordinat Point
    char JenisBangunan, CharCustomer;
    int Customer = 0; // Customer ke berapa?
    int a;
    char b;

    STARTKATA_File(FileMap);

    ADVKATA_File();

    NBaris = KataToInt(CKata); //10
    ADVKATA_File();
    NKolom = KataToInt(CKata); //15
    MakeMATRIKS(NBaris,NKolom,Map);
    ADVKATA_File();
    InsertSpasi(Map); // Isi Matriks dengan spasi dulu semuanya 
    NObjek = KataToInt(CKata); // 9
    CreateListBangunan(LBangunan);
    ADVKATA_File();    

    for (MinNObjek = 0; MinNObjek <= NObjek+1; MinNObjek++)
    {
        JenisBangunan = CKata.TabKata[0];
        ADVKATA_File();
        X = KataToInt(CKata);
        ADVKATA_File();
        Y = KataToInt(CKata);
        InsertListBangunan(LBangunan, JenisBangunan, X, Y);
        ADVKATA_File();

        if (JenisBangunan=='C')
        {
            Customer = Customer + 1; // Dimulai dari Customer nomor 1
            CharCustomer = IntToChar(Customer); // Ubah int(Customer) menjadi char()
            WriteBuilding (Map,CharCustomer,X,Y); // Tulis Customernya di titik X,Y di Map
        }
        else if (JenisBangunan=='B')
        {
            *PLoc = MakePOINT(X,Y); 
        }
        else // S
        {
            WriteBuilding (Map, JenisBangunan, X, Y);
        }
    } 
}   

void MAP(){
    WriteMap(Map, Absis(LokasiPlayer), Ordinat(LokasiPlayer));
}

int main(){
    LoadingMap("config.txt", &Map, &Bangunan, &LokasiPlayer);
    MAP();
}