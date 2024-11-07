//
// Created by Даниил Гиршович on 06.11.2024.
//

#ifndef BIGNUM_ARITHMETIC_NATURAL_H
#define BIGNUM_ARITHMETIC_NATURAL_H

#include <vector>
#include "string"
#include "Integer.h"
#include <iostream>

class Natural {
private:
    std::vector<int> digits;

    //Приватный конструктор использующийся в методах;
    explicit Natural(std::vector<int> digits); // Даниил Гиршович
public:
    // Конструкторы
    Natural();
    explicit Natural(std::string number); // Даниил Гиршович
    explicit Natural(unsigned long long int number); // Даниил Гиршович


    // Длина числа
    unsigned long long int length(); // Даниил Гиршович

    // Вывод в консоль
    void print(); // Даниил Гиршович

    Natural &operator=(const Natural &other) noexcept; // Максим Баринов
    bool operator==(const Natural& other) noexcept;
    bool operator>(const Natural& other) noexcept;
    bool operator>=(const Natural& other) noexcept;
    Natural operator+(const Natural& other) noexcept;
    Natural operator-(const Natural& other) noexcept;
    Natural operator*(Natural& other) noexcept;
    Natural operator/(const Natural& other) noexcept;
    Natural operator%(const Natural& other) noexcept;


    // Функции для натуральных чисел
    int compare(Natural other); // N-1 COM_NN_D Даниил Гиршович
    bool compareToZero(); // N-2 NZER_N_B Даниил Гиршович
    void increment(); // N-3 ADD_1N_N Артём Першин
    Natural add(Natural other); // N-4 ADD_NN_N Даниил Гиршович
    Natural sub(Natural other); // N-5 MUL_Nk_N Даниил Гиршович
    Natural mulByDigit(int d); // N-6 MUL_ND_N Артём Першин
    Natural mulByTen(int pow); // N-7 MUL_Nk_N Матвей Тарасов
    Natural mul(Natural other); // N-8 MUL_NN_N Гиршович Даниил
    Natural subByMul(Natural other, int k); // N-9 SUB_NDN_N Гиршович Даниил
    Natural divDigit(const Natural& other); // N-10 DIV_NN_Dk Першин Артем
    Natural divQuotient(const Natural& other); // N-11 DIV_NN_N Першин Артем
    Natural divRemainder(const Natural& other); // N-12 MOD_NN_N Першин Артем
    Natural gcd(Natural& other); // N-13 GCF_NN_N Першин Артем
    Natural lcm(Natural& other); // N-14 LCM_NN_N Першин Артем
};


#endif //BIGNUM_ARITHMETIC_NATURAL_H
