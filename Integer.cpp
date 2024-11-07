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
