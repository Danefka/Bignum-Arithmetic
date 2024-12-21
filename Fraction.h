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
    Fraction operator+(const Fraction& other) const noexcept; //Q-5
    Fraction operator-(const Fraction& other) const noexcept; //Q-6
    Fraction operator*(const Fraction& other) const noexcept; //Q-7
    Fraction operator/(const Fraction& other) const; //Q-8

    // Вывод в консоль
    void print() const;
    void printToLine() const;


    //getters
    Integer numerator();
    Natural denominator();

    // Функции для рациональными числами
    Fraction simplify() const; // Q-1 Гиршович Даниил
    bool isInteger() const; // Q-2 Гиршович Даниил
    Integer toInteger() const; // Q-4 Тарасов Матвей
};


#endif //BIGNUM_ARITHMETIC_FRACTION_H