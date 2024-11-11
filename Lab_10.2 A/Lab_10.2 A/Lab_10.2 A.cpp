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
    // Округлює середнє значення до 2 знаків після коми
    return round((student.physicsGrade + student.mathGrade + student.informaticsGrade) / 3.0 * 100) / 100.0;
}

// Сортування студентів за спеціальністю, середнім балом та прізвищем
void sortStudents(Student students[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            // Порівнюються спеціальність, середній бал і прізвище
            if (students[j].speciality > students[j + 1].speciality ||
                (students[j].speciality == students[j + 1].speciality && calculateAverage(students[j]) > calculateAverage(students[j + 1])) ||
                (students[j].speciality == students[j + 1].speciality && calculateAverage(students[j]) == calculateAverage(students[j + 1]) && students[j].lastName > students[j + 1].lastName)) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

// Функція для побудови індексного масиву, який містить індекси студентів
void indexSortStudents(Student students[], int indexArray[], int count) {
    // Заповнення індексного масиву
    for (int i = 0; i < count; i++) {
        indexArray[i] = i;
    }

    // Сортування індексного масиву за тими ж критеріями, що й сортовані студенти
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            int index1 = indexArray[j];
            int index2 = indexArray[j + 1];
            // Порівняння індексів за тим же принципом, що й сортування студентів
            if (students[index1].speciality > students[index2].speciality ||
                (students[index1].speciality == students[index2].speciality && calculateAverage(students[index1]) > calculateAverage(students[index2])) ||
                (students[index1].speciality == students[index2].speciality && calculateAverage(students[index1]) == calculateAverage(students[index2]) && students[index1].lastName > students[index2].lastName)) {
                int temp = indexArray[j];
                indexArray[j] = indexArray[j + 1];
                indexArray[j + 1] = temp;
            }
        }
    }
}

// Бінарний пошук студента за прізвищем, спеціальністю та середнім балом
bool binarySearchStudent(Student students[], int count, const string& lastName, Speciality speciality, double average) {
    int left = 0, right = count - 1; // Межі пошуку: left — це початок масиву, а right — це кінець масиву
    while (left <= right) {
        int mid = left + (right - left) / 2;
        double studentAvg = calculateAverage(students[mid]);
        // Перевірка на збіг прізвища, спеціальності та середнього балу
        if (students[mid].speciality == speciality && studentAvg == average && students[mid].lastName == lastName) {
            return true;
        }
        // Пошук студента, порівнюючи критерії
        if (students[mid].speciality < speciality ||
            (students[mid].speciality == speciality && studentAvg < average) ||
            (students[mid].speciality == speciality && studentAvg == average && students[mid].lastName < lastName)) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return false;
}

// Введення даних про студентів
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

// Виведення таблиці студентів
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

    // Виведення даних студентів
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
    // Підтримка кирилиці в консолі
    SetConsoleCP(1251);          // Встановлення сторінки win-cp1251 для вводу
    SetConsoleOutputCP(1251);    // Встановлення сторінки win-cp1251 для виводу

    int count;
    Student students[100];  // Максимальна кількість студентів = 100

    inputStudentData(students, count);  // Введення даних про студентів

    sortStudents(students, count);  // Сортування студентів
    printStudents(students, count); // Виведення таблиці студентів

    int indexArray[100];  // Індексний масив для 100 студентів
    indexSortStudents(students, indexArray, count);  // Сортування індексів

    // Перевірка наявності студента за допомогою бінарного пошуку
    string lastName;
    Speciality speciality;
    double average;

    cout << "Введіть прізвище студента для пошуку: ";
    cin >> lastName;

    int specialityChoice;
    cout << "Виберіть спеціальність для пошуку (0 - Комп'ютерні науки, 1 - Математика, 2 - Фізика): ";
    cin >> specialityChoice;
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
