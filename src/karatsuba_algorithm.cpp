#include <iostream>

#include "karatsuba_algorithm.h"

static std::string align_number(const std::string &number);

static void align_numbers(std::string &n1, std::string &n2);

static bool is_pow2(size_t n);

static uint8_t get_digit(const char string_view_digit);

static std::string get_half(const std::string &number, size_t n, half half);

static std::string sum(const std::string &n1, const std::string &n2);

static std::string sub(const std::string &n1, const std::string &n2);

static void remove_start_zeros(std::string &number);

std::string multiplie_karatsuba(const std::string &x, const std::string &y) {
    if (x.size() == 0 || y.size() == 0) {
        return "";
    }

    std::string aligned_x{align_number(x)};
    std::string aligned_y{align_number(y)};
    align_numbers(aligned_x, aligned_y);
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
        std::cout << p << " = " << a << " + " << b << "\n";
        std::string q{sum(c, d)};
        std::cout << q << " = " << c << " + " << d << "\n";

        std::string ac{multiplie_karatsuba(a, c)};
        std::string bd{multiplie_karatsuba(b, d)};
        std::string pq{multiplie_karatsuba(p, q)};

        align_numbers(ac, bd);
        align_numbers(bd, pq);
        align_numbers(ac, pq);

        std::string adbc{sub(pq, ac)};
        std::cout << pq << " - " << ac << " = " << adbc << "\n";
        std::cout << adbc << " - ";
        adbc = sub(adbc, bd);
        std::cout << bd << " = " << adbc << "\n";

        for (size_t i{0}; i < n; i++) {
            ac.push_back('0');
        }

        for (size_t i{0}; i < n / 2; i++) {
            adbc.push_back('0');
        }

        align_numbers(ac, adbc);
        result = sum(ac, adbc);
        std::cout << ac << " + " << adbc << " = " << result << "\n";
        align_numbers(result, bd);
        std::cout << result << " + ";
        result = sum(result, bd);
        //remove_start_zeros(result);
        std::cout << bd << " = " << result << "\n";
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

void align_numbers(std::string &n1, std::string &n2) {
    size_t max_n{(n1.size() > n2.size())? n1.size() : n2.size()};

    while (n1.size() != max_n) {
        n1.insert(0, std::to_string(0));
    }

    while (n2.size() != max_n) {
        n2.insert(0, std::to_string(0));
    }
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

            if (sum == 10) {
                result.insert(0, std::to_string(0));
            }
            else {
                result.insert(0, std::to_string(sum));
            }
        }
        else {
            if (is_carry) {
                if (sum >= 10) {
                    sum++;
                }
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

std::string sub(const std::string &n1, const std::string &n2) {
    size_t n{n1.size()};
    std::string result{""};
    result.reserve(n);
    bool is_carry{false};

    for (size_t i{0}; i < n; i++) {
        int diff{get_digit(n1.at(n - i - 1)) - get_digit(n2.at(n - i - 1))};

        if (diff >= 0) {
            if (is_carry) {
                diff--;
                is_carry = (diff >= 0)? false : true;
            }

            if (is_carry) {
                result.insert(0, std::to_string(10 + diff));
            }
            else {
                result.insert(0, std::to_string(diff));
            }
        }
        else {
            if (is_carry) {
                diff--;
            }

            result.insert(0, std::to_string(10 + diff));
            is_carry = true;
        }
    }

    return result;
}

static void remove_start_zeros(std::string &number) {
    while (number.at(0) == '0') {
        number = number.erase(0, 1);
    }
}
