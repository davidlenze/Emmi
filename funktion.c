#include<math.h>
#include<stdio.h>

double fctn (double);
double diff (double);





int main (void) {
  double x=3.5;  //Startwert (>0, da sqrt gebildet wird.)
  double acc = 0.00001;


  while (fabs(fctn(x))>=acc){



    x=x-fctn(x)/diff(x);

  }

  printf ("%f\n",x);
}


double fctn (double x){
  double a1 = 1+x;     //sieht hässlich aus, ist aber der Leibniz-Algorithmus
  double a2 = sqrt(a1);  //Zerlegung der Funktion in kleine Abschnitte zur
  double a3 = log(a2);  //besseren Berechnung der Ableitung
  double a4 = a3*x;
  double a5 = exp(a4);
  double a6 = log(x)*a2;
  double a7 = exp(a6);
  double a8 = a5-a7;

  return (a8);

}

double diff (double x){

  double a1 = 1+x;       //Auch das natürlich unschön,aber was will man machen
  double a2 = sqrt(a1);
  double a3 = log(a2);
  double a4 = a3*x;
  double a5 = exp(a4);
  double a6 = log(x)*a2;
  double a7 = exp(a6);
  double a8 = a5-a7;

  double b1 = 1;
  double b2 = (1/(2*sqrt(a1)))*b1;
  double b3 = (1/a2)*b2;
  double b4 = b3*x+a3;
  double b5 = exp(a4)*b4;
  double b6 = (1/x)*a2+log(x)*b2;
  double b7 = exp(a6)*b6;
  double b8 = b5-b7;

  return (b8);

}
