struct RNG {
  unsigned int a;
  unsigned int b;
  unsigned int m;
};

typedef struct RNG RNG;

RNG RNG_Set(unsigned int,unsigned int,unsigned int);
RNG RNG_Set_Knuth (void);

unsigned int RNG_Evaluate (RNG, unsigned int);

void RNG_Report (RNG);

double distance(unsigned int, unsigned int);

double estimate_pi(unsigned int, unsigned int);
void create_rauschen(unsigned int);
double a(double);
unsigned int find_optimal(unsigned int, unsigned int, unsigned int);
double give_optimal_value(unsigned int , unsigned int , unsigned int);
