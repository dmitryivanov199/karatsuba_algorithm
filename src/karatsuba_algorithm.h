#ifndef KARATSUBA_ALGORITHM_H
#define KARATSUBA_ALGORITHM_H

#include <string>

enum class half {
    LEFT,
    RIGHT
};

std::string multiplie_karatsuba(const std::string &x, const std::string &y);

#endif //KARATSUBA_ALGORITHM_H
