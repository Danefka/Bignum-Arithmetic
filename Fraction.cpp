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

void Fraction::print() {
    this->up.print();
    for (int i = down.length() > up.abs().length() ? down.length() : up.abs().length(); i > 0; i--) {
        std::cout << "-";
    }
    std::cout << "\n";
    this->down.print();
}

Fraction Fraction::simplify() {
    Fraction res;
    Natural gcd;
    gcd = this->up.abs().gcd(this->down);
    res.up = up.div(gcd);
    res.down = this->down.divQuotient(gcd);
    return res;
}

bool Fraction::isInteger() {
    Natural one = Natural(1);
    if (!this->simplify().down.compare(one)) {
        return true;
    }
    return false;
}

Fraction Fraction::add(Fraction &other) {
    Natural resDown = this->down.mul(other.down);
    Integer resUp = this->up.mul(other.down).add(other.up.mul(this->down));
    return {resUp,resDown};
}

Fraction Fraction::sub(Fraction &other) {
    Natural resDown = this->down.mul(other.down);
    Integer resUp = this->up.mul(other.down).sub(other.up.mul(this->down));
    return {resUp,resDown};
}

Fraction Fraction::div(Fraction& other) {
    Fraction res;
    if(other.up.isPoz()){
        res.down = this->down.mul(other.up.abs());
        res.up = this->up.mul(other.down);
        return res;
    }
    res.down = this->down.mul(other.up.abs());
    res.up = this->up.mul(other.down).changeSign();
    return res;
}

Fraction Fraction::mul(Fraction& other) {
    Fraction res;
    res.down = this->down.mul(other.down);
    res.up = this->up.mul(other.up);
    return res;
}

Integer Fraction::toInteg() {
    return this->up;
}