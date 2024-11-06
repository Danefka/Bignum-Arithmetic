//
// Created by Даниил Гиршович on 06.11.2024.
//

#include "Natural.h"

Natural::Natural(std::string number) {
    std::vector<int> digits;
    for (int i = number.length() - 1; i >= 0; i--) {
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

Natural::Natural(std::vector<int> digits) {
    std::copy(digits.begin(), digits.end(), std::back_inserter(this->digits));
}

Natural Natural::operator+(const Natural &other) const {
    std::vector<int> digits;
    int overflow = 0;
    for (int i = 0; i < this->digits.size() && other.digits.size(); ++i) {
        int digit = other.digits.at(i) + this->digits.at(i) + overflow;
        if(digit> 9){
            overflow = 1;
            digit%=10;
        } else{
            overflow = 0;
        }
        digits.push_back(digit);
    }

    if (overflow == 1){
        digits.push_back(1);
    }

    return Natural(digits);
}
Natural Natural::operator=(const Natural &other) const {
    return Natural(other.digits);
}