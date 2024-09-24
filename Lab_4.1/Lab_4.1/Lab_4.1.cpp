// Lab_04_1.cpp
// < ������� ���� >
// ����������� ������ � 4.1
// �����.
// ������ 0.4

#include <iostream>  // ��� ������ � �����-�������
#include <cmath>     // ��� ������������ �������

using namespace std;  // ������ ������������ �������� ���������� ��������

int main()
{
    int N, i;
    double S;

    cout << "N = "; cin >> N;  // �������� �������� N � ���������

    S = 0;
    i = 1;

    // ���� while ��� ���������� ���� � ������ (i <= N)
    while (i <= N)
    {
        S += (1 + 1.0 * i / N) / i * i;
        i++;
    }

    cout << S << endl;  // ��������� ����������

    S = 0;
    i = 1;

    // ���� do-while ��� ���������� ����
    do {
        S += (1 + 1.0 * i / N) / i * i;
        i++;
    } while (i <= N);

    cout << S << endl;

    S = 0;

    // ���� for ��� ���������� ���� (i �� 1 �� N)
    for (int i = 1; i <= N; i++)
    {
        S += (1 + 1.0 * i / N) / i * i;
    }

    cout << S << endl;

    S = 0;

    // ��������� ���� for ��� ���������� ���� (i �� N �� 1)
    for (i = N; i >= 1; i--)
    {
        S += (1 + 1.0 * i / N) / i * i;
    }

    cout << S << endl;

    return 0;  // ���������� ��������

}