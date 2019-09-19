#ifndef tuple_H
#define tuple_H
#include <stdlib.h>
#include <stdio.h>
#include "RNG.h"

unsigned int * Tuple_Create(unsigned int);
void Tuple_Destroy(unsigned int*);
unsigned int * Tuple_Create_Random(unsigned int, unsigned int);
void Tuple_Report(FILE *, unsigned int *, unsigned int);
void Tuple_Sort(FILE *, unsigned int *, unsigned int);


#endif
