#include <iostream>

#include "karatsuba_algorithm.h"

int main() {
    std::string x{"4"};
    std::string y{"8"};
    std::string result{multiplie_karatsuba(x, y)};

    std::cout << x << " * " << y << " = " << result << std::endl;

    return 0;
}
