#include <stdio.h>
#include <time.h>

clock_t start,end;
double cpu_time_used;

int ggt1(int a, int b);
int ggt1_r(int a, int b);
int ggt2(int a, int b);
int ggt2_r(int a, int b);
int ggt3(int a, int b);
int ggt3_r(int a, int b);


int main(void) {

  int n,m;
  int low, high;

  low=1;
  high=2000;

for (size_t i = 1; i < 7; i++) {

 int mode=i;
 int v1;

 start = clock();
 for (m = low; m <= high; m++) {
   for (n = low; n <= high; n++) {

     v1 = ggt(m,n,mode);
     //printf("%5u %u %5u \n",m,n,v1);

   }
 }
  end=clock();

  cpu_time_used = 1.0*(end-start)/CLOCKS_PER_SEC;
  printf("%u %e %12.6f\n \n", mode, cpu_time_used, cpu_time_used);

  }

  return 0;
}


int ggt(int n, int m, int mode) {

  switch(mode) {
	  case 1: return ggt1_r(n,m); break;
    case 2: return ggt1(n,m); break;
    case 3: return ggt2_r(n,m); break;
    case 4: return ggt2(n,m); break;
    case 5: return ggt3_r(n,m); break;
    case 6: return ggt3(n,m); break;
	  default: return 0; break;
 }

}

int ggt1_r(int n, int m) {
  int g;
  if(m==n) {return m;}
  else {
    if(m>n) { g=ggt1_r(m-n,n); }
    else    { g=ggt1_r(m,n-m); }
      }
  return g;
}

int ggt1(int n, int m) {

  while(m!=n) {
		if(m>n) {m=m-n;}
		else {n=n-m;}
	}
 return n;
}

int ggt2_r(int n, int m) {
  int g;
  if(m%n==0) {return n;}
  else {
    if(m>n) { g=ggt2_r(n,(m%n)); }
    else    { g=ggt2_r(m,(n%m)); }
      }
  return g;
}

int ggt2(int n, int m) {
  int r;

  while(m%n!=0) {
    r=m%n; m=n; n=r;
   }
  return n;
 }

int ggt3_r(int n, int m) {
  int g;
  if(m==n) {return m;}
  else {
    if(m%2==0) {
      if(n%2==0) {g=2*ggt3_r(n/2,m/2);}
      else       {g=ggt3_r(m/2,n);} }

    else {
      if(n%2==0) {g=ggt3_r(n/2,m);}
      else {
        if(m>n) {g=ggt3_r((m-n)/2,n);}
        else    {g=ggt3_r((n-m)/2,m);}
    }} }
  return g;
}

int ggt3(int n, int m) {
  int M=1;

  while(m!=n) {

   if(m%2==0) {
      if(n%2==0) {n=n/2; m=m/2; M=M*2;}
      else       {m=m/2;} }
   else {
      if(n%2==0) {n=n/2;}
      else {
        if(m>n) {m=(m-n)/2;}
        else    {n=(n-m)/2;}
    }}  }
  return n*M;
}

