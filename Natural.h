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
    explicit Natural(std::vector<int> digits); // Даниил Гиршович
public:
    // Конструкторы
    explicit Natural(std::string number); // Даниил Гиршович
    explicit Natural(unsigned long long int number); // Даниил Гиршович

    // Длина числа
    unsigned long long int length(); // Даниил Гиршович

    // Вывод в консоль
    void print(); // Даниил Гиршович

    Natural& operator = (const Natural& other) noexcept; // Максим Баринов

    // Функции для натуральных чисел
    int compare(Natural other); // N-1 COM_NN_D Даниил Гиршович
    bool compareToZero(); // N-2 NZER_N_B Даниил Гиршович
    void increment(); // N-3 ADD_1N_N Артём Першин
    Natural sum(Natural other); // N-4 ADD_NN_N Даниил Гиршович
    Natural div(Natural other); // N-5 MUL_Nk_N Даниил Гиршович
    Natural mulByDigit(int d); // N-6 MUL_ND_N Артем Першин

};


#endif //BIGNUM_ARITHMETIC_NATURAL_H
