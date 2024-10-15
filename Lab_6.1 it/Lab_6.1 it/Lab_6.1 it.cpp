// Lab_06_1.cpp
// < Величко Іван >
// Лабораторна робота № 6.1
// Пошук елементів одновимірного масиву ітераційним та рекурсивним способом
// Варіант 0.4

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

// Функція для створення масиву випадкових чисел в заданому діапазоні
void CreateArray(int* array, const int size, const int Low, const int High)
{
    for (int i = 0; i < size; i++)
        array[i] = Low + rand() % (High - Low + 1); // Генерація випадкового числа
}

// Функція для виведення масиву на екран
void PrintArray(int* array, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(4) << array[i]; // Вивід кожного елемента
    cout << endl;
}

// Функція для обчислення суми всіх елементів масиву
void CalculateSum(int* array, const int size)
{
    int sum = 0; // Змінна для зберігання суми
    for (int i = 0; i < size; i++) {
        sum += array[i]; // Додавання значення до суми
    }
    cout << sum << endl; // Вивід суми
}

// Функція для виведення розміру масиву
void CountNumbers(int* array, const int size)
{
    cout << size << endl; // Вивід розміру
}

// Функція для виведення модифікованого масиву (значення < 0 або з непарними індексами)
void PrintModifiedArray(int* array, const int size)
{
    for (int i = 0; i < size; i++) {
        if (array[i] < 0 || i % 2 != 0) // Перевірка умов
            cout << setw(4) << array[i]; // Вивід значення
        else
            cout << setw(4) << 0;
    }
    cout << endl;
}

// Функція для обчислення суми модифікованих значень
void CalculateModifiedSum(int* array, const int size)
{
    int sum = 0; // Змінна для зберігання суми
    for (int i = 0; i < size; i++) {
        if (array[i] < 0 || i % 2 != 0) // Перевірка умов
            sum += array[i]; // Додавання значення до суми
    }
    cout << sum << endl; // Вивід суми модифікованих значень
}

// Функція для підрахунку кількості модифікованих елементів
void CountModifiedNumbers(int* array, const int size)
{
    int count = 0; // Лічильник кількості елементів
    for (int i = 0; i < size; i++) {
        if (array[i] < 0 || i % 2 != 0) { // Перевірка умов
            count++; // Збільшення лічильника
        }
    }
    cout << count << endl; // Вивід кількості
}

int main() {
    srand((unsigned)time(NULL)); // Ініціалізація генератора випадкових чисел

    const int n = 24; // Розмір масиву
    int a[n]; // Оголошення масиву
    int Low = -40; // Нижня межа діапазону
    int High = 20; // Верхня межа діапазону

    CreateArray(a, n, Low, High); // Виклик функції для створення масиву

    cout << "Original array:" << endl;
    PrintArray(a, n); // Вивід оригінального масиву
    cout << "Modified array:" << endl;
    PrintModifiedArray(a, n); // Вивід модифікованого масиву
    cout << "Sum of numbers:" << endl;
    CalculateSum(a, n); // Обчислення та вивід суми
    cout << "Count of elements:" << endl;
    CountNumbers(a, n); // Вивід розміру масиву
    cout << "Sum of modified numbers:" << endl;
    CalculateModifiedSum(a, n); // Обчислення та вивід суми модифікованих значень
    cout << "Count of modified numbers:" << endl;
    CountModifiedNumbers(a, n); // Підрахунок та вивід кількості модифікованих елементів

    return 0;
}
