# include <stdlib.h>
# include <stdio.h>
# include "circular_queue.h"


void main(){
    int max=15; /*Jumlah maksimal antrian pesanan*/
    Queue Q;
    int nomorOrder=1; /* Nomor Order */
    Q = CreateQueue(max);
    printf("Pemesan : %d\n",NoPelanggan(InfoHead(Q)));
    printf("Invoice : $%d\n",Harga(InfoHead(Q)));
    CheckKomponen(Q);
    






}