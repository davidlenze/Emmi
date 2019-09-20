#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "RNG.h"
#include "RNG.c"

double v[10];
void random_vector(double[10]);
void report_vector(double[10]);
void rotatate_vector(double[10], unsigned int);
void backward_vector(double[] , unsigned int);

int main(void) {
  random_vector(v);
  report_vector(v);

  for (unsigned int i = 9; i>0 ; i=i-1) {
    rotatate_vector(v,i);
    printf("\n");
  }

  for (unsigned int i = 1; i<10 ; i=i+1) {
    backward_vector(v,i);
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

void rotatate_vector(double a[], unsigned int A) {
  double c = a[A-1]/sqrt(a[A-1]*a[A-1]+a[A]*a[A]);
  double s = -a[A]/sqrt(a[A-1]*a[A-1]+a[A]*a[A]);
  double tmp=a[A];
  a[A]=s;
  a[A-1]=sqrt(a[A-1]*a[A-1]+tmp*tmp);
  printf("%lf ",c );
  printf("%lf\n",s );
  report_vector(a);
}

void backward_vector(double a[], unsigned int A) {
  a[A]=-a[A]*a[A-1];
  a[A-1]=sqrt(a[A-1]*a[A-1]-a[A]*a[A]);

  report_vector(a);
}
