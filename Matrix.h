#ifndef matrix_H
#define matrix_H
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

struct Vektor {
  size_t n;
  double * v;
};

struct Matrix{
  size_t m;
  size_t n;
  double * M;
};

typedef struct Vektor Vektor;
typedef struct Matrix Matrix;

double * TupleCreate(size_t);
double ** TupleOfTupleCreate(size_t, size_t);
void TupleDestroy(double*);
void TupleOfTupleDestroy(double**);

Matrix Matrix_Create(size_t, size_t)
void Matrix_Destroy(Matrix);
void Matrix_Report(Matrix);

Vektor Vektor_Create(size_t);
void Vektor_Destroy(Vektor);
void Vektor_Report(FILE *, Vektor);





#endif
