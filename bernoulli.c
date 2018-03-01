#include  <stdio.h>


double power (double, unsigned int);
double bernoulli (double, unsigned int);
double diff_bernoulli (double, unsigned int);

int main (void) {

  for (unsigned int n=1; n<=1000; n=n+2){  //Nullstellen für verschiedene n-Werte, ungerade, da bei n%2=0 die einzige und damit triviale Nullstelle immer bei x=0 liegt.
    double x=-3.0;  //Startwert bei -3, damit nicht die triviale Nullstelle x=0 als erstes gefunden wird

      while (!(bernoulli(x,n)<0.0001&&bernoulli(x,n)>-0.0001)){  //0.0001 gibt die Genauigkeit der Näherung an

          if (diff_bernoulli(x,n)!=0){
          x=x-bernoulli(x,n)/diff_bernoulli(x,n);  //newton-verfahren zur Nullstellenbestimmung
          }
          else{ x=x-bernoulli(x,n)/diff_bernoulli(x,n)+0,00001;}

      }

        printf("Bernoulli von %f mit n = %u ist %f\n", x, n, bernoulli(x,n) );

    }

}

double diff_bernoulli (double x, unsigned int n){

  return(n*power(1+x,n-1)-n);
}

double bernoulli (double x, unsigned int n){

  return(power(1+x,n)-1-n*x);

}

double power (double x, unsigned int n){
  double p=1;
    if(n==0) {x=1; n=1;}
      while (n!=1) {
        if(n%2==0) {n=(n/2);}
        else {n=(n-1)/2; p=p*x;}
        x=x*x;
      }
      return x*p;
}
