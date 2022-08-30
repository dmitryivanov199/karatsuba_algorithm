#ifndef KARATSUBA_ALGORITHM_H
#define KARATSUBA_ALGORITHM_H

#include "number.h"

class KaratsubaMultiplication {
public:
    KaratsubaMultiplication(const Number &x, const Number &y);

    ~KaratsubaMultiplication();

    Number multipleNumbers();

private:
    Number x;
    Number y;

    KaratsubaMultiplication();
};

#endif //KARATSUBA_ALGORITHM_H
