#include <iostream>

#include "karatsuba_algorithm.h"
#include "number.h"

int main() {
    Number x;
    x.inputNumber();
    x.printNumber();
    std::cout << std::endl;

    Number y;
    y.inputNumber();
    y.printNumber();
    std::cout << std::endl;

    KaratsubaMultiplication algorithm{x, y};
    Number result = algorithm.multipleNumbers();
    result.printNumber();

    return 0;
}
