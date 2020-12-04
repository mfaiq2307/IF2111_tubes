#ifndef graph_H
#define graph_H

#include "boolean.h"
#include "point.h"

#define Nil NULL

typedef POINT infotype;
typedef struct tElmtNode *addrNode;
typedef struct tElmtConNode *addrCon;
typedef struct tElmtNode {
    infotype Info;
    /*int NPred;*/
    addrCon Hub;
    addrNode Next;
} ElmtNode;

typedef struct tElmtConNode{
    addrNode Connect;
    addrCon NextCon;
} ConnectNode;

typedef struct { 
    addrNode First;
} Graph;

#define Info(G) (G)->Info
#define Hub(G) (G)->Hub
#define Next(G) (G)->Next
#define Connect(G) (G)->Connect
#define NextC(G) (G)->NextCon

/*Selektor Point.Bangunan */
#define Lokasi(P) ((P).Lokasi)
#define Simbol(P) ((P).Simbol)
#define First(L) ((L).First)

void CreateGraph(POINT P, Graph *G);

addrNode AlokNode(POINT P);

addrCon AlokCon(addrNode Pn);

void DealokNode(addrNode *Pn);

void DealokCon(addrCon *Pt);

addrNode SearchNode(Graph G, int x, int y);

addrCon SearchEdge(Graph G, int x1, int y1, int x2, int y2);

void InsertNode(Graph G, int x, int y);

void InsertEdge(Graph G, int x1, int y1, int x2, int y2);

#endif