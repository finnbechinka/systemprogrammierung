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

/*
template <class T>
T* CustomAllocator<T>::allocate(size_t n){
    #ifndef DNDEBUG
    cout << "allocate called."<< endl;
    cout << " n : " << n << endl;
    bad_alloc exception;
    throw exception;
    #endif
}

template <class T>
void CustomAllocator<T>::deallocate(T* p, size_t n) noexcept{
    #ifndef DNDEBUG
    cout << "deallocate called." << endl;
    cout << "n : " << n << endl;
    cout << "start address : " << p << endl;
    cout << "end address : " << (p + n-1) << endl;
    #endif
}
*/

template <class T>
T* CustomAllocator<T>::allocate(size_t n){

    T* ptr = (T*) malloc(n * sizeof(T));

    #ifndef DNDEBUG
    cout << "allocate called."<< endl;
    cout << "n : " << n << endl;
    cout << "first address : " << ptr << endl;
    cout << "last address : " << (ptr + n -1) << endl;
    #endif

    return ptr;
}

template <class T>
void CustomAllocator<T>::deallocate(T* p, size_t n) noexcept{
    #ifndef DNDEBUG
    cout << "deallocate called." << endl;
    cout << "n : " << n << endl;
    cout << "first address : " << p << endl;
    cout << "last address : " << (p + n-1) << endl;
    #endif

    for(int i = 0; i < n; i++){
        free((p + i));
    }
}