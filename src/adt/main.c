#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*include include file ADT */
#include "mesinkata.h"
#include "circular_queue.h"
#include "stack.h"
#include "parts.h"
#include "inventory.h"
#include "graph.h"
#include "addition.h"
#include "map.h"

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
        /*Pembangunan Peta berdasarkan Konfigurasi */
        STARTKATA_File("config.txt");
        /* Deklarasi Status &
        Initialisasi Kondisi Awal Game*/
        status_t Status;
        Status.Uang = 10000;
        /*base*/


        /*Baris kode buat bikin Map */
        ListOfBangunan L; // Semua building masukin ke list
        MATRIKS Map; // Peta Gamenya
        POINT PLOCA;

        LoadingMap("config.txt", &Map, &L, &PLOCA);
        MAP(Map, Absis(PLOCA), Ordinat(PLOCA));
        EndRead();
        Status.PlayerLoc.X = Absis(PLOCA);
        Status.PlayerLoc.Y = Ordinat(PLOCA);
        /*--------Pembuatan Graph------------*/ 
        printf("Masul");
        
        STARTKATA_File("config.txt");
        int i = 0;
        for (i = 0; i < 36;i++){
            ADVKATA_File();
        }

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
        int Baris = 1;
        while (Baris <= 9){
            int Kolom = 1;
            while(Kolom <= 9){
                ADVKATA_File();
                if (IsStringSama(CKata.TabKata,"1")){
                    InsertEdge(&G,Baris,Kolom);
                }
                Kolom++;
            }
            Baris++;
        }
        /*Tes Graph: PrintGraph(G);*/
        /* Pembuatan Queue dengan panjang max */
        int max=15; /*Jumlah maksimal antrian pesanan*/
        Queue Q;
        int nomorOrder=1; /* Nomor Order */
        Q = CreateQueue(max);
        Order(&Q); /*Inisialisasi Order*/
        boolean OrderAman = false;

        /* Deklarasi Stack */
        Stack S;

        /* Baris kode buat inventory */
        TabInventory T;

        /*Input Command */
        Kata Command;
        printf("ENTER COMMAND: ");
        SalinKata_Input(&Command);

        while (!IsStringSama(Command.TabKata,"EXIT")){
            if(IsStringSama(Command.TabKata,"MOVE")){
                char SymGraph;
                SymGraph = SearchSymPoint(L, Absis(Locate(Status)), Ordinat(Locate(Status)));
                int IdxGraph;
                IdxGraph = SearchIndex(G,SymGraph);
                addrNode GPS;
                GPS = SearchNode(G,IdxGraph);
                if (!HubEmpty(GPS)){
                    printf("Daftar lokasi yang dapat dicapai: \n");
                    addrCon Way = Hub(GPS);
                    int Iterator = 1;
                    while(Way != Null){
                        if(Bangunan(Info(Connect(Way))) == 'B'){
                            printf("%d. Base\n",&Iterator);
                        }
                        else if (Bangunan(Info(Connect(Way))) == 'S'){
                            printf("%d. Shop\n",&Iterator);
                        }
                        else
                        {
                            printf("%d. Pelanggan %c\n",Iterator,Bangunan(Info(Connect(Way))));
                        }
                        Way = NextC(Way);
                        Iterator++;
                    }

                    char MoveTo;
                    printf("Nomor tujuan: ");
                    MoveTo = READ_Input();
                        
                    int Where = 1;
                    addrCon WayP = Hub(GPS);
                    while (IntToChar(Where) != MoveTo){
                        WayP = NextC(WayP);
                        Where++;
                    }
                    printf("\n");
                    char Dest = Bangunan(Info(Connect(WayP)));
                        
                    Locate(Status) = SearchPoint(L,Dest);

                    printf("Kamu telah mencapai lokasi Pelanggan %c", &Dest);
                }
                /* code */
            }
            else if(IsStringSama(Command.TabKata,"STATUS")){
                /* code */
                printf("Uang tersisa: $%d\n",Status.Uang);
                printf("Buld yang sedang dikerjakan: pesanan %d untuk pelanggan %d\n", &nomorOrder, NoPelanggan(InfoHead(Q)));
                char SymStatus;
                SymStatus =  SearchSymPoint(L, Absis(Locate(Status)), Ordinat(Locate(Status)));               
                if (SymStatus == 'B'){
                    printf("Lokasi: pemain sedang berada pada base \n");
                }
                else if (SymStatus == 'S'){
                    printf("Lokasi: pemain sedang berada pada shop\n");
                }else{
                    printf("Lokasi: pemain sedang berada pada pelanggan %d\n", CharToInt(SymStatus));
                }
                printf("Inventory anda: \n");
                TulisIsiTabInventory(T);
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
                /*Jika jumlah elemen stack = 8*/
                if (NbStackElmt(S)==8) {
                    int *komponen = Kompn(ListKomponen(InfoHead(Q))); /* Assigm List Komponen pada Head Queue ke dalam variabel komponen yang bertipe list of integer*/
                    int i; /* variabel indeks */
                    int count=0 ; /* determiner untuk ketepatan isi stack melalui jumlah count=8 */
                    for(i=0;i<8;i++) { /* Pengecekan isi stack apakah sudah sesuai urutan dan  isinya dengan list komponen queue */
                        if (i==0){  /*MotherBoard*/
                            if ((komponen[i]==0) && (IsStringSama(S.T[i],"ROG X570"))) { /*x570*/
                                    count++;
                                }
                            else if ((komponen[i]==1) && (IsStringSama(S.T[i],"UF B550"))) { /*b550*/
                                    count++;
                                }
                            else if ((komponen[i]==2) && (IsStringSama(S.T[i],"ASUS A320"))) { /*a320*/
                                    count++;
                                }
                            else { 
                                    count--;
                                }
                            }
                        if (i==1){ /*CPU*/
                            if ((komponen[i]==0) && (IsStringSama(S.T[i],"AMD Ryzen 7"))) {/* ryzen 7*/
                                    count++;
                                }
                            else if ((komponen[i]==1) && (IsStringSama(S.T[i],"AMD Ryzen 5"))){/* ryzen 5*/
                                    count++;
                                }
                            else if ((komponen[i]==2) && (IsStringSama(S.T[i],"AMD Ryzen 3"))){ /* ryzen 3 */
                                    count++;
                                }
                            else { 
                                    count--;
                                }
                            }
                        if (i==2){ /*RAM*/
                            if ((komponen[i]==0) && (IsStringSama(S.T[i],"Kingston HyperX Fury 2x16 GB"))) { /*2x16 Gb*/
                                    count++;
                                }
                            else if ((komponen[i]==1) && (IsStringSama(S.T[i],"Kingston HyperX 2x8 GB"))) { /*2x8 GB*/
                                    count++;
                                }
                            else if ((komponen[i]==2) && (IsStringSama(S.T[i],"Kingston 2x4 GB"))){ /*2x4 GB */
                                    count++;
                                }
                            else { 
                                    count--;
                                }
                            }
                        if (i==3){ /*CPU Cooler */
                            if ((komponen[i]==0) && (IsStringSama(S.T[i],"Noctua AIO Watercooling"))) { /*AIO Watercooling*/
                                    count++;
                                }
                            else if ((komponen[i]==1) && (IsStringSama(S.T[i],"Noctua High-profile Aircooling"))) { /*High-profile Aircooling */
                                    count++;
                                }
                            else if ((komponen[i]==2) && (IsStringSama(S.T[i],"Noctua Low-profile Aircooling"))) { /* Low-profile Aircooling */
                                    count++;
                                }
                            else { 
                                    count--;
                                }
                            }
                        if (i==4){ /*Casing*/
                            if ((komponen[i]==0) && (IsStringSama(S.T[i],"SilverStone Tower"))) { /*Tower*/
                                    count++;
                                }
                            else if ((komponen[i]==1) && (IsStringSama(S.T[i],"SilverStone MTX"))) { /*MTX*/
                                   count++;
                                }
                            else if ((komponen[i]==2) && (IsStringSama(S.T[i],"SilverStone ITX"))) { /*ITX*/
                                   count++;
                                }
                            else { 
                                    count--;
                                }
                            }
                        if (i==5){ /*GPU*/
                            if ((komponen[i]==5) && (IsStringSama(S.T[i],"Nvidia RTX 2060"))) { /*RTX*/
                                    count++;          
                                }
                            else if ((komponen[i]==1) && (IsStringSama(S.T[i],"Nvidia GTX 1050Ti"))){ /*GTX*/
                                   count++;
                                }
                            else if ((komponen[i]==2) && (IsStringSama(S.T[i],"Nvidia GTX 750"))){ /*GT*/
                                    count++;
                                }
                            else { 
                                    count--;
                                }
                            }                   
                        if (i==6){ /*Storage*/
                            if ((komponen[i]==0) && (IsStringSama(S.T[i],"WD Black NVME SSD 512GB"))) { /*NVME SSD 512 GB*/
                                    count++;
                                }
                            else if ((komponen[i]==1) && (IsStringSama(S.T[i],"WD Green SATA SSD 512GB"))){ /*SATA SSD 512 GB*/
                                    count++;
                                }
                            else if ((komponen[i]==2) && (IsStringSama(S.T[i],"WD Blue SATA HDD 1TB"))){ /* SATA HDD 1 TB*/
                                    count++;
                                }
                            else { 
                                    count--;
                                }
                            }
                        if (i==7){ /*PSU*/
                            if ((komponen[i]==0) && (IsStringSama(S.T[i],"Corsair 850W Gold Efficiency"))) { /*Gold Efficiency*/
                                    count++;
                                }
                            else if ((komponen[i]==1) && (IsStringSama(S.T[i],"Corsair 650W Silver Efficiency"))){ /*Silver Efficiency*/
                                    count++;
                                }
                            else if ((komponen[i]==2) && (IsStringSama(S.T[i],"Corsair 450W Bronze Efficiency"))){/* Bronze Efficiency*/
                                    count++;
                                }
                            else { 
                                    count--;
                                }
                            }
                        }
                    if (count==8) { /* Jika telah Selesai */
                            printf("Pesanan %d telah selesai. Silahkan antar ke pelanggan %d!\n",nomorOrder,NoPelanggan(InfoHead(Q)));
                            Dequeue(&Q); /*Pesanan terdepan diambil dari queue */
                            SimpanPart(&T,IntToKata(nomorOrder),IntToKata(99));
                            nomorOrder++;
                            OrderAman = true;
                        }
                    else { /*Jika belum selesai yaitu isinya belum sesuai*/
                            printf("Komponen yang dipasangkan belum sesuai dengan pesanan, build belum dapat diselesaikan.\n");
                        }
                    }
                /*Jika belum selesai yaitu jumlah elemen stack < 8*/
                else {
                    printf("Komponen yang dipasangkan belum sesuai dengan pesanan, build belum dapat diselesaikan.\n");
                }

            }
            else if(IsStringSama(Command.TabKata,"ADDCOMPONENT")){
                printf("Komponen yang telah terpasang: \n");
                PrintStack(S);
                printf("Komponen yang tersedia: \n");
                TulisIsiTabInventory(T);
                int pilihan;
                printf("Komponen yang ingin dipasang:");
                scanf("%d", &pilihan);
                printf("\n");
                int indekspart;
                int i;
                i = 0;
                indekspart = 1 ;
                while(i<pilihan){
                    if(BanyakInventory(T,indekspart) != 0){
                        i++;
                    }
                    indekspart++;
                }
                Kata katapartterambil;
                katapartterambil = NamaInventory(T,indekspart);
                char partterambil[40];
                CopyString(NamaInventory(T,indekspart).TabKata,partterambil);
                AmbilPart(&T,katapartterambil);
                Push(&S,partterambil);
                printf("Komponen berhasil dipasang!");
                printf("\n");    
            }
            else if(IsStringSama(Command.TabKata,"REMOVECOMPONENT")){
                char X[40];
                Pop(&S, X);
                printf("Komponen %s berhasil dicopot!\n", X);
            }
            else if(IsStringSama(Command.TabKata,"SHOP")){
                STARTKATA_File("parts.txt");
                ElPartType shop;
                TabPart arrayshop;
                MakePartEmpty(&arrayshop,30);
                while(!IsEOP()){
                    Kata katashop;
                    katashop=CKata;
                    ADVKATA_File();
                    Kata hargashop;
                    hargashop=CKata;
                    ADVKATA_File();
                    Kata jenisshop;
                    jenisshop=CKata;
                    shop.NamaPart=katashop;
                    shop.HargaPart=hargashop;
                    shop.JenisPart=jenisshop;
                    AddAsLastElPart(&arrayshop,shop);
                    ADVKATA_File();    
                }
                printf("Komponen yang tersedia");
                TulisIsiTabPart(arrayshop);
                int pilihan;
                int kuantitas;
                pilihan = scanf("Komponen yang ingin dibeli :");
                kuantitas = scanf("Masukkan jumlah yang ingin dibeli :");
                if(kuantitas*(KataToInt(HargaPart(arrayshop,pilihan))) <= Status.Uang){
                    int i;
                    for(i = 1 ; i <= kuantitas; i++){
                        SimpanPart(&T,NamaPart(arrayshop,pilihan),JenisPart(arrayshop,pilihan));
                    }
                    Status.Uang = Status.Uang - kuantitas*(KataToInt(HargaPart(arrayshop,pilihan)));
                }
                else{
                    printf("uang tidak cukup");
                }
            }
            else if(IsStringSama(Command.TabKata,"DELIVER")){

                char InfoIdx;
                InfoIdx = IntToChar(NoPelanggan(InfoHead(Q)));
                boolean CanDeliver;
                CanDeliver = EqPOINT((Locate(Status)),SearchPoint(L,InfoIdx));
                if(OrderAman && CanDeliver){
                    Status.Uang = Status.Uang + Harga(InfoHead(Q)); /* Invoice dimasukkan ke status uang */
                    OrderAman = false;
                }else{
                    printf("Delivery tidak dapat dilakukan ehe, mohon cek detail order anda :D");
                }
            }
            else if(IsStringSama(Command.TabKata,"END_DAY")){

                /* code */
                Order(&Q); /*Pesanan dibangkitkan secara random */
            }
            else if(IsStringSama(Command.TabKata,"SAVE")){
                /* code */

            }
            else if(IsStringSama(Command.TabKata,"MAP")){
                MAP(Map, Absis(Locate(Status)), Ordinat(Locate(Status)));
            }
            Command = Purify(Command);
            printf("ENTER COMMAND: ");
            SalinKata_Input(&Command);     
        }
    }
}

