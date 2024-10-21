// Lab_7_1.cpp
// < Величко Іван >
// Лабораторна робота № 7.1.
// Пошук заданих елементів та впорядкування рядків / стовпчиків матриці.
// Варіант 3

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

// Функція для обміну рядків масиву
void Change(int** a, int row1, int row2, int colCount, int j = 0);

// Функція для створення 2D масиву з випадковими числами
void CreateArray(int** a, const int rowCount, const int colCount, const int Low, const int High, int i = 0, int j = 0)
{
    a[i][j] = Low + rand() % (High - Low + 1); // Заповнення масиву випадковими числами

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
void PrintArray(int** a, const int rowCount, const int colCount, int i = 0, int j = 0)
{
    cout << setw(5) << a[i][j]; // Виведення елемента масиву

    if (j < colCount - 1)
    {
        PrintArray(a, rowCount, colCount, i, j + 1); // Рекурсивний виклик для наступного стовпця
    }
    else if (i < rowCount - 1)
    {
        cout << endl; // Перехід на новий рядок
        PrintArray(a, rowCount, colCount, i + 1, 0); // Рекурсивний виклик для наступного рядка
    }
}

// Функція для сортування масиву за специфічними критеріями
void SortArray(int** a, const int rowCount, const int colCount, int i0 = 0, int i = 0, int j = 0)
{
    // Перевірка умов для обміну рядків масиву на основі значень у першому, другому та третьому стовпцях
    if ((a[i][0] > a[i + 1][0]) || // Порівняння першого стовпця
        (a[i][0] == a[i + 1][0] && a[i][1] < a[i + 1][1]) || // Порівняння другого стовпця, якщо перші однакові
        ((a[i][0] == a[i + 1][0] && a[i][1] == a[i + 1][1]) && a[i][2] > a[i + 1][2])) // Третій стовпець по зростанню
    {
        Change(a, i, i + 1, colCount); // Виклик функції для обміну рядків
    }

    // Рекурсивний виклик для сортування наступного рядка
    if (i < colCount - 1 - i0)
    {
        SortArray(a, rowCount, colCount, i0, i + 1); // Перехід до наступного елемента в поточному рядку
    }
    else if (i0 < rowCount - 1) // Якщо досягнуто кінця рядка, переходьте до наступного рядка
    {
        SortArray(a, rowCount, colCount, i0 + 1, 0); // Скидання індексу стовпця для нового рядка
    }
}


// Функція для обміну елементів
void Change(int** a, const int row1, const int row2, const int colCount, int j)
{
    int tmp = a[row1][j]; // Збереження значення
    a[row1][j] = a[row2][j]; // Обмін значеннями
    a[row2][j] = tmp;

    if (j < colCount - 1)
    {
        Change(a, row1, row2, colCount, j + 1); // Рекурсивний виклик для наступного стовпця
    }
}

// Функція для підрахунку кількості позитивних чисел, які кратні 5
void Number(int** a, const int rowCount, const int colCount, int& number, int i = 0, int j = 0)
{
    // Перевірка, чи число позитивне і кратне 5
    if (a[i][j] > 0 && a[i][j] % 5 == 0)
    {
        number++; // Збільшення лічильника
    }

    if (j < colCount - 1)
    {
       Number(a, rowCount, colCount, number, i, j + 1); // Рекурсивний виклик для наступного стовпця
    }
    else if (i < rowCount - 1)
    {
        Number(a, rowCount, colCount, number, i + 1, 0); // Рекурсивний виклик для наступного рядка
    }
    else
    {
        cout << "Number: " << number << endl; // Виведення кількості
    }
}

// Функція для підрахунку суми позитивних чисел, які кратні 5
void Sum(int** a, const int rowCount, const int colCount, int sum = 0, int i = 0, int j = 0)
{
    // Перевірка, чи число позитивне і кратне 5
    if (a[i][j] > 0 && a[i][j] % 5 == 0)
    {
        sum += a[i][j]; // Додавання до суми
    }

    if (j < colCount - 1)
    {
        Sum(a, rowCount, colCount, sum, i, j + 1); // Рекурсивний виклик для наступного стовпця
    }
    else if (i < rowCount - 1)
    {
        Sum(a, rowCount, colCount, sum, i + 1, 0); // Рекурсивний виклик для наступного рядка
    }
    else
    {
        cout << "Sum: " << sum << endl; // Виведення суми
    }
}

// Функція для модифікації масиву: обнулення позитивних чисел, кратних 5
void ModifiedArray(int** a, const int rowCount, const int colCount, int i = 0, int j = 0)
{
    // Обнулення позитивних чисел, кратних 5
    if (a[i][j] > 0 && a[i][j] % 5 == 0)
    {
        a[i][j] = 0; // Обнулення
    }

    if (j < colCount - 1)
    {
        ModifiedArray(a, rowCount, colCount, i, j + 1); // Рекурсивний виклик для наступного стовпця
    }
    else if (i < rowCount - 1)
    {
        ModifiedArray(a, rowCount, colCount, i + 1, 0); // Рекурсивний виклик для наступного рядка
    }
}

int main()
{
    srand((unsigned)time(NULL));  // Ініціалізація генератора випадкових чисел

    const int Low = -42;  // Нижня межа випадкових чисел
    const int High = 51;  // Верхня межа випадкових чисел
    const int rowCount = 7;  // Кількість рядків
    const int colCount = 6;  // Кількість стовпців

    // Створення динамічного масиву
    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    // Заповнення масиву випадковими числами
    CreateArray(a, rowCount, colCount, Low, High);

    // Виведення початкового масиву
    cout << "Initial Array:" << endl;
    PrintArray(a, rowCount, colCount); cout << endl << endl;
    Sum(a, rowCount, colCount); // Підрахунок суми

    int number = 0;
    Number(a, rowCount, colCount, number); cout << endl;  // Підрахунок кількості

    // Сортування масиву
    SortArray(a, rowCount, colCount);
    cout << "Sorted Array:" << endl;
    PrintArray(a, rowCount, colCount); cout << endl;

    // Модифікація масиву
    ModifiedArray(a, rowCount, colCount); cout << endl;
    cout << "Modified Array:" << endl;
    PrintArray(a, rowCount, colCount); cout << endl;

    // Очищення пам'яті
    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0; // Завершення програми
}
