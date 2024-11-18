#ifndef _SORT_INSERTIONSORT_H_
#define _SORT_INSERTIONSORT_H_

#include "../Utility/Sequence.h"

template <typename T>
void InsertionSort(ArraySequence<T>* arr, int low, int high, int (*cmp)(const T &, const T &)) {
    for (int i = low + 1; i <= high; ++i) {
        T key = (*arr)[i];
        int j = i - 1;
        while (j >= low && (cmp((*arr)[j], key) > 0)) {
            (*arr)[j + 1] = (*arr)[j];
            --j;
        }
        (*arr)[j + 1] = key;
    }
}


#endif