#ifndef graph_H
#define graph_H

#include "boolean.h"
#include "point.h"
#include "mesin_kar.h"

#define Null NULL
#define MaxIdx 9

typedef struct {
    char Symbol;
    int Index;
} Infotype;

typedef struct tElmtNode *addrNode;
typedef struct tElmtConNode *addrCon;
typedef struct tElmtNode {
    Infotype Info;
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
#define Bangunan(P) ((P).Symbol)
#define Index(P) ((P).Index)
#define First(L) ((L).First)

void CreateGraph(Graph *G);

addrNode AlokNode(int I);

addrCon AlokCon(addrNode Pn);

void DealokNode(addrNode *Pn);

void DealokCon(addrCon *Pt);

addrNode SearchNode(Graph G, int I);

addrCon SearchEdge(Graph G, int I1, int I2);

void InsertNode(Graph *G, int I);

void InsertEdge(Graph *G, int I1, int I2);

void MappingGraph(Graph *G);

#endif