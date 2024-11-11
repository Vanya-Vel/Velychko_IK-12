// Lab_10_1 B.cpp
// < Величко Іван >
// Лабораторна робота № 10.1 B
// Послідовний пошук в масиві структур
// Варіант 3

#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>  // для SetConsoleCP та SetConsoleOutputCP

using namespace std;

// Перелік спеціальностей
enum class Speciality {
    COMPUTER_SCIENCE,
    INFORMATICS,
    MATH_ECONOMICS,
    PHYSICS_INFORMATICS,
    LABOR_TRAINING
};

// Функція для перетворення спеціальності у текстовий формат
string getSpecialityName(Speciality speciality) {
    switch (speciality) {
    case Speciality::COMPUTER_SCIENCE: return "Комп'ютерні науки";
    case Speciality::INFORMATICS: return "Інформатика";
    case Speciality::MATH_ECONOMICS: return "Математика та економіка";
    case Speciality::PHYSICS_INFORMATICS: return "Фізика та інформатика";
    case Speciality::LABOR_TRAINING: return "Трудове навчання";
    default: return "Невідомо";
    }
}

// Структура для зберігання інформації про студента
struct Student {
    int id;                    // Порядковий номер студента у групі
    string surname;            // Прізвище студента
    int course;                // Курс студента
    Speciality speciality;     // Спеціальність студента
    int physicsGrade;          // Оцінка з фізики
    int mathGrade;             // Оцінка з математики
    union {
        int programmingGrade;  // Оцінка з програмування (для COMPUTER_SCIENCE)
        int numericalMethodsGrade; // Оцінка з чисельних методів (для INFORMATICS)
        int pedagogyGrade;     // Оцінка з педагогіки (для інших спеціальностей)
    } additionalGrade;         // Об'єднання для третьої оцінки
};

// Функція для виведення таблиці з інформацією про студентів
void printStudentTable(const Student students[], int size) {
    cout << left << setw(4) << "ID"
        << setw(15) << "Прізвище"
        << setw(6) << "Курс"
        << setw(25) << "Спеціальність"
        << setw(8) << "Фізика"
        << setw(12) << "Математика"
        << setw(15) << "Програмування" 
        << setw(17) << "Чисельні методи" 
        << setw(10) << "Педагогіка" << endl;
    cout << string(112, '-') << endl;

    for (int i = 0; i < size; ++i) {
        cout << left << setw(4) << students[i].id
            << setw(15) << students[i].surname
            << setw(6) << students[i].course
            << setw(25) << getSpecialityName(students[i].speciality)
            << setw(8) << students[i].physicsGrade
            << setw(12) << students[i].mathGrade;

        // Вивід додаткової оцінки залежно від спеціальності
        if (students[i].speciality == Speciality::COMPUTER_SCIENCE) {
            cout << setw(15) << students[i].additionalGrade.programmingGrade
                << setw(17) << "-"  // Порожнє місце для чисельних методів
                << setw(10) << "-"; // Порожнє місце для педагогіки
        }
        else if (students[i].speciality == Speciality::INFORMATICS) {
            cout << setw(15) << "-"  // Порожнє місце для програмування
                << setw(17) << students[i].additionalGrade.numericalMethodsGrade
                << setw(10) << "-"; // Порожнє місце для педагогіки
        }
        else {
            cout << setw(15) << "-"  // Порожнє місце для програмування
                << setw(17) << "-"  // Порожнє місце для чисельних методів
                << setw(10) << students[i].additionalGrade.pedagogyGrade;
        }
        cout << endl;
    }
    cout << string(112, '-') << endl;
}

// Функція для виведення студентів без трійок
void printStudentsWithoutThrees(const Student students[], int size) {
    cout << "\nСтуденти, які вчаться без трійок:\n";
    cout << left << setw(15) << "Прізвище" << setw(10) << "Курс" << setw(20) << "Спеціальність" << endl;
    cout << string(46, '-') << endl;
    for (int i = 0; i < size; ++i) {
        if (students[i].physicsGrade >= 4 && 
            students[i].mathGrade >= 4 && 
            students[i].additionalGrade.programmingGrade >= 4 &&
            students[i].additionalGrade.numericalMethodsGrade >= 4 &&
            students[i].additionalGrade.pedagogyGrade >= 4) {
            cout << left << setw(15) << students[i].surname
                 << setw(10) << students[i].course
                 << setw(20) << getSpecialityName(students[i].speciality)
                 << endl;
        }
    }
    cout << string(46, '-') << endl;
}

// Функція для підрахунку студентів з оцінкою "5" з фізики
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
    Student students[studentCount] = {
        {1, "Іваненко", 1, Speciality::COMPUTER_SCIENCE, 5, 4},
        {2, "Петренко", 2, Speciality::INFORMATICS, 4, 4},
        {3, "Сидоренко", 1, Speciality::MATH_ECONOMICS, 3, 5},
        {4, "Коваленко", 3, Speciality::PHYSICS_INFORMATICS, 5, 5},
        {5, "Гриценко", 2, Speciality::LABOR_TRAINING, 4, 3}
    };

    // Ініціалізація додаткових оцінок
    students[0].additionalGrade.programmingGrade = 5;
    students[1].additionalGrade.numericalMethodsGrade = 4;
    students[2].additionalGrade.pedagogyGrade = 5;
    students[3].additionalGrade.pedagogyGrade = 4;
    students[4].additionalGrade.pedagogyGrade = 3;

    // Виведення таблиці студентів
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
