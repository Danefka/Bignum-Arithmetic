//
// Created by Даниил Гиршович on 07.11.2024.
//

#include "Fraction.h"

Fraction::Fraction() = default;

Fraction::Fraction(unsigned long long int up, long long int down) {
    this->up = Natural(up);
    this->down = Integer(down);
}

Fraction::Fraction(Natural up, Natural down) {
    this->up = up;
    this->down = down;
}

Fraction::Fraction(Natural up, Integer down) {
    this->up = up;
    this->down = down;
}

Fraction::Fraction(Integer up, Integer down) {
    this->up = up.abs();
    this->down = Integer(up.isPoz() == down.isPoz(), down.abs());
}

Fraction &Fraction::operator=(const Fraction &other) noexcept {
    this->up = other.up;
    this->down = other.down;
    return *this;
}

void Fraction::print() {
    this->up.print();
    for (int i = up.length() > down.abs().length() ? up.length() : down.abs().length(); i > 0; i--) {
        std::cout << "-";
    }
    std::cout << "\n";
    this->down.print();
}

Fraction Fraction::simplify() {
    Fraction res;
    Natural gcd;
    gcd = this->up.gcd(this->down.abs());
    res.up = up.divQuotient(gcd);
    res.down = this->down.div(gcd);
    return res;
}

bool Fraction::isInteger() {
    Natural one = Natural(1);
    if (!this->simplify().down.abs().compare(one)) {
        return true;
    }
    return false;
}


