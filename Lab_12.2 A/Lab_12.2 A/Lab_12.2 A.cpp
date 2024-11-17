// Lab_12_2 A.cpp
// < Величко Іван >
// Лабораторна робота № 12.2 A
// Послідовний пошук у бінарному файлі
// Варіант 3

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip> // Бібліотека для форматування виводу (для роботи з виведенням у таблицю)
#include <windows.h> // Бібліотека для налаштування кодування Windows-1251 для вводу/виводу

using namespace std;

// Перелік спеціальностей студентів
enum Speciality {
    ComputerScience,     // Комп'ютерні науки
    SoftwareEngineering, // Програмна інженерія
    CyberSecurity,       // Кібербезпека
    Physics,             // Фізика
    Math                 // Математика
};

// Структура для зберігання даних про студента
struct Student {
    int id;             // Порядковий номер студента
    char surname[50];   // Прізвище студента
    int course;         // Курс студента (1-5)
    Speciality speciality; // Спеціальність студента (перелічені значення з enum)
    int physics;        // Оцінка з фізики
    int math;           // Оцінка з математики
    int informatics;    // Оцінка з інформатики
};

// Функція для створення файлу студентів
void CreateStudentFile(const char* filename) {
    ofstream fout(filename, ios::binary); // Відкриваємо файл для запису в бінарному вигляді
    int n;
    cout << "Кількість студентів: "; // Запитуємо кількість студентів
    cin >> n;

    // Цикл для введення даних для кожного студента
    for (int i = 0; i < n; i++) {
        Student student; // Створюємо об'єкт студента
        student.id = i + 1; // Призначаємо порядковий номер

        // Вводимо дані про студента
        cout << "Прізвище студента: ";
        cin >> student.surname;
        cout << "Курс (1-5): ";
        cin >> student.course;

        int spec;
        // Запитуємо спеціальність та перетворюємо введену цифру в тип Speciality
        cout << "Спеціальність (0 - Computer Science, 1 - Software Engineering, 2 - Cyber Security, 3 - Physics, 4 - Math): ";
        cin >> spec;
        student.speciality = static_cast<Speciality>(spec); // Присвоюємо спеціальність

        // Вводимо оцінки з фізики, математики та інформатики
        cout << "Оцінка з фізики: ";
        cin >> student.physics;
        cout << "Оцінка з математики: ";
        cin >> student.math;
        cout << "Оцінка з інформатики: ";
        cin >> student.informatics;

        // Записуємо дані студента в бінарний файл
        fout.write((char*)&student, sizeof(student));
    }
    fout.close(); // Закриваємо файл після запису
}

// Функція для підрахунку кількості студентів з оцінкою "5" з фізики
void CountPhysicsFive(const char* filename, int& count) {
    ifstream fin(filename, ios::binary); // Відкриваємо файл для читання в бінарному режимі
    Student student; // Створюємо об'єкт студента для зчитування даних
    count = 0; // Ініціалізація лічильника студентів

    // Читаємо кожного студента з файлу і перевіряємо оцінку з фізики
    while (fin.read((char*)&student, sizeof(student))) {
        if (student.physics == 5) { // Якщо оцінка з фізики дорівнює 5
            count++; // Збільшуємо лічильник
        }
    }
    fin.close(); // Закриваємо файл після читання
}

// Функція для виведення списку всіх студентів у вигляді таблиці
void PrintStudents(const char* filename) {
    ifstream fin(filename, ios::binary); // Відкриваємо файл для читання в бінарному режимі
    Student student; // Створюємо об'єкт студента

    // Форматований вивід заголовка таблиці
    cout << left << setw(5) << "ID" << setw(20) << "Прізвище" << setw(10) << "Курс"
        << setw(25) << "Спеціальність" << setw(10) << "Фізика" << setw(10) << "Математика"
        << setw(15) << "Інформатика" << endl;

    // Виведення роздільної лінії для таблиці
    cout << "---------------------------------------------------------------"
        << "---------------------------------" << endl;

    // Читаємо і виводимо дані кожного студента
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
    fin.close(); // Закриваємо файл після читання
}

// Функція для виведення студентів, у яких не було трійок
void PrintStudentsWithoutThrees(const char* filename) {
    ifstream fin(filename, ios::binary); // Відкриваємо файл для читання в бінарному режимі
    Student student; // Створюємо об'єкт студента

    cout << "Студенти без трійок:" << endl;

    // Читаємо кожного студента і перевіряємо, чи немає трійок у оцінках
    while (fin.read((char*)&student, sizeof(student))) {
        if (student.physics >= 4 && student.math >= 4 && student.informatics >= 4) {
            cout << student.surname << endl; // Виводимо прізвище студента, якщо він не має трійок
        }
    }
    fin.close(); // Закриваємо файл після читання
}

int main() {
    // Встановлення кодування Windows-1251 для вводу/виводу, щоб коректно обробляти українські символи
    SetConsoleCP(1251); // Встановлення кодування Windows-1251 для вводу
    SetConsoleOutputCP(1251); // Встановлення кодування Windows-1251 для виводу

    char filename[100]; // Масив для зберігання імені файлу

    cout << "Введіть ім'я файлу: "; // Запитуємо у користувача ім'я файлу
    cin >> filename;

    // Створюємо бінарний файл з даними про студентів
    CreateStudentFile(filename);

    // Виводимо список студентів з файлу
    PrintStudents(filename);

    // Виводимо студентів, у яких немає трійок
    PrintStudentsWithoutThrees(filename);

    // Підраховуємо студентів, у яких оцінка "5" з фізики
    int physicsFiveCount = 0;
    CountPhysicsFive(filename, physicsFiveCount);  // Результат передається через посилання
    cout << "Кількість студентів з оцінкою '5' з фізики: " << physicsFiveCount << endl;

    return 0; // Завершення програми
}
