#include <stdio.h>
#include 'Matrix.h'

Vektor Vektor_Create(size_t n){
  Vektor v;
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

void TupleOfTupleDestroy(double ** M){
  for (size_t i = 0; i < count; i++) {
    free(V[i]);
  }
  free(V);
}

void Vektor_Destroy( Vektor v){
  TupleDestroy(v.v);
}

void Matrix_Destroy (Matrix A){
  TupleOfTupleDestroy(A.M);
}

Matrix Matrix_Report(FILE * f, Matrix A){
  size_t n = A.n;
  size_t m = A.m;

  for (size_t i = 0; i <m; i++){
    for (size_t j = 0; j < count; j++) {
      fprintf(f, "%lf ", A[i][j] );
    }
    fprintf(F, "\n");
  }
}

Vektor Vektor_Report(FILE * f, Vektor v){
  size_t n = v.n;

  for (size_t i = 0; i < count; i++) {
    fprintf(f, "%lf\n",v[i]);
  }
}
