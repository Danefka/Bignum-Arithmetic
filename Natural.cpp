//
// Created by Даниил Гиршович on 06.11.2024.
//

#include "Natural.h"

Natural::Natural(std::vector<int> digits) {
    while (!digits.empty() && digits.back() == 0) {
        digits.pop_back();
    }
    std::copy(digits.begin(), digits.end(),
              std::back_inserter(this->digits)); // копирование цифр из динамического массива в динамический массив
}

Natural::Natural() = default; // конструктор по умолчанию

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

unsigned long long int Natural::length() const{
    return this->digits.size();
}



void Natural::print() const { // вывод числа
    if (this->length() == 0) std::cout << "0\n"; // проверка на ненужные нули
    else {
        for (auto it = this->digits.rbegin(); it != this->digits.rend(); it++) {
            std::cout << *it << "";
        }
        std::cout << "\n";
    }
}

Natural &Natural::operator=(const Natural &other) noexcept { // Оператор присваивания
    if (this != &other) {
        digits = other.digits;
    }
    return *this;
}

bool Natural::operator==(const Natural &other) const noexcept { // Опаратор сравнения
    Natural thisCopy = *this;
    if (thisCopy.compare(other) == 0) {
        return true;
    }
    return false;
}

bool Natural::operator>(const Natural &other) const noexcept { // оператор "больше"
    Natural thisCopy = *this;
    if (thisCopy.compare(other) == 2) {
        return true;
    }
    return false;
}

bool Natural::operator<(const Natural &other) const noexcept { // оператор "меньше"
    Natural thisCopy = *this;
    if (thisCopy.compare(other) == 1) {
        return true;
    }
    return false;
}

bool Natural::operator>=(const Natural &other) const noexcept {
    if (*this > other || *this == other) {
        return true;
    }
    return false;
}
bool Natural::operator<=(const Natural &other) const noexcept {
    if (*this < other || *this == other) {
        return true;
    }
    return false;
}

Natural Natural::operator+(const Natural& other) const noexcept{ // Оператор сложения
    std::vector<int> digits;
    int compare = this->compare(other);
    int overflow = 0;
    for (int i = 0; i < this->length() && i < other.length(); ++i) { // складываем цифры до тех пор, пока они не закончатся в меньшем
        digits.push_back((this->digits.at(i) + other.digits.at(i) + overflow) % 10);
        if (this->digits.at(i) + other.digits.at(i) + overflow > 9) { // проверяем на переполнение
            overflow = 1;
        } else {
            overflow = 0;
        }
    }

    int i = this->length() > other.length() ? other.length() : this->length(); // сравниваем два числа
    if (compare == 1) {
        for (int j = i; j < other.length(); ++j) {
            digits.push_back((other.digits.at(j) + overflow) % 10);
            if (other.digits.at(j) + overflow > 9) {
                overflow = 1;
            } else {
                overflow = 0;
            }
        }
    } else if (compare == 2) {
        for (int j = i; j < this->length(); ++j) {
            digits.push_back((this->digits.at(j) + overflow) % 10);
            if (this->digits.at(j) + overflow > 9) {
                overflow = 1;
            } else {
                overflow = 0;
            }
        }
    }
    if (overflow == 1) { // если после всех сложений остался перенос, добавляем его
        digits.push_back(overflow);
    }
    return Natural(digits);
}

Natural Natural::operator-(const Natural& other) const  noexcept{ // Оператор вычитания
    if (this->compare(other) == 1) {
        return Natural(0);
    }

    std::vector<int> digits;
    int overflow = 0;
    for (int i = 0; i < other.length(); i++) { // вычитаем цифры до тех пор, пока не закончатся цифры в меньшем числе
        digits.push_back((this->digits.at(i) - overflow - other.digits.at(i) + 10) % 10);
        if (this->digits.at(i) - overflow - other.digits.at(i) < 0) {
            overflow = 1;
        } else {
            overflow = 0;
        }
    }
    if (overflow == 1) { // если есть перенос, обрабатываем оставшиеся цифры большего числа
        for (int i = other.length(); i < this->length(); i++) {
            digits.push_back((this->digits.at(i) - overflow + 10) % 10);
            if (this->digits.at(i) - overflow < 0) {
                overflow = 1;
            } else {
                overflow = 0;
            }
        }
    } else {
        for (int i = other.length(); i < this->length(); i++) {
            digits.push_back(this->digits.at(i));
        }
    }

    return Natural(digits);
}
Natural Natural::operator*(const Natural& other) const noexcept { // Оператор умножения
    Natural res = Natural(0);
    for (int i = 0; i < other.length(); i++) { // используем методы умножения на цифру и умножение на десятки
        Natural j = Natural(this->digits);
        j = j.mulByTen(i);
        j = j.mulByDigit(other.digits.at(i));
        res = res + j;
    }
    return res;
}

