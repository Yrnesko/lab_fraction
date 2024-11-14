#include "fraction.h"
#include <iostream>
#include <stdexcept>
#include <cmath> 

using namespace std;

// Функция для вычисления НОД по алгоритму Евклида
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Функция для упрощения дроби
void simplify(Fraction& frac) {
    int commonDivisor = gcd(abs(frac.numerator), abs(frac.denominator));
    frac.numerator /= commonDivisor;
    frac.denominator /= commonDivisor;
    if (frac.denominator < 0) {
        frac.numerator = -frac.numerator;
        frac.denominator = -frac.denominator;
    }
}

// Функция для вывода дроби на экран
void display(const Fraction& frac) {
    cout << frac.numerator << "/" << frac.denominator << endl;
}

// Функция для вычисления целой части дроби
int wholePart(const Fraction& frac) {
    return frac.numerator / frac.denominator;
}

// Функция для сложения дробей
Fraction add(const Fraction& a, const Fraction& b) {
    Fraction result;
    result.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
    result.denominator = a.denominator * b.denominator;
    simplify(result);
    return result;
}

// Функция для вычитания дробей
Fraction subtract(const Fraction& a, const Fraction& b) {
    Fraction result;
    result.numerator = a.numerator * b.denominator - b.numerator * a.denominator;
    result.denominator = a.denominator * b.denominator;
    simplify(result);
    return result;
}

// Функция для умножения дробей
Fraction multiply(const Fraction& a, const Fraction& b) {
    Fraction result;
    result.numerator = a.numerator * b.numerator;
    result.denominator = a.denominator * b.denominator;
    simplify(result);
    return result;
}

// Функция для деления дробей
Fraction divide(const Fraction& a, const Fraction& b) {
    if (b.numerator == 0) {
        throw invalid_argument("Деление на ноль!");
    }
    Fraction result;
    result.numerator = a.numerator * b.denominator;
    result.denominator = a.denominator * b.numerator;
    simplify(result);
    return result;
}

// Функция для сложения дроби с целым числом
Fraction addInteger(const Fraction& frac, int integer) {
    return add(frac, { integer, 1 });
}
