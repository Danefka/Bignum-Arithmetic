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
    // Конструкторы
    explicit Natural(std::string number); // Даниил Гиршович
    explicit Natural(unsigned long long int number); // Даниил Гиршович
    explicit Natural(std::vector<int> digits); // Даниил Гиршович

    // Длина числа
    unsigned long long int length(); // Даниил Гиршович

    // Вывод в консоль
    void print(); // Даниил Гиршович

    Natural& operator = (const Natural& other) noexcept; // Максим Баринов

    // Функции для натуральных чисел
    int compare(Natural other); // COM_NN_D Даниил Гиршович

    void increment(); //ADD_1N_N
  
    bool compareToZero(); // NZER_N_B Даниил Гиршович

    Natural mpByDigit(int d);
};




#endif //BIGNUM_ARITHMETIC_NATURAL_H
