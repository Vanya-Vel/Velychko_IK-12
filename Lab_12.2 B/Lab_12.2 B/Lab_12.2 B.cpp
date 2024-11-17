// Lab_12_2 B.cpp
// < Величко Іван >
// Лабораторна робота № 12.2 B
// Послідовний пошук у бінарному файлі
// Варіант 3

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <windows.h>  // Для функцій SetConsoleCP та SetConsoleOutputCP, які дозволяють змінювати кодування

using namespace std;

// Перелік спеціальностей, що дозволяє використовувати більш читабельні значення замість чисел
enum Speciality {
    ComputerScience,        // 0 - Інформатика
    SoftwareEngineering,    // 1 - Програмна інженерія
    CyberSecurity,          // 2 - Кібербезпека
    Physics,                // 3 - Фізика
    Math                    // 4 - Математика
};

// Структура для зберігання даних про студента
struct Student {
    int id;                   // Порядковий номер студента
    char surname[50];         // Прізвище студента (масив для зберігання до 50 символів)
    int course;               // Курс студента (число від 1 до 5)
    Speciality speciality;    // Спеціальність студента (одне з значень enum Speciality)
    int physics;              // Оцінка з фізики (від 1 до 5)
    int math;                 // Оцінка з математики (від 1 до 5)
    int programming;          // Оцінка з програмування (тільки для студентів спеціальності ComputerScience)
    int numericalMethods;     // Оцінка з чисельних методів (для спеціальностей SoftwareEngineering, CyberSecurity)
    int pedagogy;             // Оцінка з педагогіки (для спеціальностей Physics, Math)
};

// Функція для створення бінарного файлу зі студентами
void CreateStudentFile(const char* filename) {
    ofstream fout(filename, ios::binary); // Відкриваємо файл для запису в бінарному режимі
    int n;
    cout << "Кількість студентів: ";  // Запитуємо кількість студентів, яких треба додати в файл
    cin >> n;

    for (int i = 0; i < n; i++) {  // Цикл для введення даних кожного студента
        Student student;  // Створюємо змінну для зберігання інформації про студента
        student.id = i + 1;  // Призначаємо порядковий номер студента

        // Введення даних студента
        cout << "Прізвище студента: ";  // Запитуємо прізвище
        cin >> student.surname;
        cout << "Курс (1-5): ";  // Запитуємо курс студента
        cin >> student.course;

        int spec;
        // Запитуємо спеціальність студента (вводиться число, яке перетворюється в значення enum)
        cout << "Спеціальність (0 - Computer Science, 1 - Software Engineering, 2 - Cyber Security, 3 - Physics, 4 - Math): ";
        cin >> spec;
        student.speciality = static_cast<Speciality>(spec);  // Преобразуємо введене число в тип Speciality

        // Введення оцінок для кожної дисципліни
        cout << "Оцінка з фізики: ";
        cin >> student.physics;
        cout << "Оцінка з математики: ";
        cin >> student.math;

        // Визначаємо оцінку з програмування, чисельних методів та педагогіки, в залежності від спеціальності
        if (student.speciality == ComputerScience) {
            cout << "Оцінка з програмування: ";
            cin >> student.programming;
        }
        else {
            student.programming = -1;  // Якщо спеціальність не "Computer Science", то це поле не використовується
        }

        if (student.speciality == SoftwareEngineering || student.speciality == CyberSecurity) {
            cout << "Оцінка з чисельних методів: ";
            cin >> student.numericalMethods;
        }
        else {
            student.numericalMethods = -1;  // Якщо спеціальність не "Software Engineering" або "Cyber Security", то це поле не використовується
        }

        if (student.speciality == Physics || student.speciality == Math) {
            cout << "Оцінка з педагогіки: ";
            cin >> student.pedagogy;
        }
        else {
            student.pedagogy = -1;  // Якщо спеціальність не "Physics" або "Math", то це поле не використовується
        }

        // Записуємо інформацію про студента в бінарний файл
        fout.write((char*)&student, sizeof(student));
    }

    fout.close();  // Закриваємо файл після запису
}

