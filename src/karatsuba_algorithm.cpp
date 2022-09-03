#include <iostream>

#include "karatsuba_algorithm.h"

static size_t get_n(const std::string &number);

static uint8_t get_digit(const char string_view_digit);

static std::string get_half(const std::string &number, size_t n, half half);

static std::string sum(const std::string &n1, const std::string &n2);

std::string multiplie_karatsuba(const std::string &x, const std::string &y) {
    size_t n{get_n(x)};
    std::string result{""};

    if (n == 1) {
        result = std::to_string(get_digit(x.at(0)) * get_digit(y.at(0)));
    }
    else {
        std::string a{get_half(x, n, half::LEFT)};
        std::string b{get_half(x, n, half::RIGHT)};
        std::string c{get_half(y, n, half::LEFT)};
        std::string d{get_half(y, n, half::RIGHT)};

        std::string p{sum(a, b)};
        std::string q{sum(c, d)};

        std::cout << p << "\n" << q << "\n";
    }

    return result;
}

size_t get_n(const std::string &number) {
    return number.size();
}

uint8_t get_digit(const char string_view_digit) {
    return static_cast<uint8_t>(string_view_digit - '0');
}

std::string get_half(const std::string &number, size_t n, half half) {
    return (half == half::LEFT)? number.substr(0, n / 2) : number.substr(n / 2, n / 2);
}

std::string sum(const std::string &n1, const std::string &n2) {
    size_t n{n1.size()};
    std::string result{""};
    result.reserve(n);
    bool is_carry{false};

    for (size_t i{0}; i < n; i++) {
        int sum{get_digit(n1.at(n - i - 1)) + get_digit(n2.at(n - i - 1))};

        if (sum < 10) {
            if (is_carry) {
                sum++;

                is_carry = (sum < 10)? false : true;
            }

            result.insert(0, std::to_string(sum));
        }
        else {
            if (is_carry) {
                sum++;
            }

            result.insert(0, std::to_string(sum - 10));
            is_carry = true;
        }
    }

    if (is_carry) {
        result.insert(0, std::to_string(1));
    }

    return result;
}
