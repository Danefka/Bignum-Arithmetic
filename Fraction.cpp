//
// Created by Даниил Гиршович on 07.11.2024.
//

#include "Fraction.h"

Fraction::Fraction() = default; // Конструктор по умолчанию

Fraction::Fraction(long long int up, unsigned long long int down) { // Конструктор с целым и натуральным числами
    this->up = Integer(up);
    this->down = Natural(down);
}

Fraction::Fraction(Natural up, Natural down) { // Конструктор для натуральных чисел
    this->up = up;
    this->down = down;
}

Fraction::Fraction(Integer up, Natural down) { // Конструктор с целым и натуральным числами
    this->up = up;
    this->down = down;
}

Fraction::Fraction(Integer up, Integer down) { // Конструктор с двумя целыми числами
    this->up = Integer(up.isPoz() == down.isPoz(), down.abs());
    this->down = down.abs();
}

Fraction::Fraction(Integer integer) { // Конструктор с целым числом
    this->up = integer;
    this->down = Natural(1);
}

Fraction &Fraction::operator=(const Fraction &other) noexcept { // Оператор присваивания
    this->up = other.up;
    this->down = other.down;
    return *this;
}

bool Fraction::operator==(const Fraction &other) const noexcept { // Оператор "равно"
    return this->up == other.up && this->down == other.down;
}

bool Fraction::operator>(const Fraction &other) const noexcept { // Оператор "больше"
    Fraction thisCopy = *this;
    Fraction otherCopy = other;
    return (thisCopy - otherCopy).up.isPoz() && !((thisCopy - otherCopy).up.isZero());
}

Fraction Fraction::operator+(const Fraction &other) const noexcept { // Оператор сложения
    Fraction thisCopy = *this;
    Fraction otherCopy = other;
    Natural resDown = thisCopy.down * otherCopy.down;
    Integer resUp = thisCopy.up * otherCopy.down + otherCopy.up * thisCopy.down;
    return Fraction(resUp, resDown).simplify();
}

Fraction Fraction::operator-(const Fraction &other) const noexcept { // Оператор вычитания
    Fraction thisCopy = *this;
    Fraction otherCopy = Fraction(other.up.changeSign(), other.down);
    Natural resDown = thisCopy.down * otherCopy.down;
    Integer resUp = thisCopy.up * otherCopy.down + otherCopy.up * thisCopy.down;
    return Fraction(resUp, resDown).simplify();
}

Fraction Fraction::operator*(const Fraction &other) const noexcept { // Оператор умножения
    Natural resDown = this->down * other.down;
    Integer resUp = this->up * other.up;
    return  Fraction(resUp, resDown).simplify();
}

Fraction Fraction::operator/(const Fraction &other) const { // Оператор деления
    if(other.up == 0){ // Проверка числителя второй дроби на ноль
        throw std::invalid_argument("Деление на 0 (Рациональные).");
    }
    Fraction res;
    if (other.up.isPoz()) {
        Natural resDown = this->down * other.up.abs();
        Integer resUp = this->up * other.down;
        return Fraction(resUp, resDown).simplify();
    }
    Natural resDown = this->down * other.up.abs();
    Integer resUp = (this->up * other.down).changeSign();
    return  Fraction(resUp, resDown).simplify();
}

void Fraction::print() const{ // Вывод дроби
    this->up.print();
    for (int i = down.length() > up.abs().length() ? down.length() : up.abs().length(); i > 0; i--) {
        std::cout << "-";
    }
    std::cout << "\n";
    this->down.print();
}

Fraction Fraction::simplify() const{ // Упрощение дроби
    Fraction res;
    Natural gcd;
    gcd = this->up.abs().gcd(this->down); // делим чеслитель и знаменатель на их НОД
    res.up = up / gcd;
    res.down = this->down / gcd;
    return res;
}

bool Fraction::isInteger() const{ // Проверка на целое число
    Natural one = Natural(1);
    if (!this->simplify().down.compare(one)) { // Проверяет, является ли дробь целым числом, сравнивая знаменатель с 1 после упрощения
        return true;
    }
    return false;
}




Integer Fraction::toInteger() const{ // Преобразование в целое число
    return this->up;
}

bool Fraction::operator<(const Fraction &other) const noexcept { // Оператор "меньше"
    return !this->operator==(other) && !this->operator>(other);
}

void Fraction::printToLine() const{ // Вывод дроби в одну строку
    this->up.printToLine();
    std::cout << "/";
    this->down.printToLine();
}

Integer Fraction::numerator() { // Получение числителя
    return this->up;
}

Natural Fraction::denominator() { // Получение знаменателя
    return this->down;
}


