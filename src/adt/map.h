#ifndef map_H
#define map_H


#include "boolean.h"
#include "point.h"
#include "mesinkata.h"
#include "mesin_kar.h"
#include "matriks.h"
#include <stdio.h>
#include <stdlib.h>

void MAP(MATRIKS Map, int X, int Y);

void LoadingMap(char *FileMap,MATRIKS *Map,ListOfBangunan *LBangunan, POINT *PLoc);

#endif