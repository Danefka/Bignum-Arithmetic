//
// Created by Даниил Гиршович on 08.11.2024.
//

#include "include/Polynomial.h"

Polynomial::Polynomial() = default; // Конструктор по умолчанию

Polynomial::Polynomial(std::vector<Fraction> fractions, std::vector<Natural> naturals) { // Конструктор с векторами коэффициентов и степеней
    if (fractions.size() != naturals.size()) { // Проверка размеров векторов
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

void Polynomial::print() const { // Вывод многочлена
    if(x.empty()){ // если многочлен пустой
        Natural(0).print();
        return;
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

Polynomial &Polynomial::operator=(const Polynomial &other) noexcept { // Оператор присваивания
    this->x = other.x;
    return *this;
}

Polynomial Polynomial::mulByFrac(Fraction other) { // Умножение многочлена на дробь
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

Polynomial Polynomial::mulByX(Natural pow) const { // Умножение многочлена на X в заданной степени
    Polynomial res;
    for (auto pair : this->x){
        Natural natural = pair.first;
        res.x.insert(std::make_pair(natural + pow, pair.second));
    }
    return res;
}

Natural Polynomial::degree() const { // Получение старшей степени многочлена
    if(x.empty()){
        return Natural(0);
    }
    return x.rbegin()->first;
}

Fraction Polynomial::coefficient() const { // Получение коэффициента при старшем члене
    if(x.empty()){
        return Fraction(0);
    }
    return x.rbegin()->second;
}

Polynomial Polynomial::derivative() { // Вычисление производной многочлена
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

Fraction Polynomial::fac() { // Вычисление факториала многочлена
    Natural LCM(1);
    Natural GCD = this->coefficient().numerator().abs();
    for(auto i : x){ // вычисляем при помощи НОДа числителя и НОКа знаменателя
        GCD = GCD.gcd(i.second.numerator().abs());
        LCM = LCM.lcm(i.second.denominator());
    }
    Fraction res(GCD, LCM);
    return res;
}

Polynomial Polynomial::gcd(Polynomial &other) { // Вычисление НОД двух многочленов
    Polynomial first = *this;
    Polynomial second = other;
    while(!second.isZero()){ // по алгоритму Евклида
        Polynomial temp = second;
        second = first % second;
        first = temp;
    }
    return first;
}

bool Polynomial::isZero() const { // Проверка на нулевой многочлен
    return x.empty();
}

Polynomial Polynomial::clean() { // Очистка многочлена от нулевых коэффициентов
    Polynomial res;
    if(x.empty()){
        return res;
    }
    for(auto pair:x){
        if(!pair.second.numerator().isZero()) {
            res.x[pair.first] = pair.second;
        }
    }
    return res;
}

bool Polynomial::operator==(const Polynomial &other) const noexcept { // Оператор "равно"
    return (*this - other).isZero();
}

Polynomial Polynomial::operator-(const Polynomial &other) const noexcept { // Оператор вычитания
    Polynomial res = *this;
    for (auto && pair : other.x){ // вычитаем многочлены из друг друга, обрабатывая члены с одинаковыми степенями
        if (res.x.count(pair.first) != 1) {
            Fraction minusOne = Fraction(Integer(-1));
            res.x.insert(std::make_pair(pair.first, pair.second * minusOne));
            continue;
        }
        res.x[pair.first] = res.x.at(pair.first) - pair.second;
    } // очищение от нулевых коэффициентов
    res = res.clean();
    return res;
}

Polynomial Polynomial::operator+(const Polynomial &other) const noexcept { // Оператор сложения
    Polynomial res = *this;
    for (auto && pair : other.x){ // Складывает два многочлена, обрабатывая члены с одинаковыми степенями
        if (res.x.count(pair.first) != 1) {
            res.x.insert(std::make_pair(pair.first, pair.second));
            continue;
        }
        res.x[pair.first] = res.x.at(pair.first)+ pair.second;
    }
    res = res.clean(); // Результат очищается от нулевых коэффициентов
    return res;
}

Polynomial Polynomial::nmr() {
    Polynomial derivative = this->derivative();
    Polynomial gcd = this->gcd(derivative);
    return (*this / gcd);
}

Polynomial Polynomial::operator*(const Polynomial &other) const noexcept { // Оператор умножения
    Polynomial res;
    Fraction Coef;
    Fraction cur;
    Natural newDegree = this->degree() + other.degree() + Natural(1);
    for(Natural i(0); newDegree > i; i.increment()){ // используя метод "умножения столбиком"
        Coef = Fraction(0);
        for(Natural j(0); i + Natural(1) > j; j.increment()){
            if(this->x.count(j) != 0 && other.x.count((i-j)) != 0){
                cur = this->x.at(j) * other.x.at(i-j);
                Coef = Coef + cur;
            }
        }
        res.x.insert(std::make_pair(i,Coef));
    }
    res = res.clean(); // Результат очищается от нулевых коэффициентов
    return res;
}

Polynomial Polynomial::operator/(const Polynomial &other) const { // Оператор деления
    if(other.isZero()){
        throw std::invalid_argument("Деление на 0 (Многочлены).");
    }
    Polynomial copy = *this;
    Polynomial res;
    Polynomial w;
    Fraction Coef;
    while(copy.degree() >= other.degree() && !copy.isZero()){ // используя метод "деления уголком"
        Coef = copy.coefficient() / other.coefficient();
        res.x.insert(std::make_pair((copy.degree() - other.degree()),Coef));
        w = other.mulByX(copy.degree() - other.degree()).mulByFrac(Coef);
        copy = copy - w;
    }
    return res;
}

Polynomial Polynomial::operator%(const Polynomial &other) const { // Оператор остатка от деления
    if(other.isZero()){ // проверка на ноль
        throw std::invalid_argument("Деление на 0 (Многочлены).");
    }
    Polynomial res = *this;
    Fraction Coef;
    Polynomial w;
    while(res.degree() >= other.degree() && !res.isZero()){ // используя метод "деления уголком"
        Coef = res.coefficient() / other.coefficient();
        w = other.mulByX(res.degree() - other.degree()).mulByFrac(Coef);
        res = res - w;
        res = res.clean();
    }
    return res;
}

