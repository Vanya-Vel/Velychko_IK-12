// Lab_7_1.cpp
// < Величко Іван >
// Лабораторна робота № 7.1.
// Пошук заданих елементів та впорядкування рядків / стовпчиків матриці.
// Варіант 3

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void CreateArray(int** a, const int rowCount, const int colCount, const int Low, const int High);
void PrintArray(int** a, const int rowCount, const int colCount);
void SortArray(int** a, const int rowCount, const int colCount);
void Change(int** a, int row1, int row2, int colCount);
void Number(int** a, const int rowCount, const int colCount, int& number);
void Sum(int** a, const int rowCount, const int colCount);
void ModifiedArray(int** a, const int rowCount, const int colCount);



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
    PrintArray(a, rowCount, colCount);  // Виведення початкового масиву
    Sum(a, rowCount, colCount);  // Підрахунок суми
    int number = 0;
    Number(a, rowCount, colCount, number); cout << endl;  // Підрахунок кількості

    // Сортування масиву
    SortArray(a, rowCount, colCount);  // Сортування масиву
    cout << "Sorted Array:" << endl;
    PrintArray(a, rowCount, colCount);  // Виведення відсортованого масиву

    // Модифікація масиву
    ModifiedArray(a, rowCount, colCount);  // Модифікація масиву
    cout << "Modified Array:" << endl;
    PrintArray(a, rowCount, colCount);  // Виведення модифікованого масиву

    // Очищення пам'яті
    for (int i = 0; i < rowCount; i++)
        delete[] a[i];  // Звільнення пам'яті рядків
    delete[] a;  // Звільнення пам'яті масиву

    return 0;  // Завершення програми
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

// Функція для сортування масиву за специфічними критеріями
void SortArray(int** a, const int rowCount, const int colCount)
{
    // Впорядкування за стовпцями 0 ↑, 1 ↓, 2 ↑
    for (int i0 = 0; i0 < rowCount - 1; i0++)
    {
        for (int i = 0; i < rowCount - 1 - i0; i++)
        {
            // Порівняння значень у вказаних стовпцях
            if ((a[i][0] > a[i + 1][0]) ||
                (a[i][0] == a[i + 1][0] && a[i][1] < a[i + 1][1]) ||
                ((a[i][0] == a[i + 1][0] && a[i][1] == a[i + 1][1]) && a[i][2] > a[i + 1][2])) // Третій стовпець по зростанню
            {
                Change(a, i, i + 1, colCount);  // Виклик функції обміну рядків
            }
        }
    }
}

// Функція для обміну елементів
void Change(int** a, const int row1, const int row2, const int colCount)
{
    int tmp;
    for (int j = 0; j < colCount; j++)  // Міняємо елементи у рядках
    {
        tmp = a[row1][j];
        a[row1][j] = a[row2][j];
        a[row2][j] = tmp;
    }
}

// Функція для підрахунку кількості позитивних чисел, які кратні 5
void Number(int** a, const int rowCount, const int colCount, int& number)
{

    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
        {
            // Перевірка на позитивне число, яке кратне 5
            if (a[i][j] > 0 && a[i][j] % 5 == 0)
                number++;  // Збільшення лічильника
        }
    }
    cout << "Amount: " << number << endl;  // Вивід кількості
}

// Функція для підрахунку суми позитивних чисел, які кратні 5
void Sum(int** a, const int rowCount, const int colCount)
{
    int sum = 0;
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
        {
            // Додавання до суми
            if (a[i][j] > 0 && a[i][j] % 5 == 0)
                sum += a[i][j];  // Додавання елемента до суми
        }
    }
    cout << "Sum: " << sum << endl;  // Вивід суми
}

// Функція для модифікації масиву: обнулення позитивних чисел, кратних 5
void ModifiedArray(int** a, const int rowCount, const int colCount)
{
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
        {
            // Обнулення чисел, які позитивні і кратні 5
            if (a[i][j] > 0 && a[i][j] % 5 == 0)
            {
                a[i][j] = 0;  // Обнулення
            }
        }
    }
}
