#ifndef NUMBER_H
#define NUMBER_H

#include <iostream>

class Number {
public:
    Number();

    Number(const Number &number);

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

#endif //NUMBER_H
