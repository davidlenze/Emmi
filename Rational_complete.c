#include<stdio.h>

struct Rational {
  unsigned char s; //Vorzeichen
  unsigned int p;  //Zähler
  unsigned int q;  //Nenner
};
typedef struct Rational Rational;

Rational RationalSet_setElement(unsigned char, unsigned int, unsigned int);
Rational RationalSet_setZero(void);
Rational RationalSet_setOne(void);

Rational RationalSet_calcSum (Rational, Rational);
Rational RationalSet_calcDifference (Rational, Rational);
Rational RationalSet_calcProduct (Rational, Rational);
Rational RationalSet_calcQuotient (Rational, Rational);
Rational RationalSet_calcInverse (Rational);

unsigned int ggt (unsigned int,unsigned int);

void RationalSet_showElement (Rational);

double Rational_asDouble (Rational);

int main (void){




unsigned char v,w;
unsigned int p,q,r,s;

v=0;
w=1;
p=1;
q=4294967295;
r=3;
s=4294967295;

Rational m,n,result;
m = RationalSet_setElement(v,p,q);
n = RationalSet_setElement(w,r,s);
result = RationalSet_calcSum(m,n);

RationalSet_showElement(result);
printf("%f\n",Rational_asDouble(result));



}

unsigned int ggt (unsigned int m, unsigned int n){ //euklid itterativ
  unsigned int d;

    if(m==0){
        return n;
    }else if (n==0){
  return m;
  }

  else{

    while(m%n!=0){
	      d=m%n;
	       m=n;
	        n=d;
                  }
    return n;

  }
}

Rational RationalSet_setElement(unsigned char s, unsigned int p, unsigned int q){

if (q!=0){

    Rational r;
    r.s=s%2;
    r.p=p/ggt(p,q);
    r.q=q/ggt(p,q);

    return r;
}else{  //in case of zero-denominator the return value is 0/1
  printf("invalid demoninator entered\n");

  return RationalSet_setZero();
}
}

Rational RationalSet_setZero(void){

    Rational r;
    r.s=0;
    r.p=0;
    r.q=1;

    return r;
}

Rational RationalSet_setOne(void){

    Rational r;
    r.s=0;
    r.p=1;
    r.p=1;

    return r;

}

Rational RationalSet_calcSum (Rational r1, Rational r2){
      unsigned char s;
      unsigned int g,h;

        g=r2.q/ggt(r1.q,r2.q);
        h=r1.q/ggt(r1.q,r2.q);

        if (r1.s==r2.s){
                    return RationalSet_setElement(r1.s,(r1.p*g+r2.p*h),r1.q*g);
            }
            else if(r1.p*g>=r2.p*h){
                    return RationalSet_setElement(r1.s,(r1.p*g-r2.p*h),r1.q*g);
              }
            else {
                    return RationalSet_setElement(r2.s,(r2.p*h-r1.p*g),r1.q*g);
                  }



}

Rational RationalSet_calcDifference (Rational r1, Rational r2){

    r2.s=(r2.s+1)%2;

    return RationalSet_calcSum(r1,r2);

}

Rational RationalSet_calcProduct (Rational r1, Rational r2){

    unsigned char s = (r1.s+r2.s);
    unsigned int g = ggt(r1.p,r2.q);
    unsigned int h = ggt(r2.p,r1.q);
    r1.p=r1.p/g;

    r1.q=r1.q/h;

    r2.p=r2.p/h;

    r2.q=r2.q/g;



    return RationalSet_setElement(s,r1.p*r2.p,r1.q*r2.q);

}

Rational RationalSet_calcInverse (Rational r){

  if (r.p!=0){
      return RationalSet_setElement(r.s,r.q,r.p);
      }else{
        printf("Exception while dividing by Zero \n"); //in case of Zero, the return is Zero
        return RationalSet_setZero();
      }
}


Rational RationalSet_calcQuotient (Rational r1, Rational r2){
    return RationalSet_calcProduct(r1,RationalSet_calcInverse(r2));
}


void RationalSet_showElement (Rational r){
  if(r.s==0||r.p==0){
    printf("( %u / %u ) \n",r.p,r.q);
  }else {
    printf("- ( %u / %u ) \n",r.p,r.q);
  }
}

double Rational_asDouble (Rational r){

if(r.s==0||r.p==0){
  return (1.0*r.p)/(r.q);
}else return (-1.0*r.p)/(r.q);

}
