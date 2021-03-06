#include "stack.h"
#include "mesinkata.h"

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyStack (Stack *S)
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl-1 */
/* Ciri stack kosong : TOP bernilai Nil */
{
	Top(*S) = Nil;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsStackEmpty (Stack S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
{
	return Top(S) == Nil;
}
boolean IsStackFull (Stack S)
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
{
	return Top(S) == MaxEl - 1;
}

int NbStackElmt (Stack S)
/* Menghitung jumlah elemen stack efektif */
{
	int count = 0;
	int i = 0;

	while (i < 8 && (i != Top(S)+1)) {
		count++;
		i++;
	}
	return count;
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push (Stack *S, infotype X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
	Top(*S)++;
	CopyString(X, InfoTop(*S));
}
/* ************ Menghapus sebuah elemen Stack ************ */
void Pop (Stack *S, infotype X)
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
	CopyString(InfoTop(*S), X);
	Top(*S)--;
}

/* ************ Mencetak sebuah elemen Stack ************ */
void PrintStack(Stack S)
/* Mencetak elemen dari Stack */
/* I.S. sembarang; */
/* F.S. Tercetak semua elemen Stack dari indeks awal hingga indeks TOP */
{
	int i;
	for (i = 0; i < S.TOP+1; i++)
	{
		printf("%d. %s\n", i+1, S.T[i]);
	}
}