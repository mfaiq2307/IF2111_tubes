#include "stdio.h"
#include "stdlib.h"
#include "graph.h"


void CreateGraph(POINT P, Graph *G){
    addrNode Pn;
    Pn = AlokNode(P);
    First(*G) = Pn; 
}

addrNode AlokNode(POINT P){
    addrNode Pn = (addrNode) malloc(1 * sizeof (ElmtNode));
    if (Pn != Nil){
        Info(Pn) = P;
        Hub(Pn) = Nil;
        Next(Pn) = Nil;
        return Pn;
    } {
        return Nil;
    }
}

addrCon AlokCon(addrNode Pn)
{
    addrCon Pt = (addrCon) malloc(1 * sizeof (ConnectNode));
}

void DealokNode(addrNode *Pn)
{
    free(*Pn);
}
void DealokCon(addrCon *Pt)
{
    free(*Pt);
}
addrNode SearchNode(Graph G, POINT P)
{
    
}

addrCon SearchEdge(Graph G, POINT P1, POINT P2)
{

}

void InsertNode(Graph G, POINT P)
{

}

void InsertEdge(Graph G, POINT P1, POINT P2)
{

}

/* ADT TAMBAHAN UNTUK KEPERLUAN GAME
baca map.txt, trus liat disitu, kalo dia 1 berarti dia nanti dihubungin sama jalan
ini belum di test, masih kasarnya aja

void ConvertMapToGraph (Matriks M, Graph *G){ 
    for (int i = BarisPertama; i <= BarisTerakhir; i++)
    {
        for (int j = KolomPertama; j <= KolomTerakhir; j++)
        {
            if (Elmt(M, i, j) == 1)
            {
                InsertEdge();
            }
        }
    }
}
/*