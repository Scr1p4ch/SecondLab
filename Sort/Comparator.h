#ifndef _COMPARATOR_H_
#define _COMPARATOR_H_

#include "../Utility/ProductClass.h"


int IntCompareFunc(int & a, int & b);
int SoldCopCompareFunc(const Product& a, const Product& b);
int DurationCompareFunc(const Product& a, const Product& b);

#endif