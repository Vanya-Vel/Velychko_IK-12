// Lab_12_3 A.cpp
// < Величко Іван >
// Лабораторна робота № 12.3 A
// Впорядкування та бінарний пошук у бінарному файлі
// Варіант 3

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <windows.h> // Для SetConsoleCP та SetConsoleOutputCP (для встановлення кодування Windows-1251)

using namespace std;

// Перелік спеціальностей (для зручності використовується enum)
enum Speciality {
    ComputerScience,      // 0: Комп'ютерні науки
    SoftwareEngineering,  // 1: Програмна інженерія
    CyberSecurity,        // 2: Кібербезпека
    Physics,              // 3: Фізика
    Math                  // 4: Математика
};

// Структура для зберігання даних студента
struct Student {
    int id;              // Порядковий номер студента
    char surname[50];    // Прізвище студента
    int course;          // Курс студента (1-5)
    Speciality speciality;  // Спеціальність студента (за допомогою enum)
    int physics;         // Оцінка з фізики
    int math;            // Оцінка з математики
    int informatics;     // Оцінка з інформатики
};

// Функція для створення файлу з даними студентів
void CreateFile(const char* filename) {
    ofstream fout(filename, ios::binary);  // Відкриваємо файл для запису в бінарному форматі
    if (!fout) {
        cout << "Не вдалося відкрити файл для запису." << endl;
        return;
    }

    int n;
    cout << "Введіть кількість студентів: ";
    cin >> n;
    cin.ignore(); // Очистити буфер вводу

    // Цикл для введення даних студентів
    for (int i = 0; i < n; i++) {
        Student student;
        student.id = i + 1;  // Присвоюємо порядковий номер

        // Введення прізвища студента
        cout << "Прізвище студента: ";
        cin.getline(student.surname, 50);

        // Введення курсу студента (перевірка правильності вводу)
        cout << "Курс (1-5): ";
        while (!(cin >> student.course) || student.course < 1 || student.course > 5) {
            cout << "Невірний ввід. Введіть курс (1-5): ";
            cin.clear();  // Очищаємо потік
            cin.ignore(100, '\n');  // Ігноруємо залишки даних у буфері
        }

        // Введення спеціальності студента (перевірка правильності вводу)
        cout << "Спеціальність (0 - Computer Science, 1 - Software Engineering, 2 - Cyber Security, 3 - Physics, 4 - Math): ";
        int spec;
        while (!(cin >> spec) || spec < 0 || spec > 4) {
            cout << "Невірний ввід. Введіть спеціальність (0-4): ";
            cin.clear();
            cin.ignore(100, '\n');
        }
        student.speciality = static_cast<Speciality>(spec);  // Присвоюємо спеціальність студенту

        // Введення оцінок з фізики, математики та інформатики
        cout << "Оцінка з фізики: ";
        cin >> student.physics;
        cout << "Оцінка з математики: ";
        cin >> student.math;
        cout << "Оцінка з інформатики: ";
        cin >> student.informatics;
        cin.ignore(); // Очистити буфер вводу після отримання оцінок

        // Записуємо дані студента у файл
        fout.write((char*)&student, sizeof(student));
    }

    fout.close();  // Закриваємо файл
    cout << "Файл успішно створено." << endl;
}

// Функція для додавання нового студента в файл
void AddStudent(const char* filename) {
    ofstream fout(filename, ios::binary | ios::app);  // Відкриваємо файл в режимі додавання
    if (!fout) {
        cout << "Не вдалося відкрити файл для додавання." << endl;
        return;
    }

    // Отримуємо останній ID студента для коректного присвоєння новому студенту
    ifstream fin(filename, ios::binary);  // Відкриваємо файл для читання
    Student lastStudent;
    int lastId = 0;

    fin.seekg(-static_cast<int>(sizeof(Student)), ios::end);  // Переходимо до кінця файлу
    if (fin.read((char*)&lastStudent, sizeof(Student))) {
        lastId = lastStudent.id;  // Читаємо останнього студента та отримуємо його ID
    }
    fin.close();  // Закриваємо файл

    Student student;
    student.id = lastId + 1;  // Присвоюємо наступний ID

    // Введення даних нового студента
    cout << "Прізвище студента: ";
    cin.ignore();  // Очищаємо буфер вводу
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

    // Введення оцінок
    cout << "Оцінка з фізики: ";
    cin >> student.physics;
    cout << "Оцінка з математики: ";
    cin >> student.math;
    cout << "Оцінка з інформатики: ";
    cin >> student.informatics;

    // Записуємо нового студента в файл
    fout.write((char*)&student, sizeof(student));
    fout.close();
    cout << "Студент успішно доданий." << endl;
}

// Функція для виведення даних всіх студентів з файлу
void PrintFile(const char* filename) {
    ifstream fin(filename, ios::binary);  // Відкриваємо файл для читання
    if (!fin) {
        cout << "Не вдалося відкрити файл для читання." << endl;
        return;
    }

    // Виведення заголовку таблиці
    cout << left << setw(5) << "ID" << setw(20) << "Прізвище" << setw(10) << "Курс"
        << setw(20) << "Спеціальність" << setw(10) << "Фізика" << setw(13) << "Математика"
        << setw(10) << "Інформатика" << endl;
    cout << string(85, '-') << endl;

    Student student;
    // Читаємо кожного студента і виводимо його дані
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

    fin.close();  // Закриваємо файл
}

// Функція для виведення головного меню програми
void Menu() {
    char filename[100];  // Змінна для зберігання імені файлу
    cout << "Введіть ім'я файлу: ";
    cin.getline(filename, 100);

    int choice;
    do {
        // Виведення меню
        cout << "\nМеню:\n";
        cout << "1. Створити файл\n";
        cout << "2. Вивести файл\n";
        cout << "3. Додати студента\n";
        cout << "0. Вихід\n";
        cout << "Ваш вибір: ";
        cin >> choice;
        cin.ignore();  // Очистити буфер вводу

        // Обробка вибору користувача
        switch (choice) {
        case 1:
            CreateFile(filename);  // Створення нового файлу
            break;
        case 2:
            PrintFile(filename);  // Виведення даних з файлу
            break;
        case 3:
            AddStudent(filename);  // Додавання нового студента
            break;
        case 0:
            cout << "Вихід з програми." << endl;
            break;
        default:
            cout << "Невірний вибір. Спробуйте ще раз." << endl;
        }
    } while (choice != 0);  // Повторюємо меню, поки користувач не вибере вихід
}

// Головна функція програми
int main() {
    // Встановлення кодування Windows-1251 для коректного відображення кирилиці
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Menu();  // Виклик основного меню
    return 0;
}
