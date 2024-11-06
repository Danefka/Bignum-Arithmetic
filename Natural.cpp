//
// Created by Даниил Гиршович on 06.11.2024.
//

#include "Natural.h"

Natural::Natural(std::string number) {
    std::vector<int> digits;
    for (int i = 0; i < number.length(); ++i) {
        if ((number[i] >= '0') && (number[i] <= '9')) {
            digits.push_back(number[i] - '0');
        }
    }
    this->digits = digits;
}

Natural::Natural(unsigned long long int number) {
    std::vector<int> digits;
    while (number > 0) {
        digits.push_back(number % 10);
        number /= 10;
    }
    this->digits = digits;
}
