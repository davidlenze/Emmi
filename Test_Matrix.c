#include <stdio.h>
#include "Matrix.h"
#include "RNG.h"

int main (void) {

  RNG Joe = RNG_Set_Knuth();
  FILE * F = stdout;
  Matrix A = Matrix_Create_Random(3,4, Joe, 3.14);
  Matrix_Report(F,A, "%lf", "MATRIX");
  Matrix_Destroy(A);

  return 0;

}
