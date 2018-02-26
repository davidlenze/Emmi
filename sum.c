#include <stdio.h>

int sum(int n);
int func1(int a);

int main(void) {

   x=10;
   printf("the sum is\n %u \n", sum(x) );

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
