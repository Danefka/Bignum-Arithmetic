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
    Natural(std::vector<int> digits); // Created by Даниил Гиршович on 06.11.2024.
    Natural operator + (const Natural& other) const; // Created by Даниил Гиршович on 06.11.2024.
    Natural operator - (const Natural& counter) const; // Created by Даниил Гиршович on 06.11.2024.
    Natural operator = (const Natural& other) const; // Created by Максим Баринов on 06.11.2024.
};




#endif //BIGNUM_ARITHMETIC_NATURAL_H
