#include "karatsuba_algorithm.h"

static size_t get_n(const std::string &number);

static void fetch_digits(const std::string &number, uint8_t *digits, size_t n);

std::string multiplie_karatsuba(const std::string &x, const std::string &y) {
    size_t n{get_n(x)};
    uint8_t *x_digits = new uint8_t[n];
    uint8_t *y_digits = new uint8_t[n];
    fetch_digits(x, x_digits, n);
    fetch_digits(y, y_digits, n);

    if (n == 1) {
        uint8_t result = x_digits[0] * y_digits[0];
        delete [] x_digits;
        delete [] y_digits;
        return std::to_string(result);
    }
    else {
        delete [] x_digits;
        delete [] y_digits;
        return std::string{""};
    }
}

size_t get_n(const std::string &number) {
    return number.size();
}

static void fetch_digits(const std::string &number, uint8_t *digits, size_t n) {
    for (size_t i{0}; i < n; i++) {
        digits[i] = number.at(i) - '0';
    }
}
