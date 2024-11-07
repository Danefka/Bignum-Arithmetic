//
// Created by Даниил Гиршович on 07.11.2024.
//

#include "Integer.h"
#include "Natural.h"

Integer::Integer(std::string number) {
    this->sign = true;
    if (!number.empty() && number.at(0) == '-') {
        this->sign = false;
        number = number.substr(1, number.length());
    }
    this->natural = Natural(number);

}

bool Integer::operator>(const Integer &other) noexcept {
    Natural copy = other.natural;
    if (this->natural.isZero() && copy.isZero()) {
        return false;
    }
    if (this->sign && !other.sign) {
        return true;
    }
    if (this->sign && other.sign) {
        return this->natural > other.natural;
    }
    return copy > this->natural;
}

Integer::Integer(long long int number) {
    this->sign = true;
    if (number < 0) {
        this->sign = false;
        number = number * (-1);
    }
    this->natural = Natural(number);
}

Integer::Integer(Natural number) {
    this->sign = true;
    this->natural = number;
}

void Integer::print() {
    if (!this->sign && !natural.isZero()) {
        std::cout << "-";
    }
    natural.print();
}

Integer::Integer() {}

Integer &Integer::operator=(const Integer &other) noexcept {
    this->sign = new bool(sign);
    this->natural = other.natural;
    return *this;
}

Integer &Integer::operator=(const Natural &other) noexcept {
    this->sign = true;
    this->natural = Natural(other);
    return *this;
}

bool Integer::isZero() {
    return this->natural.isZero();
}

Integer::Integer(bool sign, Natural natural) {
    this->sign = new bool(sign);
    this->natural = natural;
}

Natural Integer::abs() {
    return this->natural;
}


Integer Integer::add(Integer other) {
    Integer res;
    if (this->sign == other.sign) {
        res.sign = this->sign;
        res.natural = this->natural.add(other.natural);
    }
    if (this->natural > other.natural) {
        res.sign = this->sign;
        res.natural = this->natural.sub(other.natural);
    }
    res.sign = other.sign;
    res.natural = other.natural.sub(this->natural);
    return res;
}

bool Integer::isPoz() {
    return sign;
}

Integer Integer::sub(Integer other) {
    Integer res, integer;
    integer = other.changeSign();
    res = res.add(integer);
    return res;
}

Integer::Integer(Natural natural, bool sign) {
    this->sign = sign;
    this->natural = natural;
}

Integer Integer::mul(Integer other) {
    Integer res;
    res.sign = this->sign == other.sign;
    res.natural = this->natural.mul(other.natural);
    return res;
}

Integer Integer::changeSign() {
    Integer integer(this->natural, !this->sign);
    return integer;
}

Integer Integer::div(Integer other) {
    Integer res;
    res.sign = this->sign == other.sign;
    res.natural = this->natural.divQuotient(other.natural);
    if (res.mul(other) > *this) {
        Integer i;
        i.natural = Natural(1);
        res = res.add(i);
    }
    return res;
}

Integer Integer::mod(Integer other) {
    Integer res = *this;
    Integer integer = *this;
    integer = integer.div(other);
    integer = integer.mul(other);
    res = res.sub(integer);
    return res;
}

Integer::Integer(const Integer &integer) {
    this->sign= new bool (sign);
    this->natural = integer.natural;
}
