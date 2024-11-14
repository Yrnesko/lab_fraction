#include "fraction.h"
#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "russian");
    // Пример использования
    Fraction frac1 = { 3, 4 }; // 3/4
    Fraction frac2 = { 5, 6 }; // 5/6

    cout << "Первая дробь: ";
    display(frac1);
    cout << "Вторая дробь: ";
    display(frac2);

    Fraction sum = add(frac1, frac2);
    cout << "Сумма: ";
    display(sum);

    Fraction difference = subtract(frac1, frac2);
    cout << "Разность: ";
    display(difference);

    Fraction product = multiply(frac1, frac2);
    cout << "Произведение: ";
    display(product);

    Fraction quotient = divide(frac1, frac2);
    cout << "Частное: ";
    display(quotient);

    cout << "Целая часть первой дроби: " << wholePart(frac1) << endl;

    Fraction sumWithInteger = addInteger(frac1, 2);
    cout << "Сумма 3/4 и 2: ";
    display(sumWithInteger);

    return 0;
}
