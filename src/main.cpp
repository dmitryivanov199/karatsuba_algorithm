#include <iostream>

#include "karatsuba_algorithm.h"

int main() {
    std::string x{"1234567890123456"};
    std::string y{"1234567890123456"};
    std::string result{multiplie_karatsuba(x, y)};

    std::cout << x << " * " << y << " = " << result << std::endl;

    return 0;
}
