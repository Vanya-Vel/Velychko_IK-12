// Lab_7_2.cpp
// < прізвище, ім’я автора >
// Лабораторна робота № 7.2
// Опрацювання багатовимірних масивів ітераційним і рекурсивним способами
// Варіант 3

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void CreateArray(int** a, const int rowCount, const int colCount, const int Low, const int High, int i = 0, int j = 0);
void PrintArray(int** a, const int rowCount, const int colCount, int i = 0, int j = 0);
void SumMinElementsInRow(int** a, const int rowCount, const int colCount, int& sum, int i = 0, int i0 = 0, int MinElementInRow = 0);

int main()
{
    srand((unsigned)time(NULL));  // Ініціалізація генератора випадкових чисел

    const int Low = -50;  // Нижня межа випадкових чисел
    const int High = 50;  // Верхня межа випадкових чисел
    const int rowCount = 3;  // Кількість рядків
    const int colCount = 3;  // Кількість стовпців

    // Створення динамічного масиву
    int** a = new int* [rowCount]; // Виділення пам'яті для рядків масиву
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount]; // Виділення пам'яті для стовпців у кожному рядку

    // Заповнення масиву випадковими числами
    CreateArray(a, rowCount, colCount, Low, High);

    // Виведення початкового масиву
    cout << "Initial Array [" << rowCount << "x" << colCount << "]:" << endl;
    PrintArray(a, rowCount, colCount);  // Виведення початкового масиву

    int sum = 0;
    // Обчислення та виведення суми мінімальних елементів у кожному рядку
    SumMinElementsInRow(a, rowCount, colCount, sum);

    // Очищення пам'яті
    for (int i = 0; i < rowCount; i++)
        delete[] a[i];  // Звільнення пам'яті рядків
    delete[] a;  // Звільнення пам'яті масиву

    return 0;
}

// Функція для створення 2D масиву з випадковими числами
void CreateArray(int** a, const int rowCount, const int colCount, const int Low, const int High, int i, int j)
{
    // Генерація випадкового числа в заданому діапазоні
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

// Функція для виведення 2D масиву
void PrintArray(int** a, const int rowCount, const int colCount, int i, int j)
{
    cout << setw(5) << a[i][j];  // Виведення значень з форматуванням

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

// Функція для знаходження суми мінімальних елементів у рядках
void SumMinElementsInRow(int** a, const int rowCount, const int colCount, int& sum, int i, int i0, int MinElementInRow)
{
    if (i0 == 0)
    {
        MinElementInRow = a[i][0]; // Ініціалізація мінімального елемента першим елементом рядка
    }

    // Порівняння поточного елемента з наступним
    if (a[i][i0] < MinElementInRow) // Знаходження мінімального елемента
    {
        MinElementInRow = a[i][i0]; // Оновлення мінімального елемента
    }

    // Рекурсія для перебору стовпців
    if (i0 < colCount - 1) // Якщо не досягнуто кінця рядка
    {
        SumMinElementsInRow(a, rowCount, colCount, sum, i, i0 + 1, MinElementInRow);
    }
    else // Якщо досягнуто кінець рядка
    {
        sum += MinElementInRow; // Додаємо мінімальний елемент до суми
        if (i < rowCount - 1) // Якщо не досягнуто останнього рядка
        {
            SumMinElementsInRow(a, rowCount, colCount, sum, i + 1, 0, 0);
        }
        else // Якщо це останній рядок
        {
            cout << endl << endl;;
            cout << "Sum of min elements: " << sum << endl; // Виведення загальної суми
        }
    }
}
