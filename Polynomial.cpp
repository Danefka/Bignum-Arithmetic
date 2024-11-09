//
// Created by Даниил Гиршович on 08.11.2024.
//

#include "Polynomial.h"

Polynomial::Polynomial() = default;

Polynomial::Polynomial(std::vector<Fraction> fractions, std::vector<Natural> naturals) {
    if (fractions.size() != naturals.size()) {
        std::cout << "Количество коэффицентов не равно количеству X";
        exit(40);
    }
    for (int i = 0; i < fractions.size(); ++i) {
        Natural key = naturals.at(i);
        if (x.count(key) != 1) {
            x.insert(std::make_pair(key, fractions.at(i)));
            continue;
        }
        x[key] = x.at(key) + (fractions.at(i));
    }
}

void Polynomial::print() {
    this->clean();
    if(x.empty()){
        Natural(0).print();
    }
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
    for (auto && pair : other.x){

        if (res.x.count(pair.first) != 1) {
            res.x.insert(std::make_pair(pair.first, pair.second));
            continue;
        }
        res.x[pair.first] = res.x.at(pair.first)+ pair.second;
    }
    return res;
}

Polynomial &Polynomial::operator=(const Polynomial &other) noexcept {
    this->x = other.x;
    return *this;
}

Polynomial Polynomial::sub(Polynomial other) {
    Polynomial res = *this;
    for (auto && pair : other.x){
        if (res.x.count(pair.first) != 1) {
            Fraction minusOne = Fraction(Integer(-1));
            res.x.insert(std::make_pair(pair.first, pair.second * minusOne));
            continue;
        }
        res.x[pair.first] = res.x.at(pair.first) - pair.second;
    }
    return res;
}

Polynomial Polynomial::mulByFrac(Fraction other) {
    Polynomial res = *this;
    for (auto && pair : res.x){
        if (res.x.count(pair.first) != 1) {
            res.x.insert(std::make_pair(pair.first, pair.second * other));
            continue;
        }
        res.x[pair.first] = res.x.at(pair.first) * other;
    }
    return res;
}

Polynomial Polynomial::mulByX(Natural pow) {
    Polynomial res;
    for (auto pair : this->x){
        Natural natural = pair.first;
        res.x.insert(std::make_pair(natural + pow, pair.second));
    }
    return res;
}

Natural Polynomial::degree() {
    this->clean();
    if(x.empty()){
        return Natural(0);
    }
    return x.rbegin()->first;
}

Fraction Polynomial::coefficient() {
    if(x.empty()){
        return Fraction(0);
    }
    return x.rbegin()->second;
}

Polynomial Polynomial::derivative() {
    Polynomial res;
    Natural one = Natural(1);
    for (auto &&pair: this->x) {
        Natural natural = pair.first;
        if (!natural.isZero()) {
            res.x.insert(std::make_pair(natural - one, pair.second * Fraction(natural)));
        }
    }
    return res;
}

Fraction Polynomial::fac() {
    Natural LCM(1);
    Natural GCD = this->coefficient().numerator().abs();
    for(auto i : x){
        GCD = GCD.gcd(i.second.numerator().abs());
        LCM = LCM.lcm(i.second.denominator());
    }
    Fraction res(GCD, LCM);
    return res;
}

Polynomial Polynomial::mul(Polynomial& other) {
    Polynomial res;
    Fraction Coef;
    Fraction cur;
    Natural newDegree = this->degree() + other.degree() + Natural(1);
    for(Natural i(0); newDegree > i; i.increment()){
        Coef = Fraction(0);
        for(Natural j(0); i + Natural(1) > j; j.increment()){
            if(this->x.count(j) != 0 && other.x.count((i-j)) != 0){
                cur = this->x[j] * other.x[i - j];
                Coef = Coef + cur;
            }
        }
        res.x.insert(std::make_pair(i,Coef));
    }
    return res;
}

Polynomial Polynomial::div(Polynomial &other) {
    Polynomial copy = *this;
    Polynomial res;
    Polynomial w;
    Fraction Coef;
    while(copy.degree() >= other.degree() && !copy.isZero()){
        Coef = copy.coefficient() / other.coefficient();
        res.x.insert(std::make_pair((copy.degree() - other.degree()),Coef));
        w = other.mulByX(copy.degree() - other.degree()).mulByFrac(Coef);
        copy = copy.sub(w);
    }
    return res;
}

Polynomial Polynomial::mod(Polynomial& other) {
    Polynomial res = *this;
    Fraction Coef;
    Polynomial w;
    while(res.degree() >= other.degree() && !res.isZero()){
        Coef = res.coefficient() / other.coefficient();
        w = other.mulByX(res.degree() - other.degree()).mulByFrac(Coef);
        res = res.sub(w);
    }
    return res;
}

Polynomial Polynomial::gcd(Polynomial &other) {
    Polynomial first = *this;
    Polynomial second = other;
    while(!second.isZero()){
        Polynomial temp = second;
        second = first.mod(second);
        first = temp;
    }
    return first;
}

bool Polynomial::isZero() {
    this->clean();
    return x.empty();
}

void Polynomial::clean() {
    if(x.empty()){
        return;
    }
    while(x.rbegin()->second.numerator() == 0){
        x.erase(x.rbegin()->first);
        if(x.empty()){
            return;
        }
    }
}
