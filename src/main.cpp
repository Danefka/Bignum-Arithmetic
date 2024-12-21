#include "Numbers/include/Natural.h"
#include "Numbers/include/Integer.h"
#include "Numbers/include/Fraction.h"
#include "Numbers/include/Polynomial.h"
#include "CLI/include/CLI.h"
#include <iostream>
#include <ctime>

int main(){

    CLI* cli = new CLI();
    cli->help();
//    clock_t start, end;
//    double time_taken;
//    Natural x = Natural(202);
//    Natural one = Natural(1);
//    Natural zero = Natural(0);
//    Fraction fractionOne = Fraction(one, one);
//    Fraction fractionX = Fraction(x, one);
//    Polynomial polynomial1 = Polynomial({fractionOne, fractionOne}, {x,zero});
//    Polynomial polynomial2 = Polynomial({fractionX, fractionOne + fractionOne}, {one, zero});
//    polynomial1.print();
//    polynomial2.print();
//    start = clock(); // Начало замера времени
//    Polynomial answer = polynomial1 / polynomial2;
//    end = clock(); // Завершение замера времени
//    answer.print();
//    time_taken = double(end - start) / CLOCKS_PER_SEC;
//    std::cout << "Время выполнения программы: " << time_taken << " секунд" << std::endl;
//    return 0;
}