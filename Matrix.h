#ifndef matrix_H
#define matrix_H
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

struct Vector {
  size_t n;
  double * v;
};

struct Matrix{
  size_t m;
  size_t n;
  double ** M;
};

typedef struct Vector Vector;
typedef struct Matrix Matrix;

double * TupleCreate(size_t);
double ** TupleOfTupleCreate(size_t, size_t);

void TupleDestroy(double*);
void TupleOfTupleDestroy(double**, size_t);

Matrix Matrix_Create(size_t, size_t);
void Matrix_Destroy(Matrix);
void Matrix_Report(FILE *,Matrix);

Vector Vector_Create(size_t);
void Vector_Destroy(Vector);
void Vector_Report(FILE *, Vector);





#endif
