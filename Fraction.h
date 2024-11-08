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
    Fraction(Integer integer);

    // Операторы
    Fraction &operator=(const Fraction &other) noexcept;
    bool operator==(const Fraction& other) const noexcept;
    bool operator>(const Fraction& other) const noexcept;
    bool operator<(const Fraction& other) const noexcept;

    // Вывод в консоль
    void print();
    void printToLine();



    // Функции для рациональными числами
    Fraction simplify(); // Q-1 Гиршович Даниил
    bool isInteger(); // Q-2 Гиршович Даниил
    Integer toInteger(); // Q-4 Тарасов Матвей
    Fraction add(Fraction& other); // Q-5 ADD_QQ_Q Першин Артем
    Fraction sub(Fraction& other); // Q-6 SUB_QQ_Q Першин Артем
    Fraction mul(Fraction& other); // Q-7 MUL_QQ_Q Першин Артем
    Fraction div(Fraction& other); // Q-8 DIV_QQ_Q Першин Артем
};


#endif //BIGNUM_ARITHMETIC_FRACTION_H
