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
    Natural natural;

public:
    // Конструкторы
    Integer();  // Гиршович Даниил
    Integer(Integer &integer);  // Гиршович Даниил
    explicit Integer(Natural number);  // Гиршович Даниил
    Integer(bool sign,Natural number);  // Гиршович Даниил
    Integer(std::string number);  // Гиршович Даниил
    Integer(long long int number);  // Гиршович Даниил

    // Операторы
    Integer &operator=(const Integer &other) noexcept;  // Гиршович Даниил
    Integer &operator=(const Natural &other) noexcept; // Гиршович Даниил
    bool operator==(const Integer& other) noexcept;
    bool operator>(const Integer& other) noexcept;
    Integer operator%(Integer& other) noexcept; // Z-10 MOD_ZZ_Z Першин Артем
    Natural abs(); // Тарасов Матвей

    // Вывод в консоль
    void print(); // Гиршович Даниил

    bool isZero(); // Тарасов Матвей
    bool isPoz(); // Тарасов Матвей

    Integer add(Integer& other); // Z-6 ADD_ZZ_Z Першин Артем
    Integer sub(Integer& other); // Z-7 SUB_ZZ_Z Першин Артем
    Integer mul(Integer& other); // Z-8 MUL_ZZ_Z Першин Артем
    Integer div(Integer other); // Z-9 DIV_ZZ_Z Першин Артем
    Integer mod(Integer other); // Z-10 MOD_ZZ_Z Першин Артем
    Integer signSwap(); // Тарасов Матвей


};


#endif //BIGNUM_ARITHMETIC_INTEGER_H
