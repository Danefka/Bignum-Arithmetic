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
    Polynomial();
    Polynomial(std::vector<Fraction> fractions, std::vector<Integer> integers);
    Polynomial(Fraction fractions[], Integer integers[]);
};


#endif //BIGNUM_ARITHMETIC_POLYNOMIAL_H
