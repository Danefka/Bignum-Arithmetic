//
// Created by Даниил Гиршович on 06.11.2024.
//

#include <iostream>
#include "Natural.h"

Natural::Natural(std::string number) {
    std::vector<int> digits;
    for (int i = number.length() - 1; i >= 0; i--) {  // копирование цифр из строки в динамический массив
        if ((number[i] >= '0') && (number[i] <= '9')) {
            digits.push_back(number[i] - '0');
        }
    }
    if (digits.back() == 0){ // проверка на наличие нулей перед числом
        while(digits.back() == 0){
            digits.pop_back();
        }
    }
    this->digits = digits;
}

Natural::Natural(unsigned long long int number) {
    std::vector<int> digits;
    while (number > 0) { // копирование цифр из числа в динамический массив
        digits.push_back(number % 10);
        number /= 10;
    }
    this->digits = digits;
}


Natural::Natural(std::vector<int> digits) {
    std::copy(digits.begin(), digits.end(), std::back_inserter(this->digits)); // копирование цифр из динамического массива в динамический массив
}


Natural& Natural::operator=(const Natural &other) noexcept {
    std::copy(other.digits.begin(), other.digits.end(), std::back_inserter(this->digits)); // копирование цифр из динамического массива в динамический массив
    return *this; //Создание нового
}

unsigned long long int Natural::length() {
    return this->digits.size();
}

void Natural::print() {
    for (const int x: this->digits)
        std::cout << x << ' ';
    std::cout << '\n';
}

