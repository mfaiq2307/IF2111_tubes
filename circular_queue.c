#include<stdlib.h>
#include "circular_queue.h"

/* ********* Prototype ********* */
boolean IsEmpty (Queue Q) {
    return Head(Q)== NIL && Tail(Q)== NIL;
}
boolean IsFull (Queue Q) {
    return Length(Q) == MaxOrder(Q);
}
int Length (Queue Q) {
    if (IsEmpty(Q))
        return 0;
    else if (Head(Q)>= Tail(Q))
        return MaxOrder(Q)+ Tail(Q) - Head(Q);
    else
        return Tail(Q) - Head(Q);
}
int MaxLength (Queue Q) {
    return MaxOrder(Q);
}

/* *** Kreator *** */
Queue CreateQueue (int Max) {
    Queue Q;
    Q.Info = (ElType *) malloc (Max * sizeof(ElType));
    Head(Q) = NIL;
    Tail(Q)= NIL;
    MaxOrder(Q) = Max;
    return Q;
}

/* *** Destruktor *** */
void DeleteQueue (Queue * Q) {
    MaxOrder(*Q)= 0;
    free(Q->Info);
}

/* *** Primitif Add/Delete *** */
void Enqueue (Queue * Q, int num, Item component, int price) {
    /*Kamus Lokal*/
    ElType X;
    /*Algoritma*/
    NoPelanggan(X)=num;
    ListKomponen(X)=component;
    Harga(X)=price;
    
    if (IsEmpty(*Q)) {
        Head(*Q) = 0;
        Tail(*Q) = 0;
    }
    InfoTail(*Q) = X;
    Tail(*Q)++;
    if (Tail(*Q) == MaxOrder(*Q)){
        Tail(*Q) = 0;
    }
    
    
}
ElType Dequeue (Queue * Q) {
    ElType ret = InfoHead(*Q);
    Head(*Q)++;
    if (Head(*Q) == MaxOrder(*Q)) {
        Head(*Q)= 0;
    }
    if (Head(*Q)==Tail(*Q)) {
        Head(*Q)= NIL;
        Tail(*Q) = NIL;
    }
    return ret;
}
ElType Front (Queue Q) {
    return InfoHead(Q);
}

/* *** Utilitas *** */
Queue CopyQueue (Queue Q) {
    Queue baru = CreateQueue(MaxOrder(Q));
    if (!IsEmpty(Q)) {
        int tail = Head(Q);
        while (Length(baru) != Length(Q)) {
            Push(&baru, NoPelanggan(InfoTail(Q)),ListKomponen(InfoTail(Q)),Harga(InfoTail(Q)));
            tail = (tail + 1) % MaxOrder(Q);
        }
    }
    return baru;
}

void Order(Queue *Q) {
    int num = (rand() % 7); /* Mengambil random nomor pemain */
    int price;
    int i; /* indeks pada list komponen */
    int *kompo;
    kompo=(int *) malloc(8*(sizeof(int)));
    for(i=0;i<8;i++){
        kompo[i]= (rand() % 3);
    }
    Item k;
    Kompn(k)=kompo; /* Assign list komponen menjadi elemen tipe Item */
    Enqueue(&(*Q),num,k,price);

}

