#include <stdio.h>
#include "Matrix.h"

Vector Vector_Create(size_t n){
  Vector v;
  v.n = n;
  v.v = TupleCreate(n);
  return v;
}
Matrix Matrix_Create(size_t m, size_t n){
  Matrix A;
  A.m = m;
  A.n = n;
  A.M = TupleOfTupleCreate(m,n);

  return A;
}

double * TupleCreate(size_t n){
  double * v;
  v = calloc(n,sizeof(double));
  return v;
}

double ** TupleOfTupleCreate(size_t m, size_t n){
  double ** V;
  V = calloc(m, sizeof(double *));
  for (size_t i = 0; i<m; i++){
    V[i] = calloc(n,sizeof(double));
  }
  return V;
}

void TupleDestroy(double * v){
  free(v);
  return;
}

void TupleOfTupleDestroy(double ** M, size_t m){
  for (size_t i = 0; i < m; i++) {
    free(M[i]);
  }
  free(M);
}

void Vector_Destroy( Vector v){
  TupleDestroy(v.v);
}

void Matrix_Destroy (Matrix A){
  TupleOfTupleDestroy(A.M, A.m);
}

void Matrix_Report(FILE * f, Matrix A){
  size_t n = A.n;
  size_t m = A.m;

  for (size_t i = 0; i <m; i++){
    for (size_t j = 0; j < n; j++) {
      fprintf(f, "%lf ", A.M[i][j] );
    }
    fprintf(f, "\n");
  }
  return;
}

void Vector_Report(FILE * f, Vector v){
  size_t n = v.n;

  for (size_t i = 0; i < n; i++) {
    fprintf(f, "%lf\n",v.v[i]);
  }
  return;
}
