#include <stdio.h>
#include "Matrix.h"
#include "RNG.c"
#include "RNG.h"
#include <math.h>

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

Matrix Matrix_Create_Random(size_t m, size_t n) {

  Matrix A;
  A=Matrix_Create(m,n);
  RNG R=RNG_Set_Knuth();
  unsigned int s=42;
  for (size_t i = 0; i < m; i++) {
    for (size_t j = 0; j < n; j++) {
      s=RNG_Evaluate(R,s);
      A.M[i][j]=s*1.0/20000;
  }}

  return A;

}
void Matrix_Rotate_Complete(Matrix M) {
  for (size_t j = 0; j < M.n -1; j++) {
    for (size_t i = j+1; i < M.m ; i++) {
      Matrix_Rotate(M, i, j);
    }
  }
}
void Matrix_Rotate(Matrix A, size_t i, size_t j) {
  double x=A.M[j][j]; // j 0
  double y=A.M[i][j];
  double alpha=copysign(sqrt(x*x+y*y),x);
  double c = x/alpha;
  double s = -y/alpha;
  for (size_t t = 0; t < A.n; t++) {
    double x=A.M[j][t]; //j 0
    double y=A.M[i][t];
    A.M[j][t]=c*x-s*y; //j 0s
    A.M[i][t]=s*x+c*y;
  }
  //A.M[i][j]=s/c;
}

double det(Matrix M) {
  Matrix_Rotate_Complete(M);
  double p=1.0;
  for (size_t i = 0; i < M.n && i < M.m; i++) {
    p=p*M.M[i][i];
  }

  return p;
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
      fprintf(f, "%2.3lf    ", A.M[i][j] );
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
