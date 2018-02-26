#include <stdio.h>

int prime(int a);



int main(void) {
 int cont=1;

 while(cont==1) {
   printf("Input an integer to be checked for primality\n" );

   int x;
   scanf("%u", &x);

   int z=prim(x);

   if(z==0) {printf("the integer is not a prime\n");}
   else     {printf("the integer is a prime\n");}

   printf("type 1 to continue, any other number to exit\n");
   scanf("%u",&cont );

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

