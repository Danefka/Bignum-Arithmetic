//
// Created by Артем on 09.11.2024.

#include "Natural.h"
#include "Integer.h"
#include "Fraction.h"
#include "Polynomial.h"
#include <iostream>

int main(){
    Fraction a1(1);
    Fraction b1(1);
    Fraction c1(-2);
    Fraction a2(1);
    Fraction b2(2);
    Fraction a3(1);
    Fraction b3(-1);
    std::vector <Fraction> fractions1 = {a1, b1, c1};
    std::vector <Fraction> fractions2 = {a2, b2};
    std::vector <Fraction> fractions3 = {a3, b3};
    std::vector <Natural> naturals1 = {Natural(2),Natural(1),Natural(0)};
    std::vector <Natural> naturals2 = {Natural(1),Natural(0)};
    std::vector <Natural> naturals3 = {Natural(0)};
    Polynomial p1(fractions1, naturals1);
    Polynomial p2(fractions2, naturals2);
    Polynomial p3(fractions3, naturals2);
    Polynomial w1 = p1.derivative();
    w1.print();
    Polynomial w2 = w1.derivative();
    w2.print();
    return 0;
}