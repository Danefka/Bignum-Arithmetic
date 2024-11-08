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
        x[key] = x.at(key).add(fractions.at(i));
    }
}

void Polynomial::print() {
    unsigned long long i = 0;
    for(auto pair = x.rbegin(); pair!=x.rend(); pair++){
        Integer pow = pair->first;
        pair->second.printToLine();
        std::cout << " * X^";
        pow.printToLine();
        i++;
        if(i == x.size()){ std::cout << "\n"; return;}
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
        res.x[pair.first] = res.x.at(pair.first).add(pair.second);
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
            res.x.insert(std::make_pair(pair.first, pair.second.mul(minusOne)));
            continue;
        }
        res.x[pair.first] = res.x.at(pair.first).sub(pair.second);
    }
    return res;
}

Polynomial Polynomial::mulByFrac(Fraction other) {
    Polynomial res = *this;
    for (auto && pair : res.x){
        if (res.x.count(pair.first) != 1) {
            res.x.insert(std::make_pair(pair.first, pair.second.mul(other)));
            continue;
        }
        res.x[pair.first] = res.x.at(pair.first).mul(other);
    }
    return res;
}

Polynomial Polynomial::mulByX(Natural pow) {
    Polynomial res;
    for (auto && pair : res.x){
        Integer integer = pair.first;
        res.x.insert(std::make_pair(integer.add(pow), pair.second));
    }
    return res;
}

Integer Polynomial::degree() {
    return x.begin()->first;
}

Fraction Polynomial::coefficient() {
    return x.rbegin()->second;
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
    for(Natural i(0); this->degree().add(other.degree()).add(Natural(1)) > i; i.increment()){
        Coef = Fraction(0);
        for(Natural j(0); i.add(Natural(1)) > j; j.increment()){
            cur = this->x[j].mul(other.x[i.sub(j)]);
            Coef.add(cur);
        }
        res.x[i] = Coef;
    }
    return res;
}

Polynomial Polynomial::div(Polynomial &other) {
    Polynomial copy = *this;
    Polynomial res;
    Fraction Coef;
    while(copy.degree() > other.degree()){
        Coef = copy.coefficient().div(other.coefficient());
        res.x[copy.degree().sub(other.degree())] = Coef;
        copy = copy.sub(other.mulByFrac(Coef).mulByX(copy.degree().sub(other.degree())));
    }
    return res;
}

