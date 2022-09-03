#include <iostream>

#include "karatsuba_algorithm.h"

static std::string align_number(const std::string &number);

static bool is_pow2(size_t n);

static uint8_t get_digit(const char string_view_digit);

static std::string get_half(const std::string &number, size_t n, half half);

static std::string sum(const std::string &n1, const std::string &n2);

//static std::string sub(const std::string &n1, const std::string &n2);

std::string multiplie_karatsuba(const std::string &x, const std::string &y) {
    if (x.size() == 0 || y.size() == 0) {
        return "";
    }

    std::string aligned_x{align_number(x)};
    std::string aligned_y{align_number(y)};
    size_t n{aligned_x.size()};
    std::string result{""};

    if (n == 1) {
        result = std::to_string(get_digit(x.at(0)) * get_digit(y.at(0)));
    }
    else {
        std::string a{get_half(aligned_x, n, half::LEFT)};
        std::string b{get_half(aligned_x, n, half::RIGHT)};
        std::string c{get_half(aligned_y, n, half::LEFT)};
        std::string d{get_half(aligned_y, n, half::RIGHT)};

        std::string p{sum(a, b)};
        std::string q{sum(c, d)};

        /*std::string ac{multiplie_karatsuba(a, c)};
        std::string bd{multiplie_karatsuba(b, d)};
        std::string pq{multiplie_karatsuba(p, q)};*/

        /*std::string adbc{sub(pq, ac)};
        adbc = sub(adbc, bd);*/
    }

    return result;
}

std::string align_number(const std::string &number) {
    std::string aligned_number{number};

    while (!is_pow2(aligned_number.size())) {
        aligned_number.insert(0, std::to_string(0));
    }

    return aligned_number;
}

bool is_pow2(size_t n) {
    return (n == 0) ? false : (n & (n - 1)) == 0;
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

/*std::string sub(const std::string &n1, const std::string &n2) {

}*/
