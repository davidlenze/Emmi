#ifndef RNG_H
#define RNG_H
struct RNG {
  unsigned int a ;
  unsigned int b ;
  unsigned int m ;
};



typedef struct RNG RNG;
RNG RNG_Set (unsigned int, unsigned int, unsigned int);
RNG RNG_Set_Knuth(void);

double RNG_Evaluate(RNG, double);

void RNG_Report (RNG);
#endif
