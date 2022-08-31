#include <iostream>

#include "karatsuba_algorithm.h"

int main() {
    std::string x{"1234"};
    std::string y{"5678"};
    std::string result{multiplieKaratsuba(x, y)};

    std::cout << x << " * " << y << " = " << result << std::endl;

    return 0;
}
