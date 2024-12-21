//
// Created by Даниил Гиршович on 16.11.2024.
//

#ifndef BIGNUM_V2_0_NATURAL_H
#define BIGNUM_V2_0_NATURAL_H


#include <vector>
#include "string"
#include "iostream"
#include "cmath"

class Natural {
private:

    std::vector<int> digits;
    void removeLeadingZeros();
public:
    Natural(std::string str);
    Natural();
    Natural(unsigned  long long int);
    Natural& operator=(const Natural& other) noexcept;
    bool operator==(const Natural& other) const noexcept;
    bool operator>(const Natural& other) const noexcept;
    bool operator<(const Natural& other) const noexcept;
    bool operator>=(const Natural& other) const noexcept;
    bool operator<=(const Natural& other) const noexcept;
    Natural operator+(const Natural& other) const noexcept;
    Natural operator-(const Natural& other) const noexcept;
    Natural operator*(const Natural& other) const noexcept; // N-8
    Natural operator/(const Natural& other) const; // N-11
    Natural operator%(const Natural& other) const ; // N-12

    void print() const;
    void printToLine() const;
    //function
    short compare(const Natural& other) const; // N-1 COM_NN_D
    unsigned long long int length() const;

    // Функции для натуральных чисел
    bool isZero() const;
    Natural increment();
    Natural mulByDigit(int d) const; // N-6 MUL_ND_N
    Natural mulByTen(int pow) const; // N-7 MUL_Nk_N
    Natural subByMul(const Natural& other, int k) const; // N-9 SUB_NDN_N
    Natural divFirstDigit(const Natural& other) const; // N-10 DIV_NN_Dk
    Natural gcd(const Natural& other) const; // N-13 GCF_NN_N
    Natural lcm(const Natural& other) const; // N-14 LCM_NN_N
};


#endif //BIGNUM_V2_0_NATURAL_H