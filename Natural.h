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
    explicit Natural(std::string number); // Даниил Гиршович
    explicit Natural(unsigned long long int number); // Даниил Гиршович
    explicit Natural(std::vector<int> digits); // Даниил Гиршович

    unsigned long long int length(); // Даниил Гиршович

    void print(); // Даниил Гиршович

    Natural& operator = (const Natural& other) noexcept; // Максим Баринов
};




#endif //BIGNUM_ARITHMETIC_NATURAL_H
