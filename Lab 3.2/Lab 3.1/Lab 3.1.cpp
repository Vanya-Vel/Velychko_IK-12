// Lab_03_2.cpp
// < Величко Іван Олександрович >
// Лабораторна робота № 3.2
// Розгалуження, задане формулою: функція з параметрами.
// Варіант 0.4

#include <iostream>

using namespace std;

int main()
{
	double x; // вхідний аргумент
	double a; // вхідний параметр
	double b; // вхідний параметр
	double c; // вхідний параметр
	double F; // результат обчислення виразу

	cout << "a = "; cin >> a;
	cout << "b = "; cin >> b;
	cout << "c = "; cin >> c;
	cout << "x = "; cin >> x;

	if (c < 0 && x != 0)
		F = -a * x - c;
	if (c > 0 && x == 0)
		F = (x - a) / -c;
	if (!(c < 0 && x != 0) && !(c > 0 && x == 0))
		F = b * x / (c - a);

	cout << endl;
	cout << "1) F = " << F << endl;

	if (c < 0 && x != 0)
		F = -a * x - c;
	else
		if (c > 0 && x == 0)
			F = (x - a) / -c;
		else
			F = b * x / (c - a);

	cout << "2) F = " << F << endl;

	cin.get();
	return 0;
}