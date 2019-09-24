#include <stdio.h>
#include "Matrix.h"
#include "RNG.h"

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
  A.V = TupleOfTupleCreate(m,n);

  return A;
}

Vector Vector_Create_Random(size_t n, RNG Joe, double s){
  Vector v = Vector_Create(n);
  s = RNG_Evaluate(Joe, s);
  for (size_t i = 1; i < n; i++) {
    v.v[i]=s;
    s = RNG_Evaluate(Joe,s);
  }
  return v;
}

Matrix Matrix_Create_Random(size_t m, size_t n, RNG Joe, double s){
  Matrix A = Matrix_Create(m,n);

  s = RNG_Evaluate(Joe, s);
  for (size_t i = 0; i < m;  i++) {
    for (size_t j = 0; j < n; j++) {
      A.V[i][j]= s;
      s = RNG_Evaluate(Joe, s);
    }
  }

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

void TupleOfTupleDestroy(double ** V, size_t m){
  for (size_t i = 0; i < m; i++) {
    free(V[i]);
  }
  free(V);
}

void Vector_Destroy( Vector v){
  TupleDestroy(v.v);
}

void Matrix_Destroy (Matrix A){
  TupleOfTupleDestroy(A.V, A.m);
}

void Matrix_Report(FILE * f, Matrix A, char * fmt, char * info){
  size_t n = A.n;
  size_t m = A.m;

  fprintf(f, "%s \n", info);
  for (size_t i = 0; i <m; i++){
    for (size_t j = 0; j < n; j++) {
      fprintf(f, fmt, A.V[i][j] );
      fprintf(f, "  ");
    }
    fprintf(f, "\n");
  }
  return;
}

void Vector_Report(FILE * f, Vector v, char * fmt, char * info){
  size_t n = v.n;

  fprintf(f, "%s\n", info);

  for (size_t i = 0; i < n; i++) {
    fprintf(f, fmt,v.v[i]);
    fprintf(f, "\n" );
  }
  return;
}
