//
// Created by Даниил Гиршович on 06.11.2024.
//

#ifndef BIGNUM_ARITHMETIC_NATURAL_H
#define BIGNUM_ARITHMETIC_NATURAL_H

#include <vector>
#include "string"

class Natural {
private:
    std::vector<int> digits;
public:
    Natural(std::string number); // Created by Даниил Гиршович on 06.11.2024.
    Natural(unsigned long long int number); // Created by Даниил Гиршович on 06.11.2024.
};




#endif //BIGNUM_ARITHMETIC_NATURAL_H
