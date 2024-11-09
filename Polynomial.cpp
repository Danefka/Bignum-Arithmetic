//
// Created by Даниил Гиршович on 08.11.2024.
//

#include "Polynomial.h"

Polynomial::Polynomial() = default;

Polynomial::Polynomial(std::vector<Fraction> fractions, std::vector<Integer> integers) {
    if (fractions.size() != integers.size()) {
        std::cout << "Количество коэффицентов не равно количеству X";
        exit(40);
    }
    for (int i = 0; i < fractions.size(); ++i) {
        Integer key = integers.at(i);
        if (x.count(key) != 1) {
            x.insert(std::make_pair(key, fractions.at(i)));
            continue;
        }
        x[key] = x.at(key)+fractions.at(i);
    }
}

void Polynomial::print() {
    unsigned long long i = 0;
    for (auto pair = x.rbegin(); pair != x.rend(); pair++) {
        Integer pow = pair->first;
        pair->second.printToLine();
        std::cout << " * X^";
        pow.printToLine();
        i++;
        if (i == x.size()) {
            std::cout << "\n";
            return;
        }
        std::cout << " + ";
    }
}

Polynomial Polynomial::add(Polynomial other) {
    Polynomial res = *this;
    for (auto &&pair: other.x) {

        if (res.x.count(pair.first) != 1) {
            res.x.insert(std::make_pair(pair.first, pair.second));
            continue;
        }
        res.x[pair.first] = res.x.at(pair.first)+pair.second;
    }
    return res;
}

Polynomial &Polynomial::operator=(const Polynomial &other) noexcept {
    this->x = other.x;
    return *this;
}

Polynomial Polynomial::sub(Polynomial other) {
    Polynomial res = *this;
    for (auto &&pair: other.x) {
        if (res.x.count(pair.first) != 1) {
            Fraction minusOne = Fraction(Integer(-1));
            res.x.insert(std::make_pair(pair.first, pair.second*minusOne));
            continue;
        }
        res.x[pair.first] = res.x.at(pair.first) - pair.second;
    }
    return res;
}

Polynomial Polynomial::mulByFrac(Fraction other) {
    Polynomial res = *this;
    for (auto &&pair: res.x) {
        if (res.x.count(pair.first) != 1) {
            res.x.insert(std::make_pair(pair.first, pair.second*other));
            continue;
        }
        res.x[pair.first] = res.x.at(pair.first) * other;
    }
    return res;
}

Polynomial Polynomial::mulByX(Natural pow) {
    Polynomial res;
    for (auto &&pair: res.x) {
        Integer integer = pair.first;
        res.x.insert(std::make_pair(integer + pow, pair.second));
    }
    return res;
}

Integer Polynomial::degree() {
    return x.begin()->first;
}

Fraction Polynomial::coefficient() {
    return x.rbegin()->second;
}

Polynomial Polynomial::derivative() {
    Polynomial res;
    Integer one = Integer(1);
    for (auto &&pair: this->x) {
        Integer integer = pair.first;
        if (!integer.isZero()) {
            res.x.insert(std::make_pair(integer - one, pair.second*integer));
        }
    }
    return res;
}

