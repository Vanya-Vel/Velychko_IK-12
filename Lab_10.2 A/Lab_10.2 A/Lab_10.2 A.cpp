// Lab_10_2 A.cpp
// < Величко Іван >
// Лабораторна робота № 10.2 A
// Впорядкування та бінарний пошук в масиві структур
// Варіант 3

#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>  // Для підтримки кирилиці в консолі

using namespace std;

// Перелік спеціальностей
enum Speciality { COMPUTER_SCIENCE, MATHEMATICS, PHYSICS };

// Структура для зберігання інформації про студента
struct Student {
    int id;                    // Ідентифікатор студента
    string lastName;           // Прізвище студента
    int course;                // Курс студента
    Speciality speciality;     // Спеціальність студента
    int physicsGrade;          // Оцінка з фізики
    int mathGrade;             // Оцінка з математики
    int informaticsGrade;      // Оцінка з інформатики
};

// Функція для обчислення середнього балу студента
double calculateAverage(const Student& student) {
    // Обчислює середнє значення оцінок з фізики, математики та інформатики,
    // округлене до двох знаків після коми.
    return round((student.physicsGrade + student.mathGrade + student.informaticsGrade) / 3.0 * 100) / 100.0;
}

// Функція для сортування студентів за спеціальністю, середнім балом і прізвищем
void sortStudents(Student students[], int count) {
    // Сортування за алгоритмом "бульбашка", використовуючи три критерії:
    // спеціальність, середній бал і прізвище.
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            // Порівняння спеціальності, середнього балу та прізвища
            if (students[j].speciality > students[j + 1].speciality ||
                (students[j].speciality == students[j + 1].speciality && calculateAverage(students[j]) > calculateAverage(students[j + 1])) ||
                (students[j].speciality == students[j + 1].speciality && calculateAverage(students[j]) == calculateAverage(students[j + 1]) && students[j].lastName > students[j + 1].lastName)) {
                // Обмін місцями студентів у разі порушення порядку
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

// Функція для побудови індексного масиву
void indexSortStudents(Student students[], int indexArray[], int count) {
    // Заповнення індексного масиву номерами студентів
    for (int i = 0; i < count; i++) {
        indexArray[i] = i;
    }

    // Сортування індексного масиву за тими ж критеріями, що й масив студентів
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            int index1 = indexArray[j];
            int index2 = indexArray[j + 1];
            // Порівняння студентів через індекси масиву
            if (students[index1].speciality > students[index2].speciality ||
                (students[index1].speciality == students[index2].speciality && calculateAverage(students[index1]) > calculateAverage(students[index2])) ||
                (students[index1].speciality == students[index2].speciality && calculateAverage(students[index1]) == calculateAverage(students[index2]) && students[index1].lastName > students[index2].lastName)) {
                // Обмін індексів для зміни порядку у масиві
                int temp = indexArray[j];
                indexArray[j] = indexArray[j + 1];
                indexArray[j + 1] = temp;
            }
        }
    }
}

// Функція для бінарного пошуку студента за прізвищем, спеціальністю та середнім балом
bool binarySearchStudent(Student students[], int count, const string& lastName, Speciality speciality, double average) {
    int left = 0, right = count - 1; // Межі пошуку у відсортованому масиві
    while (left <= right) {
        int mid = left + (right - left) / 2; // Середина відрізку
        double studentAvg = calculateAverage(students[mid]);
        // Якщо знайшли студента, що відповідає критеріям
        if (students[mid].speciality == speciality && studentAvg == average && students[mid].lastName == lastName) {
            return true;
        }
        // Якщо шуканий студент має бути далі за середину
        if (students[mid].speciality < speciality ||
            (students[mid].speciality == speciality && studentAvg < average) ||
            (students[mid].speciality == speciality && studentAvg == average && students[mid].lastName < lastName)) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return false; // Студент не знайдений
}

// Функція для введення даних про студентів
void inputStudentData(Student students[], int& count) {
    cout << "Введіть кількість студентів: ";
    cin >> count;

    // Введення даних для кожного студента
    for (int i = 0; i < count; ++i) {
        students[i].id = i + 1;

        cout << "Введіть прізвище студента: ";
        cin >> students[i].lastName;

        cout << "Введіть курс студента: ";
        cin >> students[i].course;

        int specialityChoice;
        cout << "Виберіть спеціальність (0 - Комп'ютерні науки, 1 - Математика, 2 - Фізика): ";
        cin >> specialityChoice;
        students[i].speciality = static_cast<Speciality>(specialityChoice);

        cout << "Введіть оцінку з фізики: ";
        cin >> students[i].physicsGrade;

        cout << "Введіть оцінку з математики: ";
        cin >> students[i].mathGrade;

        cout << "Введіть оцінку з інформатики: ";
        cin >> students[i].informaticsGrade;
    }
}

// Функція для виведення даних студентів у вигляді таблиці
void printStudents(Student students[], int count) {
    // Виведення заголовків таблиці
    cout << left << setw(4) << "ID"
        << setw(15) << "Прізвище"
        << setw(6) << "Курс"
        << setw(16) << "Спеціальність"
        << setw(8) << "Фізика"
        << setw(12) << "Математика"
        << setw(12) << "Інформатика" << endl;
    cout << string(72, '-') << endl;

    // Виведення даних для кожного студента
    for (int i = 0; i < count; ++i) {
        cout << left << setw(4) << students[i].id
            << setw(15) << students[i].lastName
            << setw(6) << students[i].course
            << setw(16) << students[i].speciality
            << setw(8) << students[i].physicsGrade
            << setw(12) << students[i].mathGrade
            << setw(12) << students[i].informaticsGrade << endl;
    }
    cout << string(72, '-') << endl;
}

int main() {
    // Налаштування підтримки кирилиці в консолі
    SetConsoleCP(1251);          // Установка кодування для введення
    SetConsoleOutputCP(1251);    // Установка кодування для виведення

    int count;
    Student students[100];  // Масив студентів, максимальна кількість 100

    inputStudentData(students, count);  // Введення даних студентів

    sortStudents(students, count);  // Сортування студентів
    printStudents(students, count); // Виведення таблиці студентів

    int indexArray[100];  // Індексний масив для збереження порядку студентів
    indexSortStudents(students, indexArray, count);  // Сортування індексів

    // Пошук студента з заданими критеріями
    string lastName;
    Speciality speciality;
    double average;

    cout << "Введіть прізвище студента для пошуку: ";
    cin >> lastName;

    int specialityChoice;
    cout << "Виберіть спеціальність для пошуку (0 - Комп'ютерні науки, 1 - Математика, 2 - Фізика): ";
    cin >> specialityChoice;
    // перетворює ціле число specialityChoice до типу Speciality за допомогою static_cast.
    // Це означає, що введене число тепер зберігається як значення перерахування Speciality, а не просто як число.
    speciality = static_cast<Speciality>(specialityChoice);

    cout << "Введіть середній бал для пошуку: ";
    cin >> average;

    bool found = binarySearchStudent(students, count, lastName, speciality, average);
    if (found) {
        cout << "Студента знайдено!\n";
    }
    else {
        cout << "Студента не знайдено.\n";
    }

    return 0;
}
