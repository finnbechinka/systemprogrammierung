#include <iostream>
#include <cstdlib>
#include "RefCounter.h"

RefCounter::RefCounter(){
    n = 0;
}

void RefCounter::inc(){
    n++;
}

void RefCounter::dec(){
    n--;
}

bool RefCounter::isZero() const{
    if(n == 0){
        return true;
    }else{
        return false;
    }
}

unsigned int RefCounter::getRefCount() const{
    return n;
}