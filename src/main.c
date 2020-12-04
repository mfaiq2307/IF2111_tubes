#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*include include file ADT */
#include "adt/mesinkata.h"
#include "adt/circular_queue.h"
#include "adt/stack.h"

typedef struct {
    int Uang;
    int Order; /* ini nanti diganti sama ADT Queue */
    int Lokasi; /*ini nanti diganti sama ADT Point */
} status_t;

int main(void)
{
    int Start; /* bisa diganti pilihan */
    printf("1. Start Game Game \n");
    printf("2. Load Game \n");
    printf("Press 1 or 2 to Pick.\n");
    scanf("%d",Start);

    if (Start == 1){
        STARTKATA_File("data/config.txt");
        /*Pembangunan Peta berdasarkan Konfigurasi */
        
        /* Deklarasi Status &
        Initialisasi Kondisi Awal Game*/
        status_t Status;
        Status.Uang = 10000;
        Status.Lokasi = 0;/*base*/

        /* Baris kode buat ngebangkitin order*/
        /* Baris kode buat nyimpen detail order pertama di 
        Status : Status.order = ...*/

        /* Baris kode buat nentuin Ukuran Peta */
        int Baris;
        int Kolom;
        while (!EndKata) {
            Baris = CC;
            ADV_File();
            Kolom = CC; 
        }

        
        /* Baris kode buat Jumlah Bangunan */
        int NBangunan;
        ADVKATA_File;
        NBangunan = CC;
        
        /* Baris kode buat Spesifikin Bangunan */
        for (int i=0;i<NBangunan;i++){
            /*Kode buat masukin tiap bangunan ke ADT Point */
        }
        /* Pembuatan Queue dengan panjang max */
        int max=15; /*Jumlah maksimal antrian pesanan*/
        Queue Q;
        int nomorOrder=1; /* Nomor Order */
        Q = CreateQueue(max);
        Order(&Q); /*Inisialisasi Order*/

        /* Deklarasi Stack */
        Stack S;

        /*Baris kode buat bikin Map */

        /* Baris kode buat ngebangkitin order*/

        Kata Command;
        printf("ENTER COMMAND: ");
        SalinKata_Input(&Command);

        while (!IsStringSama(Command.TabKata,"EXIT")){
            if(IsStringSama(Command.TabKata,"MOVE")){
                /* code */
            }
            else if(IsStringSama(Command.TabKata,"STATUS")){
                /* code */
                
            }
            else if(IsStringSama(Command.TabKata,"CHECKORDER")){
                /* code */
                printf("Nomor Order: %d\n",nomorOrder);
                printf("Pemesan : %d\n",NoPelanggan(InfoHead(Q)));
                printf("Invoice : $%d\n",Harga(InfoHead(Q)));
                CheckKomponen(Q);
            }
            else if(IsStringSama(Command.TabKata,"STARTBUILD")){
                CreateEmptyStack(&S);
                printf("Kamu telah memulai pesanan %d untuk pelanggan %d\n",nomorOrder,NoPelanggan(InfoHead(Q)));
            }
            else if(IsStringSama(Command.TabKata,"FINISHBUILD")){
                /* code */
                /*Jika telah selesai*/
                printf("Pesanan %d telah selesai. Sialhkan antar ke pelanggan %d!\n",nomorOrder,NoPelanggan(InfoHead(Q)));

                /*Jika belum selesai*/
                printf("Komponen yang dipasangkan belum sesuai dengan pesanan, build belum dapat diselesaikan.\n");

            }
            else if(IsStringSama(Command.TabKata,"ADDCOMPONENT")){
                printf("Komponen yang telah terpasang: \n");
                PrintStack(S);
                printf("Komponen yang tersedia: \n");

            }
            else if(IsStringSama(Command.TabKata,"REMOVECOMPONENT")){
                char X[40];
                Pop(&S, X);
                printf("Komponen %s berhasil dicopot!\n", X);
            }
            else if(IsStringSama(Command.TabKata,"SHOP")){
                /* code */
            }
            else if(IsStringSama(Command.TabKata,"DELIVER")){
                /* code */
                Status.Uang = Status.Uang + Harga(InfoHead(Q)); /* Invoice dimasukkan ke status uang */
                Dequeue(&Q); /*Pesanan terdepan diambil dari queue */
            }
            else if(IsStringSama(Command.TabKata,"END_DAY")){

                /* code */
                Order(&Q); /*Pesanan dibangkitkan secara random */
                nomorOrder++;
            }
            else if(IsStringSama(Command.TabKata,"SAVE")){
                /* code */

            }
            else if(IsStringSama(Command.TabKata,"MAP")){
                /* code */
            }
            printf("ENTER COMMAND: ");
            SalinKata_Input(&Command);     
        }
    }
}

