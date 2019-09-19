#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "tuple.h"
#include "RNG.h"

CompareFunctionName CompareLess;
CompareFunctionName CompareEvenOdd;

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
void Tuple_Sort(FILE * f, unsigned int * v, unsigned int n, CompareFunctionName c){


  for (unsigned int i =  n-1, tmp; i > 0; i--){
    for (unsigned int j = 0; j<i; j++){
      if (c(v[j+1],v[j])){
        tmp=v[j];
        v[j]=v[j+1];
        v[j+1]=tmp;
        Tuple_Report(f,v,n);
      }
    }
  }
  for (size_t i = 0; i < 100; i++) {
    Tuple_Report(f,v,n);
  }
  return;
}

bool CompareLess(unsigned int a, unsigned int b){
  return (a<b);
}

bool CompareEvenOdd(unsigned int a, unsigned int b){
  if (a%2==0){
    if(b%2==0){
      return (a<b);
    }
    else {
      return true;
    }
  }else if(b%2==0){
    return false;
  }else {
    return (a>b);
  }

}
