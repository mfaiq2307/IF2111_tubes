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

    STARTKATA_File(FileMap);
    NBaris = KataToInt(CKata); //10
    ADVKATA_File();
    NKolom = KataToInt(CKata); //15
    MakeMATRIKS(NBaris,NKolom,Map);
    ADVKATA_File();
    InsertSpasi(Map); // Isi Matriks dengan spasi dulu semuanya 
    ADVKATA_File();
    NObjek = KataToInt(CKata); // 9
    CreateListBangunan(LBangunan);

    for (MinNObjek = 1; MinNObjek <= NObjek; MinNObjek++)
    {
        ADVKATA_File();
        JenisBangunan = CKata.TabKata[0]; //B

        ADVKATA_File();
        X = KataToInt(CKata);

        ADVKATA_File();
        Y = KataToInt(CKata);

        InsertListBangunan(LBangunan, JenisBangunan, X, Y);
        
        if (JenisBangunan=='C')
        {
            Customer = Customer + 1;
            CharCustomer = IntToChar(Customer);
            WriteBuilding (Map,CharCustomer,X,Y);
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