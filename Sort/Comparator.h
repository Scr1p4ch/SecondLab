#ifndef _COMPARATOR_H_
#define _COMPARATOR_H_

#include "../Utility/ProductClass.h"


int IntCompareFunc(int & a, int & b) {
    if (a < b) {
        return -1;
    }
    if (a == b) {
        return 0;
    }
    return 1;
}

int SoldCopCompareFunc(const Product& a, const Product& b) {
    int s1 = a.GetSoldCopK(), s2 = b.GetSoldCopK();
    return IntCompareFunc(s1, s2);
}

#endif