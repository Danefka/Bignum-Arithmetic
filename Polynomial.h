//
// Created by Даниил Гиршович on 08.11.2024.
//

#ifndef BIGNUM_ARITHMETIC_POLYNOMIAL_H
#define BIGNUM_ARITHMETIC_POLYNOMIAL_H


#include <map>
#include "Fraction.h"

class Polynomial {
private:
    std::map<Integer,Fraction> x;
public:
    // Конструкторы
    Polynomial(); // Гиршович Даниил
    Polynomial(std::vector<Fraction> fractions, std::vector<Integer> integers); // Гиршович Даниил

    // Вывод в консоль
    void print(); // Гиршович Даниил

    Polynomial &operator=(const Polynomial &other) noexcept; // Гиршович Даниил


    // Функции для работы с многочленами
    Polynomial add(Polynomial other); // P-1 Гиршович Даниил
    Polynomial sub(Polynomial other); // P-2 Гиршович Даниил
    Polynomial mulByFrac(Fraction fraction); // P-3 Гиршович Даниил
    Polynomial mulByX(Natural pow);  // P-4 Гиршович Даниил
    Fraction coefficient(); // P-5 Гиршович Даниил
    Integer degree(); // P-6 Гиршович Даниил

};


#endif //BIGNUM_ARITHMETIC_POLYNOMIAL_H
