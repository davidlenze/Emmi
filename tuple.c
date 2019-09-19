#include <stdlib.h>
#include <stdio.h>
#include "tuple.h"
#include "RNG.h"



unsigned int * Tuple_Create(unsigned int n){
  unsigned int * v;
  v = malloc(sizeof(unsigned int)*n);
  return v;
}

unsigned int * Tuple_Create_Random(unsigned int n, unsigned int s){

  unsigned int * v = Tuple_Create(n);

  RNG Donald = RNG_Set_Knuth();

  for (unsigned int i = 0; i < n; i++) {

    s = RNG_Evaluate(Donald, s);
    v[i]=s;

  }
  return v;
}

void Tuple_Destroy(unsigned int* v){
  free(v);
  return;
}

void Tuple_Report(FILE * f, unsigned int * v, unsigned int n){

  for (unsigned int i = 0; i < n; i++) {
    fprintf(f, "%u\n",v[i] );
  }
  fprintf(f, "\n\n");
  return;
}
void Tuple_Sort(FILE * f, unsigned int * v, unsigned int n){


  for (unsigned int i =  n-1, tmp; i > 0; i--){
    for (unsigned int j = 0; j<i; j++){
      if (v[j]>v[j+1]){
        tmp=v[j];
        v[j]=v[j+1];
        v[j+1]=tmp;
        Tuple_Report(f,v,n);
      }
    }
  }
  return;
}
