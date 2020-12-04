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
boolean IsIdxEff (MATRIKS M, indeks i, indeks j)
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
{
    return (i>=BarisPertama(M) && i<=BarisTerakhir(M) && j>=KolomPertama(M) && j<=KolomTerakhir(M));
}
ElType GetElmtDiagonal (MATRIKS M, indeks i)
/* Mengirimkan elemen M(i,i) */
{
    return Elmt(M,i,i);
}

/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl)
/* Melakukan assignment MHsl  MIn */
{
    indeks i;
    indeks j;
    MakeMATRIKS(Baris(MIn),Kolom(MIn),MHsl);
    for (i = BarisPertama(MIn); i <= BarisTerakhir(MIn); i++)
    {
        for (j = KolomPertama(MIn); i <= KolomTerakhir(MIn); j++)
        {
            Elmt(*MHsl,i,j) = Elmt(MIn,i,j);
        }
        
    }
}

/* ********** KELOMPOK BACA/TULIS ********** */ 
void BacaMATRIKS (MATRIKS *M, int NB, int NK)
/* I.S. IsIdxValid(NB,NK) */ 
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
{
    indeks i;
    indeks j;    
    MakeMATRIKS(NB,NK,M);
    for (i = BarisPertama(*M); i <= BarisTerakhir(*M); i++)
    {
        for (j = KolomPertama(*M); j <= KolomTerakhir(*M); j++)
        {
			scanf("%d",&(Elmt(*M,i,j)));
        }
    }
}
void TulisMATRIKS (MATRIKS M)
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
{
    indeks i;
    indeks j;
    for (i = BarisPertama(M); i <= BarisTerakhir(M); i++)
    {
        for (j = KolomPertama(M); j < KolomTerakhir(M); j++)
        {
            printf("%d ", Elmt(M,i,j)); 
        }
        printf("%d\n", Elmt(M,i,KolomTerakhir(M)));
    }
}

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */                                  
MATRIKS TambahMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : M1  berukuran sama dengan M2 */
/* Mengirim hasil penjumlahan matriks: M1 + M2 */ 
{
    MATRIKS Mp;
    indeks i;
    indeks j;
    MakeMATRIKS(Baris(M1),Kolom(M1),&Mp);
    for (i = BarisPertama(Mp); i <= BarisTerakhir(Mp); i++)
    {
        for (j = KolomPertama(Mp); j <= KolomTerakhir(Mp); j++)
        { 
            Elmt(Mp,i,j) = Elmt(M1,i,j) + Elmt(M2,i,j);       
        }
    }
    return Mp;
}
MATRIKS KurangMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : M berukuran sama dengan M */
/* Mengirim hasil pengurangan matriks: salinan M1 – M2 */
{
    MATRIKS Mm;
    indeks i;
    indeks j;
    MakeMATRIKS(Baris(M1),Kolom(M1),&Mm);
    for (i = BarisPertama(Mm); i <= BarisTerakhir(Mm); i++)
    {
        for (j = KolomPertama(Mm); j <= KolomTerakhir(Mm); j++)
        {
            Elmt(Mm,i,j) = Elmt(M1,i,j) - Elmt(M2,i,j);        
        }
    }
    return Mm;
} 
MATRIKS KaliMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2 */
/* Mengirim hasil perkalian matriks: salinan M1 * M2 */
{
    MATRIKS Mt;
    indeks i;
    indeks j;
    indeks k;
    MakeMATRIKS(Baris(M1),Kolom(M2),&Mt);
    for (i = BarisPertama(Mt); i <= BarisTerakhir(Mt); i++){
        for (j = KolomPertama(Mt); j <= KolomTerakhir(Mt); j++){
            for (k = KolomPertama(M1); k <= KolomTerakhir(M1); k++){
                Elmt(Mt,i,j) += Elmt(M1,i,k)*Elmt(M2,k,j); 
            }       
        }
    }
    return Mt;
}
MATRIKS KaliKons (MATRIKS M, ElType X)
/* Mengirim hasil perkalian setiap elemen M dengan X */
{
    MATRIKS Mt;
    indeks i;
    indeks j;
    MakeMATRIKS(Baris(M),Kolom(M),&Mt);
    for (i = BarisPertama(Mt); i <= BarisTerakhir(Mt); i++)
    {
        for (j = KolomPertama(Mt); j <= KolomTerakhir(Mt); j++)
        {
            Elmt(Mt,i,j) = X*Elmt(M,i,j);
        }
    }
    return Mt;
}
void PKaliKons (MATRIKS *M, ElType K)
/* I.S. M terdefinisi, K terdefinisi */
/* F.S. Mengalikan setiap elemen M dengan K */
{
    indeks i;
    indeks j;
    for (i = BarisPertama(*M); i <= BarisTerakhir(*M); i++)
    {
        for (j = KolomPertama(*M); j <= KolomTerakhir(*M); j++)
        {
            Elmt(*M,i,j) = K*Elmt(*M,i,j);
        }
    }
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
boolean EQMATRIKS (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
/* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
/* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2) 
   dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */
{
    boolean equal;
    indeks i;
    indeks j;

    if (EQSizeMATRIKS(M1,M2))
    {
        equal = true;
        i = BarisPertama(M1);
        while (equal && i<=BarisTerakhir(M1))
        {
            j = KolomPertama(M2);
            while (equal && j<=KolomTerakhir(M2))
            {
                if (Elmt(M1,i,j)!=Elmt(M2,i,j))
                {
                    equal = false;
                } else 
                {
                    j++;
                }
            }
            i++;
        }
        return equal;
    } 
    else 
    {
        return false;
    }
}
boolean NEQMATRIKS (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika M1 tidak sama dengan M2 */
{
    return !EQMATRIKS(M1,M2);
}

boolean EQSizeMATRIKS (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
/* yaitu NBrsEff(M1) = NBrsEff (M2) dan NKolEff (M1) = NKolEff (M2) */
{
    return Baris(M1) == Baris(M2) && Kolom(M1) == Kolom(M2);
}

/* ********** Operasi lain ********** */
int NBElmtMATRIKS (MATRIKS M)
/* Mengirimkan banyaknya elemen M */
{
    return Baris(M)*Kolom(M);
}

/* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */
boolean IsBujurSangkar (MATRIKS M)
/* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */
{
    return Baris(M) == Kolom(M);
}
boolean IsSimetri (MATRIKS M)
/* Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M) 
   dan untuk setiap elemen M, M(i,j)=M(j,i) */
{
    boolean simetri;
    indeks i;
    indeks j;

    if (IsBujurSangkar(M))
    {
        simetri = true;
        i = BarisPertama(M);
        while (simetri && i<=BarisTerakhir(M))
        {
            j = KolomPertama(M);
            while (simetri && j<=KolomTerakhir(M))
            {
                if (Elmt(M,i,j)!=Elmt(M,j,i))
                {
                    simetri = false;
                } else 
                {
                    j++;
                }
            }
            i++;
        }
        return simetri;
    } 
    else 
    {
        return false;
    }
}
boolean IsSatuan (MATRIKS M)
/* Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) dan 
   setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
{
    boolean satuan;
    indeks i;
    indeks j;

    if (IsBujurSangkar(M)){
        satuan = true;
        i = BarisPertama(M);
        while (satuan && i<=BarisTerakhir(M))
        {
            j = KolomPertama(M);
            while (satuan && j<=KolomTerakhir(M))
            {
                if (i==j)
                {
                    if (Elmt(M,i,j)!=1)
                    {
                        satuan = false;
                    }
                } 
                else 
                {
                    if (Elmt(M,i,j)!=0)
                    {
                        satuan = false;
                    }
                }
                j++;
            }
            i++;
        }
    }
} 
boolean IsSparse (MATRIKS M)
/* Mengirimkan true jika M adalah matriks sparse: matriks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */ 
{
    int count = 0;
    indeks i;
    indeks j;
    for (i = BarisPertama(M); i <= BarisTerakhir(M); i++)
    {
        for (j = KolomPertama(M); j <= KolomTerakhir(M); j++)
        {
            if (Elmt(M,i,j)!=0)
            {
                count++;
            }
        }
    }
    return (0.05*NBElmtMATRIKS(M) >= count);
}
MATRIKS Inverse1 (MATRIKS M)
/* Menghasilkan salinan M dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
{
    MATRIKS MIn;
    indeks i;
    indeks j;
    MakeMATRIKS(Baris(M),Kolom(M),&MIn);
    for (i = BarisPertama(M); i <= BarisTerakhir(M); i++)
    {
        for (j = KolomPertama(M); j <= KolomTerakhir(M); j++)
        {
            Elmt(MIn,i,j) = (-1)*(Elmt(M,i,j));
        }
    }
    return MIn;
}
void Transpose (MATRIKS * M)
/* I.S. M terdefinisi dan IsBujursangkar(M) */
/* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */
{
    ElType temp;
    for (indeks i=BarisPertama(*M); i<=BarisTerakhir(*M); i++)
    { 
        for (indeks j=i; j<=KolomTerakhir(*M); j++)
        {
            temp = Elmt(*M,j,i);
            Elmt(*M,j,i) = Elmt(*M,i,j);
            Elmt(*M,i,j) = temp;
        }
    }
}
float RataBrs (MATRIKS M, indeks i)
/* Menghasilkan rata-rata dari elemen pada baris ke-i */
/* Prekondisi: i adalah indeks baris efektif dari M */
{
    ElType sum = 0;
    for (indeks j=KolomPertama(M); j<=KolomTerakhir(M); j++)
    {
        sum = sum + Elmt(M,i,j);
    }
    return (float)sum/Kolom(M);
}
float RataKol (MATRIKS M, indeks j)
/* Menghasilkan rata-rata dari elemen pada kolom ke-j */
/* Prekondisi: j adalah indeks kolom efektif dari M */
{
    ElType sum = 0;
    for (indeks i = BarisPertama(M); j <= BarisTerakhir(M); i++)
    {
        sum = sum + Elmt(M,i,j);
    }
    return (float)sum/Baris(M);
}
void MaxMinBrs (MATRIKS M, indeks i, ElType * max, ElType * min)
/* I.S. i adalah indeks baris efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada baris i dari M
           min berisi elemen minimum pada baris i dari M */
{
    indeks j;
    (*max) = Elmt(M,i,0);
    (*min) = Elmt(M,i,0);
    for (j = KolomPertama(M); j <= KolomTerakhir(M); j++)
    {
        if (Elmt(M,i,j) > (*max))
        {
            (*max) = Elmt(M,i,j);
        }
        if (Elmt(M,i,j) < (*min))
        {
            (*min) = Elmt(M,i,j);
        }
    }
}
void MaxMinKol (MATRIKS M, indeks j, ElType * max, ElType * min)
/* I.S. j adalah indeks kolom efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada kolom j dari M
           min berisi elemen minimum pada kolom j dari M */
{
    indeks i;
    (*max) = Elmt(M,0,j);
    (*min) = Elmt(M,0,j);
    for (i = BarisPertama(M); j <= BarisTerakhir(M); i++)
    {
        if (Elmt(M,i,j) > (*max))
        {
            (*max) = Elmt(M,i,j);
        }
        if (Elmt(M,i,j)<*min)
        {
            (*min) = Elmt(M,i,j);
        }
    }
}
int CountXBrs (MATRIKS M, indeks i, ElType X)
/* Menghasilkan banyaknya kemunculan X pada baris i dari M */
{
    indeks j;
    int count = 0;
    for (j = KolomPertama(M); j < KolomTerakhir(M); j++)
    {
        if (Elmt(M,i,j)==X)
        {
            count++;
        }
    }
    return count;
}
int CountXKol (MATRIKS M, indeks j, ElType X)
/* Menghasilkan banyaknya kemunculan X pada kolom j dari M */
{
    indeks i;
    int count = 0;
    for (i = BarisPertama(M); i <= BarisTerakhir(M); i++)
    {
        if (Elmt(M,i,j)==X)
        {
            count++;
        }
    }
    return count;
}

/* ADT TAMBAHAN UNTUK KEPERLUAN GAME */
void WriteMap (MATRIKS M, indeks X, indeks Y)
/* I.S. M terdefinisi sebagai Map, berikut dengan simbolnya */
/* F.S. Map tertulis di layar dicover oleh bintang '*', dan replace posisi P di koordinat (X,Y) */
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
                    printf("%c", 'P');
                }
                else 
                {
                    printf("%c", Elmt(M,i,j));
                }
            } 
            else 
            {
                printf("%c", Elmt(M,i,j));
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
/* I.S. M terdefinisi sebagai Map Kosong */ 
/* F.S. Map diisi dengan spasi ' ' */
{
    indeks i;
    indeks j;
    for (i = BarisPertama(*M); i <= BarisTerakhir(*M); i++)
    {
        for (j = KolomPertama(*M); j <= KolomTerakhir(*M); j++)
        {
            Elmt(*M,i,j) = ' ';
        }
    }
}

void WriteBuilding (MATRIKS *M, char C, indeks X, indeks Y)
/* I.S. M terdefinisi sebagai Map Kosong */ 
/* F.S. Char (C) yang merupakan sebuah building char terdefinisi di Map pada koordinat (X,Y) */
{
    Elmt(*M,X,Y) = C;
}

