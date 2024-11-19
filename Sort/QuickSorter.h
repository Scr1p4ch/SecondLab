#ifndef _SORT_QUICKSORTER_H_
#define _SORT_QUICKSORTER_H_

#include "Sorter.h"
#include "InsertionSort.h"
#include "../Utility/Sequence.h"
#include "../Utility/FirstLabUtility/Move.h"
#include "../Utility/FirstLabUtility/Swap.h"



/*
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
        while (low < high) {
            if (high - low < 32) {
                InsertionSort(arr, low, high, cmp);
                return;
            } else {
                int pivotIndex = Partition(arr, low, high, cmp);

                if (pivotIndex - low < high - pivotIndex) {
                    QuickSort(arr, low, pivotIndex - 1, cmp);
                    low = pivotIndex + 1;
                } else {
                    QuickSort(arr, pivotIndex + 1, high, cmp);
                    high = pivotIndex - 1;
                }
            }
        }
    }

    inline int Partition(ArraySequence<T>* arr, int low, int high, int (*cmp)(const T &, const T &)) {
        T pivot = (*arr)[high];
        int i = low - 1;

        for (int j = low; j < high; ++j) {
            if (cmp((*arr)[j], pivot) < 0) {
                ++i;
                arr->Swap(i, j);
            }
        }
        arr->Swap(i + 1, high);
        return i + 1;
    }
};
*/


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
            InsertionSort(arr, low, high, cmp);
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
            
            std::swap((*arr)[i++], (*arr)[j--]);
            //MySwap((*arr)[i++], (*arr)[j--]);
        }
        return j;
    }
};

#endif