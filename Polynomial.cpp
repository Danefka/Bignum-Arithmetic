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
    }
}

Polynomial::Polynomial(Fraction *fractions, Integer *integers) {

}
