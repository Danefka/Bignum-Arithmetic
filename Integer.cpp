//
// Created by Даниил Гиршович on 07.11.2024.
//

#include "Integer.h"
#include "Natural.h"

Integer::Integer() = default; // Конструктор по умолчанию

Integer::Integer(const Integer &integer) { // Конструктор копирования
    this->sign = integer.sign;
    this->natural = integer.natural;
}

Integer::Integer(Natural number) { // Конструктор натурального числа
    this->sign = true;
    this->natural = number;
}

Integer::Integer(Natural natural, bool sign) {
    this->sign = sign;
    this->natural = natural;
}

Integer::Integer(bool sign, Natural natural) {
    this->sign = sign;
    this->natural = natural;
}

Integer::Integer(std::string number) { // Конструктор со строкой
    this->sign = true;
    if (!number.empty() && number.at(0) == '-') {
        this->sign = false;
        number = number.substr(1, number.length());
    }
    this->natural = Natural(number);

}

Integer::Integer(long long int number) { // Конструктор с целым числом
    this->sign = true;
    if (number < 0) {
        this->sign = false;
        number = number * (-1);
    }
    this->natural = Natural(number);
}

Integer & Integer::operator=(const Integer &other) noexcept { // Оператор присваивания
    this->sign = other.sign;
    this->natural = other.natural;
    return *this;
}

Integer &Integer::operator=(const Natural &other)  noexcept { // Оператор присвания для натурального числа
    this->sign = true;
    this->natural = Natural(other);
    return *this;
}

bool Integer::operator>(const Integer &other) const noexcept { // Оператор сравнения "больше"
    Integer copyThis = *this;
    Integer copyOther = other;
    if (copyThis.isZero() && copyOther.isZero()) {
        return false;
    }
    if (this->sign == other.sign) { // проверка на знак
        if (this->sign) return this->natural > other.natural;
        else return !(this->natural > other.natural);
    }
    if (this->sign) {
        return true;
    }else {
        return false;
    }
}

bool Integer::operator<(const Integer &other) const noexcept { // Оператор сравнения "меньше"
    Integer copyThis = *this;
    Integer copyOther = other;
    if (copyThis.isZero() && copyOther.isZero()) {
        return false;
    }
    if (this->sign == other.sign) {
        if (this->sign) return this->natural < other.natural;
        else return !(this->natural < other.natural);
    }
    if (this->sign) {
        return false;
    }else {
        return true;
    }
}


bool Integer::operator==(const Integer &other) const noexcept {
    if(this->natural == Natural(0) && other.natural == Natural(0)){ // если оба числа равны нулю
        return true;
    }
    return this->sign == other.sign && this->natural == other.natural;
}

Integer Integer::operator+(const Integer& other) const noexcept { // Оператор сложения
    Integer res;
    if (this->sign == other.sign) { // если знаки одиковые
        res.sign = this->sign;
        res.natural = this->natural + other.natural;
        return res;
    }
    if (this->natural > other.natural) { // если модуль изначального числа больше другого
        res.sign = this->sign;
        res.natural = this->natural - other.natural;
        return res;
    }
    res.sign = other.sign;
    res.natural = other.natural - this->natural;
    return res;
}
Integer Integer::operator-(const Integer& other) const noexcept { // Оператор вычитания
    Integer a(other);
    return *this + a.changeSign();
}

Integer Integer::operator*(const Integer& other) const noexcept { // Оператор умножения
    Integer res;
    res.sign = this->sign == other.sign;
    res.natural = this->natural * other.natural;
    return res;
}

Integer Integer::operator/(const Integer &other) const { // Оператор деления
    if (other.isZero()) { // проверка на ноль
        throw std::invalid_argument("Деление на 0 (Целые).");
    }
    Integer res;
    res.sign = this->sign == other.sign;
    res.natural = this->natural / other.natural;
    return res;
}

Integer Integer::operator%(const Integer &other) const { // Оператор остатка от деления
    if (other.isZero()) {
        throw std::invalid_argument("Деление на 0 (Целые).");
    }
    Integer res = *this;
    Integer integer = *this;
    integer = integer / other;
    integer = integer * other;
    res = res - integer;
    while(res < Integer(0) && !res.isZero())  {
        res = res + other.abs();
    }
    return res;
}

void Integer::print() const{ // Вывод числа
    if (!this->sign && !natural.isZero()) {
        std::cout << "-";
    }
    natural.print();
}

Natural Integer::abs() const{ // Абсолютное значение числа
    return this->natural;
}

bool Integer::isZero() const{ // Проверка целого числа на ноль
    return this->natural.isZero();
}

bool Integer::isPoz() const{ // Проверка на положительность
    return sign;
}

Integer Integer::changeSign() const{ // Смена знака
    Integer integer(this->natural, !this->sign);
    return integer;
}

Natural Integer::toNatural() const{ // Преобразование целого в натуральное число
    return this->natural;
}




void Integer::printToLine() const{ // Вывод числа в строку
    if (!this->sign && !natural.isZero()) {
        std::cout << "-";
    }
    this->natural.printToLine();
}

