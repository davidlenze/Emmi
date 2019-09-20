#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "RNG.h"
#include "RNG.c"

double v[10];
void random_vector(double[10]);
void report_vector(double[10]);
void rotatate(double[10], unsigned int);
void rotate_back(double[10] , unsigned int);

int main(void) {
  random_vector(v);
  report_vector(v);

  for (unsigned int i = 9; i>0 ; i=i-1) {
    rotatate(v,i);
    printf("\n");
  }

  for (unsigned int i = 1; i<10 ; i=i+1) {
    rotate_back(v,i);
    printf("\n");
  }

}

void random_vector(double a[]) {
  unsigned int x=42;
  RNG R=RNG_Set_Knuth();
  for (size_t i = 0; i < 10; i++) {
    a[i]=RNG_Evaluate(R,x);
    x=RNG_Evaluate(R,x);
  }
}

void report_vector(double a[]) {
  for (size_t i = 0; i <10; i++) {
    printf("%lf\n",a[i]);
  }
  printf("\n");
}

void rotatate(double a[], unsigned int A) {
  double x=a[A-1];
  double y=a[A];
  double alpha=copysign(sqrt(x*x+y*y),x);
  double c = x/alpha;
  double s = -y/alpha;
  a[A]=s/c;
  a[A-1]=c*x-s*y;
  report_vector(a);
}

void rotate_back(double a[], unsigned int A) {
  double t=a[A];
  double alpha=a[A-1];
  double c=sqrt(1/(1+t*t));
  double s=t*c;
  a[A-1]=c*alpha;
  a[A]=-s*alpha;
  report_vector(a);
}
