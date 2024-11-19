#ifndef _FIRSTLAB_SWAP_H_
#define _FIRSTLAB_SWAP_H_

#include "Move.h"

template<typename T>
void MySwap(T & first, T & second) {
    T tmp = first;
    first = second;
    second = first;
}

#endif