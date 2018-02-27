//Wichtig es gibt die Eigenschaft des Ganzzahl-Überlauf; i.e. Zahlen werden mod 2^(n) addiert

int main (void) {

  unsigned char m,n,r;
  m=222;
  n=80;
  r = m+n,
  printf("%u + %u = %u\n",m,n,r );
}
