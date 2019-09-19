#include <stdlib.h>
#include <stdio.h>
#include "tuple.h"
#include "RNG.h"

/*Compare Functions:

  CompareLess
  CompareEvenOdd


*/

int main (void){

  FILE * f;
  f = fopen("gif.dtn", "w");
  unsigned int * v = Tuple_Create_Random(100,145);
  Tuple_Report(f,v,100);
  Tuple_Sort(f,v,100,CompareEvenOdd);
  Tuple_Report(f,v,100);
  return 42;
}
