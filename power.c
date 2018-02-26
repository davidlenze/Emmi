#include <stdio.h>
#include <time.h>

//clock_t start,end;
//double cpu_time_used;

double egyptian_recursive(double a, int b);
double egyptian_iterative(double a, int b);
double classic_iterative(double a, int b);
double classic_recursive(double a, int b);
double power(double x, int n, int mode);


int main(void) {

  //double v1;
  int mode=2;
  double x=12.5;
  int n=3;

  printf("the power is\n %12.6f \n \n", power(x,n,mode) );


  return 0;
}


double power(double x, int n, int mode) {

  switch(mode) {
    case 1: return classic_recursive(x,n); break;
    case 2: return classic_iterative(x,n); break;
	  case 3: return egyptian_recursive(x,n); break;
    case 4: return egyptian_iterative(x,n); break;
	  default: return 0.0; break;
 }

}

double classic_recursive(double x, int n) {
  if(n==0) {return 1.0;}
  else if(n==1) {return x;}
  else {return x = x*classic_recursive(x,n-1); }
}

double classic_iterative(double x, int n) {
  double p=1.0;
  for (int i = 1; i <= n; i++) {
    p=x*p;
  }
 return p;
}

double egyptian_recursive(double x, int n) {
  if(n==0) {return 1;}
  else if(n==1) {return x;}
  else if(n%2==0) {return  egyptian_recursive(x, n/2)*egyptian_recursive(x, n/2);}
  else {return x*egyptian_recursive(x, (n-1)/2)*egyptian_recursive(x, (n-1)/2);}
}

double egyptian_iterative(double x, int n) {
  double p=1;
  if(n==0) {x=1; n=1;}
  while (n!=1) {
    if(n%2==0) {n=(n/2);}
    else {n=(n-1)/2; p=p*x;}
    x=x*x;
  }
  return x*p;
}
