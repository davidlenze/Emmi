/* 
 * ******************************************************** 
 *  EMMI/NUMERIK - Unterrichtsmaterial (c) 2018
 *  Jens Burmeister, Scientific Computing, Uni Kiel      
 * ********************************************************
 */

#include <stdbool.h>  /* wegen bool */
#include <stddef.h>   /* wegen size_t, NULL */
#include <stdio.h>    /* wegen printf */
#include <stdlib.h>   /* wegen calloc, exit, */

#include "Tuple.h"

/* ---------------------------------------------------------------------------------------- */

double * Tuple_Create (size_t n){
  
  double * p = NULL;
  p = calloc (n, sizeof(double));
  return p;
}

void Tuple_Destroy (double * p){
  
  if (p != NULL) {
    free(p);
  } else {
    exit(41);
  }  
}

double * Tuple_Create_Unit (size_t n, size_t i){
  
  double * x;
  x = Tuple_Create (n);
  x[i] = 1.0;
  return x;
}

void Tuple_Report ( FILE * F, size_t n, double * x, char * fmt, char * info ){
    
   fprintf (F, "# Tuple_Report: (n=%zu) [%s]\n", n, info);
   for (size_t i=0; i<n; i=i+1) {
     fprintf (F, fmt, x[i]);
  }    
}

double * Tuple_LoadFromFile (char * Filename, size_t * pn){

  double * x = NULL;
  
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
  
  x = Tuple_Create (n);
  
  {  
    char * p;
    for (size_t i = 0; i<n; i=i+1) {
      do {
        t = fgets (s, 2048, F);
      }
      while ((s[0] == '#') || (s[0] == 10));
      p = s;
      x[i] = strtod (p, NULL);
      
    }
  }
  
  fclose(F);

  *pn = n;
  return x;
}


/* ---------------------------------------------------------------------------------------- */

unsigned int * TupleOfUnsignedInt_Create (size_t n){
  
  unsigned int * p = NULL;
  p = calloc (n, sizeof(unsigned int));
  return p;
}

void TupleOfUnsignedInt_Destroy (unsigned int * p){
  
  if (p != NULL) {
    free(p);
  } else {
    exit(41);
  }  
}

void TupleOfUnsignedInt_Report ( FILE * F, size_t n, unsigned int * x, char * fmt, char * info ){
    
   fprintf (F, "# TupleOfUnsignedInt_Report: (n=%zu) [%s]\n", n, info);
   for (size_t i=0; i<n; i=i+1) {
     fprintf (F, fmt, i, x[i]);
  }    
}

unsigned int * Permutation_Create_Identity (size_t n){
  
  unsigned int * P;
  P = TupleOfUnsignedInt_Create (n);
  for (unsigned int i=0; i<n; i=i+1) {P[i] = i;}
  return P;
}
void Permutation_Destroy (unsigned int * P){
  
  TupleOfUnsignedInt_Destroy(P);
}

void Permutation_Swap (unsigned int * P, size_t i, size_t j){
  
  unsigned int tmp;
  tmp = P[i]; P[i] = P[j]; P[j] = tmp;
}


/* ---------------------------------------------------------------------------------------- */

double ** TupleOfTuple_Create (size_t m, size_t n){
  
  double ** A;
  double * x;
  
  A = calloc (m, sizeof(double *));
  x = Tuple_Create (m*n);
  A[0] = x;
  for (size_t i=1; i<m; i=i+1){
    A[i] = A[i-1] + n;
  }
  
  return A;
}  

void TupleOfTuple_Destroy (double ** A){
    
  Tuple_Destroy (A[0]);
  free (A);
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
  
  A = TupleOfTuple_Create (m,n);
  
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


void TupleOfTuple_Report ( FILE * F, size_t m, size_t n, double ** A, char * fmt, char * info){
  
  fprintf (F, "# TupleOfTuple_Report: (m=%zu)(n=%zu) [%s]\n", m, n, info);
  for (size_t i=0; i<m; i=i+1) {
    for (size_t j=0; j<n; j=j+1) {
      fprintf (F, fmt, A[i][j]);
    } 
    fprintf (F, "\n");   
  }
}       
