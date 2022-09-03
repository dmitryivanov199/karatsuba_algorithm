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
    const size_t tests_number{10};
    std::array<std::string, tests_number> x{"23", "1234",
        "24358685", "3467848",
        "4859074536475867", "0",
        "547", "",
        "1", "3463467374357878"};
    std::array<std::string, tests_number> y{"89", "3473",
        "89595900", "459549549",
        "9999999999999999", "0",
        "569569", "1",
        "1", "0"};
    std::array<std::string, tests_number> result{"2047", "4285682",
        "2182438305391500", "1593647984400552",
        "48590745364758665140925463524133", "0",
        "311554243", "",
        "1", "0"};

    for (size_t i{0}; i < tests_number; i++) {
        if (result.at(i).compare(multiplie_karatsuba(x.at(i), y.at(i))) != 0) {
            return false;
        }
    }

    return true;
}
