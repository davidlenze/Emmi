#include<stdlib.h>
#include<stdio.h>
double sumexp(double , int );
double hornerexp(double, int );

int main(void) {
  int n=1;
  while(sumexp(1.0,n)!=sumexp(1.0,n+1)) {
    n=n+1;
  }

  printf("BOOM %u\n",n );
  return 0;
}

double sumexp(double x, int n) {
  double s=1;
  double S=0;
  for (int i = 1; i < n+1; i++) {
    S=S+s;
    s=s*(x/i);
  }
  return S;
}

double hornerexp(double x, int n) {
  double P=1;
  while (n!=0) {
    P=1+(x/n)*P;
    n=n-1;
  }
  return P;
}
