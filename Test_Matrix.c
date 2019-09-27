#include <stdio.h>
#include <stdbool.h>
#include "Matrix.h"
#include "RNG.h"

int main (void) {
  bool inv;
  FILE * F = stdout;
  Matrix A = Matrix_CreateFromFile("Matrix1.dtn");

  Vector v = Vector_CreateFromFile("Vector1.dtn");
/*  Matrix A = VandermondeMatrix_Create(v);
  Matrix_Report(F,A, "%lf", "MATRIX START");
  Matrix_Eliminate(A);
  Matrix_Report(F,A, "%lf", "MATRIX ELIMINATED");
  TupleEliminateFromMatrix(v.v, A.V, v.n,v.n);
  Vector_Report(F,v, "%lf", "SOLUTION");
  Matrix_ReEliminate(A);
  Matrix_Report(F,A, "%lf", "MATRIX RESTORED");*/

  Matrix_Report(F,A, "%lf", "MATRIX START");
  Vector_Report(F,v, "%lf", "VECTOR");
  inv = Solve_LinearSystemOfEquations(A,v);
  Matrix_Report(F,A, "%lf", "MATRIX AFTER GIVEN-ROT");
  Vector_Report(F,v, "%lf", "SOLUTION");
  if (!inv){
    fprintf(F, "\nThis Solution is not unique, because A is not invertible\n\n");
  }
  return 0;

}
