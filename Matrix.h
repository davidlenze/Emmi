#ifndef matrix_H
#define matrix_H
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "RNG.h"

struct Vector {
  size_t n;
  double * v;
};

struct Matrix{
  size_t m;
  size_t n;
  double ** V;
};

typedef struct Vector Vector;
typedef struct Matrix Matrix;



double * TupleCreate(size_t);
double ** TupleOfTupleCreate(size_t, size_t);

void TupleDestroy(double*);
void TupleOfTupleDestroy(double**, size_t);

Matrix Matrix_Create(size_t, size_t);
Matrix Matrix_Create_Random(size_t, size_t, RNG, double);
void Matrix_Destroy(Matrix);
void Matrix_Report(FILE *,Matrix, char *, char *);

Vector Vector_Create(size_t);
Vector Vector_Create_Random(size_t, RNG, double);
void Vector_Destroy(Vector);
void Vector_Report(FILE *, Vector, char *, char *);







#endif
