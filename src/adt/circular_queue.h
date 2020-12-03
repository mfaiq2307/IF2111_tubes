/* MODUL CIRCULAR QUEUE */
/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi dinamik */
/* Implementasi Queue menggunakan circular buffer (Alternatif III) */

#ifndef __circular_queue_h__
#define __circular_queue_h__

#include "boolean.h"

/* Nilai untuk indeks yang tidak terdefinisi */
#define NIL -999

/* Definisi tipe elemen dan indeks pada Queue */
typedef struct {
    int *compn;
}Item;

# define Kompn(K) (K).compn

typedef struct{
    int noPelanggan;    /*  Nomor Representasi Pemain dalam game yang meng-order*/
    Item listKomponen;    /* Komponen - Komponen yang di butuhkan */
    int harga;} ElType;  /*harga dari pesanan */
typedef int IdxType;

# define NoPelanggan(E) (E).noPelanggan
# define ListKomponen(E) (E).listKomponen
# define Harga(E) (E).harga

typedef struct { ElType * Info;  /* tabel penyimpan detail pesanan */
                 IdxType HEAD;  /* indeks pesanan yang paling awal untuk diselesaikan*/
                 IdxType TAIL;  /* indeks pesanan yang  terakhir di order */
                 int MaxOrder;     /* kapasitas jumlah pesanan*/
               } Queue;
/* Definisi Queue kosong: HEAD=NIL; TAIL=NIL. */
#define Head(Q) (Q).HEAD
#define Tail(Q) (Q).TAIL
#define InfoHead(Q) (Q).Info[(Q).HEAD]
#define InfoTail(Q) (Q).Info[(Q).TAIL]
#define MaxOrder(Q) (Q).MaxOrder
#define NoPesanan(Q) (Q).noPesanan
/* ********* Prototype ********* */
boolean IsEmpty (Queue Q);
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsFull (Queue Q);
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxOrder */
int Length (Queue Q);
/* Mengirimkan banyaknya elemen Q, 0 jika kosong */
int MaxLength (Queue Q);
/* Mengirimkan kapasitas jumlah elemen Q */

/* *** Kreator *** */
Queue CreateQueue (int Max);
/* Proses : Melakukan alokasi memori, membuat sebuah Q kosong */
/* I.S. sembarang */
/* F.S. mengembalikan Q kosong dengan kondisi sbb: */
/*   Jika alokasi berhasil, Tab dialokasi berukuran Max */
/*   Jika alokasi gagal, Q kosong dengan MaxOrder=0 */

/* *** Destruktor *** */
void DeleteQueue (Queue * Q);
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. membebaskan memori Tab, Q.MaxOrder di-set 0 */

/* *** Primitif Add/Delete *** */
void Enqueue (Queue * Q, int num, Item component, int price);
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru,
        TAIL "maju" dengan mekanisme circular buffer
        Jika Q kosong, HEAD dimulai dari 0 */
ElType Dequeue (Queue * Q);
/* Proses: Menghapus indeks HEAD pada Q dengan aturan FIFO, lalu mengembalikan nilainya */
/* I.S. Q tidak mungkin kosong */
/* F.S. mengembalikan nilai Q pada indeks HEAD;
        HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
ElType Front (Queue Q);
/* Proses: Mengembalikan nilai Q pada indeks HEAD tanpa penghapusan */
/* I.S. Q tidak mungkin kosong */
/* F.S. mengembalikan nilai Q pada indeks HEAD;
        Q pasti tetap tidak kosong */

/* *** Utilitas *** */
Queue CopyQueue (Queue Q);
/* Proses: Mengembalikan Queue baru dengan isi antrean sama seperti Q */
/* I.S. Q pernah dialokasi */
/* F.S. Queue baru dengan nilai isi antrean sama seperti Q;
        HEAD pada Queue baru dimulai dari 0 */

void Order (Queue *Q);
/* Proses : Menambahkan pesanan dengan elemen info yang dibangkitkan secara random*/
/* I.S. Q mungkin kosong */
/* F.S. Queue baru dengan  tambahan satu pesanan */

#endif
