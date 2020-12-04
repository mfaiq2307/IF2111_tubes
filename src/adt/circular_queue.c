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
            Enqueue(&baru, NoPelanggan(InfoTail(Q)),ListKomponen(InfoTail(Q)),Harga(InfoTail(Q)));
            tail = (tail + 1) % MaxOrder(Q);
        }
    }
    return baru;
}

void Order (Queue * Q) {
    int num = (rand() % 7); /* Mengambil random nomor pemain */
    int price=0; /* Insiasi harga */
    int i; /* indeks pada list komponen */
    int *kompo;
    kompo=(int *) malloc(8*(sizeof(int)));
    for(i=0;i<8;i++){ 
        kompo[i]= (rand() % 3);
        if (i==0){  /*MotherBoard*/
            if (kompo[i]==0) { /*x570*/
                price = price + 400;
            }
            else if (kompo[i]==1){ /*b550*/
                price = price + 250;
            }
            else { /*a320*/
                price = price + 150;
            }
        }
        if (i==1){ /*CPU*/
            if (kompo[i]==0) {/* ryzen 7*/
                price = price + 300;
            }
            else if (kompo[i]==1){/* ryzen 5*/
                price = price + 200;
            }
            else { /* ryzen 3 */
                price = price + 100;
            }
        }
        if (i==2){ /*RAM*/
            if (kompo[i]==0) { /*2x16 Gb*/
                price = price + 160;
            }
            else if (kompo[i]==1){ /*2x8 GB*/
                price = price + 80;
            }
            else { /*2x4 GB */
                price = price + 40;
            }
        }
        if (i==3){ /*CPU Cooler */
            if (kompo[i]==0) { /*AIO Watercooling*/
                price = price + 100;
            }
            else if (kompo[i]==1){ /*High-profile Aircooling */
                price = price + 50;
            }
            else { /* Low-profile Aircooling */
                price = price + 25;
            }
        }
        if (i==4){ /*Casing*/
            if (kompo[i]==0) { /*Tower*/
                price = price + 100;
            }
            else if (kompo[i]==1){ /*MTX*/
                price = price + 100;
            }
            else { /*ITX*/
                price = price + 25;
            }
        }
        if (i==5){ /*GPU*/
            if (kompo[i]==5) { /*RTX*/
                price = price + 300;
            }
            else if (kompo[i]==1){ /*GTX*/
                price = price + 100;
            }
            else { /*GT*/
                price = price + 30;
            }
        }
        if (i==6){ /*Storage*/
            if (kompo[i]==0) { /*NVME SSD 512 GB*/
                price = price + 80;
            }
            else if (kompo[i]==1){ /*SATA SSD 512 GB*/
                price = price + 60;
            }
            else { /* SATA HDD 1 TB*/
                price = price + 40;
            }
        }
        if (i==7){ /*PSU*/
            if (kompo[i]==0) { /*Gold Efficiency*/
                price = price + 80;
            }
            else if (kompo[i]==1){ /*Silver Efficiency*/
                price = price + 60;
            }
            else { /* Bronze Efficiency*/
                price = price + 40;
            }
        }
        

    }
    price = price + 30; /* Harga komponen ditambah upah pengerjaan */
    Item k;
    Kompn(k)=kompo;  /* Assign list komponen menjadi elemen tipe Item */
    Enqueue((&Q),num,k,price);
}

void CheckKomponen(Queue Q){
    int *komponen = Kompn(ListKomponen(InfoHead(Q)));
    int i;
    printf("Komponen:")
    for(i=0;i<8;i++){ 
        if (i==0){  /*MotherBoard*/
            if (komponen[i]==0) { /*x570*/
                printf("1. ROG X570");
            }
            else if (komponen[i]==1){ /*b550*/
                printf("1. TUF B550");
            }
            else { /*a320*/
                printf("1. ASUS A320");
            }
        }
        if (i==1){ /*CPU*/
            if (komponen[i]==0) {/* ryzen 7*/
                printf("2. AMD Ryzen 7");
            }
            else if (komponen[i]==1){/* ryzen 5*/
                printf("2. AMD Ryzen 5");
            }
            else { /* ryzen 3 */
                printf("2. AMD Ryzen 3");
            }
        }
        if (i==2){ /*RAM*/
            if (komponen[i]==0) { /*2x16 Gb*/
                printf("3. Kingston HyperX Fury 2x16 GB");
            }
            else if (komponen[i]==1){ /*2x8 GB*/
                printf("3. Kingston HyperX 2x8 GB");
            }
            else { /*2x4 GB */
                printf("3. Kingston 2x4 GB");
            }
        }
        if (i==3){ /*CPU Cooler */
            if (komponen[i]==0) { /*AIO Watercooling*/
                printf("4. Noctua AIO Watercooling");
            }
            else if (komponen[i]==1){ /*High-profile Aircooling */
                printf("4. Noctua High-profile Aircooling");
            }
            else { /* Low-profile Aircooling */
                printf("4. Noctua Low-profile Aircooling");
            }
        }
        if (i==4){ /*Casing*/
            if (komponen[i]==0) { /*Tower*/
                printf("5. SilverStone Tower");
            }
            else if (komponen[i]==1){ /*MTX*/
                printf("5. SilverStone MTX");
            }
            else { /*ITX*/
                printf("5. SilverStone ITX");
            }
        }
        if (i==5){ /*GPU*/
            if (komponen[i]==5) { /*RTX*/
                printf("6. Nvidia RTX 2060");
            }
            else if (komponen[i]==1){ /*GTX*/
                printf("6. Nvidia GTX 1050Ti");
            }
            else { /*GT*/
                printf("6. Nvidia GTX 750");
            }
        }
        if (i==6){ /*Storage*/
            if (komponen[i]==0) { /*NVME SSD 512 GB*/
                printf("7. WD Black NVME SSD 512GB");
            }
            else if (komponen[i]==1){ /*SATA SSD 512 GB*/
                printf("7. WD Green SATA SSD 512GB");
            }
            else { /* SATA HDD 1 TB*/
                printf("7. WD Blue SATA HDD 1TB");
            }
        }
        if (i==7){ /*PSU*/
            if (komponen[i]==0) { /*Gold Efficiency*/
                printf("8. Corsair 850W Gold Efficiency");
            }
            else if (komponen[i]==1){ /*Silver Efficiency*/
                printf("8. Corsair 650W Silver Efficiency");
            }
            else { /* Bronze Efficiency*/
                printf("8. Corsair 450W Bronze Efficiency");
            }
        }
        

    }
}

