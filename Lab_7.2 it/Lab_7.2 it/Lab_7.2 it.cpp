// Lab_7_2.cpp
// < Величко Іван >
// Лабораторна робота № 7.2
// Опрацювання багатовимірних масивів ітераційним і рекурсивним способами
// Варіант 3
#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void CreateArray(int** a, const int rowCount, const int colCount, const int Low, const int High);
void PrintArray(int** a, const int rowCount, const int colCount);
void SumMinElementsInRow(int** a, const int rowCount, const int colCount, int& sum);


int main()
{
    srand((unsigned)time(NULL));  // Ініціалізація генератора випадкових чисел

    const int Low = -50;  // Нижня межа випадкових чисел
    const int High = 50;  // Верхня межа випадкових чисел
    const int rowCount = 10;  // Кількість рядків
    const int colCount = 7;  // Кількість стовпців

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
void CreateArray(int** a, const int rowCount, const int colCount, const int Low, const int High)
{
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
        {
            // Генерація випадкового числа в заданому діапазоні
            a[i][j] = Low + rand() % (High - Low + 1);
        }
}

// Функція для виведення 2D масиву
void PrintArray(int** a, const int rowCount, const int colCount)
{
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
            cout << setw(5) << a[i][j];  // Виведення значень з форматуванням
        cout << endl;  // Новий рядок після кожного рядка
    }
    cout << endl;  // Додатковий рядок для відступу
}

// Функція для знаходження суми мінімальних елементів у рядках
void SumMinElementsInRow(int** a, const int rowCount, const int colCount, int& sum)
{
    int MinElementInRow = 0; // Змінна для збереження мінімального елемента в рядку

    // Проходження по всіх рядках матриці
    for (int i = 0; i < rowCount; i++)
    {
        MinElementInRow = a[i][0]; // Ініціалізація мінімального елемента першим елементом рядка

        // Проходження по всіх стовпцях в поточному рядку
        for (int i0 = 1; i0 < colCount; i0++) // Перебір з другого елемента
        {
            // Порівняння поточного елемента з наступним
            if (a[i][i0] < MinElementInRow) // Знаходження мінімального елемента
            {
                MinElementInRow = a[i][i0]; // Оновлення мінімального елемента
            }
        }
        sum += MinElementInRow; // Додавання мінімального елемента до суми
    }
    cout << "Sum of min elements: " << sum << endl; // Виведення суми мінімальних елементів
}
