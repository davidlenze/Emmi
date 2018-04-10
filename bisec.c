#include <stdio.h>
#include <math.h>

double f(double);
double sect(double, double, unsigned int);

int main (void) {

unsigned int N=50;
double p = 1;
double n=2;
double root;

root = sect(n,p, N);
printf("%e \n", root);
return 0;
}

double f(double x) {

  double result = pow(x,sqrt(1+x))-pow(sqrt(1+x),x);
  return result;

}

/*double Df(double x ) {
  double result1 = ((sqrt(1+x)/x)+(log(x)/(2*sqrt(1+x))))*pow(x,sqrt(1+x))-((x/(2*(1+x)))+log(1+x)/2)*pow(sqrt(1+x),x);
  return result1;
}*/

double sect(double n , double p, unsigned N) {

  for (size_t i = 0; i < N; i++) {
    double a=(p+n)/2;
    //printf("%e \n", a);
    if(f(a)>0) {
      n=a;
    }
    else {
      p=a;
    }
  }

  return (p+n)/2;

}
