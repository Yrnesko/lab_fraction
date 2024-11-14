#ifndef FRACTION_H
#define FRACTION_H

// Структура для представления обыкновенной дроби
struct Fraction {
    int numerator;   // Числитель
    int denominator; // Знаменатель
};

// Функции для работы с дробями
int gcd(int a, int b);
void simplify(Fraction& frac);
void display(const Fraction& frac);
int wholePart(const Fraction& frac);
Fraction add(const Fraction& a, const Fraction& b);
Fraction subtract(const Fraction& a, const Fraction& b);
Fraction multiply(const Fraction& a, const Fraction& b);
Fraction divide(const Fraction& a, const Fraction& b);
Fraction addInteger(const Fraction& frac, int integer);

#endif // FRACTION_H
