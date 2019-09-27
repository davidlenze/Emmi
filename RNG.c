#include <stdio.h>
#include <stdlib.h>
#include "RNG.h"


RNG RNG_Set (unsigned int a, unsigned int b, unsigned int m){
    RNG r;
    r.a=a;
    r.b=b;
    r.m=m;

    return r;
}

RNG RNG_Set_Knuth(void){
  return RNG_Set(25173,13849,65536);
}

void RNG_Report(RNG r){
  printf("a = %u\n",r.a );
  printf("b = %u\n",r.b );
  printf("m = %u\n",r.m );
}

double RNG_Evaluate(RNG r, double x){
  int y = (int) ( x * r.m);
  x = 1.0*((r.a * y + r.b ) % r.m);
  return x/r.m;
}
