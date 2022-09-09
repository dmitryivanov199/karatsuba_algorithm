#ifndef KARATSUBA_ALGORITHM_HPP
#define KARATSUBA_ALGORITHM_HPP

#include <string>

enum class half {
    LEFT,
    RIGHT
};

std::string multiplie_karatsuba(const std::string &x, const std::string &y);

#endif //KARATSUBA_ALGORITHM_HPP
