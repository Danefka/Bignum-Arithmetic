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
    void print(); // Гиршович Даниил

    Polynomial &operator=(const Polynomial &other) noexcept; // Гиршович Даниил


    // Функции для работы с многочленами
    void clean(); // Уничтожение нулей
    bool isZero();
    Polynomial add(Polynomial other); // P-1 Гиршович Даниил
    Polynomial sub(Polynomial other); // P-2 Гиршович Даниил
    Polynomial mulByFrac(Fraction fraction); // P-3 Гиршович Даниил
    Polynomial mulByX(Natural pow);  // P-4 Гиршович Даниил
    Fraction coefficient(); // P-5 Гиршович Даниил
    Natural degree(); // P-6 Гиршович Даниил
    Fraction fac(); // P-7 FAC_P_Q Першин Артем
    Polynomial mul(Polynomial& other); // P-8 MUL_PP_P Першин Артем
    Polynomial div(Polynomial& other); // P-9 DIV_PP_P Першин Артем
    Polynomial mod(Polynomial& other); // P-10 MOD_PP_P Першин Артем
    Polynomial gcd(Polynomial& other); // P-11 GCF_PP_P Першин Артем
    Integer degree(); // P-6 Гиршович Даниил
    Polynomial derivative(); // P-12 Гиршович Даниил

};


#endif //BIGNUM_ARITHMETIC_POLYNOMIAL_H
