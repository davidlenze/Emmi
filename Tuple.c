#include "Tuple.h"
#include "RNG.h"
#include "RNG.c"
#include <stdbool.h>
#include<math.h>
void Vector_Rotate(FILE * F, vector v){
	Givens_Rotate(F, v.v, v.n);
	
}
vector Vector_Create_Random(RNG joe, size_t n){
	vector x ={0, NULL};
	x= Vector_Create(n);
	for(size_t i=0; i<n; i++){
		x.v[i]=RNG_Evaluate_Double(joe, joe.l);
		
	}
	return x;
}
vector Vector_Create(size_t n){
	vector v = {0,NULL};
	v.v = Tuple_Create(n);
	v.n= n;
	return v;
	
}
void Vector_Destroy(vector v){
	Tuple_Destroy(v.v);
	
}
void Vector_Report(FILE * F, vector v, char * fmt, char * info){
	fprintf(F,"%s \n \n", info);
	for(unsigned int i = 0;i<v.n;i++){
		fprintf(F, fmt, v.v[i], "\n");
	}
	
}
double Givens_Rotate(FILE * F, double * v, unsigned int n){
	Tuple_Print(F,v,n);
	double tmp=0;
	double c,s;
	for(unsigned int i=0;i<n;i++){
	tmp=tmp+ v[i]*v[i];
	}
	tmp=sqrt(tmp);
	v[0]= tmp;
	Tuple_Print(F,v,n);
	for(unsigned int i=1;i<n;i++){
		c=1.0; s= - v[i]/tmp;
		v[i]= s;
		Tuple_Print(F,v,n);
	}
	return tmp;
}
void Givens_Backwards(FILE * F, double * v, unsigned int n){
	Tuple_Print(F,v,n);
	double tmp=0 ;
	for(unsigned int i=1; i<n;i++){
		v[i]=v[i]*(-1)*v[0];
		if(i<=n-1){
			tmp=tmp+v[i]*v[i];
		}
	
		Tuple_Print(F,v,n);
	}
	
	v[0]=sqrt((v[0]*v[0])-tmp);
	Tuple_Print(F,v,n);
}
bool compare (unsigned int a,unsigned int b){
	if(a%2==1){ 
				if(b%2==1){
					return (a<b);
				}
				return true;
	}
	else if(b%2==1){
					return false;
				}
			
	return (a>b);
}
double * Tuple_Create(size_t n){
	double * tuple;
	tuple= malloc(sizeof(double)*n);
	return tuple;
}
void Tuple_Destroy(double * tuple){
	free(tuple);
}
void Tuple_Print(FILE * F, double * tuple,size_t n){
	fprintf(F, "\n \n");
	for(unsigned int i = 0;i<n;i++){
		fprintf(F,"%lf \n", tuple[i]);
	}
}
unsigned int * unsignedTuple_Create(unsigned int n){
	unsigned int * v;
	v= malloc(sizeof(unsigned int)*n);
	return v;
	
}
void unsignedTuple_Destroy(unsigned int * v){
	
	free(v);
	
}
void unsignedTuple_Print(FILE * F, unsigned int * v,unsigned int n){
	fprintf(F,"\n \n");
	for(unsigned int i = 0;i<n;i++){
		fprintf(F, "%u \n", v[i]);
	}
	
}
void unsignedTuple_Bubblesort(FILE * F, unsigned int * v, unsigned int n){
	unsigned int tmp;
	for(unsigned int i=n-1;i>0;i--){
		for(unsigned int j=0;j<i;j++){
			
			if(compare(v[j],v[j+1])){
				unsignedTuple_Print(F,v,n);
				tmp= v[j];
				v[j]=v[j+1];
				v[j+1]=tmp;
			}
		}
		
		
	}
	
	
	
}
void Tuple_Bubblesort(FILE * F, double * v, unsigned int n){
	double tmp;
	for(unsigned int i=n-1;i>0;i--){
		for(unsigned int j=0;j<i;j++){
			
			if(v[j]>v[j+1]){
				Tuple_Print(F,v,n);
				tmp= v[j];
				v[j]=v[j+1];
				v[j+1]=tmp;
			}
		}
		
		
	}
	
	
	
}
double * unsignedTuple_RNG_Create(unsigned int n, RNG joe){
	double * v;
	unsigned int l=3;
	v=malloc(sizeof(unsigned int)*n);
		for(unsigned int i=0;i<n;i++){
			l=RNG_Evaluate(joe,l);
			v[i]=l;
			
		}
	return v;
}
int main(void){
	unsigned int n=10;
	double * v;
	double l;
	vector x= {0,NULL};
	RNG joe;
	FILE * F;
	F = stdout;
	//F= fopen("Tuple.dat","w");*/
	joe= RNG_Set_Knuth();
	v= unsignedTuple_RNG_Create(n,joe);
	Givens_Rotate(F,v,n);
	Givens_Backwards(F,v,n);
	
	//unsignedTuple_Bubblesort(F,v,n);
	/*for(unsigned int i =0;i<10;i++){
		unsignedTuple_Print(F,v,n);
	}*/
	Tuple_Destroy(v);
	return 0;
}