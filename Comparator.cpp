#include "Utility/ProductClass.h"

int IntCompareFunc(int & a, int & b) {
    return (a < b) ? -1 : (a > b) ? 1 : 0;
}

int SoldCopCompareFunc(const Product& a, const Product& b) {
    double s1 = a.GetSoldCopK(), s2 = b.GetSoldCopK();
    return (s1 < s2) ? -1 : (s1 > s2) ? 1 : 0;
}

int DurationCompareFunc(const Product& a, const Product& b) {
    unsigned int s1 = a.GetDuration(), s2 = b.GetDuration();
    return (s1 < s2) ? -1 : (s1 > s2) ? 1 : 0;

}