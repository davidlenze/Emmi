#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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

Matrix Matrix_CreateFromFile(char * Filename){
  size_t n,m;

  double ** V = TupleOfTuple_LoadFromFile(Filename, &m, &n);

  Matrix A = Matrix_Create(m, n);
  A.V= V;

  return A;
}

void Matrix_Rotate(Matrix A){
  double x, y, alpha,c,s;
  for (size_t j = 0; j < A.n -1; j++) {
    for (size_t i = j+1; i < A.m ; i++) {

      x=A.V[j][j]; // j 0
      y=A.V[i][j];
      alpha=copysign(sqrt(x*x+y*y),x);
      c = x/alpha;
      s = -y/alpha;
      for (size_t t = j; t < A.n; t++) {
        x=A.V[j][t]; //j 0
        y=A.V[i][t];
        A.V[j][t]=c*x-s*y; //j 0s
        A.V[i][t]=s*x+c*y;
      }
      A.V[i][j]=s/c;
    }
  }
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

double ** TupleOfTuple_LoadFromFile (char * Filename, size_t * pm, size_t * pn){

  double ** A = NULL;

  char s[2048];
  FILE * F = NULL;
  size_t m=0, n=0;

  char * t;

  F = fopen (Filename, "r");

  do {
    t = fgets (s, 2048, F);
  }
  while ((s[0] == '#') || (s[0] == 10));

  if (t==NULL) return NULL;

	sscanf(s, "%zu %zu", &m, &n);

  A = TupleOfTupleCreate (m,n);

  {
    char * p;
    char * q;
    for (size_t i = 0; i<m; i=i+1) {
      do {
        t = fgets (s, 2048, F);
      }
      while ((s[0] == '#') || (s[0] == 10));
      p = s; q = NULL;
      for (size_t j = 0; j<n; j=j+1) {

        A[i][j] = strtod (p, &q);
        p = q;
      }
    }
  }

  fclose(F);

  *pm = m; *pn = n;
  return A;
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
