//
// Created by Даниил Гиршович on 06.11.2024.
//

#ifndef BIGNUM_ARITHMETIC_NATURAL_H
#define BIGNUM_ARITHMETIC_NATURAL_H

#include <vector>
#include "string"
#include <iostream>

class Natural {
private:
    std::vector<int> digits;

    //Приватный конструктор использующийся в методах;
    explicit Natural(std::vector<int> digits);

public:
    // Конструкторы
    Natural();
    explicit Natural(std::string number);
    explicit Natural(unsigned long long int number);


    // Длина числа
    unsigned long long int length() const;

    // Вывод в консоль
    void print() const;

    // Операторы
    Natural &operator=(const Natural &other) noexcept;
    bool operator==(const Natural& other) const noexcept;
    bool operator>(const Natural& other) const noexcept;
    bool operator<(const Natural& other) const noexcept;
    bool operator>=(const Natural& other) const noexcept;
    bool operator<=(const Natural& other) const noexcept;
    Natural operator+(const Natural& other) const noexcept;
    Natural operator-(const Natural& other) const noexcept;
    Natural operator*(const Natural& other) const noexcept; // N-8
    Natural operator/(const Natural& other) const ; // N-11
    Natural operator%(const Natural& other) const ; // N-12

    // Функции для натуральных чисел
    int compare(const Natural& other) const; // N-1 COM_NN_D
    bool isZero() const; // N-2 NZER_N_B
    void increment(); // N-3 ADD_1N_N
    Natural mulByDigit(int d) const; // N-6 MUL_ND_N
    Natural mulByTen(int pow) const; // N-7 MUL_Nk_N
    Natural subByMul(const Natural& other, int k) const; // N-9 SUB_NDN_N
    Natural divFirstDigit(const Natural& other) const; // N-10 DIV_NN_Dk
    Natural gcd(const Natural& other) const; // N-13 GCF_NN_N
    Natural lcm(const Natural& other) const; // N-14 LCM_NN_N
    void printToLine() const;
};


#endif //BIGNUM_ARITHMETIC_NATURAL_H
