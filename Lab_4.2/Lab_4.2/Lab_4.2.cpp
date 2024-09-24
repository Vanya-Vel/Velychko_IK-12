// Lab_04_2.cpp
// < ������� ���� >
// ����������� ������ � 4.2
// ��������� �������, ������ ��������: ������� ������ �����
// ������ 0.4

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
	double x, xp, xk, dx, A, B, y;
	double Pi = 4 * atan(1.0); // ����� �
	
	cout << "xp = "; cin >> xp;
	cout << "xk = "; cin >> xk;
	cout << "dx = "; cin >> dx;
	cout << fixed;
	cout << "------------------------" << endl;
	cout << "|" << setw(7) << "x   " << " |"     // setw(n) �-�� �������
		<< setw(12) << "y     " << " |" << endl;  // setprecision(n) �-�� ����� ���� ����
	cout << "|----------------------|" << endl;
	x = xp;
	while (x <= xk)
	{
		double a = ((1 + x) / 9) * (Pi / 180.0); // ����������� ������ � ������� � ������
		A = 1 + x;
		if (x <= 4)
			B = (2 + 2 * x) * exp(2 * x);
		else
			if (x > 4 && x <= 7)
				B = 1 / tan(a) + 8 * x;
			else
				B = 1 - 7 * x + x * x - 2 * x * x * x;

		y = A + B;

		cout << "|" << setw(7) << setprecision(2) << x
			<< " |" << setw(12) << setprecision(3) << y
			<< " |" << endl;
		x += dx;
	}
	cout << "|----------------------|" << endl;
	return 0;
}