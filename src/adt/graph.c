#include "stdio.h"
#include "stdlib.h"
#include "graph.h"


void CreateGraph(Graph *G){
    First(*G) = Null; 
}

boolean YesEmpty(Graph G){
    return (First(G) == Null);
}

addrNode AlokNode(int I){
    Infotype P;
    Index(P) = I;
    addrNode Pn = (addrNode) malloc(1 * sizeof (ElmtNode));
    if (Pn != Null){
        Info(Pn) = P;
        Hub(Pn) = Null;
        Next(Pn) = Null;
        return Pn;
    } {
        return Null;
    }
}

addrCon AlokCon(addrNode Pn)
{
    addrCon Pt = (addrCon) malloc(1 * sizeof (ConnectNode));
    Connect(Pt) = Pn;
    NextC(Pt) = Null;
}

void DealokNode(addrNode *Pn)
{
    free(*Pn);
}
void DealokCon(addrCon *Pt)
{
    free(*Pt);
}
addrNode SearchNode(Graph G, int I)
{
    /* KAMUS LOKAL */
    addrNode Pnode;

    /*Algoritma*/
    Pnode=First(G);
    while ((Index(Info(Pnode)) != I) && (Pnode != Null)) {
        Pnode=Next(Pnode);
    }
    return Pnode;

    
    
}
addrCon SearchEdge(Graph G, int I1, int I2)
{

    /*KAMUS LOKAL */
    addrNode P;
    addrNode Pn;
    addrCon S;
    boolean found = false;

    /*Algoritma*/
    P = SearchNode(G,I1);
    Pn = SearchNode(G,I2);
    if ((P != Null) && (Pn != Null)){
        S = Hub(P);
        while ((S != Null) && (!found)){
            if (Connect(S) == Pn){
                found = true;
            }else{
                S = NextC(S);
            }
        }
        if (found){
            return S;
        }else{
            return Null;
        }
    }else{
        return Null;
    }

}

void InsertNode(Graph *G, int I)
{
    /* KAMUS LOKAl */
    addrNode Pn;
    addrNode Prec;
    /* Algoritma */
    Pn = AlokNode(I);
    if (Pn != Null){
        if (YesEmpty(*G)){
            First(*G)=Pn;
        }
        else {
            Prec=First(*G);
            while(Next(Prec)!=Null){
                Prec=Next(Prec);
            }
            Next(Prec)=Pn;
        }
    }
}

void InsertEdge(Graph *G, int I1, int I2)
{
    addrCon S1,S2;
    addrCon C1,C2;
    addrNode P1,P2;
    if ((SearchNode(*G,I1) != Null) && ((SearchNode(*G,I2)) != Null)){

    }else{
        InsertNode(G,I1);
        InsertNode(G,I2);
    }
    P1 = SearchNode(*G,I1);
    P2 = SearchNode(*G,I2);
    C2 = AlokCon(P1);
    C1 = AlokCon(P2);
    S1 = Hub(P1);
    while(S1 != Null){
        S1 = NextC(S1);
    }
    NextC(S1) = C1;
    while(S2 != Null){
        S2 = NextC(S2);
    }
    NextC(S2) = C2;
}

/* ADT TAMBAHAN UNTUK KEPERLUAN GAME */
/*baca map.txt, trus liat disitu, kalo dia 1 berarti dia nanti dihubungin sama jalan
ini belum di test, masih kasarnya aja */

/*void ConvertMapToGraph (Matriks M, Graph *G){ 
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
} */


/*---------Fungsi Tambahan--------- */
/*Untuk menghubungkan antara Graph dengan Konfigurasi */
/* Index 1 = Base */
/* Index 2 = Shop */
/* Index lainnya = Index - 2 (Customer) */
void MappingGraph(Graph *G){
    addrNode Pn;
    Pn = First(*G);
    int i = 1;
    while (Pn != Null){
        if(Index(Info(Pn)) == 1){
            Bangunan(Info(Pn)) = 'B';
        }
        else if (Index(Info(Pn)) == 2){
            Bangunan(Info(Pn)) = 'S';
        }
        else{
            Bangunan(Info(Pn)) = IntToChar(Index(Info(Pn)) - 2);
        }
        Pn = Next(Pn);
    }
}

