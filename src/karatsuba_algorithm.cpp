#include <iostream>

#include "karatsuba_algorithm.h"

static size_t get_n(const std::string &number);

static std::string get_half(const std::string &number, size_t size, half half);

std::string multiplie_karatsuba(const std::string &x, const std::string &y) {
    size_t n{get_n(x)};
    std::string result{""};

    if (n == 1) {
        result = std::to_string(static_cast<uint8_t>(x[0] - '0') * static_cast<uint8_t>(y[0] - '0'));
    }
    else {
        std::string a{get_half(x, n, half::LEFT)};
        std::string b{get_half(x, n, half::RIGHT)};
        std::string c{get_half(y, n, half::LEFT)};
        std::string d{get_half(y, n, half::RIGHT)};
    }

    return result;
}

size_t get_n(const std::string &number) {
    return number.size();
}

static std::string get_half(const std::string &number, size_t size, half half) {
    return (half == half::LEFT)? number.substr(0, size / 2) : number.substr(size / 2, size / 2);
}
