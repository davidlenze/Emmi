#include<stdlib.h>
#include<stdio.h>

double f (double);
double expo (double, unsigned int);
double cosi (double, unsigned int);
double sinu (double, unsigned int);

int main (void){
  double max=0.000000001;
  int m=30;
  double x=1.0;

  while(!((cosi(x,m)<max)&&((-cosi(x,m))<max))){
    printf("%12.10f\n",x*2);
      x=x+cosi(x,m)/sinu(x,m);


  }
  printf("%12.10f",x*2);



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

double f (double x){
  x=x*x-1.0;
  return x;

}
