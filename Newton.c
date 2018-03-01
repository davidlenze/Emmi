#include <stdio.h>
#include <math.h>

double pot(double, unsigned int);
double b(double, unsigned int);
double b_prime(double, unsigned int);
double newton(double, unsigned int);

int main (void){
unsigned int n=2;
double x0 = -2;
double root;

root = newton(x0,n);
printf("%e %e\n", root, b(root, n) );

return 0;
}

double pot(double x, unsigned int n) {
  double factor = 1.0;

  if(n==0) {
    return 1.0;
  }
  while(n !=1){
    if(n%2 != 0){
      factor = factor *x;
    }
    x =x*x;
    n= n/2;
    }
  return factor * x;
}
double b(double x, unsigned int n) {
  double result = pot(1.0 + x, n) - 1.0 -n*x;
  return result;
}
double b_prime(double x, unsigned int n) {
  double result = n * pot(1.0+x, n-1) -n;
  return result;
}
double newton(double xo, unsigned int n){
  double x =xo;

  while(b(x, n) != 0.0){
  x = x - b(x, n)/b_prime(x, n);
}
  return x;
}
