// Lab_03_3.cpp
// < Величко Іван Олександрович >
// Лабораторна робота № 3.3
// Розгалуження, задане графіком функції.
// Варіант 0.4

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double x; // вхідний аргумент
	double R; // вхідний параметр
	double y; // результат обчислення виразу

	cout << "R = "; cin >> R;
	cout << "x = "; cin >> x;

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

	cout << endl;
	cout << "y = " << y << endl;

	cin.get();
	return 0;
}
