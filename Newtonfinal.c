#include <stdio.h>
#include <math.h>

double f(double);
double Df(double);
double newton(double, unsigned int);

int main (void) {

unsigned int n=5;
double x0 = 1.5;
double root;

root = newton(x0,n);
printf("%e \n", root);
return 0;
}

double f(double x) {

  double result = pow(x,sqrt(1+x))-pow(sqrt(1+x),x);
  return result;

}

double Df(double x ) {
  double result1 = ((sqrt(1+x)/x)+(log(x)/(2*sqrt(1+x))))*pow(x,sqrt(1+x))-((x/(2*(1+x)))+log(1+x)/2)*pow(sqrt(1+x),x);
  return result1;
}

double newton(double x0, unsigned int n) {

  double x = x0;
  for (size_t i = 0; i < n; i++) {
    x=x-(f(x))/(Df(x));
  }

  return x;
}

