// Lab_7_2.cpp
// < �������, ��� ������ >
// ����������� ������ � 7.2
// ����������� ������������� ������ ����������� � ����������� ���������
// ������ 3

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void CreateArray(int** a, const int rowCount, const int colCount, const int Low, const int High, int i = 0, int j = 0);
void PrintArray(int** a, const int rowCount, const int colCount, int i = 0, int j = 0);
void SumMinElementsInRow(int** a, const int rowCount, const int colCount, int& sum, int i = 0, int i0 = 0, int MinElementInRow = 0);

int main()
{
    srand((unsigned)time(NULL));  // ����������� ���������� ���������� �����

    const int Low = -50;  // ����� ���� ���������� �����
    const int High = 50;  // ������ ���� ���������� �����
    const int rowCount = 3;  // ʳ������ �����
    const int colCount = 3;  // ʳ������ ��������

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
void CreateArray(int** a, const int rowCount, const int colCount, const int Low, const int High, int i, int j)
{
    // ��������� ����������� ����� � �������� �������
    a[i][j] = Low + rand() % (High - Low + 1);

    if (j < colCount - 1)
    {
        CreateArray(a, rowCount, colCount, Low, High, i, j + 1);
    }
    else if (i < rowCount - 1)
    {
        CreateArray(a, rowCount, colCount, Low, High, i + 1, 0);
    }
}

// ������� ��� ��������� 2D ������
void PrintArray(int** a, const int rowCount, const int colCount, int i, int j)
{
    cout << setw(5) << a[i][j];  // ��������� ������� � �������������

    if (j < colCount - 1)
    {
        PrintArray(a, rowCount, colCount, i, j + 1);
    }
    else if (i < rowCount - 1)
    {
        cout << endl;
        PrintArray(a, rowCount, colCount, i + 1, 0);
    }
}

// ������� ��� ����������� ���� ��������� �������� � ������
void SumMinElementsInRow(int** a, const int rowCount, const int colCount, int& sum, int i, int i0, int MinElementInRow)
{
    if (i0 == 0)
    {
        MinElementInRow = a[i][0]; // ����������� ���������� �������� ������ ��������� �����
    }

    // ��������� ��������� �������� � ���������
    if (a[i][i0] < MinElementInRow) // ����������� ���������� ��������
    {
        MinElementInRow = a[i][i0]; // ��������� ���������� ��������
    }

    // ������� ��� �������� ��������
    if (i0 < colCount - 1) // ���� �� ��������� ���� �����
    {
        SumMinElementsInRow(a, rowCount, colCount, sum, i, i0 + 1, MinElementInRow);
    }
    else // ���� ��������� ����� �����
    {
        sum += MinElementInRow; // ������ ��������� ������� �� ����
        if (i < rowCount - 1) // ���� �� ��������� ���������� �����
        {
            SumMinElementsInRow(a, rowCount, colCount, sum, i + 1, 0, 0);
        }
        else // ���� �� ������� �����
        {
            cout << endl << endl;;
            cout << "Sum of min elements: " << sum << endl; // ��������� �������� ����
        }
    }
}
