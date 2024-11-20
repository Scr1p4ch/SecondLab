#ifndef _SORT_QUICKSORTER_H_
#define _SORT_QUICKSORTER_H_

#include "Sorter.h"
#include "InsertionSort.h"
#include "../Utility/Sequence.h"
#include "../Utility/FirstLabUtility/Move.h"
#include "../Utility/FirstLabUtility/Swap.h"
#include <iostream>


template <typename T>
class QuickSorter : public Sorter<T> {
public:
    QuickSorter() = default;

    ArraySequence<T>* Sort(ArraySequence<T>* arr, int (*cmp)(const T &, const T& )) override {
        QuickSort(arr, 0,  arr->getSize() - 1, cmp);
        return arr;
    }

    virtual ~QuickSorter() override = default;

private:
    void QuickSort(ArraySequence<T>* arr, int low, int high, int (*cmp)(const T& , const T& )) {
        if (high - low <= 32) {
            for (int i = low + 1; i <= high; ++i) { // тут потом глянуть, high - 1 или нет
                int j = i - 1;
                while (j >= 0 && 1 == cmp((*arr)[j], (*arr)[j + 1])) {
                    std::swap((*arr)[j], (*arr)[j + 1]);
                    --j;
                }
            }
            return;
        }
        int i = Partition(arr, low, high, cmp);
        QuickSort(arr, low, i, cmp);
        QuickSort(arr, i + 1, high, cmp);
    }

    inline int Partition(ArraySequence<T>* arr, int l, int h, int (*cmp)(const T &, const T &)) {
        T v = (*arr)[(l + h) / 2];
        int i = l;
        int j = h;

        while (i <= j) {
            while (-1 == cmp((*arr)[i], v)) {
                ++i;
            }
            while (1 == cmp((*arr)[j], v))
            {
                --j;
            }
            if (i >= j) {
                break;
            }
            
            //std::swap((*arr)[i++], (*arr)[j--]);
            MySwap((*arr)[i++], (*arr)[j--]);
        }
        return j;
    }
};

#endif