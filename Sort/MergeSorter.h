#ifndef _SORT_MERGESORTER_H_
#define _SORT_MERGESORTER_H_

#include "Sorter.h"
#include "InsertionSort.h"
#include "../Utility/Sequence.h"
#include "../Utility/FirstLabUtility/Move.h"



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