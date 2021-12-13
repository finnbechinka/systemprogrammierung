#include <iostream>
#include <cstdlib>
#include "CustomAllocator.h"

using namespace std;


int main() {
    CustomAllocator<int> intAllocator;
    intAllocator.allocate(5);
    return EXIT_SUCCESS;
}