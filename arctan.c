#include<stdlib.h>
#include<stdio.h>
#include <math.h>

double arctan(double);
double sum1(double);
double sum2(double);

int main(void) {
  double A= arctan(1);
  printf("%25.24f\n", A );

  return 0;
}

double arctan(double x) {
  double a=x/(1+sqrt(1+x*x));
  if(x<0) {return arctan(-x);}
  else if(x>1) {return 2*arctan(a);}
  else {return sum1(x);}

  }


double sum1(double x) {
  int n=10000;
  double S=0;
  double s=x/(1+x*x)*2*2*2;
  double a,b;

  for (int i = 0; i <= n+1; i++) {
    S=S+s;
    a=(2*i+2)*(2*i+3);
    b=4*(i+1)*(i+1);
    a=b/a;

    s=s*a*(x*x/(1+x*x));
  }

  return S/8;
}
