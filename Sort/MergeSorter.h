#ifndef _SORT_MERGESORTER_H_
#define _SORT_MERGESORTER_H_

#include "Sorter.h"
#include "../Utility/Sequence.h"
#include "../Utility/FirstLabUtility/Move.h"

template <typename T>
void InsertionSort(ArraySequence<T>* arr, int low, int high, int (*cmp)(T &, T &)) {
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

template <typename T>
class MergeSorter : public Sorter<T> {
public:
    MergeSorter() = default;

    ArraySequence<T>* Sort(ArraySequence<T>* arr, int (*cmp)(T &, T& )) override {
        MergeSort(arr, 0,  arr->getSize() - 1, cmp);
        return arr;
    }

    virtual ~MergeSorter() override = default;

private:
    
};

#endif