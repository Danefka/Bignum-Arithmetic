//
// Created by Даниил Гиршович on 07.11.2024.
//

#ifndef BIGNUM_ARITHMETIC_FRACTION_H
#define BIGNUM_ARITHMETIC_FRACTION_H


#include "Natural.h"

class Fraction {
private:
    Natural up;
    Integer down;
public:
    // Конструкторы
    Fraction();
    Fraction(unsigned long long int up, long long int down);
    Fraction(Natural up, Natural down);
    Fraction(Natural up, Integer down);
    Fraction(Integer up, Integer down);

    Fraction &operator=(const Fraction &other) noexcept;
};


#endif //BIGNUM_ARITHMETIC_FRACTION_H
