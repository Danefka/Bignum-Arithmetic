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

Fraction &Fraction::operator=(const Fraction &other) noexcept {
    this->up = other.up;
    this->down = other.down;
    return *this;
}

void Fraction::print() {
    this->down.print();
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

