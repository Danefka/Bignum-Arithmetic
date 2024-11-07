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
    this->abs = Natural(number);

}

bool Integer::operator>(const Integer &other) noexcept {
    Natural copy = other.abs;
    if(this->abs.compareToZero() && copy.compareToZero()){
        return false;
    }
}

Integer::Integer(long long int number) {
    this->sign = true;
    if(number < 0){
        this->sign = false;
        number = number*(-1);
    }
    this->abs = Natural(number);
}

Integer::Integer(Natural number) {
    this->sign = true;
    this->abs = number;
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

bool Integer::operator==(const Integer &other) noexcept {
    return true;
}

Integer Integer::operator+(const Integer &other) noexcept {
    Integer res;
    Natural copy = other.abs;
    if(this->sign == other.sign){
        res.sign = this->sign;
        res.abs = this->abs + other.abs;
    }
    if(this->abs > other.abs){
        res.sign = this->sign;
        res.abs = this->abs - other.abs;
    }
    res.sign = other.sign;
    res.abs = copy - this->abs;
}

Integer Integer::operator-(const Integer &other) noexcept {
    return *this - other.changeSign();
}

Integer Integer::operator*(const Integer &other) const noexcept {
    Integer res;
    Natural copy = this->abs;
    res.sign = this->sign == other.sign;
    res.abs = copy * other.abs;
    return res;
}

Integer Integer::operator/(const Integer &other) noexcept {
    Integer res;
    res.sign = this->sign == other.sign;
    res.abs = this->abs / other.abs;
    if(res * other > *this){
        res = res + Integer(1);
    }
    return res;
}

Integer Integer::operator%(const Integer &other) noexcept {
    return ;
}
