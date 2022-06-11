//
// Created by dmitry on 11.06.2022.
//

#include "number.h"

Number::Number() :
        digits{nullptr},
        bitWidth{0} {
}

Number::Number(const Number &number) {
    bitWidth = number.bitWidth;
    digits = new uint8_t[bitWidth];

    for (size_t i{0}; i < bitWidth; i++) {
        digits[i] = number.digits[i];
    }
}

Number::~Number() {
    freeMemory();
}

void Number::inputNumber() {
    std::string str;

    while (true) {
        std::cout << "Input number" << std::endl;
        std::cout << ">";
        std::cin >> str;

        if (isNumber(str)) {
            break;
        }
    }

    freeMemory();
    bitWidth = str.size();
    digits = new uint8_t[bitWidth];
    saveDigits(str);
}

void Number::printNumber() {
    for (size_t i{0}; i < bitWidth; i++) {
        std::cout << unsigned(digits[i]);
    }
}

bool Number::isNumber(const std::string &str) {
    for (size_t i{0}; i < str.size(); i++) {
        if (str.at(i) < '0' || str.at(i) > '9') {
            return false;
        }
    }

    return true;
}

void Number::freeMemory() {
    delete[] digits;
    bitWidth = 0;
}

void Number::saveDigits(const std::string &str) {
    const int base{10};
    char startPtr[1];
    char *endPtr{nullptr};

    for (size_t i{0}; i < str.size(); i++) {
        str.copy(startPtr, 1, i);
        digits[i] = static_cast<uint8_t>(std::strtoll(startPtr, &endPtr, base));
    }
}
