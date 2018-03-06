#include<stdlib.h>
#include<stdio.h>
#include <math.h>

long double arctan(long double);
long double sum1(long double);

int main(void) {
  long double A= arctan(1.0/3) + arctan(0.5);
  printf("%30.29Lf\n", 4*A);

  return 0;
}

long double arctan(long double x) {
  long double a=x/(1+sqrt(1+x*x));
  if(x<0) {return arctan(-x);}
  else if(x>1) {return 2*arctan(a);}
  else {return sum1(x);}

  }


long double sum1(long double x) {
  int n=100000;
  long double S=0;
  long double s=x/(1+x*x)*2*2*2;
  long double a,b;

  for (int i = 0; i <= n+1; i++) {
    S=S+s;
    a=(2*i+2)*(2*i+3);
    b=4*(i+1)*(i+1);
    a=b/a;

    s=s*a*(x*x/(1+x*x));
  }

  return S/8;
}
