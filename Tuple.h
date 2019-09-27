#ifndef tuple_H
#define tuple_H
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "RNG.h"
double * TupleCreate(size_t);
double ** TupleOfTupleCreate(size_t, size_t);
double ** VandermondeTuple_Create(double*, size_t);

double ** TupleOfTuple_LoadFromFile (char *, size_t *, size_t *);

void TupleOfTupleRotate(int, int, double ** );
void TupleOfTupleRerotate(int, int, double **);
void TupleOfTupleEliminate(int, int, double **);
void TupleOfTupleReEliminate(int, int, double **);
void TupleRotateFromMatrix(double*, double **, size_t, size_t);
void TupleEliminateFromMatrix(double*, double**, size_t, size_t);
bool TupleSolveBackwardsRow(double *, double **, size_t);
bool TupleSolveBackwardsColumn(double *, double **, size_t);


void TupleDestroy(double*);
void TupleOfTupleDestroy(double**, size_t);
double * Tuple_LoadFromFile(char *, size_t *);

#endif
