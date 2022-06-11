#include <iostream>

#include "src/number.h"

int main() {
    Number x;
    x.inputNumber();
    x.printNumber();
    std::cout << std::endl;
    Number y{x};
    y.printNumber();
    return 0;
}
