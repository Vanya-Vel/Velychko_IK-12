// Lab_09_1.cpp
// < Величко Іван >
// Лабораторна робота № 9.1
// Простори імен
// Варіант 0.3

#include <iostream>
#include <math.h>
#include <iomanip>

#include "dod.h"
#include "sum.h"
#include "var.h"

using namespace std;

using namespace nsDod;
using namespace nsSum;
using namespace nsVar;


int main()
{
    // Введення початкового та кінцевого значень x, кроку dx, та точності eps
    cout << "xp = "; cin >> x_p;
    cout << "xk = "; cin >> x_k;
    cout << "dx = "; cin >> dx;
    cout << "eps = "; cin >> eps;
    cout << fixed;

    cout << "-------------------------------------------------" << endl;
    cout << "|" << setw(7) << "x" << " |"
        << setw(10) << "e^(x^2)" << " |"
        << setw(10) << "S" << " |" 
        << setw(5) << "n" << " |"
        << endl;
    cout << "-------------------------------------------------" << endl;

    x = x_p;
    while (x <= x_k) 
    {
        sum(); // виклик процедури обчислення суми

        cout << "|" << setw(7) << setprecision(2) << x << " |"
            << setw(10) << setprecision(5) << exp(x * x) << " |"
            << setw(10) << setprecision(5) << s << " |" 
            << setw(5) << n << " |"
            << endl;

        x += dx;  // Збільшення x на крок dx
    }
    cin.get();
    return 0;
}
