#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "RNG.h"

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

double ** VandermondeTuple_Create(double* v, size_t n){
  double ** V = TupleOfTupleCreate(n,n);

  for (size_t i = 0; i < n; i++) {
    V[i][0] = 1.0;
    for (size_t j = 1; j < n; j++) {
      V[i][j]=V[i][j-1]*v[i];
    }
  }
  return V;
}

void TupleOfTupleRotate(int m, int n, double ** V){
  double x, y, alpha,c,s;
  for (int j = 0; j < n -1; j++) {
    for (int i = j+1; i < m ; i++) {

      x=V[j][j]; // j 0
      y=V[i][j];
      alpha=copysign(sqrt(x*x+y*y),x);
      c = x/alpha;
      s = -y/alpha;
      for (int t = j; t < n; t++) {
        x=V[j][t]; //j 0
        y=V[i][t];
        V[j][t]=c*x-s*y; //j 0s
        V[i][t]=s*x+c*y;
      }
      V[i][j]=s/c;
    }
  }
}

void TupleOfTupleRerotate(int m, int n, double ** V){
    double x,y,c,s,t;

    for (int j = n-2; j >= 0; j--){
      for (int i = m-1; i > j; i--) {
        t = V[i][j];
        V[i][j]=0.0;
        c = sqrt(1.0/(t*t+1.0));
        if (c == 0){
          s = copysign(1.0, t);
        }
        else{
          s = t*c;
        }
        for (int t = j; t < n; t++) {
          x = V[j][t];
          y = V[i][t];
          V[j][t]=c*x+s*y;
          V[i][t]=c*y-s*x;
        }
      }
    }
}

void TupleOfTupleEliminate(int m, int n, double ** V){
  double lambda;
  for (int j = 0; j < n -1; j++) {
    for (int i = j+1; i < m ; i++) {

      lambda = V[i][j]/V[j][j];

      for (int t = j; t < n; t++) {

        V[i][t]=V[i][t]-lambda*V[j][t];
      }
      V[i][j]=lambda;
    }
  }
}

void TupleOfTupleReEliminate(int m, int n, double ** V){
  double lambda;
  for (int j = n-1; j >=0 ; j--) {
    for (int i = m-1; i > j ; i--) {

      lambda = V[i][j];
      V[i][j]=0;

      for (int t = j; t < n; t++) {

        V[i][t]=V[i][t]+lambda*V[j][t];
      }

    }
  }
}

void TupleRotateFromMatrix(double* v, double ** V, size_t m, size_t n){
  double x,y,c,s,t;


  for (size_t j = 0; j < n-1; j++) {

    for (size_t i = j+1; i < m; i++) {

      t = V[i][j];
      c = sqrt(1.0/(t*t+1.0));
      s = t*c;
      x = v[j];
      y = v[i];
      v[j]=c*x-y*s;
      v[i]=s*x+c*y;
    }
  }
}

void TupleEliminateFromMatrix(double* v, double ** V, size_t m, size_t n){
  for (size_t j = 0; j < n-1; j++) {

    for (size_t i = j+1; i < m; i++) {

      v[i] = v[i] - V[i][j]* v[j];

    }
  }
}

bool TupleSolveBackwardsRow(double * v, double ** V, size_t n){
  double h;
  bool inv;
  inv = true;
  for (int i = n-1; i >=0 ; i--) {
    h = 0;
    for (int j = n-1; j>i; j--){
      h = h + V[i][j] * v[j];
    }
    if (fabs(V[i][i])!=0){
      v[i] = (v[i]-h)/V[i][i];
    }else{
      v[i]=1.0;
      inv = false;
    }

  }
  return inv;
}

bool TupleSolveBackwardsColumn(double * v, double ** V, size_t n){
  bool inv;
  inv = true;
  for (int j = (int)n-1; j >= 0; j--){
    if (fabs(V[j][j])==0){
      v[j]= 1.0;
      inv = false;
    }
      v[j]= v[j]/V[j][j];
    for (int i = j -1; i >=0; i-- ){
      v[i] = v[i] - v[j] * V[i][j];
    }
  }
  return inv;
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

double * Tuple_LoadFromFile(char * Filename, size_t * pn){
  double * v = NULL;

  char s[2048];
  FILE * F = NULL;
  size_t n=0;

  char * t;

  F = fopen (Filename, "r");

  do {
    t = fgets (s, 2048, F);
  }
  while ((s[0] == '#') || (s[0] == 10));

  if (t==NULL) return NULL;

	sscanf(s, "%zu", &n);

  v = TupleCreate (n);

  {
    char * q;
    for (size_t i = 0; i<n; i=i+1) {
      do {
        t = fgets (s, 2048, F);
      }
      while ((s[0] == '#') || (s[0] == 10));


      v[i] = strtod (s, &q);


      }
    }


  fclose(F);

  *pn = n;
  return v;
}
