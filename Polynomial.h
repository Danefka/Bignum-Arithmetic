//
// Created by Даниил Гиршович on 08.11.2024.
//

#ifndef BIGNUM_ARITHMETIC_POLYNOMIAL_H
#define BIGNUM_ARITHMETIC_POLYNOMIAL_H


#include <map>
#include "Fraction.h"

class Polynomial {
private:
    std::map<Natural,Fraction> x;
public:
    // Конструкторы
    Polynomial(); // Гиршович Даниил
    Polynomial(std::vector<Fraction> fractions, std::vector<Natural> naturals); // Гиршович Даниил

    // Вывод в консоль
    void print() const; // Гиршович Даниил

    // Операторы
    Polynomial &operator=(const Polynomial &other) noexcept; // Гиршович Даниил
    bool operator==(const Polynomial& other) noexcept;

    Polynomial operator+(const Polynomial& other) const noexcept; // P-1 Гиршович Даниил
    Polynomial operator-(const Polynomial& other) const noexcept; // P-2 Гиршович Даниил
    Polynomial operator*(const Polynomial& other) const noexcept; // P-8 MUL_PP_P Першин Артем
    Polynomial operator/(const Polynomial& other) const noexcept; // P-9 DIV_PP_P Першин Артем
    Polynomial operator%(const Polynomial& other) const noexcept; // P-10 MOD_PP_P Першин Артем


    // Функции для работы с многочленами
    Polynomial clean(); // Уничтожение нулей
    bool isZero();

    Polynomial mulByFrac(Fraction fraction); // P-3 Гиршович Даниил
    Polynomial mulByX(Natural pow) const; // P-4 Гиршович Даниил
    Fraction coefficient() const; // P-5 Гиршович Даниил
    Natural degree() const; // P-6 Гиршович Даниил
    Fraction fac(); // P-7 FAC_P_Q Першин Артем
    Polynomial gcd(Polynomial& other); // P-11 GCF_PP_P Першин Артем
    Polynomial derivative(); // P-12 Гиршович Даниил
    Polynomial nmr(); // P-13 Першин Артем
};


#endif //BIGNUM_ARITHMETIC_POLYNOMIAL_H
