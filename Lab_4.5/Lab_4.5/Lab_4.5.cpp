// Lab_04_4.cpp
// < ������� ���� >
// ����������� ������ � 4.4
// ��������� �������, ������ ��������
// ������ 0.4

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
	double x, y, R; // ������� ��������

	srand((unsigned)time(NULL));

	cout << "R = "; cin >> R;

	for (int i = 0; i < 2; i++)
	{
		cout << "x = "; cin >> x;
		cout << "y = "; cin >> y;

		if ((y <= sqrt(R * R - x * x) && y >= 0) || (y <= 0 && y >= -R && x <= 0 && y <= x))
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
	cout << endl << fixed;

	
	for (int i = 0; i < 10; i++)
	{
		x = 2 * R * rand() / RAND_MAX - R; // ���� ���� ������ R ����� 6 �� ������ � . 
		y = 2 * R * rand() / RAND_MAX - R; // ��� ��������� �� ����� � ��� double/float
		if ((y <= sqrt(R * R - x * x) && y >= 0) || (y <= 0 && y >= -R && x <= 0 && y <= x)) // ���� �����
			cout << setw(8) << setprecision(4) << x << " | "               // ������� R
			<< setw(8) << setprecision(4) << y << " |----" << "yes" << endl << "---------|----------|" << endl;
		else
			cout << setw(8) << setprecision(4) << x << " | "
			<< setw(8) << setprecision(4) << y << " |--" << "no" << endl << "---------|----------|" << endl;
	}
	return 0;
}