#include <stdlib.h>
#include <stdio.h>
#include "tuple.h"
#include "RNG.h"

int main (void){
  FILE * f;
  f = fopen("gif.dtn", "w");
  unsigned int * v = Tuple_Create_Random(100,100);
  Tuple_Report(f,v,100);
  Tuple_Sort(f,v,100);
  Tuple_Report(f,v,100);
  return 42;
}