// Функція для виведення списку всіх студентів у вигляді таблиці
void PrintStudents(const char* filename) {
    ifstream fin(filename, ios::binary);  // Відкриваємо файл для читання в бінарному вигляді
    Student student;

    // Форматований вивід заголовка таблиці
    cout << left << setw(5) << "ID" << setw(20) << "Прізвище" << setw(10) << "Курс"
        << setw(25) << "Спеціальність" << setw(10) << "Фізика" << setw(13) << "Математика"
        << setw(15) << "Програмування" << setw(20) << "Чисельні методи" << setw(15) << "Педагогіка" << endl;

    // Розділяємо заголовок від таблиці лінією
    cout << setfill('-') << setw(5) << "-" << setw(20) << "-" << setw(10) << "-"
        << setw(25) << "-" << setw(10) << "-" << setw(10) << "-"
        << setw(15) << "-" << setw(20) << "-" << setw(15) << "-" << endl;
    cout << setfill(' ');  // Повертаємо стандартну заповнювачку пробілами для виведення

    // Читаємо і виводимо кожного студента
    while (fin.read((char*)&student, sizeof(student))) {
        cout << left << setw(5) << student.id
            << setw(20) << student.surname
            << setw(10) << student.course
            << setw(25) << (student.speciality == ComputerScience ? "Computer Science" :
                student.speciality == SoftwareEngineering ? "Software Engineering" :
                student.speciality == CyberSecurity ? "Cyber Security" :
                student.speciality == Physics ? "Physics" : "Math")
            << setw(10) << student.physics
            << setw(13) << student.math;

        // Виводимо оцінки для спеціальних дисциплін
        cout << setw(15) << (student.programming != -1 ? to_string(student.programming) : "-")
            << setw(20) << (student.numericalMethods != -1 ? to_string(student.numericalMethods) : "-")
            << setw(15) << (student.pedagogy != -1 ? to_string(student.pedagogy) : "-") << endl;
    }

    fin.close();  // Закриваємо файл після читання
}

// Функція для виведення студентів, які не мають трійок
void PrintStudentsWithoutThrees(const char* filename) {
    ifstream fin(filename, ios::binary);  // Відкриваємо файл для читання в бінарному вигляді
    Student student;

    cout << "Студенти без трійок:" << endl;
    // Читаємо і перевіряємо оцінки кожного студента
    while (fin.read((char*)&student, sizeof(student))) {
        // Якщо студент має оцінки не менше 4 з фізики і математики
        if (student.physics >= 4 && student.math >= 4) {
            // Для спеціальності "Computer Science" перевіряємо оцінку з програмування
            if (student.speciality == ComputerScience && student.programming >= 4) {
                cout << student.surname << endl;  // Виводимо прізвище студента
            }
            // Для спеціальностей "Physics" або "Math" перевіряємо оцінку з педагогіки
            else if (student.speciality == Physics || student.speciality == Math) {
                if (student.pedagogy >= 4) {
                    cout << student.surname << endl;  // Виводимо прізвище студента
                }
            }
        }
    }
    fin.close();  // Закриваємо файл після читання
}

// Функція для підрахунку студентів з оцінкою "5" з фізики
void CountPhysicsFive(const char* filename, int& count) {
    ifstream fin(filename, ios::binary);  // Відкриваємо файл для читання в бінарному вигляді
    Student student;
    count = 0;

    // Читаємо кожного студента і перевіряємо оцінку з фізики
    while (fin.read((char*)&student, sizeof(student))) {
        if (student.physics == 5) {
            count++;  // Якщо оцінка з фізики дорівнює 5, збільшуємо лічильник
        }
    }
    fin.close();  // Закриваємо файл після читання
}

int main() {
    // Встановлення кодування Windows-1251 для коректного виведення кирилиці
    SetConsoleCP(1251);  // Встановлення кодування для введення
    SetConsoleOutputCP(1251);  // Встановлення кодування для виведення

    char filename[100];

    // Запитуємо у користувача ім'я файлу для роботи
    cout << "Введіть ім'я файлу: ";
    cin >> filename;

    // Створюємо файл зі студентами
    CreateStudentFile(filename);

    // Виводимо вміст файлу
    PrintStudents(filename);

    // Виводимо студентів без трійок
    PrintStudentsWithoutThrees(filename);

    // Підраховуємо кількість студентів з оцінкою "5" з фізики
    int physicsFiveCount = 0;
    CountPhysicsFive(filename, physicsFiveCount);
    cout << "Кількість студентів з оцінкою '5' з фізики: " << physicsFiveCount << endl;

    return 0;
}
