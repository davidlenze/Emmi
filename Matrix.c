#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "Matrix.h"
#include "RNG.h"
#include "Tuple.h"


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

Vector Vector_CreateFromFile(char * Filename){
  size_t n;

  double * v = Tuple_LoadFromFile(Filename, &n);

  Vector w = Vector_Create(n);
  w.v= v;

  return w;
}

Matrix VandermondeMatrix_Create(Vector v){
  size_t n = v.n;
  Matrix A = Matrix_Create(n,n);
  A.V = VandermondeTuple_Create (v.v, n);
  return A;
}

void Matrix_Rotate(Matrix A){
  int m,n;
  m = (int) A.m;
  n = (int) A.n;

  TupleOfTupleRotate(m,n,A.V);
}

void Matrix_Rerotate(Matrix A){

  int n,m;

  n = (int) A.n;
  m = (int) A.m;
  TupleOfTupleRerotate(m,n,A.V);
}

void Matrix_Eliminate(Matrix A){
  TupleOfTupleEliminate((int)A.m,(int)A.n,A.V);
}

void Matrix_ReEliminate(Matrix A){
  TupleOfTupleReEliminate((int)A.m,(int)A.n,A.V);
}

bool Solve_LinearSystemOfEquations(Matrix A, Vector v){
  bool inv;
  Matrix_Rotate(A);
  TupleRotateFromMatrix(v.v, A.V, A.m, A.n);
  inv = TupleSolveBackwardsColumn(v.v, A.V, v.n);
  return inv;
}

double det(Matrix M) {
  double p;
  p = 1.0;
  Matrix_Rotate(M);

  for (size_t i = 0; i < M.n && i < M.m; i++) {
    p=p*M.V[i][i];
  }

  return p;
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

  fprintf(f, "\n%s \n", info);
  for (size_t i = 0; i <m; i++){
    for (size_t j = 0; j < n; j++) {
      if (A.V[i][j]>=0){
        fprintf(f, " ");
      }
      fprintf(f, fmt, A.V[i][j] );
      fprintf(f, "  ");
    }
    fprintf(f, "\n");
  }
  fprintf(f, "\n\n");
  return;
}

void Vector_Report(FILE * f, Vector v, char * fmt, char * info){
  size_t n = v.n;

  fprintf(f, "%s\n", info);

  for (size_t i = 0; i < n; i++) {
    if(v.v[i]>=0){
      fprintf(f, " ");
    }
    fprintf(f, fmt,v.v[i]);
    fprintf(f, "\n" );
  }
  fprintf(f, "\n\n");
  return;
}
