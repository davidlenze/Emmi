Rational RationalSet_setElement(unsigned char, unsigned int, unsigned int);
Rational RationalSet_setZero(void);
Rational RationalSet_setOne(void);

Rational RationalSet_calcSum (Rational, Rational);
Rational RationalSet_calcDifference (Rational, Rational);
Rational RationalSet_calcProduct (Rational, Rational);
Rational RationalSet_calcQuotient (Rational, Rational);

void RationalSet_showElement (Rational);

double Rational_asDouble (Rational);
