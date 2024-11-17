// Lab_12_3 A.cpp
// < Величко Іван >
// Лабораторна робота № 12.3 A
// Впорядкування та бінарний пошук у бінарному файлі
// Варіант 3

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <windows.h> // Для SetConsoleCP та SetConsoleOutputCP

using namespace std;

// Перелік спеціальностей
enum Speciality { ComputerScience, SoftwareEngineering, CyberSecurity, Physics, Math };

// Структура студента
struct Student {
    int id;              // Порядковий номер студента
    char surname[50];    // Прізвище
    int course;          // Курс
    Speciality speciality;  // Спеціальність
    int physics;         // Оцінка з фізики
    int math;            // Оцінка з математики
    int informatics;     // Оцінка з інформатики
};

// Функція для створення файлу з даними студентів
void CreateFile(const char* filename) {
    ofstream fout(filename, ios::binary);
    if (!fout) {
        cout << "Не вдалося відкрити файл для запису." << endl;
        return;
    }

    int n;
    cout << "Введіть кількість студентів: ";
    cin >> n;
    cin.ignore(); // Очистити буфер вводу

    for (int i = 0; i < n; i++) {
        Student student;
        student.id = i + 1;

        cout << "Прізвище студента: ";
        cin.getline(student.surname, 50);

        cout << "Курс (1-5): ";
        while (!(cin >> student.course) || student.course < 1 || student.course > 5) {
            cout << "Невірний ввід. Введіть курс (1-5): ";
            cin.clear();
            cin.ignore(100, '\n');
        }

        cout << "Спеціальність (0 - Computer Science, 1 - Software Engineering, 2 - Cyber Security, 3 - Physics, 4 - Math): ";
        int spec;
        while (!(cin >> spec) || spec < 0 || spec > 4) {
            cout << "Невірний ввід. Введіть спеціальність (0-4): ";
            cin.clear();
            cin.ignore(100, '\n');
        }
        student.speciality = static_cast<Speciality>(spec);

        cout << "Оцінка з фізики: ";
        cin >> student.physics;
        cout << "Оцінка з математики: ";
        cin >> student.math;
        cout << "Оцінка з інформатики: ";
        cin >> student.informatics;
        cin.ignore(); // Очистити буфер вводу

        fout.write((char*)&student, sizeof(student));
    }

    fout.close();
    cout << "Файл успішно створено." << endl;
}

// Функція для додавання студента у файл
void AddStudent(const char* filename) {
    ofstream fout(filename, ios::binary | ios::app);
    if (!fout) {
        cout << "Не вдалося відкрити файл для додавання." << endl;
        return;
    }

    // Отримуємо останній ID студента
    ifstream fin(filename, ios::binary);
    Student lastStudent;
    int lastId = 0;

    fin.seekg(-static_cast<int>(sizeof(Student)), ios::end);
    if (fin.read((char*)&lastStudent, sizeof(Student))) {
        lastId = lastStudent.id;
    }
    fin.close();

    Student student;
    student.id = lastId + 1;

    cout << "Прізвище студента: ";
    cin.ignore();
    cin.getline(student.surname, 50);

    cout << "Курс (1-5): ";
    while (!(cin >> student.course) || student.course < 1 || student.course > 5) {
        cout << "Невірний ввід. Введіть курс (1-5): ";
        cin.clear();
        cin.ignore(100, '\n');
    }

    cout << "Спеціальність (0 - Computer Science, 1 - Software Engineering, 2 - Cyber Security, 3 - Physics, 4 - Math): ";
    int spec;
    while (!(cin >> spec) || spec < 0 || spec > 4) {
        cout << "Невірний ввід. Введіть спеціальність (0-4): ";
        cin.clear();
        cin.ignore(100, '\n');
    }
    student.speciality = static_cast<Speciality>(spec);

    cout << "Оцінка з фізики: ";
    cin >> student.physics;
    cout << "Оцінка з математики: ";
    cin >> student.math;
    cout << "Оцінка з інформатики: ";
    cin >> student.informatics;

    fout.write((char*)&student, sizeof(student));
    fout.close();
    cout << "Студент успішно доданий." << endl;
}

// Функція для виведення списку студентів
void PrintFile(const char* filename) {
    ifstream fin(filename, ios::binary);
    if (!fin) {
        cout << "Не вдалося відкрити файл для читання." << endl;
        return;
    }

    cout << left << setw(5) << "ID" << setw(20) << "Прізвище" << setw(10) << "Курс"
        << setw(20) << "Спеціальність" << setw(10) << "Фізика" << setw(13) << "Математика"
        << setw(10) << "Інформатика" << endl;
    cout << string(85, '-') << endl;

    Student student;
    while (fin.read((char*)&student, sizeof(student))) {
        cout << left << setw(5) << student.id
            << setw(20) << student.surname
            << setw(10) << student.course
            << setw(20) << (student.speciality == ComputerScience ? "Computer Science" :
                student.speciality == SoftwareEngineering ? "Software Engineering" :
                student.speciality == CyberSecurity ? "Cyber Security" :
                student.speciality == Physics ? "Physics" : "Math")
            << setw(10) << student.physics
            << setw(13) << student.math
            << setw(10) << student.informatics << endl;
    }

    fin.close();
}

// Меню програми
void Menu() {
    char filename[100];
    cout << "Введіть ім'я файлу: ";
    cin.getline(filename, 100);

    int choice;
    do {
        cout << "\nМеню:\n";
        cout << "1. Створити файл\n";
        cout << "2. Вивести файл\n";
        cout << "3. Додати студента\n";
        cout << "0. Вихід\n";
        cout << "Ваш вибір: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            CreateFile(filename);
            break;
        case 2:
            PrintFile(filename);
            break;
        case 3:
            AddStudent(filename);
            break;
        case 0:
            cout << "Вихід з програми." << endl;
            break;
        default:
            cout << "Невірний вибір. Спробуйте ще раз." << endl;
        }
    } while (choice != 0);
}

// Головна функція
int main() {
    // Встановлення кодування Windows-1251 для введення та виведення
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Menu();
    return 0;
}
