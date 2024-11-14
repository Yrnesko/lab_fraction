#include "fraction.h"
#include <iostream>
#include <stdexcept>
#include <cmath> 

using namespace std;

// ������� ��� ���������� ��� �� ��������� �������
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// ������� ��� ��������� �����
void simplify(Fraction& frac) {
    int commonDivisor = gcd(abs(frac.numerator), abs(frac.denominator));
    frac.numerator /= commonDivisor;
    frac.denominator /= commonDivisor;
    if (frac.denominator < 0) {
        frac.numerator = -frac.numerator;
        frac.denominator = -frac.denominator;
    }
}

// ������� ��� ������ ����� �� �����
void display(const Fraction& frac) {
    cout << frac.numerator << "/" << frac.denominator << endl;
}

// ������� ��� ���������� ����� ����� �����
int wholePart(const Fraction& frac) {
    return frac.numerator / frac.denominator;
}

// ������� ��� �������� ������
Fraction add(const Fraction& a, const Fraction& b) {
    Fraction result;
    result.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
    result.denominator = a.denominator * b.denominator;
    simplify(result);
    return result;
}

// ������� ��� ��������� ������
Fraction subtract(const Fraction& a, const Fraction& b) {
    Fraction result;
    result.numerator = a.numerator * b.denominator - b.numerator * a.denominator;
    result.denominator = a.denominator * b.denominator;
    simplify(result);
    return result;
}

// ������� ��� ��������� ������
Fraction multiply(const Fraction& a, const Fraction& b) {
    Fraction result;
    result.numerator = a.numerator * b.numerator;
    result.denominator = a.denominator * b.denominator;
    simplify(result);
    return result;
}

// ������� ��� ������� ������
Fraction divide(const Fraction& a, const Fraction& b) {
    if (b.numerator == 0) {
        throw invalid_argument("������� �� ����!");
    }
    Fraction result;
    result.numerator = a.numerator * b.denominator;
    result.denominator = a.denominator * b.numerator;
    simplify(result);
    return result;
}

// ������� ��� �������� ����� � ����� ������
Fraction addInteger(const Fraction& frac, int integer) {
    return add(frac, { integer, 1 });
}