Natural Natural::operator/(const Natural& other) const { // Оператор деления
    if(other.isZero()){ // Проверка на ноль
        throw std::invalid_argument("Деление на 0 (Натуральные).");
    }
    Natural numerator = *this;
    Natural quotient(0);
    while (numerator >= other && !numerator.isZero()) { // пока изначальное число больше или равно делителя и не ноль
        quotient = quotient + numerator.divFirstDigit(other);
        numerator = numerator - numerator.divFirstDigit(other) * other;
    }
    return quotient;
}

Natural Natural::operator%(const Natural& other) const { // Оператор деления с остатком
    if(other.isZero()){ // проверка на ноль
        throw std::invalid_argument("Деление на 0 (Натуральные).");
    }
    if (!this->compare(other)) { // если наше число меньше другого, возвращаем его
        return Natural(0);
    }
    Natural numerator = *this;
    while (numerator > other) {
        numerator = numerator - numerator.divFirstDigit(other) * other;
    }
    return numerator;
}


int Natural::compare(const Natural& other) const{ // Метод сравнения
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

bool Natural::isZero() const{
    if (this->length() == 0) { // Проверка на ноль
        return true;
    }
    return false;
}

void Natural::increment(){ // Добавляем цифру
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


Natural Natural::mulByDigit(int d) const{ // Умножение на цифру
    int overflow = 0;
    int i = 0;
    int res;
    std::vector<int> digits;
    while (i < this->length()) { // перебераем цифры и умножаем их на число учитывая переполнение
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

Natural Natural::mulByTen(int pow) const{ // Умножение на 10 в степени pow
    std::vector<int> digits;
    while (pow > 0) { // записываем pow нулей
        digits.push_back(0);
        pow--;
    }
    for (int i = 0; i < this->length(); i++) {
        digits.push_back(this->digits.at(i)); // добавляем к ним наше число
    }
    return Natural(digits);
}

Natural Natural::subByMul(const Natural& other, int k) const{ // Вычитание числа умноженного на цифру
    Natural i = other.mulByDigit(k);
    return *this-i;
}


Natural Natural::divFirstDigit(const Natural& other) const{ // Деление с получением первой цифры частного
    unsigned long long pow = 1; // Степень в которую возводим делитель
    Natural numerator = *this; // Создаем копию текущего числа, которое будет делимым
    while (numerator >= other.mulByTen(pow)) { // Определяем максимальную степень, в которую нужно возвести делитель, чтобы получить число, меньшее или равное делимому
        pow++;
    }
    Natural denominator = other.mulByTen(pow - 1); // Делитель, умноженный на 10 в степени (pow - 1)
    short k = 0; // переменная хранящая полученную цифру
    while (numerator >= denominator) {
        k++;
        numerator = numerator - denominator;
    }
    return Natural(k).mulByTen(pow - 1);
}




Natural Natural::gcd(const Natural& other) const{ // НОД
    Natural first = *this;
    Natural second = other;
    while (!second.isZero()) { // по алгоритму Евклида
        Natural j = second;
        second = first % second;
        first = j;
    }
    return first;
}

Natural Natural::lcm(const Natural& other) const{ // НОК
    Natural gcd = this->gcd(other);
    return (*this*other) / gcd;
}

void Natural::printToLine() const{ // Вывод одного числа в строку
    if (this->length() == 0) std::cout << "0";
    else {
        for (auto it = this->digits.rbegin(); it != this->digits.rend(); it++) {
            std::cout << *it << "";
        }
        std::cout << "";
    }
}
