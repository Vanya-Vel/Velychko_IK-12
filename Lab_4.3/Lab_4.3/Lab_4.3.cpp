// Lab_04_3.cpp
// < ������� ���� >
// ����������� ������ � 4.3
// ��������� �������, ������ ��������: ������� � �����������
// ������ 0.4

#include <iostream>   // ��� ������ � ��������� � ����������
#include <iomanip>    // ��� ������������ ������ (setw, setprecision)
#include <cmath>      // ��� ������������ ������������ ������� (���� ������������)

using namespace std;

int main()
{
    // ���������� ������
    double x, xp, xk, dx, a, b, c, F;

    // �������� ������� ������ a, b, c, � ����� �����������, �������� �������� x �� ����� dx
    cout << "a = "; cin >> a;
    cout << "b = "; cin >> b;
    cout << "c = "; cin >> c;
    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;

    // Գ�������� ������ ���������, ��� ���� �������� ������� �������
    cout << fixed;
    cout << "------------------------" << endl;
    cout << "|" << setw(7) << "x   " << " |"       // setw(7) - ������ ���� ��� ����� x
        << setw(12) << "F     " << " |" << endl;  // setw(12) - ������ ���� ��� ������� F
    cout << "|----------------------|" << endl;

    x = xp;

    while (x <= xk)
    {

        if (c < 0 && x != 0)
            F = -a * x - c;
        else if (c > 0 && x == 0)
            F = (x - a) / -c;
        else
            F = b * x / (c - a);

        // ��������� ���������� � ������ �������
        cout << "|" << setw(7) << setprecision(2) << x    // ��������� x � �������� �� 2 ����� ���� ����
            << " |" << setw(12) << setprecision(3) << F  // ��������� F � �������� �� 3 ����� ���� ����
            << " |" << endl;

        // ��������� x �� ���� dx
        x += dx;
    }

    // ��������� ������ ���� �������
    cout << "|----------------------|" << endl;

    return 0;
}