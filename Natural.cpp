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
    if (digits.back() == 0) { // проверка на наличие нулей перед числом
        while (digits.back() == 0) {
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
    std::copy(digits.begin(), digits.end(),
              std::back_inserter(this->digits)); // копирование цифр из динамического массива в динамический массив
}


Natural &Natural::operator=(const Natural &other) noexcept {
    std::copy(other.digits.begin(), other.digits.end(),
              std::back_inserter(this->digits)); // копирование цифр из динамического массива в динамический массив
    return *this; //Создание нового
}

unsigned long long int Natural::length() {
    return this->digits.size();
}

void Natural::print() {
    if (this->length() == 0) std::cout << "0\n";
    else {
        for (auto it = this->digits.rbegin(); it != this->digits.rend(); it++) {
            std::cout << *it << "";
        }
        std::cout << "\n";
    }
}

int Natural::compare(Natural other) {
    if (other.length() != this->length()) {
        return other.length() > this->length() ? 1 : 2; // сравнение длин и возвращение большей, если они не равны
    }
    for (int i = this->length() - 1; i >= 0; i--) { // если равны то сравнение по цифрам
        if (other.digits.at(i) != this->digits.at(i)) {
            return other.digits.at(i) > this->digits.at(i) ? 1 : 2;
        }
    }
    return 0; // Если все цифры чисел равны, то возвращаем 0
}

bool Natural::compareToZero() {
    if (this->length() == 1 && this->digits.at(0) == 0) { // Проверка на ноль
        return true;
    }
    return false;
}

void Natural::increment() {
    int i = 0;
    while (i < this->length() && this->digits[i] == 9) {
        this->digits[i] = 0;
        i++;
    }
    if (i == this->length()) {
        this->digits.push_back(1);
        return;
    }
    this->digits[i]++;
}

Natural Natural::add(Natural other) {
    std::vector<int> digits;
    int compare = this->compare(other);


    int overflow = 0;
    for (int i = 0; i < this->length() && i < other.length(); ++i) {
        digits.push_back((this->digits.at(i) + other.digits.at(i) + overflow) / 10);
        if (this->digits.at(i) + other.digits.at(i) + overflow > 9) {
            overflow = 1;
        } else {
            overflow = 0;
        }
    }

    int i = this->length() > other.length() ? other.length() : this->length();
    if (compare == 1) {
        for (int j = i; j < other.length(); ++j) {
            digits.push_back((other.digits.at(i) + overflow) / 10);
            if (other.digits.at(i) + overflow > 9) {
                overflow = 1;
            } else {
                overflow = 0;
            }
        }
    } else if (compare == 2) {
        for (int j = i; j < this->length(); ++j) {
            digits.push_back((this->digits.at(i) + overflow) / 10);
            if (this->digits.at(i) + overflow > 9) {
                overflow = 1;
            } else {
                overflow = 0;
            }
        }
    }
    if (overflow == 1) {
        digits.push_back(overflow);

    }
    return Natural(digits);
}


Natural Natural::mulByDigit(int d) {
    int overflow = 0;
    int i = 0;
    int res;
    std::vector<int> digits;
    while (i < this->length()) {
        res = this->digits[i] * d + overflow;
        digits.push_back(res % 10);
        overflow = res / 10;
        i++;
    }
    if (overflow == 0) {
        return Natural(digits);
    }
    digits.push_back(overflow);
    return Natural(digits);
}

Natural Natural::sub(Natural other) {
    if (this->compare(other) == 1) {
        return Natural(0);
    }

    std::vector<int> digits;
    int overflow = 0;
    for (int i = 0; i < this->length(); i++) {
        digits.push_back(this->digits.at(i) - overflow - other.digits.at(i) % 10);
        if (this->digits.at(i) - overflow - other.digits.at(i) < 0) {
            overflow = 1;
        } else {
            overflow = 0;
        }
    }

    return Natural(digits);
}

Natural Natural::mul(Natural other) {
    Natural res = Natural(0);
    for (int i = other.length() - 1; i > -1; i--) {
        Natural j = res;
        res = res.mulByTen(1);
        j = j.mulByDigit(other.digits.at(i));
        res = res.add(j);
    }
    return res;
}

Natural Natural::subByMul(Natural other, int k) {
    Natural i = other.mulByDigit(k);
    return this->sub(i);
}

Natural Natural::mulByTen(int pow) {
    std::vector<int> digits;
    while (pow > 0) {
        digits.push_back(0);
        pow--;
    }
    for (int i = 0; this->length(); i++) {
        digits.push_back(this->digits.at(i));
    }
    return Natural(digits);
}

Natural::Natural() = default;
