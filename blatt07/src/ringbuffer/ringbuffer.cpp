/**
 * @file ringbuffer.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-11
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include <cstdlib>
#include "ringbuffer.h"
#include "CustomAllocator.h"

using namespace std;

template <class T>
T* CustomAllocator<T>::allocate(size_t n){
    cout << ("allocate called. n : " + n) << endl;
    bad_alloc exception;
    throw exception;
}
