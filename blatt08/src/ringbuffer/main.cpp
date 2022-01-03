#include <iostream>
#include <cstdlib>
#include "ringbuffer.h"
#include "CustomAllocator.h"

int main() {
    CustomAllocator<int> intAllocator;

    intAllocator.allocate((size_t)5);

    return EXIT_SUCCESS;
}