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

v=5;
w=4;
p=15;
q=46;
r=13;
s=39;

Rational m,n,result;
m = RationalSet_setElement(v,p,q);
n = RationalSet_setElement(w,r,s);
result = RationalSet_calcQuotient(m,n);

RationalSet_showElement(result);
printf("%f\n",Rational_asDouble(result));



}

unsigned int ggt (unsigned int m, unsigned int n){ //euklid itterativ
  unsigned int d;

if(m==0||n==0){
  return 1;
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

Rational r;
r.s=s%2;
r.p=p/ggt(p,q);
r.q=q/ggt(p,q);

return r;
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

    Rational sum;

      unsigned char s;
      unsigned int p,q;

        if(r1.s==r2.s){
            s=r1.s;
            p=r1.p*r2.q+r2.p*r1.q;
            q=r1.q*r2.q;
          }else if(r1.p*r2.q<=r2.p*r1.q){
            s=r2.s;
            p=r2.p*r1.q-r1.p*r2.q;
            q=r1.q*r2.q;
          }
          else {
            s=r1.s;
            p=r1.p*r2.q-r2.p*r1.q;
            q=r1.q*r2.q;
}


return RationalSet_setElement(s,p,q);
}

Rational RationalSet_calcDifference (Rational r1, Rational r2){

  Rational help=RationalSet_setElement(r2.s+1,r2.p,r2.q);

  return RationalSet_calcSum(r1,help);

}

Rational RationalSet_calcProduct (Rational r1, Rational r2){

  unsigned char s = (r1.s+r2.s);
  unsigned int p = r1.p*r2.p;
  unsigned int q = r1.q*r2.q;

  return RationalSet_setElement(s,p,q);

}

Rational RationalSet_calcInverse (Rational r){

  if (r.p!=0){
      return RationalSet_setElement(r.s,r.q,r.p);
      }else{
        printf("Exception while dividing by Zero \n");
        return RationalSet_setZero();
      }
}


Rational RationalSet_calcQuotient (Rational r1, Rational r2){
    return RationalSet_calcProduct(r1,RationalSet_calcInverse(r2));
}


void RationalSet_showElement (Rational r){
  if(r.s==0){
    printf("%u/%u \n",r.p,r.q);
  }else {
    printf("-%u/%u \n",r.p,r.q);
  }
}

double Rational_asDouble (Rational r){

if(r.s==0){
  return (1.0*r.p)/(r.q);
}else return (-1.0*r.p)/(r.q);

}
