#include "stdio.h"
#include "stdlib.h"
#include "graph.h"


void CreateGraph(Graph *G){
    First(*G) = Nil; 
}

addrNode AlokNode(int x, int y,char Sym){
    BANGUNAN B;
    Absis(Lokasi(B)) = x;
    Ordinat(Lokasi(B)) = y;
    Simbol(B) = Sym;
    addrNode Pn = (addrNode) malloc(1 * sizeof (ElmtNode));
    if (Pn != Nil){
        Info(Pn) = B;
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
    Connect(Pt) = Pn;
    NextC(Pt) = Nil;
}

void DealokNode(addrNode *Pn)
{
    free(*Pn);
}
void DealokCon(addrCon *Pt)
{
    free(*Pt);
}
addrNode SearchNode(Graph G, int x, int y)
{
    /* KAMUS LOKAL */
    BANGUNAN P;
    addrNode Pnode;

    /*Initialisasi BANGUNAN */    
    Absis(Lokasi(P)) = x;
    Ordinat(Lokasi(P)) = y;

    /*Algoritma*/
    Pnode=First(G);
    while ((!EqPOINT(Lokasi(Info(Pnode)),Lokasi(P))) && (Pnode!=Nil)) {
        Pnode=Next(Pnode);
    }
    return Pnode;

    
    
}
addrCon SearchEdge(Graph G, int x1, int y1, int x2, int y2)
{
    BANGUNAN P1,P2;
    Absis(Lokasi(P1)) = x1;
    Ordinat(Lokasi(P1)) = y1;

    Absis(Lokasi(P2)) = x2;
    Ordinat(Lokasi(P2)) = y2;

    /*KAMUS LOKAL */
    addrNode P;
    addrNode Pn;
    addrCon S;
    boolean found = false;

    /*Algoritma*/
    P = SearchNode(G,x1,y1);
    Pn = SearchNode(G,x2,y2);
    if ((P != Nil) && (Pn != Nil)){
        S = Hub(P);
        while ((S != Nil) && (!found)){
            if (Connect(S) == Pn){
                found = true;
            }else{
                S = NextC(S);
            }
        }
        if (found){
            return S;
        }else{
            return Nil;
        }
    }else{
        return Nil;
    }

}

void InsertNode(Graph G, int x, int y,char sym)
{
    /* KAMUS LOKAl */
    BANGUNAN P;
    addrNode Pn;
    addrNode Prec;
    /* Algoritma */
    Pn= AlokNode(x,y,sym);
    if (Pn != Nil){
        if (IsEmpty(G)){
            First(G)=Pn;
        }
        else {
            Prec=First(G);
            while(Next(Prec)!=Nil){
                Prec=Next(Prec);
            }
            Next(Prec)=Pn;
        }
    }
}

void InsertEdge(Graph G, int x1, int y1, char sym1, int x2, int y2,char sym2)
{
    addrCon S1,S2;
    addrCon C1,C2;
    addrNode P1,P2;
    if ((SearchNode(G,x1,y1) != Nil) && ((SearchNode(G,x2,y2)) != Nil)){
        P1 = SearchNode(G,x1,y1);
        P2 = SearchNode(G,x2,y2);
    }else{
        P1 = InsertNode(G,x1,y1,sym1);
        P2 = InsertNode(G,x2,y2,sym2);
    }
    C2 = AlokCon(P1);
    C1 = AlokCon(P2);
    S1 = Hub(P1);
    while(S1 != Nil){
        S1 = NextC(S1);
    }
    Next(S1) = C1;
    while(S2 != Nil){
        S2 = NextC(S2);
    }
    Next(S2) = C2;
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
