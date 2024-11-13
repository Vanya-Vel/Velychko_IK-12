// Lab_10_1 A.cpp
// < Величко Іван >
// Лабораторна робота № 10.1 A
// Послідовний пошук в масиві структур
// Варіант 3

#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>  // для SetConsoleCP та SetConsoleOutputCP

using namespace std;

// Перелік спеціальностей
// Визначаємо перелік спеціальностей (енумератор), які можуть мати студенти
enum class Speciality {
    COMPUTER_SCIENCE,
    MATHEMATICS,
    PHYSICS,
    ENGINEERING
};

// Функція для перетворення спеціальності у текстовий формат
// Повертає назву спеціальності у вигляді рядка, залежно від значення елемента Speciality
string getSpecialityName(Speciality speciality) {
    switch (speciality) {
    case Speciality::COMPUTER_SCIENCE: return "Комп'ютерні науки";
    case Speciality::MATHEMATICS: return "Математика";
    case Speciality::PHYSICS: return "Фізика";
    case Speciality::ENGINEERING: return "Інженерія";
    default: return "Невідомо";
    }
}

// Структура для зберігання інформації про студента
// Визначаємо структуру Student, яка зберігає ID студента, прізвище, курс, спеціальність та оцінки
struct Student {
    int id;                    // Порядковий номер студента у групі
    string surname;            // Прізвище студента
    int course;                // Курс студента
    Speciality speciality;     // Спеціальність студента
    int physicsGrade;          // Оцінка з фізики
    int mathGrade;             // Оцінка з математики
    int informaticsGrade;      // Оцінка з інформатики
};

// Функція для виведення таблиці з інформацією про студентів
// Виводить на екран відформатовану таблицю з основною інформацією про кожного студента
void printStudentTable(const Student students[], int size) {
    cout << left << setw(5) << "ID" << setw(15) << "Прізвище" << setw(8) << "Курс"
        << setw(20) << "Спеціальність" << setw(10) << "Фізика" << setw(15) << "Математика"
        << setw(15) << "Інформатика" << endl;
    cout << string(84, '-') << endl;
    for (int i = 0; i < size; ++i) {
        cout << left << setw(5) << students[i].id
            << setw(15) << students[i].surname
            << setw(8) << students[i].course
            << setw(22) << getSpecialityName(students[i].speciality)
            << setw(12) << students[i].physicsGrade
            << setw(16) << students[i].mathGrade
            << setw(15) << students[i].informaticsGrade
            << endl;
    }
    cout << string(84, '-') << endl;
}

// Функція для виведення студентів без трійок
// Виводить прізвища та інформацію про студентів, які не мають оцінок "3" з будь-якого предмету
void printStudentsWithoutThrees(const Student students[], int size) {
    cout << "\nСтуденти, які вчаться без трійок:\n";
    cout << left << setw(15) << "Прізвище" << setw(10) << "Курс" << setw(20) << "Спеціальність" << endl;
    cout << string(42, '-') << endl;
    for (int i = 0; i < size; ++i) {
        if (students[i].physicsGrade >= 4 && students[i].mathGrade >= 4 && students[i].informaticsGrade >= 4) {
            cout << left << setw(15) << students[i].surname
                << setw(10) << students[i].course
                << setw(20) << getSpecialityName(students[i].speciality)
                << endl;
        }
    }
    cout << string(42, '-') << endl;
}

// Функція для підрахунку студентів з оцінкою "5" з фізики
// Підраховує кількість студентів, які отримали максимальну оцінку з фізики (5)
void countStudentsWithFiveInPhysics(const Student students[], int size, int& count) {
    for (int i = 0; i < size; ++i) {
        if (students[i].physicsGrade == 5) {
            count++;
        }
    }
}

int main() {
    // Налаштування кодування для Windows
    SetConsoleCP(1251);          // Встановлення сторінки win-cp1251 для вводу
    SetConsoleOutputCP(1251);    // Встановлення сторінки win-cp1251 для виводу

    const int studentCount = 5; // Кількість студентів
    // Ініціалізація масиву студентів з фіксованою кількістю записів
    Student students[studentCount] = {
        {1, "Іваненко", 1, Speciality::COMPUTER_SCIENCE, 5, 4, 5},
        {2, "Петренко", 2, Speciality::MATHEMATICS, 4, 4, 4},
        {3, "Сидоренко", 1, Speciality::PHYSICS, 3, 5, 4},
        {4, "Коваленко", 3, Speciality::ENGINEERING, 5, 5, 5},
        {5, "Гриценко", 2, Speciality::COMPUTER_SCIENCE, 4, 3, 4}
    };

    // Виведення повної таблиці студентів
    cout << "Таблиця студентів:\n";
    printStudentTable(students, studentCount);

    // Виведення студентів без трійок
    printStudentsWithoutThrees(students, studentCount);

    // Підрахунок студентів, які отримали оцінку "5" з фізики
    int count = 0;
    countStudentsWithFiveInPhysics(students, studentCount, count);
    cout << "\nКількість студентів, які отримали оцінку '5' з фізики: " << count << endl;

    return 0;
}
