#ifndef graph_H
#define graph_H

#include "boolean.h"


#define Nil NULL

typedef struct {
    int X;
    int Y;
} Point;
typedef Point infotype;
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

Point MakePoint(int X, int Y);

void CreateGraph()