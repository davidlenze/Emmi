#include <stdlib.h>
#include <stdio.h>

double a=12.0;
double b=2.0;

void swap(double*, double*);

int main(void) {
  swap(&a,&b);
  printf("%lf   %lf\n",a,b );
  return 42;
}

void swap(double* p, double* q) {
  double tmp= *p;
  *p=*q;
  *q=tmp;
  return;
}
