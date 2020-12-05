
#include "map.h"

/*MATRIKS Map;
ListOfBangunan Bangunan;
POINT PLoc; */


void MAP(MATRIKS Map, int X, int Y)
{
    WriteMap(Map, X, Y);
}
void LoadingMap(char *FileMap,MATRIKS *Map,ListOfBangunan *LBangunan, POINT *PLoc){

    int NBaris, NKolom; // Baris Kolom
    int MinNObjek, NObjek; // Minimal -> Maksimal Objek
    int X, Y; // Koordinat Point
    char JenisBangunan, CharCustomer;
    int Customer = 0; // Customer ke berapa?
    int a;
    char b;

    /*STARTKATA_File(FileMap);*/

    ADVKATA_File();

    NBaris = KataToInt(CKata); //10
    ADVKATA_File();
    NKolom = KataToInt(CKata); //15
    MakeMATRIKS(NBaris,NKolom,Map); // Buat Matriks dengan 10 baris dan 15 kolom
    InsertSpasi(Map); // Isi Matriks dengan elemen spasi dulu semuanya 
    ADVKATA_File();
    NObjek = KataToInt(CKata); // 9
    CreateListBangunan(LBangunan);
    ADVKATA_File();    

    for (MinNObjek = 0; MinNObjek <= NObjek+1; MinNObjek++)
    {
        JenisBangunan = CKata.TabKata[0]; // Ambil karakter pertama
        ADVKATA_File();
        X = KataToInt(CKata); // Absis
        ADVKATA_File();
        Y = KataToInt(CKata); // Ordinat
        InsertListBangunan(LBangunan, JenisBangunan, X, Y); // Info setiap bangunan beserta koordinatnya disimpan di list bangunan
        ADVKATA_File();

        if (JenisBangunan== 'B')
        {
            *PLoc = MakePOINT(X,Y); // Lokasi Player saat ini
        }
        else if (JenisBangunan == 'S')
        {
            WriteBuilding (Map, JenisBangunan, X, Y);
        }
        else // (JenisBangunan == 'C')
        {
            Customer += 1; // Dimulai dari Customer nomor 1
            CharCustomer = IntToChar(Customer); // Ubah int(Customer) menjadi char()
            WriteBuilding (Map,CharCustomer,X,Y); // Tulis Customernya di titik X,Y di Map
        }
    }
}   
/*gcc map.c point.c mesinkata.c mesin_kar.c matriks.c */

/*int main()
{
    LoadingMap("config.txt", &Map, &Bangunan, &PLoc);
    MAP(Map, Absis(PLoc), Ordinat(PLoc));
    printf("\n");
    Kata Command;
    printf("ENTER COMMAND: ");
    SalinKata_Input(&Command);
    while ((!EndKata) && (!IsStringSama(Command.TabKata,"Done"))) { 
        /*for (int i=0;i<CKata.Length;i++) {
            printf("%s",CKata.TabKata);
        */
        /*printf("%s\n",CKata.TabKata); /*printf("\n");*/ 
        /*ADVKATA_File();
        printf("\n");
        Command = Purify(Command);
        printf("ENTER COMMAND: ");
        SalinKata_Input(&Command); 
    }
}
*/
