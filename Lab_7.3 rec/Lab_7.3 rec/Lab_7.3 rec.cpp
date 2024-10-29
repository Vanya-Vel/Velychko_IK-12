// Lab_7_3.cpp
// < ������� ���� >
// ����������� ������ � 7.3
// ����������� ��������� ������������� ������
// ������ 3

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void CreateArray(int** a, const int rowCount, const int colCount, const int Low, const int High, int i = 0, int j = 0);
void PrintArray(int** a, const int rowCount, const int colCount, int i = 0, int j = 0);
int NumberColZeroElement(int** a, const int rowCount, const int colCount, int& count, int col = 0, int row = 0);
void NumberRowMaxSeriesOfIdenticalElements(int** a, const int rowCount, const int colCount, int& count, int& max, int& NumRow, int i = 0, int j = 0);

int main()
{
    srand((unsigned)time(NULL));  // ����������� ���������� ���������� �����

    const int Low = -50;  // ����� ���� ���������� �����
    const int High = 50;  // ������ ���� ���������� �����
    int rowCount, colCount;
    cout << "rowCount = "; cin >> rowCount;
    cout << "colCount = "; cin >> colCount;

    // ��������� ���������� ������
    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    // ���������� ������ ����������� �������
    CreateArray(a, rowCount, colCount, Low, High);

    // ��������� ����������� ������
    cout << "Initial Array [" << rowCount << "x" << colCount << "]:" << endl;
    PrintArray(a, rowCount, colCount);

    int count = 0;
    NumberColZeroElement(a, rowCount, colCount, count);
    cout << "The number of columns with zero elements: " << count << endl;

    int max = -1;
    int NumRow = -1; // ������ ��� ���������� ������ �����
    count = 1; // ������� ��������
    NumberRowMaxSeriesOfIdenticalElements(a, rowCount, colCount, count, max, NumRow);


    // �������� ���'��
    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

// ������� ��� ��������� 2D ������ � ����������� �������
void CreateArray(int** a, const int rowCount, const int colCount, const int Low, const int High, int i, int j)
{
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
    cout << setw(5) << a[i][j];
    if (j < colCount - 1)
    {
        PrintArray(a, rowCount, colCount, i, j + 1);
    }
    else if (i < rowCount - 1)
    {
        cout << endl;
        PrintArray(a, rowCount, colCount, i + 1, 0);
    }
    else
    {
        cout << endl;
    }
}

// ������� ��� ��������� ������� �������� � ��������� ����������
int NumberColZeroElement(int** a, const int rowCount, const int colCount, int& count, int col, int row)
{
    if (col < colCount)
    {
        if (row < rowCount)
        {
            if (a[row][col] == 0)
            {
                count++;
            }
            NumberColZeroElement(a, rowCount, colCount, count, col, row + 1);
        }
        else
        {
            NumberColZeroElement(a, rowCount, colCount, count, col + 1, 0);
        }
    }
    return count;
}

// ������� ��� ����������� ������ ����� � ������������ ���� ��������� ��������
void NumberRowMaxSeriesOfIdenticalElements(int** a, const int rowCount, const int colCount, int& count, int& max, int& NumRow, int i, int j)
{
    if (i < rowCount)
    {
        if (j < colCount - 1)
        {
            if (a[i][j] == a[i][j + 1])
            {
                count++;
            }
            NumberRowMaxSeriesOfIdenticalElements(a, rowCount, colCount, count, max, NumRow, i, j + 1);
        }
        else
        {
            if (count > max)
            {
                max = count;
                NumRow = i; // �����'������� ����� �����
            }
            count = 1; // ������� ��������
            NumberRowMaxSeriesOfIdenticalElements(a, rowCount, colCount, count, max, NumRow, i + 1, 0);
        }

    }
    else if (NumRow != -1 && max > 1) { // ��������� ����������
        cout << "Row with max series: " << NumRow + 1 << " (length: " << max << ")" << endl;
    }
    else if (i == rowCount - 1) {
        cout << "No identical elements found." << endl;
    }

    
}
