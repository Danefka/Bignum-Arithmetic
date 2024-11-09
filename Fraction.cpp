//
// Created by Даниил Гиршович on 07.11.2024.
//

#include "Fraction.h"

Fraction::Fraction() = default;

Fraction::Fraction(long long int up, unsigned long long int down) {
    this->up = Integer(up);
    this->down = Natural(down);
}

Fraction::Fraction(Natural up, Natural down) {
    this->up = up;
    this->down = down;
}

Fraction::Fraction(Integer up, Natural down) {
    this->up = up;
    this->down = down;
}

Fraction::Fraction(Integer up, Integer down) {
    this->up = Integer(up.isPoz() == down.isPoz(), down.abs());
    this->down = down.abs();
}

Fraction::Fraction(Integer integer) {
    this->up = integer;
    this->down = Natural(1);
}

Fraction &Fraction::operator=(const Fraction &other) noexcept {
    this->up = other.up;
    this->down = other.down;
    return *this;
}

bool Fraction::operator==(const Fraction &other) const noexcept {
    return this->up == other.up && this->down == other.down;
}

bool Fraction::operator>(const Fraction &other) const noexcept {
    Fraction thisCopy = *this;
    Fraction otherCopy = other;
    return (thisCopy - otherCopy).up.isPoz() && !((thisCopy - otherCopy).up.isZero());
}

Fraction Fraction::operator+(const Fraction &other) const noexcept {
    Fraction thisCopy = *this;
    Fraction otherCopy = other;
    Natural resDown = thisCopy.down * otherCopy.down;
    Integer resUp = thisCopy.up * otherCopy.down + otherCopy.up * thisCopy.down;
    return Fraction(resUp, resDown).simplify();
}

Fraction Fraction::operator-(const Fraction &other) const noexcept {
    Fraction thisCopy = *this;
    Fraction otherCopy = Fraction(other.up.changeSign(), other.down);
    Natural resDown = thisCopy.down * otherCopy.down;
    Integer resUp = thisCopy.up * otherCopy.down + otherCopy.up * thisCopy.down;
    return Fraction(resUp, resDown).simplify();
}

Fraction Fraction::operator*(const Fraction &other) const noexcept {
    Natural resDown = this->down * other.down;
    Integer resUp = this->up * other.up;
    return  Fraction(resUp, resDown).simplify();
}

Fraction Fraction::operator/(const Fraction &other) const noexcept {
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

void Fraction::print() const{
    this->up.print();
    for (int i = down.length() > up.abs().length() ? down.length() : up.abs().length(); i > 0; i--) {
        std::cout << "-";
    }
    std::cout << "\n";
    this->down.print();
}

Fraction Fraction::simplify() const{
    Fraction res;
    Natural gcd;
    gcd = this->up.abs().gcd(this->down);
    res.up = up / gcd;
    res.down = this->down / gcd;
    return res;
}

bool Fraction::isInteger() const{
    Natural one = Natural(1);
    if (!this->simplify().down.compare(one)) {
        return true;
    }
    return false;
}




Integer Fraction::toInteger() const{
    return this->up;
}

bool Fraction::operator<(const Fraction &other) const noexcept {
    return !this->operator==(other) && !this->operator>(other);
}

void Fraction::printToLine() const{
    this->up.printToLine();
    std::cout << "/";
    this->down.printToLine();
}



