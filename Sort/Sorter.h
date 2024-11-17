#ifndef _SORT_SORTER_H_
#define _SORT_SORTER_H_

#include "../Utility/Sequence.h"

template <typename T>
class Sorter {
public:
    virtual ~Sorter() = default;

    virtual ArraySequence<T>* Sort(ArraySequence<T>* arr, int (*cmp)(T & , T & )) = 0;
};




#endif