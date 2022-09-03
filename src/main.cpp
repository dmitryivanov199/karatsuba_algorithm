#include <array>
#include <iostream>

#include "karatsuba_algorithm.h"

bool complete_tests();

int main() {
    if (complete_tests()) {
        std::cout << "All tests passed!" << std::endl;
    }
    else {
        std::cout << "Something went wrong..." << std::endl;
    }

    return 0;
}

bool complete_tests() {
    const size_t tests_number{5};
    std::array<std::string, tests_number> x{"23", "1234", "24358685", "3677", "4859074536475867"};
    std::array<std::string, tests_number> y{"89", "3473", "89595900", "1111", "9999999999999999"};
    std::array<std::string, tests_number> result{"2047", "4285682", "2182438305391500", "4085147", "48590745364758665140925463524133"};

    for (size_t i{0}; i < tests_number; i++) {
        if (result.at(i).compare(multiplie_karatsuba(x.at(i), y.at(i))) != 0) {
            return false;
        }
    }

    return true;
}
