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
    Integer();
    Integer(const Integer &integer);
    Integer(Natural number);  // Z-4
    Integer(Natural natural, bool sign); // Z-4
    Integer(bool sign,Natural number);  // Z-4
    Integer(std::string number);
    Integer(long long int number);


    // Операторы
    Integer &operator=(const Integer &other) noexcept;
    Integer &operator=(const Natural &other) noexcept;
    bool operator>(const Integer& other) const noexcept;
    bool operator<(const Integer& other) const noexcept;
    bool operator==(const Integer& other) const noexcept;
    Integer operator+(const Integer& other) const noexcept; //Z-6
    Integer operator-(const Integer& other) const noexcept; //Z-7
    Integer operator*(const Integer& other) const noexcept; //Z-8
    Integer operator/(const Integer& other) const noexcept; //Z-9
    Integer operator%(const Integer& other) const noexcept; //Z-10

    // Вывод в консоль
    void print() const;

    // Функции для целых чисел
    Natural abs() const; // Z-1
    bool isZero() const; // Z-2
    bool isPoz() const; // Z-2
    Integer changeSign() const;// Z-3
    Natural toNatural() const; // Z-5

    void printToLine();
};


#endif //BIGNUM_ARITHMETIC_INTEGER_H
