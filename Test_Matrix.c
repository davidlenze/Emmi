#include <stdio.h>
#include "Matrix.h"
#include "RNG.h"

int main (void) {

  FILE * F = stdout;
  Matrix A = Matrix_CreateFromFile("Matrix1.dtn");
  Matrix_Report(F,A, "%lf", "MATRIX");
  Matrix_Rotate(A);
  Matrix_Report(F,A, "%lf", "MATRIX");
  Matrix_Destroy(A);

  return 0;

}
