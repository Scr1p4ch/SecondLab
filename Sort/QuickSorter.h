#ifndef _SORT_QUICKSORTER_H_
#define _SORT_QUICKSORTER_H_

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
class QuickSorter : public Sorter<T> {
public:
    QuickSorter() = default;

    ArraySequence<T>* Sort(ArraySequence<T>* arr, int (*cmp)(T &, T& )) override {
        QuickSort(arr, 0,  arr->getSize() - 1, cmp);
        return arr;
    }

    virtual ~QuickSorter() override = default;

private:
    void QuickSort(ArraySequence<T>* arr, int low, int high, int (*cmp)(T& , T& )) {
        while (low < high) {
            if (high - low < 32) {
                InsertionSort(arr, low, high, cmp);
                break;
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

    inline int Partition(ArraySequence<T>* arr, int low, int high, int (*cmp)(T &, T &)) {
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



#endif