#include <stdlib.h>
#include "mesinkata.h"
#include "mesin_kar.h"
#include "graph.h"


int main() {
    Graph G;
    CreateGraph(&G);
    int Elemen = 9; /*Ambil dari file Konfig Map, CKata yg ke tiga. Sekarang 9*/
    int index;
        /*Inserting Node dan ElmtNode*/
    for (index = 1; index <= Elemen;index++){
        InsertNode(&G,index);
    }
    MappingGraph(&G);
    PrintGraph(G);
    int Baris = 1;
    while (Baris <= 9){
        int Kolom = 1;
        while(Kolom <= 9){
            if ((Baris/Kolom == 0) && (Baris != Kolom)){
                InsertEdge(&G,Baris,Kolom);
            }
            printf("Kolom: %d\n",Kolom);
            Kolom++;
        }
        Baris++;
        printf("Baris: %d \n",Baris);
    }
    PrintGraph(G);
} 
