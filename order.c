# include <stdio.h>
# include <stdlib.h>
# include "circular_queue.h"

void order(Queue *Q) {
    int num = (rand() % 7); /* Mengambil random nomor pemain */
    int price;
    int i;
    int *kompo;
    kompo=(int *) malloc(8*(sizeof(int)));
    for(i=0;i<8;i++){
        kompo[i]= (rand() % 3);

    }
    Item k;
    Kompn(k)=kompo;
    Enqueue(&(*Q),num,k,price);

}
