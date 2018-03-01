#include <stdio.h>
#include <math.h>

double pot(double, unsigned int);
double b(double, unsigned int);
double b_prime(double, unsigned int);
double newton(double, unsigned int);

int main (void){
unsigned int n=5;
double x0 = -3.2;
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
  unsigned int i=0;

  while(i<50){
  x = x - b(x, n)/b_prime(x, n);
  printf("i = %u, x = %e\n",i,x);
  i = i+1;
}
  return x;
}
