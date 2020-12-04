#include "stdio.h"
#include "stdlib.h"
#include "graph.h"


void CreateGraph(POINT P, Graph *G){
    addrNode Pn;
    Pn = AlokNode(P);
    First(*G) = Pn; 
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
    POINT P;
    addrNode Pnode;

    /*Initialisasi POINT */    
    Absis(P) = x;
    Ordinat(P) = y;

    /*Algoritma*/
    Pnode=First(G);
    while ((!EqPOINT(Info(Pnode),P)) && (Pnode!=Nil)) {
        Pnode=Next(Pnode);
    }
    return Pnode;

    
    
}
addrCon SearchEdge(Graph G, int x1, int y1, int x2, int y2)
{
    POINT P1,P2;
    Absis(P1) = x1;
    Ordinat(P1) = y1;

    Absis(P2) = x2;
    Ordinat(P2) = y2;

    /*KAMUS LOKAL */
    addrNode P;
    addrCon S;
    boolean found;

    /*Algoritma*/
    P=First(G);
    if (!IsEmpty(G)){
        found=false;
        if (EqPOINT(Info(P),P1)) {
            S=Hub(P);
            if (EqPOINT(Info(Connect(S)),P2)) {
                while((S!=Nil)&&(!found)){
                    S=NextC(S);
                    if (EqPOINT(Info(Connect(S)),P2)){
                        found=true;
                    }
                }
            }
            else {
                found=true;
            }
        }
    }

}

void InsertNode(Graph G, int x, int y)
{
    /* KAMUS LOKAl */
    BANGUNAN.P
    addrNode Pn;
    addrNode Prec;
    /* Algoritma */
    Pn= AlokNode(P);
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

void InsertEdge(Graph G, int x1, int y1, int x2, int y2)
{

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
