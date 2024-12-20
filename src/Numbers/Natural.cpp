//
// Created by Даниил Гиршович on 16.11.2024.
//

#include "Natural.h"

Natural::Natural(std::string str) {
    if (str.length() == 0) {
        this->digits = {0};
    } else {
        for (long long i = str.length(); i > 0; i -= 9) {
            if (i < 9)
                this->digits.push_back(atoi(str.substr(0, i).c_str()));
            else
                this->digits.push_back(atoi(str.substr(i - 9, 9).c_str()));
        }
    }
    removeLeadingZeros();
}

Natural::Natural(unsigned long long int number) {
    if (number == 0) {
        this->digits = {0};
    } else {
        while (number > 0) {
            this->digits.push_back(number % 1000000000); // Добавляем последние 9 цифр
            number /= 1000000000; // Убираем последние 9 цифр
        }
    }
    removeLeadingZeros();
}

void Natural::removeLeadingZeros() {
    while (this->digits.size() > 1 && this->digits.back() == 0) {
        this->digits.pop_back();
    }
}

unsigned long long int Natural::length() const {
    if (this->digits.empty()) {
        return 0;
    }

    // Длина последнего блока (самого старшего разряда)
    unsigned long long int lastBlockLength = std::to_string(this->digits.back()).length();

    // Общая длина = длина последнего блока + количество полных блоков * 9
    return lastBlockLength + (this->digits.size() - 1) * 9;
}

void Natural::print() const{
    if (digits.empty()){
        std::cout << "0";
    }
    for (long long i = digits.size() - 1; i >= 0; i--) {
        if (digits.at(i) < 100000000 && i != digits.size() - 1) {
            int size = std::to_string(digits.at(i)).length();
            std::string output;
            while (output.length() < 9 - size) {
                output.append("0");
            }
            output.append(std::to_string(digits.at(i)));
            std::cout << output;
            continue;
        }
        std::cout << digits.at(i);
    }
    std::cout << std::endl;
}


void Natural::printToLine() const {
    if (digits.empty()) {
        std::cout << "0"; // Если вектор цифр пуст, выводим 0
        return;
    }

    // Выводим последний блок (самый старший разряд) без ведущих нулей
    std::cout << digits.back();

    // Выводим остальные блоки с ведущими нулями, если необходимо
    for (int i = digits.size() - 2; i >= 0; --i) {
        // Форматируем текущий блок, добавляя ведущие нули до 9 символов
        std::cout << digits.at(i);
    }
}

Natural &Natural::operator=(const Natural &other) noexcept {
    if (&other != this) {
        this->digits = other.digits; // copy digits array
    }
    return *this;
}

short Natural::compare(const Natural &other) const {
    if (this->digits.size() != other.digits.size()) {
        return this->digits.size() > other.digits.size() ? 1 : 2;
    }
    for (int i = this->digits.size() - 1; i >= 0; i--) {
        if (this->digits.at(i) != other.digits.at(i)) {
            return this->digits.at(i) > other.digits.at(i) ? 1 : 2;
        }
    }
    return 0;
}

bool Natural::isZero() const{
    if (digits.size() == 1 && digits.at(0) == 0) {
        return true;
    }
    return false;
}

Natural Natural::increment() {
    int i = 0;
    while (i < digits.size()) {
        digits.at(i)++;
        if (digits.at(i) == 1000000000) {
            digits.at(i) = 0;
            i++;
            continue;
        }
        return *this;
    }
    digits.push_back(1);
    return *this;
}

bool Natural::operator==(const Natural &other) const noexcept {
    Natural copy = *this;
    Natural otherCopy = other;
    return copy.compare(otherCopy) == 0;
}

bool Natural::operator>(const Natural &other) const noexcept {
    Natural copy = *this;
    Natural otherCopy = other;
    return copy.compare(otherCopy) == 1;
}

bool Natural::operator<(const Natural &other) const noexcept {
    Natural copy = *this;
    Natural otherCopy = other;
    return copy.compare(otherCopy) == 2;
}

bool Natural::operator>=(const Natural &other) const noexcept {
    return this->operator==(other) || this->operator>(other);
}

bool Natural::operator<=(const Natural &other) const noexcept {
    return this->operator==(other) || this->operator<(other);
}

Natural Natural::operator+(const Natural &other) const noexcept {
    Natural answer = Natural();
    int compare = this->compare(other);
    int overflow = 0;
    for (int i = 0; i < this->digits.size() &&
                    i < other.digits.size(); ++i) { // складываем цифры до тех пор, пока они не закончатся в меньшем
        answer.digits.push_back((this->digits.at(i) + other.digits.at(i) + overflow) % 1000000000);
        if (this->digits.at(i) + other.digits.at(i) + overflow > 999999999) { // проверяем на переполнение
            overflow = 1;
        } else {
            overflow = 0;
        }
    }

    int i = this->digits.size() > other.digits.size() ? other.digits.size()
                                                      : this->digits.size(); // сравниваем два числа
    if (compare == 2) {
        for (int j = i; j < other.digits.size(); ++j) {
            answer.digits.push_back((other.digits.at(j) + overflow) % 1000000000);
            if (other.digits.at(j) + overflow >1000000000) {
                overflow = 1;
            } else {
                overflow = 0;
            }
        }
    } else if (compare == 1) {
        for (int j = i; j < this->digits.size(); ++j) {
            answer.digits.push_back((this->digits.at(j) + overflow) % 1000000000);
            if (this->digits.at(j) + overflow > 1000000000) {
                overflow = 1;
            } else {
                overflow = 0;
            }
        }
    }
    if (overflow == 1) { // если после всех сложений остался перенос, добавляем его
        answer.digits.push_back(overflow);
    }
    return answer;
}

