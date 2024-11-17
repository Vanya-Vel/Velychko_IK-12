// Lab_12_2 A.cpp
// < Величко Іван >
// Лабораторна робота № 12.2 A
// Послідовний пошук у бінарному файлі
// Варіант 3

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip> // Для форматування
#include <windows.h> // Для кодування Windows-1251

using namespace std;

// Перелік спеціальностей
enum Speciality { ComputerScience, SoftwareEngineering, CyberSecurity, Physics, Math };

// Структура студента
struct Student {
    int id;             // Порядковий номер
    char surname[50];   // Прізвище
    int course;         // Курс
    Speciality speciality; // Спеціальність
    int physics;        // Оцінка з фізики
    int math;           // Оцінка з математики
    int informatics;    // Оцінка з інформатики
};

// Функція для створення файлу студентів
void CreateStudentFile(const char* filename) {
    ofstream fout(filename, ios::binary); // Відкриваємо файл для запису
    int n;
    cout << "Кількість студентів: ";
    cin >> n;

    // Введення даних для студентів
    for (int i = 0; i < n; i++) {
        Student student;
        student.id = i + 1;
        cout << "Прізвище студента: ";
        cin >> student.surname;
        cout << "Курс (1-5): ";
        cin >> student.course;

        int spec;
        cout << "Спеціальність (0 - Computer Science, 1 - Software Engineering, 2 - Cyber Security, 3 - Physics, 4 - Math): ";
        cin >> spec;
        student.speciality = static_cast<Speciality>(spec); // Перетворення в тип Speciality

        // Введення оцінок
        cout << "Оцінка з фізики: ";
        cin >> student.physics;
        cout << "Оцінка з математики: ";
        cin >> student.math;
        cout << "Оцінка з інформатики: ";
        cin >> student.informatics;

        fout.write((char*)&student, sizeof(student)); // Запис у файл
    }
    fout.close(); // Закриваємо файл
}

// Функція підрахунку студентів з оцінкою "5" з фізики
void CountPhysicsFive(const char* filename, int& count) {
    ifstream fin(filename, ios::binary); // Відкриваємо файл для читання
    Student student;
    count = 0;

    // Підрахунок студентів з оцінкою "5" з фізики
    while (fin.read((char*)&student, sizeof(student))) {
        if (student.physics == 5) {
            count++;
        }
    }
    fin.close();
}

// Функція виведення студентів у таблицю
void PrintStudents(const char* filename) {
    ifstream fin(filename, ios::binary);
    Student student;

    // Форматований вивід таблиці
    cout << left << setw(5) << "ID" << setw(20) << "Прізвище" << setw(10) << "Курс"
        << setw(25) << "Спеціальність" << setw(10) << "Фізика" << setw(10) << "Математика"
        << setw(15) << "Інформатика" << endl;
    cout << "---------------------------------------------------------------" << endl;

    // Виведення кожного студента
    while (fin.read((char*)&student, sizeof(student))) {
        cout << left << setw(5) << student.id
            << setw(20) << student.surname
            << setw(10) << student.course
            << setw(25) << (student.speciality == ComputerScience ? "Computer Science" :
                student.speciality == SoftwareEngineering ? "Software Engineering" :
                student.speciality == CyberSecurity ? "Cyber Security" :
                student.speciality == Physics ? "Physics" : "Math")
            << setw(10) << student.physics
            << setw(10) << student.math
            << setw(15) << student.informatics << endl;
    }
    fin.close();
}

// Функція виведення студентів без трійок
void PrintStudentsWithoutThrees(const char* filename) {
    ifstream fin(filename, ios::binary);
    Student student;

    cout << "Студенти без трійок:" << endl;

    // Виведення студентів без трійок
    while (fin.read((char*)&student, sizeof(student))) {
        if (student.physics >= 4 && student.math >= 4 && student.informatics >= 4) {
            cout << student.surname << endl;
        }
    }
    fin.close();
}

int main() {
    // Встановлення кодування для вводу/виводу
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char filename[100];
    cout << "Введіть ім'я файлу: ";
    cin >> filename;

    // Створення файлу з даними студентів
    CreateStudentFile(filename);

    // Виведення всіх студентів
    PrintStudents(filename);

    // Виведення студентів без трійок
    PrintStudentsWithoutThrees(filename);

    // Підрахунок студентів з оцінкою "5" з фізики
    int physicsFiveCount = 0;
    CountPhysicsFive(filename, physicsFiveCount);
    cout << "Кількість студентів з оцінкою '5' з фізики: " << physicsFiveCount << endl;

    return 0; // Завершення програми
}
