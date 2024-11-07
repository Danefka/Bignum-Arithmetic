//
// Created by Даниил Гиршович on 07.11.2024.
//

#ifndef BIGNUM_ARITHMETIC_INTEGER_H
#define BIGNUM_ARITHMETIC_INTEGER_H



#include "string"
#include "Natural.h"


class Integer{
private:
    bool sign;
    Natural number;
public:
    Integer(std::string number);
    explicit Integer(long long int number);

};


#endif //BIGNUM_ARITHMETIC_INTEGER_H
