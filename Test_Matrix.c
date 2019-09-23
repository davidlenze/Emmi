#include <stdio.h>
#include "Matrix.h"

int main (void) {
  FILE * F = stdout;
  Matrix A = Matrix_Create(3,4);
  Matrix_Report(F,A);
  return 0;

}
