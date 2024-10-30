// Lab_09_1.cpp
// < ������� ���� >
// ����������� ������ � 9.1
// �������� ����
// ������ 0.3

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
    // �������� ����������� �� �������� ������� x, ����� dx, �� ������� eps
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
        sum(); // ������ ��������� ���������� ����

        cout << "|" << setw(7) << setprecision(2) << x << " |"
            << setw(10) << setprecision(5) << exp(x * x) << " |"
            << setw(10) << setprecision(5) << s << " |" 
            << setw(5) << n << " |"
            << endl;

        x += dx;  // ��������� x �� ���� dx
    }
    cin.get();
    return 0;
}
