#include <stdio.h>

int prime(int a);



int main(void) {

   x=17;
   int z=prim(x);

   if(z==0) {printf("the integer is not a prime\n");}
   else     {printf("the integer is a prime\n");}

 }

 return 0;
}


int prim(int n) {

  int a=2;
  int b=1;
  int s=(n/2);
  if(n==1) {b=0;}
  else {
    while(b==1 && a<=s) {
      if(n%a==0) {b=0;}
      a=a+1;
    }
      }
  return b;
}
