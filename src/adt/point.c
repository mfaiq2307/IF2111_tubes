/* *** Implementasi ABSTRACT DATA TYPE POINT *** */

#include <stdio.h>
#include "boolean.h"
#include "math.h"
#include "point.h"
#include "mesinkata.h"

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (int X, int Y)
/* Membentuk sebuah POINT dari komponen-komponennya */
{
    POINT a;
    Absis(a) = X;
    Ordinat(a) = Y;
    return a;
}

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */                                                 
void ReadPOINT (POINT *P)
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk 
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2 
   akan membentuk POINT <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
{
    int x,y;
    scanf("%d %d",&x,&y);
    Absis(*P) = x;
    Ordinat(*P) = y;
}


void WritePOINT (POINT P)
/* Nilai P ditulis ke layar dengan format "(X,Y)" 
   tanpa spasi, enter, atau karakter lain di depan, belakang, 
   atau di antaranya */
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */
{
    printf("(%d,%d)",Absis(P),Ordinat(P)); /* perhatikan bahwa untuk menghasilkan 2 desimal, gunakan %.2f */
}
          

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EqPOINT (POINT P1, POINT P2)
/* Mengirimkan true jika P1 equivalent P2 : absis dan ordinatnya sama */
{
    return (Absis(P1) == Absis(P2) && Ordinat(P1) == Ordinat(P2));
}

boolean NEqPOINT (POINT P1, POINT P2)
/* Mengirimkan true jika P1 not equivalent dengan P2 */
{
    return !EqPOINT(P1,P2);
}

/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin (POINT P)
/* Menghasilkan true jika P adalah titik origin */
{
    return EqPOINT(P,MakePOINT(0,0));
}

boolean IsOnSbX (POINT P)
/* Menghasilkan true jika P terletak Pada sumbu X */
{
    return (Ordinat(P) == 0);
}

boolean IsOnSbY (POINT P)
/* Menghasilkan true jika P terletak pada sumbu Y */
{
    return (Absis(P) == 0);
}

int Kuadran (POINT P)
/* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
/* Prekondisi : P bukan titik origin, */
/*              dan P tidak terletak di salah satu sumbu */
{
    if(Absis(P) > 0 && Ordinat(P) > 0) {
        return 1;
    } else if(Absis(P) > 0 && Ordinat(P) < 0) {
        return 4;
    } else if(Absis(P) < 0 && Ordinat(P) < 0) {
        return 3;
    }
    else {
        return 2;
    }
}


/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
POINT PlusDelta (POINT P, int deltaX, int deltaY)
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
{
    Absis(P) = Absis(P) + deltaX;
    Ordinat(P) = Ordinat(P) + deltaY;
    return P;
}

void Geser (POINT *P, int deltaX, int deltaY)
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
{
    Absis(*P) = Absis(*P) + deltaX;
    Ordinat(*P) = Ordinat(*P) + deltaY;
}

float JarakToOrigin (POINT P)
/* Menghitung jarak P ke (0,0) */
{
    return (float)(sqrt( (Absis(P) * Absis(P) ) + (Ordinat(P) * Ordinat(P) ) ) ); /* atau bisa dengan pow(...,2) */
}

float Panjang (POINT P1, POINT P2)
/* Menghitung panjang garis yang dibentuk P1 dan P2. */
{
    return (float)sqrt(pow(Absis(P1) - Absis(P2), 2) + pow(Ordinat(P1) - Ordinat(P2), 2));
}

/* ADT TAMBAHAN UNTUK KEPERLUAN GAME */
void PlayerPosition (POINT *P, int X, int Y)
/* Mengembalikan nilai posisi dari player untuk keperluan DELIVER COMMAND */
{
    Absis(*P)=X;
    Ordinat(*P)=Y;
}

void CreateListBangunan(ListOfBangunan *L)
/* Membentuk penampungan dari Bangunan dalam representasi List */
{
    NBangunan(*L) = 0;
}

void InsertListBangunan (ListOfBangunan *L, char B, int X, int Y)
/* Meng-assign list bangunan ke dalam point X dan Y, dan char tipe bangunan */
/* (Base, Shop, Customer) di S */
{
    NBangunan(*L)++;
    Absis(Point(*L,NBangunan(*L))) = X;
    Ordinat(Point(*L,NBangunan(*L))) = Y;
    CSimbol(*L,NBangunan(*L)) = B;
}

char SearchSymPoint(ListOfBangunan L, int x, int y){
    POINT P;
    P = MakePOINT(x,y);
    int i = 0;
    boolean found = false;
    while((i < MaxBangunan+1) && (!found)){
        if(EqPOINT((Point(L,i)),P)){
            found = true;
        }else{
            i++;
        }
    }
    if(found){
        return CSimbol(L,i);
    }
    else{
        return '0';
    }
}

int SearchAbsis(ListOfBangunan L, char c){
    int i = 0;
    POINT P;
    boolean found = false;
    while((i < MaxBangunan+1) && (!found)){
        if(CSimbol(L,i) == c){
            found = true;
        }else{
            i++;
        }
    }if(found){
        return Point(L,i).X;
    }
    else{
        return 0;
    }
}

int SearchOrdinat(ListOfBangunan L, char c){
    int i = 0;
    POINT P;
    boolean found = false;
    while((i < MaxBangunan+1) && (!found)){
        if(CSimbol(L,i) == c){
            found = true;
        }else{
            i++;
        }
    }if(found){
        return Point(L,i).Y;
    }
    else{
        return 0;
    }
}