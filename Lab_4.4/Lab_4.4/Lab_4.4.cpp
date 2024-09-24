// Lab_04_4.cpp
// < Величко Іван >
// Лабораторна робота № 4.4
// Табуляція функції, заданої графіком
// Варіант 0.4

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
	double x, xp, xk, dx, R, y;

	cout << "R = "; cin >> R;
	cout << "xp = "; cin >> xp;
	cout << "xk = "; cin >> xk;
	cout << "dx = "; cin >> dx;
	cout << fixed;
	cout << "------------------------" << endl;
	cout << "|" << setw(7) << "x   " << " |"     // setw(n) к-ть відступів
		<< setw(12) << "y     " << " |" << endl;  // setprecision(n) к-ть знаків після коми
	cout << "|----------------------|" << endl;
	x = xp;
	while (x <= xk)
	{
		if (x <= 0)
			y = -R * (x - 6) / 6;
		else
			if (x > 0 && x <= R)
				y = -sqrt(R * R - x * x);
			else
				if (x > R && x <= 2 * R)
					y = sqrt(R * R - (x - 2 * R) * (x - 2 * R));
				else
					y = R;

		cout << "|" << setw(10) << setprecision(2) << x
			<< " |" << setw(12) << setprecision(3) << y
			<< " |" << endl;
		x += dx;
	}
	cout << "|----------------------|" << endl;
	return 0;
}