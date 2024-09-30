// Lab_05_1.cpp
// < ������� ���� >
// ����������� ������ � 5.1
// �������, �� ������ ������������ �����
// ������ 0.4

#include <iostream>
#include <cmath>

using namespace std;

// �������� ������� k: ������ ��� ��������� ���� double, ������� ��������� ���� double
double k(const double x, const double y);

int main()
{
    double p, q;

    // ��������� ������ �� ����������� �� �������� ������� p � q
    cout << "p = "; cin >> p;
    cout << "q = "; cin >> q;

    // ���������� �������� c �� ��������� ������ ������� ������� k
    double c = k(1 + p, q * q); //- k(q * p, 1)) / (1 + k(p * p, q));

    cout << "c = " << c << endl;

    return 0;
}

// ���������� ������� k, ��� �������� ����� �� ����� ��������� x � y
double k(const double x, const double y)
{
    return ((sin(x) / (y * y)) + (cos(y) / (x * x)));
}
