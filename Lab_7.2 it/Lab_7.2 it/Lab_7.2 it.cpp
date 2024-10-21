// Lab_7_2.cpp
// < ������� ���� >
// ����������� ������ � 7.2
// ����������� ������������� ������ ����������� � ����������� ���������
// ������ 3
#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void CreateArray(int** a, const int rowCount, const int colCount, const int Low, const int High);
void PrintArray(int** a, const int rowCount, const int colCount);
void SumMinElementsInRow(int** a, const int rowCount, const int colCount, int& sum);


int main()
{
    srand((unsigned)time(NULL));  // ����������� ���������� ���������� �����

    const int Low = -50;  // ����� ���� ���������� �����
    const int High = 50;  // ������ ���� ���������� �����
    const int rowCount = 10;  // ʳ������ �����
    const int colCount = 7;  // ʳ������ ��������

    // ��������� ���������� ������
    int** a = new int* [rowCount]; // �������� ���'�� ��� ����� ������
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount]; // �������� ���'�� ��� �������� � ������� �����

    // ���������� ������ ����������� �������
    CreateArray(a, rowCount, colCount, Low, High);

    // ��������� ����������� ������
    cout << "Initial Array [" << rowCount << "x" << colCount << "]:" << endl;
    PrintArray(a, rowCount, colCount);  // ��������� ����������� ������

    int sum = 0;
    // ���������� �� ��������� ���� ��������� �������� � ������� �����
    SumMinElementsInRow(a, rowCount, colCount, sum);

    // �������� ���'��
    for (int i = 0; i < rowCount; i++)
        delete[] a[i];  // ��������� ���'�� �����
    delete[] a;  // ��������� ���'�� ������

    return 0;
}

// ������� ��� ��������� 2D ������ � ����������� �������
void CreateArray(int** a, const int rowCount, const int colCount, const int Low, const int High)
{
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
        {
            // ��������� ����������� ����� � �������� �������
            a[i][j] = Low + rand() % (High - Low + 1);
        }
}

// ������� ��� ��������� 2D ������
void PrintArray(int** a, const int rowCount, const int colCount)
{
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
            cout << setw(5) << a[i][j];  // ��������� ������� � �������������
        cout << endl;  // ����� ����� ���� ������� �����
    }
    cout << endl;  // ���������� ����� ��� �������
}

// ������� ��� ����������� ���� ��������� �������� � ������
void SumMinElementsInRow(int** a, const int rowCount, const int colCount, int& sum)
{
    int MinElementInRow = 0; // ����� ��� ���������� ���������� �������� � �����

    // ����������� �� ��� ������ �������
    for (int i = 0; i < rowCount; i++)
    {
        MinElementInRow = a[i][0]; // ����������� ���������� �������� ������ ��������� �����

        // ����������� �� ��� �������� � ��������� �����
        for (int i0 = 1; i0 < colCount; i0++) // ������ � ������� ��������
        {
            // ��������� ��������� �������� � ���������
            if (a[i][i0] < MinElementInRow) // ����������� ���������� ��������
            {
                MinElementInRow = a[i][i0]; // ��������� ���������� ��������
            }
        }
        sum += MinElementInRow; // ��������� ���������� �������� �� ����
    }
    cout << "Sum of min elements: " << sum << endl; // ��������� ���� ��������� ��������
}
