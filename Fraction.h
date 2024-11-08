//
// Created by Даниил Гиршович on 07.11.2024.
//

#ifndef BIGNUM_ARITHMETIC_FRACTION_H
#define BIGNUM_ARITHMETIC_FRACTION_H


#include "Natural.h"
#include "Integer.h"

class Fraction {
private:
    Integer up;
    Natural down;
public:
    // Конструкторы
    Fraction();
    Fraction(long long int up, unsigned long long int down);
    Fraction(Natural up, Natural down);
    Fraction(Integer up, Natural down);
    Fraction(Integer up, Integer down);

    // Операторы
    Fraction &operator=(const Fraction &other) noexcept;

    // Вывод в консоль
    void print();

    // Функции для рациональными числами
    Fraction simplify(); // Q-1 Гиршович Даниил
    bool isInteger(); // Q-2 Гиршович Даниил
    Fraction add(Fraction& other); // Q-5 ADD_QQ_Q Першин Артем
    Fraction sub(Fraction& other); // Q-6 SUB_QQ_Q Першин Артем
};


#endif //BIGNUM_ARITHMETIC_FRACTION_H
