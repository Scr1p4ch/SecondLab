#ifndef _SORT_QUICKSORTER_H_
#define _SORT_QUICKSORTER_H_

#include "Sorter.h"
//#include "InsertionSort.h"
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
            if (high - low <= 32) {
                for (int i = low + 1; i <= high; ++i) {
                    int j = i - 1;
                    while (j >= 0 && 1 == cmp((*arr)[j], (*arr)[j + 1])) {
                        std::swap((*arr)[j], (*arr)[j + 1]);
                        --j;
                    }
                }
                return;
            }
            int i = Partition(arr, low, high, cmp);
            //QuickSort(arr, low, i, cmp);
            //QuickSort(arr, i + 1, high, cmp);

            if (i - low < high - i) {
                QuickSort(arr, low, i, cmp);
                low = i + 1;
            }
            else {
                QuickSort(arr, i + 1, high, cmp);
                high = i;
            }
        }
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
};*/


template <typename T>
class QuickSorter : public ISorter<T> {
public:
    QuickSorter() = default;

    ArraySequence<T>* Sort(ArraySequence<T> & arr, int (*cmp)(const T &, const T& )) override {
        QuickSort(arr, 0,  arr.getSize() - 1, cmp);
        return &arr;
    }

    virtual ~QuickSorter() override = default;

private:
    void QuickSort(ArraySequence<T> & arr, int low, int high, int (*cmp)(const T& , const T& )) {
            if (high - low <= 32) {
                for (int i = low + 1; i <= high; ++i) {
                    int j = i - 1;
                    while (j >= 0 && 1 == cmp(arr[j], arr[j + 1])) {
                        std::swap(arr[j], arr[j + 1]);
                        --j;
                    }
                }
                return;
            }
            int i = Partition(arr, low, high, cmp);
            QuickSort(arr, low, i, cmp);
            QuickSort(arr, i + 1, high, cmp);

            
    }

    inline int Partition(ArraySequence<T>& arr, int l, int h, int (*cmp)(const T &, const T &)) {
        int index = (l + h) / 2;
        T v = arr[index];
        int i = l;
        int j = h;

        while (i <= j) {
            while (-1 == cmp(arr[i], v)) {
                ++i;
            }
            while (1 == cmp(arr[j], v))
            {
                --j;
            }
            if (i >= j) {
                break;
            }
            
            std::swap(arr[i++], arr[j--]);
            //MySwap(arr[i++], arr[j--]);
        }
        return j;
    }
};


/*
#include <random>
#include <stack>

constexpr int insertionSortThreshold = 16;

template<typename T>
class QuickSorter final : public ISorter<T> {
    void insertionSort(ArraySequence<T>& sequence, const int left, const int right, int (*cmp)(const T&, const T&)) const {
        for (int i = left + 1; i <= right; i++) {
            T key = sequence[i];
            int j = i - 1;
            while (j >= left && cmp(sequence[j], key) > 0) {
                sequence[j + 1] = sequence[j];
                --j;
            }
            sequence[j + 1] = key;
        }
    }

    std::pair<int, int> partition(ArraySequence<T>& sequence, const int left, const int right, int (*cmp)(const T&, const T&)) const {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution dis(left, right);
        int pivotIndex = dis(gen);
        T pivot = sequence[pivotIndex];
        std::swap(sequence[pivotIndex], sequence[right]);

        int lt = left;
        int gt = right;
        int i = left;

        while (i <= gt) {
            if (cmp(sequence[i], pivot) < 0) {
                std::swap(sequence[i], sequence[lt]);
                ++lt;
                ++i;
            } else if (cmp(sequence[i], pivot) > 0) {
                std::swap(sequence[i], sequence[gt]);
                --gt;
            } else {
                ++i;
            }
        }
        return {lt, gt};
    }
public:
    ArraySequence<T>* Sort(ArraySequence<T>& sequence, int (*cmp)(const T&, const T&)) override {
        std::stack<std::pair<int, int>> stack;
        stack.push({0, sequence.getSize() - 1});
        while (!stack.empty()) {
            auto [left, right] = stack.top();
            stack.pop();
            if (right - left + 1 < insertionSortThreshold) {
                insertionSort(sequence, left, right, cmp);
                continue;
            }
            auto [lt, gt] = partition(sequence, left, right, cmp);
            if (lt - 1 > left) {
                stack.push({left, lt - 1});
            }
            if (gt + 1 < right) {
                stack.push({gt + 1, right});
            }
        }
        return &sequence;
    }
};
*/

#endif