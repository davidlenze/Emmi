//82 69800 3.141592
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "RNG.h"

int main(void) {
  FILE * fehler=fopen ("/Users/davidlenze/git/Emmi/masterfile1.dtn","w");
  printf("%lf\n", estimate_pi(69800,82));
  double p,f;
  for (unsigned int i = 5; i < 100000; i++) {
    p=estimate_pi(1000*i,82);
    f=(3.141592653-p);
    fprintf(fehler, "%u ", 1000*i);
    fprintf(fehler, "%lf\n",f );
  }

    fclose(fehler);
}

double give_optimal_value(unsigned int z, unsigned int m, unsigned int w) {
  unsigned int n;
  n=find_optimal(z,m,w);

  return estimate_pi(n,z);
}

unsigned int find_optimal(unsigned int z, unsigned int m, unsigned int w) {
  double p,f,F;
  unsigned int n=50000;
  F=a((3.141592653-estimate_pi(n,z)));
  for (unsigned int i = 100; i < w; i++) {
    p=estimate_pi(m*i,z);
    f=a((3.141592653-p));
    if (f<F) {
      n=m*i;
      F=f;
    }}

    return n;
}

unsigned int RNG_Evaluate (RNG R, unsigned int x) {
  x=(R.a*x+R.b)%R.m;
  return x;
}

RNG RNG_Set(unsigned int a,unsigned int b,unsigned int m) {
  RNG R;

  R.a=a;
  R.b=b;
  R.m=m;

  return R;
}

RNG RNG_Set_Knuth() {
  return RNG_Set(2173,13849, 65536);
}

void RNG_Report (RNG R) {
  printf("a = %u/n",R.a);
  printf("b = %u/n",R.b);
  printf("m = %u/n",R.m);
}

double distance(unsigned int x, unsigned int y) {
  double X=x*0.0001;
  double Y=y*0.0001;
  unsigned int s = X*X + Y*Y;
  double S = s*0.01;
  S=sqrt(S)*100000;

  return S;
}

double estimate_pi(unsigned int n, unsigned int z) {

  RNG R=RNG_Set_Knuth();
  unsigned int x=42;
  unsigned int y=z;
  double N=0.0;
  for (unsigned int i = 1; i < n; i++) {
    x=RNG_Evaluate(R,x);
    y=RNG_Evaluate(R,y);
    if(distance(x,y)<65536) {
      N=N+1.0; }
    }
    double p=N/(n-1)*1.0;
    return 4*p;

}

void create_rauschen(unsigned int n) {
  RNG R=RNG_Set_Knuth();
  FILE * rauschen=fopen ("/Users/davidlenze/git/Emmi/masterfile.dtn","w");
  unsigned int x=42;
  unsigned int y=41;
  for (unsigned int i = 1; i < n; i++) {
    x=RNG_Evaluate(R,x);
    y=RNG_Evaluate(R,y);
    fprintf(rauschen,"%u ",x );
    fprintf(rauschen,"%u\n",y ); }
  fclose(rauschen);
  return;
}

double a(double a) {
  a=a*a;
  a=sqrt(a);
  return a;
}
