#include<stdlib.h>
#include<stdio.h>

double f (double);
double expo (double, unsigned int);

int main (void){

  double a, b;
  double x, y, y_, h;
  unsigned int n,m;
  a=-3.0;
  b=3.0;
  n=600;
  m=20;

  x=-5.0;

  h = 1.0*(b-a)/(1.0*n);



  for(unsigned int i=0 ; i<=n ; i++){

    x = a+i*h;
    y = expo(x,m);
    y_=f(x);

    printf("%10.8f     %10.8f     %10.8f\n",x,y,y_);

  }

return EXIT_SUCCESS;
}

double expo (double x, unsigned int m){
  if (x<0){
    return 1/(expo (-x,m));
  }
    else if (x>1){
      return expo(x/2,m)*expo(x/2,m);
    }
      else{
          double out = 1;
          double term = 1;

          for (unsigned int j = 1; j<=m; j++){
            term=term*(x/j);
            out=out+term;
          }
            return out;
          }
}

double f (double x){
  x=x*x-1.0;
  return x;

}
