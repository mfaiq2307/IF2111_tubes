#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*include include file ADT */
#include "adt/mesinkata.h"
#include "adt/circular_queue.h"

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
        int max=15;
        Queue Q;
        Q = CreateQueue(max);

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
            }
            else if(IsStringSama(Command.TabKata,"STARTBUILD")){
                /* code */
            }
            else if(IsStringSama(Command.TabKata,"FINISHBUILD")){
                /* code */
            }
            else if(IsStringSama(Command.TabKata,"ADDCOMPONENT")){
                /* code */
            }
            else if(IsStringSama(Command.TabKata,"REMOVECOMPONENT")){
                /* code */
            }
            else if(IsStringSama(Command.TabKata,"SHOP")){
                /* code */
            }
            else if(IsStringSama(Command.TabKata,"DELIVER")){
                /* code */

                Dequeue(&Q); /*Pesanan terdepan diambil dari queue */
            }
            else if(IsStringSama(Command.TabKata,"END_DAY")){

                /* code */
                Order(&Q); /*Pesanan dibangkitkan secara random */
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

