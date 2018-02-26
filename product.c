#include <stdio.h>

int product(int n);
int func1(int a);

int main(void) {

   int x=3;
   printf("the product is\n %u \n", product(x) );



 return 0;
}

int func1(int a) {
  return 10;
}

int product(int n) {

 int p=1;

 for (int i = 1; i < n+1; i++) {

   p=p*func1(i);
 }
 return p;
}
