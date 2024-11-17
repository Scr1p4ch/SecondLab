#ifndef _COMPARATOR_H_
#define _COMPARATOR_H_


int IntCompareFunc(int & a, int & b) {
    if (a < b) {
        return -1;
    }
    if (a == b) {
        return 0;
    }
    return 1;
}

#endif