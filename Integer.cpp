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
    this->number = Natural(number);

}

Integer::Integer(long long int number) {
    this->sign = true;
    if(number < 0){
        this->sign = false;
        number = number*(-1);
    }
    this->number = Natural(number);
}

Integer::Integer(Natural number) {
    this->sign = true;
    this->number = number;
}

void Integer::print() {
    if(!this->sign && !number.compareToZero()){
        std::cout << "-";
    }
    number.print();
}

Integer::Integer() {}



Integer::Integer(Integer &integer) {
    this->sign = new bool(integer.sign);
    this->number = Natural(number);
}

Integer &Integer::operator=(const Integer &other) noexcept {
    this->sign = new bool(sign);
    this->number = other.number;
    return *this;
}

Integer &Integer::operator=(const Natural &other) noexcept {
    this->sign = true;
    this->number = Natural(other);
    return *this;
}
