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
        x[key] = x.at(key).add(fractions.at(i));
    }
}

void Polynomial::print() {
    unsigned long long i = 0;
    for(auto pair : x){
        Integer pow = pair.first;
        pair.second.printToLine();
        std::cout << " * X^";
        pow.printToLine();
        i++;
        if(i == x.size()){ return;}
        std::cout << " + ";
    }
}

