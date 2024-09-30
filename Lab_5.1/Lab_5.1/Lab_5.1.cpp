// Lab_05_1.cpp
// < Величко Іван >
// Лабораторна робота № 5.1
// Функції, що містять арифметичний вираз
// Варіант 0.4

#include <iostream>
#include <cmath>

using namespace std;

// Прототип функції k: приймає два аргументи типу double, повертає результат типу double
double k(const double x, const double y);

int main()
{
    double p, q;

    // Виведення запиту до користувача на введення значень p і q
    cout << "p = "; cin >> p;
    cout << "q = "; cin >> q;

    // Обчислення значення c за допомогою кількох викликів функції k
    double c = k(1 + p, q * q); //- k(q * p, 1)) / (1 + k(p * p, q));

    cout << "c = " << c << endl;

    return 0;
}

// Визначення функції k, яка обчислює вираз на основі параметрів x і y
double k(const double x, const double y)
{
    return ((sin(x) / (y * y)) + (cos(y) / (x * x)));
}
