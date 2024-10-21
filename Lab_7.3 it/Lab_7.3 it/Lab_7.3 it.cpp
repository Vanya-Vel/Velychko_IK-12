// Lab_7_3.cpp
// < Величко Іван >
// Лабораторна робота № 7.3
// Опрацювання динамічних багатовимірних масивів
// Варіант 3

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
    srand((unsigned)time(NULL));  // Ініціалізація генератора випадкових чисел

    const int Low = -50;  // Нижня межа випадкових чисел
    const int High = 50;  // Верхня межа випадкових чисел
    int rowCount, colCount;
    cout << "rowCount = "; cin >> rowCount;
    cout << "colCount = "; cin >> colCount;

    // Створення динамічного масиву
    int** a = new int* [rowCount]; // Виділення пам'яті для рядків масиву
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount]; // Виділення пам'яті для стовпців у кожному рядку

    // Заповнення масиву випадковими числами
    CreateArray(a, rowCount, colCount, Low, High);

    // Виведення початкового масиву
    cout << "Initial Array [" << rowCount << "x" << colCount << "]:" << endl;
    PrintArray(a, rowCount, colCount);  // Виведення початкового масиву

    int count = 0;
    NumberColZeroElement(a, rowCount, colCount, count);
    cout << "The number of columns with zero elements: " << count << endl; // Виведення кількості стовпців з нульовими елементами

    int max = -1;
    count = 1;
    NumberRowMaxSeriesOfIdenticalElements(a, rowCount, colCount, count, max); // Знаходження номера рядка з найбільшою серією однакових елементів

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

// Функція для підрахунку кількості стовпців з нульовими елементами
int NumberColZeroElement(int** a, const int rowCount, const int colCount, int& count)
{
    for (int i0 = 0; i0 < colCount; i0++)
    {
        for (int i = 0; i < rowCount; i++)
        {
            if (a[i][i0] == 0) // Перевірка на нуль у поточному стовпці
            {
                count++; // Збільшуємо лічильник
                break; // Вихід з циклу, якщо знайдено нуль
            }
        }
    }

    return count; // Повертаємо кількість стовпців з нулями
}

// Функція для знаходження номера рядка з максимальною серією однакових елементів
void NumberRowMaxSeriesOfIdenticalElements(int** a, const int rowCount, const int colCount, int& count, int& max)
{
    int NumRow = -1; // Номер рядка з максимальною серією

    for (int i = 0; i < rowCount; i++)
    {
        count = 1; // Ініціалізуємо count для нового рядка
        for (int j = 0; j < colCount - 1; j++)
        {
            if (a[i][j] == a[i][j + 1])
            {
                count++; // Збільшуємо count, якщо елементи однакові
            }
        }

        // Оновлення max, якщо поточний count більший
        if (max < count)
        {
            max = count; // Правильне присвоєння
            NumRow = i; // Запам'ятовуємо номер рядка
        }
    }

    // Виведення номера рядка з максимальною серією
    if (NumRow != -1 && max != 1) // Перевірка, чи була знайдена серія
    {
        cout << "Row with max series: " << NumRow + 1 << " (values: " << max << ")" << endl;
    }
    else
    {
        cout << "No identical elements found." << endl;
    }
}
