#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*include include file ADT */
#include "adt/mesinkata.h"
#include "adt/circular_queue.h"
#include "adt/stack.h"
#include "adt/parts.h"
#include "adt/inventory.h"
#include "adt/graph.h"
#include "adt/addition.h"

int main(void)
{
    Kata Start; /* bisa diganti pilihan */
    printf("1. Start Game \n");
    printf("2. Load Game \n");
    printf("Press 1 or 2 to Pick: ");
    SalinKata_Input(&Start);
    int init;
    init = KataToInt(Start);

    if (init == 1){
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

        /*Baris kode buat bikin Map */


        /*--------Pembuatan Graph------------*/ 

        
        Graph G;
        CreateGraph(&G);
        int Elemen = 9; /*Ambil dari file Konfig Map, CKata yg ke tiga. Sekarang 9*/
        int index;
        /*Inserting Node dan ElmtNode*/
        for (index = 1; index <= Elemen;index++){
            InsertNode(&G,index);
        }
        MappingGraph(&G);
        /*Memetakan Koneksi antar Node */
        int Baris = 0;
        int Kolom = 0;
        while (Baris <= 9){
            while(Kolom <= 9){
                ADVKATA_File();
                if (KataToInt(CKata) == 1){
                    InsertEdge(&G,Baris,Kolom);
                }
                Kolom++;
            }
            Baris++;
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

        /* Baris kode buat inventory */


        Kata Command;
        printf("ENTER COMMAND: ");
        SalinKata_Input(&Command);

        while (!IsStringSama(Command.TabKata,"EXIT")){
            if(IsStringSama(Command.TabKata,"MOVE")){
                printf("Masuk Move\n");
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
            Command = Purify(Command);
            printf("ENTER COMMAND: ");
            SalinKata_Input(&Command);     
        }
    }
}

