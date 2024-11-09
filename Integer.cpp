//
// Created by Даниил Гиршович on 07.11.2024.
//

#include "Integer.h"
#include "Natural.h"

Integer::Integer() = default;

Integer::Integer(const Integer &integer) {
    this->sign = integer.sign;
    this->natural = integer.natural;
}

Integer::Integer(Natural number) {
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

Integer::Integer(std::string number) {
    this->sign = true;
    if (!number.empty() && number.at(0) == '-') {
        this->sign = false;
        number = number.substr(1, number.length());
    }
    this->natural = Natural(number);

}

Integer::Integer(long long int number) {
    this->sign = true;
    if (number < 0) {
        this->sign = false;
        number = number * (-1);
    }
    this->natural = Natural(number);
}

Integer & Integer::operator=(const Integer &other) noexcept {
    this->sign = other.sign;
    this->natural = other.natural;
    return *this;
}

Integer &Integer::operator=(const Natural &other)  noexcept {
    this->sign = true;
    this->natural = Natural(other);
    return *this;
}

bool Integer::operator>(const Integer &other) const noexcept {
    Integer copyThis = *this;
    Integer copyOther = other;
    if (copyThis.isZero() && copyOther.isZero()) {
        return false;
    }
    if (this->sign == other.sign) {
        if (this->sign) return this->natural > other.natural;
        else return !(this->natural > other.natural);
    }
    if (this->sign) {
        return true;
    }else {
        return false;
    }
}

bool Integer::operator<(const Integer &other) const noexcept {
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
    return this->sign == other.sign && this->natural == other.natural;
}

Integer Integer::operator+(const Integer& other) const noexcept {
    Integer res;
    if (this->sign == other.sign) {
        res.sign = this->sign;
        res.natural = this->natural + other.natural;
        return res;
    }
    if (this->natural > other.natural) {
        res.sign = this->sign;
        res.natural = this->natural - other.natural;
        return res;
    }
    res.sign = other.sign;
    res.natural = other.natural - this->natural;
    return res;
}
Integer Integer::operator-(const Integer& other) const noexcept {
    Integer a(other);
    return *this + a.changeSign();
}

Integer Integer::operator*(const Integer& other) const noexcept {
    Integer res;
    res.sign = this->sign == other.sign;
    res.natural = this->natural * other.natural;
    return res;
}

Integer Integer::operator/(const Integer &other) const noexcept {
    Integer res;
    res.sign = this->sign == other.sign;
    res.natural = this->natural / other.natural;
    return res;
}

Integer Integer::operator%(const Integer &other) const noexcept {
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

void Integer::print() const{
    if (!this->sign && !natural.isZero()) {
        std::cout << "-";
    }
    natural.print();
}

Natural Integer::abs() const{
    return this->natural;
}

bool Integer::isZero() const{
    return this->natural.isZero();
}

bool Integer::isPoz() const{
    return sign;
}

Integer Integer::changeSign() const{
    Integer integer(this->natural, !this->sign);
    return integer;
}

Natural Integer::toNatural() const{ // ADD_ZZ_Z
    return this->natural;
}




void Integer::printToLine() {
    if (!this->sign && !natural.isZero()) {
        std::cout << "-";
    }
    this->natural.printToLine();
}

