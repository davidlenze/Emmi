#include <stdio.h>

int sum(int n);
int func1(int a);

int main(void) {
 int cont=1;

 while(cont==1) {
   printf("Input in integer to which you want to calculate the sum\n" );

   int x;
   scanf("%u", &x);

   printf("the sum is\n %u \n", sum(x) );

   printf("type 1 to continue, any other number to exit\n");
   scanf("%u",&cont );
 }

 return 0;
}

int func1(int a) {
  return a;
}

int sum(int n) {

 int s=0;

 for (size_t i = 1; i < n+1; i++) {

   s=s+func1(i);
 }
 return s;
}
