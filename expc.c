#include<stdlib.h>
#include<stdio.h>
#include <math.h>
#include<complex.h>


_Complex double expc(_Complex double, unsigned int);
double expo (double, unsigned int);
double cosi (double , unsigned int );
double sinu (double , unsigned int );
double pi=3.14159265358979317172595513430;

int main (void){
 _Complex double z;
 double r=1;

  for (double i = 0.0; i < 10; i++) {
    z=r*expc(2*pi*(i/10)*I,100);
    printf("%12.6lf %12.6lf\n",creal(expc(z,100)), cimag(expc(z,100)));
  }



  return 0;
}


_Complex double expc(_Complex double z, unsigned int m) {
  double zr= expo(creal(z),m)*cosi(cimag(z),m);
  double zi= expo(creal(z),m)*sinu(cimag(z),m);

  return (zr + I*zi);

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

double sinu (double x, unsigned int m){

  if (x<0){return (-1.0)*sinu(-x,m);}
    else if (x>1){return 2*sinu(x/2,m)*cosi(x/2,m);}
      else{
        double out = x;
        double term = x;

        for (unsigned int i=2; i<=m; i=i+2){
          term=term*(-x*x/(i*(i+1)));
          out=term+out;
        }
        return out;
      }
}

double cosi (double x, unsigned int m){
 if (x<0){return cosi(-x,m);}
  else if (x>1){return cosi(x/2,m)*cosi(x/2,m)-sinu(x/2,m)*sinu(x/2,m);}
    else {
      double out = 1;
      double term = 1;
      for (unsigned int i=2; i<=m; i=i+2){
        term=term*(-x*x/(i*(i-1)));
        out=term+out;
      }
      return out;
    }


}
