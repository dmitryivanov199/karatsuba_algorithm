//
// Created by dmitry on 11.06.2022.
//

#ifndef KARATSUBA_ALGORITHM_NUMBER_H
#define KARATSUBA_ALGORITHM_NUMBER_H

#include <iostream>

class Number {
public:
    Number();

    ~Number();

    void inputNumber();

    void printNumber();

private:
    uint8_t *digits;
    size_t bitWidth;

    static bool isNumber(const std::string &str);

    void freeMemory();

    void saveDigits(const std::string &str);
};

#endif //KARATSUBA_ALGORITHM_NUMBER_H
