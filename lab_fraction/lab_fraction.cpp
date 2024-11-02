#include <iostream>
#include <locale>
using namespace std;

// Структура для представления обыкновенной дроби
struct Fraction {
    int numerator;   // Числитель
    int denominator; // Знаменатель
};

// Функция для вычисления наибольшего общего делителя (НОД) по алгоритму Евклида
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
    // Обеспечиваем, чтобы знаменатель был положительным
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

// Функция для работы с дробью и целым числом
Fraction addInteger(const Fraction& frac, int integer) {
    return add(frac, { integer, 1 });
}

int main() {
    setlocale(LC_ALL, "Russian");
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
