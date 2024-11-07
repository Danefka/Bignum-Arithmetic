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
    Natural abs;

    explicit Integer(Natural number);

public:
    //
    Integer();
    Integer(Integer &integer);
    explicit Integer(std::string number);
    explicit Integer(long long int number);

    Integer &operator=(const Integer &other) noexcept;
    Integer &operator=(const Natural &other) noexcept;

    bool operator==(const Integer& other) noexcept;
    bool operator>(const Integer& other) noexcept;
    Integer operator+(Integer& other) noexcept; // Z-6 ADD_ZZ_Z Першин Артем
    Integer operator-(Integer& other) noexcept; // Z-7 SUB_ZZ_Z Першин Артем
    Integer operator*(Integer& other) const noexcept; // Z-8 MUL_ZZ_Z Першин Артем
    Integer operator/(Integer& other) noexcept; // Z-9 DIV_ZZ_Z Першин Артем
    Integer operator%(Integer& other) noexcept; // Z-10 MOD_ZZ_Z Першин Артем



    void print();
};


#endif //BIGNUM_ARITHMETIC_INTEGER_H
