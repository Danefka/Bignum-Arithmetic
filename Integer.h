//
// Created by Даниил Гиршович on 07.11.2024.
//

#ifndef BIGNUM_ARITHMETIC_INTEGER_H
#define BIGNUM_ARITHMETIC_INTEGER_H


#include "string"
#include "Natural.h"
#include <iostream>

class Integer {
private:
    bool sign;
    Natural number;

    explicit Integer(Natural number);

public:
    //
    Integer();
    Integer(Integer &integer);
    explicit Integer(std::string number);
    explicit Integer(long long int number);
    explicit Integer(Natural number, bool sign);

    Integer &operator=(const Integer &other) noexcept;
    Integer &operator=(const Natural &other) noexcept;

    Natural abs(); // Тарасов Матвей

    bool isZero(); // Тарасов Матвей
    bool isPoz(); // Тарасов Матвей

    Integer signSwap(); // Тарасов Матвей

    void print();
};


#endif //BIGNUM_ARITHMETIC_INTEGER_H
