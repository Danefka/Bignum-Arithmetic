//
// Created by Даниил Гиршович on 07.11.2024.
//

#include "Integer.h"
#include "Natural.h"

Integer::Integer(std::string number) {
    this->sign = true;
    if (!number.empty() && number.at(0) == '-'){
        this->sign = false;
        number = number.substr(1,number.length());
    }
    this->natural = Natural(number);

}

Integer::Integer(long long int number) {
    this->sign = true;
    if(number < 0){
        this->sign = false;
        number = number*(-1);
    }
    this->natural = Natural(number);
}

Integer::Integer(Natural number) {
    this->sign = true;
    this->natural = number;
}

void Integer::print() {
    if(!this->sign && !natural.isZero()){
        std::cout << "-";
    }
    natural.print();
}

Integer::Integer() {}



Integer::Integer(Integer &integer) {
    this->sign = new bool(integer.sign);
    this->natural = Natural(natural);
}

Integer &Integer::operator=(const Integer &other) noexcept {
    this->sign = new bool(sign);
    this->natural = other.natural;
    return *this;
}

Integer &Integer::operator=(const Natural &other) noexcept {
    this->sign = true;
    this->number = Natural(other);
    return *this;
}

bool Integer::isZero(){
    return this->number.isZero();
}

Natural Integer::abs() {
    return Natural();
}

bool Integer::isPoz(){
    return sign;
}

Integer::Integer(Natural number, bool sign){
    this->sign = sign;
    this->number = number;
}

Integer Integer::signSwap() {
    Integer integer(this->number, !this->sign);
    return integer;
}

