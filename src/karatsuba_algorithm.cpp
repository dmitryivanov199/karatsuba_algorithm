#include "karatsuba_algorithm.h"

static size_t get_n(const std::string &number);

static void fetch_digits(const std::string &number, uint8_t *digits, size_t n);

static void get_half(uint8_t *digits, uint8_t *half_digits, size_t n, half half);

std::string multiplie_karatsuba(const std::string &x, const std::string &y) {
    size_t n{get_n(x)};
    uint8_t *x_digits = new uint8_t[n];
    uint8_t *y_digits = new uint8_t[n];
    fetch_digits(x, x_digits, n);
    fetch_digits(y, y_digits, n);
    std::string result{""};

    if (n == 1) {
        uint8_t result_digits = x_digits[0] * y_digits[0];
        result = std::to_string(result_digits);
    }
    else {
        uint8_t *a = new uint8_t[n / 2];
        uint8_t *b = new uint8_t[n / 2];
        uint8_t *c = new uint8_t[n / 2];
        uint8_t *d = new uint8_t[n / 2];

        get_half(x_digits, a, n, half::LEFT);
        get_half(x_digits, b, n, half::RIGHT);
        get_half(y_digits, c, n, half::LEFT);
        get_half(y_digits, d, n, half::RIGHT);

        delete [] a;
        delete [] b;
        delete [] c;
        delete [] d;
    }

    delete [] x_digits;
    delete [] y_digits;

    return result;
}

size_t get_n(const std::string &number) {
    return number.size();
}

static void fetch_digits(const std::string &number, uint8_t *digits, size_t n) {
    for (size_t i{0}; i < n; i++) {
        digits[i] = number.at(i) - '0';
    }
}

static void get_half(uint8_t *digits, uint8_t *half_digits, size_t n, half half) {
    size_t i;

    if (half == half::LEFT) {
        i = 0;
    }
    else {
        i = n / 2 - 1;
    }

    size_t j{0};

    for (; i < n; i++) {
        half_digits[j] = digits[i];
        j++;
    }
}