Natural Natural::operator-(const Natural &other) const noexcept {
    if (this->compare(other) == 2) {
        return {"0"};
    }

    Natural answer = Natural(); // Инициализируем результат
    int overflow = 0; // Перенос (заем)

    for (int i = 0; i < other.digits.size(); ++i) {
        int diff = this->digits.at(i) - other.digits.at(i) - overflow;
        if (diff < 0) {
            diff += 1000000000; // Если разность отрицательная, добавляем 10^9
            overflow = 1; // Устанавливаем перенос
        } else {
            overflow = 0; // Сбрасываем перенос
        }
        answer.digits.push_back(diff); // Добавляем разность в результат
    }

    for (int i = other.digits.size(); i < this->digits.size(); ++i) {
        int diff = this->digits.at(i) - overflow;
        if (diff < 0) {
            diff += 1000000000; // Если разность отрицательная, добавляем 10^9
            overflow = 1; // Устанавливаем перенос
        } else {
            overflow = 0; // Сбрасываем перенос
        }
        answer.digits.push_back(diff); 
    }

    answer.removeLeadingZeros();
    return answer;
}

Natural Natural::mulByDigit(int d) const {
    if (d == 0) {
        return {"0"};
    }
    if (d == 1) {
        return *this;
    }
    Natural answer = Natural();
    int overflow = 0;
    int i = 0;


    while (i < this->digits.size()) { // перебераем цифры и умножаем их на число учитывая переполнение
        if (this->digits.at(i) + overflow <= 100000000) {
            answer.digits.push_back(this->digits.at(i) * d + overflow);
            overflow = 0;
            i++;
            continue;
        } else {
            unsigned long long int j = this->digits.at(i);
            j*=d;
            j+=overflow;
            overflow = j/1000000000;
            answer.digits.push_back(j%1000000000);
            i++;
            continue;
        }
    }
    if (overflow == 0) {
        return answer;
    }
    answer.digits.push_back(overflow);
    return answer;
}

Natural Natural::mulByTen(int pow) const {
    if (pow == 0){
        return *this;
    }
    Natural answer = Natural();
    while (pow > 8){
        answer.digits.push_back(0);
        pow-=9;
    }
    int i = 0;
    int overflow = 0;
    while (i < this->digits.size()){
        unsigned long long int j = 0;
        j = this->digits.at(i);
        j *= std::pow(10,pow);
        j += overflow;
        answer.digits.push_back(j%1000000000);
        overflow = j/1000000000;
        i++;
    }
    if (overflow == 0){
        return answer;
    }
    answer.digits.push_back(overflow);
    return answer;
}

Natural Natural::subByMul(const Natural &other, int k) const {
    Natural i = other.mulByDigit(k);
    return *this-i;
}

Natural Natural::operator*(const Natural &other) const noexcept {
    Natural answer = Natural("0"); // Инициализируем результат нулем
    // Перебираем каждый блок числа other
    for (int i = 0; i < other.digits.size(); ++i) {
        int currentBlock = other.digits.at(i); // Текущий блок числа other

        // Перебираем каждую цифру в текущем блоке
        for (int j = 0; j < 9; ++j) {
            int digit = currentBlock % 10; // Получаем текущую цифру (младший разряд)
            currentBlock /= 10; // Убираем обработанную цифру

            if (digit == 0) continue; // Пропускаем умножение на 0

            // Умножаем текущее число на цифру и сдвигаем результат
            Natural temp = this->mulByDigit(digit).mulByTen(i * 9 + j);

            // Складываем результат с ответом
            answer = answer + temp;
        }
    }
    return answer;
}

Natural Natural::divFirstDigit(const Natural &other) const {
    unsigned long long pow = 1; // Степень в которую возводим делитель
    Natural numerator = *this; // Создаем копию текущего числа, которое будет делимым
    while (numerator >= other.mulByTen(pow)) { // Определяем максимальную степень, в которую нужно возвести делитель, чтобы получить число, меньшее или равное делимому
        pow++;
    }
    Natural denominator = other.mulByTen(pow - 1); // Делитель, умноженный на 10 в степени (pow - 1)
    Natural k = Natural("0"); // переменная хранящая полученную цифру
    while (numerator >= denominator) {
        k.increment();
        Natural natural = numerator - denominator;
        numerator = natural;
        numerator.removeLeadingZeros();
    }
    return k.mulByTen(pow - 1);
}

Natural Natural::operator/(const Natural &other) const {
    if(other.isZero()){ // Проверка на ноль
        throw std::invalid_argument("Деление на 0 (Natura).");
    }
    Natural numerator = *this;
    Natural quotient("0");
    while (numerator >= other && !numerator.isZero()) { // пока изначальное число больше или равно делителя и не ноль
        Natural natural =numerator.divFirstDigit(other);
        quotient = quotient + natural;
        numerator = numerator - (natural * other);
        numerator.removeLeadingZeros();
    }
    return quotient;
}

Natural Natural::operator%(const Natural &other) const {
    if(other.isZero()){ // проверка на ноль
        throw std::invalid_argument("Деление на 0 (NATURA).");
    }
    if (*this < other) { // если наше число меньше другого, возвращаем его
        return *this;
    }
    Natural numerator = *this;
    while (numerator >= other) {
        numerator = numerator - (numerator.divFirstDigit(other) * other);
        numerator.removeLeadingZeros();
    }
    return numerator;
}

Natural Natural::gcd(const Natural &other) const {
    Natural first = *this;
    Natural second = other;
    while (!second.isZero()) { // по алгоритму Евклида
        Natural j = second;
        second = first % second;
        first = j;
    }
    return first;
}

Natural Natural::lcm(const Natural &other) const {
    Natural gcd = this->gcd(other);
    return (*this*other) / gcd;
}

Natural::Natural() = default;