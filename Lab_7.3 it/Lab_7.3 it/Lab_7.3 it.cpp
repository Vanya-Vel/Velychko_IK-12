// Lab_7_3.cpp
// < ������� ���� >
// ����������� ������ � 7.3
// ����������� ��������� ������������� ������
// ������ 3

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void CreateArray(int** a, const int rowCount, const int colCount, const int Low, const int High);
void PrintArray(int** a, const int rowCount, const int colCount);
int NumberColZeroElement(int** a, const int rowCount, const int colCount, int& count);
void NumberRowMaxSeriesOfIdenticalElements(int** a, const int rowCount, const int colCount, int& count, int& max);

int main()
{
    srand((unsigned)time(NULL));  // ����������� ���������� ���������� �����

    const int Low = -50;  // ����� ���� ���������� �����
    const int High = 50;  // ������ ���� ���������� �����
    int rowCount, colCount;
    cout << "rowCount = "; cin >> rowCount;
    cout << "colCount = "; cin >> colCount;

    // ��������� ���������� ������
    int** a = new int* [rowCount]; // �������� ���'�� ��� ����� ������
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount]; // �������� ���'�� ��� �������� � ������� �����

    // ���������� ������ ����������� �������
    CreateArray(a, rowCount, colCount, Low, High);

    // ��������� ����������� ������
    cout << "Initial Array [" << rowCount << "x" << colCount << "]:" << endl;
    PrintArray(a, rowCount, colCount);  // ��������� ����������� ������

    int count = 0;
    NumberColZeroElement(a, rowCount, colCount, count);
    cout << "The number of columns with zero elements: " << count << endl; // ��������� ������� �������� � ��������� ����������

    int max = -1;
    count = 1;
    NumberRowMaxSeriesOfIdenticalElements(a, rowCount, colCount, count, max); // ����������� ������ ����� � ��������� ���� ��������� ��������

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

// ������� ��� ��������� ������� �������� � ��������� ����������
int NumberColZeroElement(int** a, const int rowCount, const int colCount, int& count)
{
    for (int i0 = 0; i0 < colCount; i0++)
    {
        for (int i = 0; i < rowCount; i++)
        {
            if (a[i][i0] == 0) // �������� �� ���� � ��������� �������
            {
                count++; // �������� ��������
                break; // ����� � �����, ���� �������� ����
            }
        }
    }

    return count; // ��������� ������� �������� � ������
}

// ������� ��� ����������� ������ ����� � ������������ ���� ��������� ��������
void NumberRowMaxSeriesOfIdenticalElements(int** a, const int rowCount, const int colCount, int& count, int& max)
{
    int NumRow = -1; // ����� ����� � ������������ ����

    for (int i = 0; i < rowCount; i++)
    {
        count = 1; // ���������� count ��� ������ �����
        for (int j = 0; j < colCount - 1; j++)
        {
            if (a[i][j] == a[i][j + 1])
            {
                count++; // �������� count, ���� �������� �������
            }
        }

        // ��������� max, ���� �������� count ������
        if (max < count)
        {
            max = count; // ��������� ���������
            NumRow = i; // �����'������� ����� �����
        }
    }

    // ��������� ������ ����� � ������������ ����
    if (NumRow != -1 && max != 1) // ��������, �� ���� �������� ����
    {
        cout << "Row with max series: " << NumRow + 1 << " (values: " << max << ")" << endl;
    }
    else
    {
        cout << "No identical elements found." << endl;
    }
}
