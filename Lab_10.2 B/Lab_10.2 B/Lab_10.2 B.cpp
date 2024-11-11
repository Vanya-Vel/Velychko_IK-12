#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>  // Для підтримки кирилиці в консолі

using namespace std;

enum Speciality { COMPUTER_SCIENCE, MATHEMATICS_AND_ECONOMICS, PHYSICS_AND_INFORMATICS, EDUCATION, INFORMATICS };

// Об'єднання для третьої оцінки в залежності від спеціальності
union Grade {
    int physicsGrade;           // Оцінка з фізики
    int programmingGrade;       // Оцінка з програмування (для "Комп’ютерні науки")
    int numericalMethodsGrade;  // Оцінка з чисельних методів (для "Інформатика")
    int pedagogyGrade;          // Оцінка з педагогіки (для інших спеціальностей)
};

// Структура для зберігання інформації про студента
struct Student {
    int id;                    // Ідентифікатор студента
    string lastName;           // Прізвище студента
    Speciality speciality;     // Спеціальність студента
    int physicsGrade;          // Оцінка з фізики
    int mathGrade;             // Оцінка з математики
    Grade thirdGrade;          // Третя оцінка (залежить від спеціальності)
    double averageGrade;       // Середній бал
};

// Функція для обчислення середнього балу студента
void calculateAverage(Student& student) {
    if (student.speciality == COMPUTER_SCIENCE)
        student.averageGrade = (student.physicsGrade + student.mathGrade + student.thirdGrade.programmingGrade) / 3.0;
    else if (student.speciality == INFORMATICS)
        student.averageGrade = (student.physicsGrade + student.mathGrade + student.thirdGrade.numericalMethodsGrade) / 3.0;
    else
        student.averageGrade = (student.physicsGrade + student.mathGrade + student.thirdGrade.pedagogyGrade) / 3.0;

    student.averageGrade = round(student.averageGrade * 100) / 100.0; // Округлюємо до 2 знаків після коми
}

// Сортування студентів за спеціальністю та середнім балом
void sortStudents(Student students[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (students[j].speciality > students[j + 1].speciality ||
                (students[j].speciality == students[j + 1].speciality && students[j].averageGrade < students[j + 1].averageGrade) ||
                (students[j].speciality == students[j + 1].speciality && students[j].averageGrade == students[j + 1].averageGrade && students[j].lastName > students[j + 1].lastName)) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

// Бінарний пошук студента за прізвищем, спеціальністю та середнім балом
bool binarySearchStudent(Student students[], int count, const string& lastName, Speciality speciality, double averageGrade) {
    int left = 0, right = count - 1; // Межі пошуку
    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Порівняння студентів за спеціальністю, середнім балом і прізвищем
        if (students[mid].speciality == speciality && students[mid].averageGrade == averageGrade && students[mid].lastName == lastName) {
            return true;
        }

        if (students[mid].speciality < speciality ||
            (students[mid].speciality == speciality && students[mid].averageGrade < averageGrade) ||
            (students[mid].speciality == speciality && students[mid].averageGrade == averageGrade && students[mid].lastName < lastName)) {
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

    for (int i = 0; i < count; ++i) {
        students[i].id = i + 1;

        cout << "Введіть прізвище студента: ";
        cin >> students[i].lastName;

        int specialityChoice;
        cout << "Виберіть спеціальність (0 - Комп’ютерні науки, 1 - Математика та економіка, 2 - Фізика та інформатика, 3 - Трудове навчання, 4 - Інформатика): ";
        cin >> specialityChoice;
        students[i].speciality = static_cast<Speciality>(specialityChoice);

        cout << "Введіть оцінку з фізики: ";
        cin >> students[i].physicsGrade;

        cout << "Введіть оцінку з математики: ";
        cin >> students[i].mathGrade;

        // Введення третьої оцінки в залежності від спеціальності
        if (students[i].speciality == COMPUTER_SCIENCE) {
            cout << "Введіть оцінку з програмування: ";
            cin >> students[i].thirdGrade.programmingGrade;
        }
        else if (students[i].speciality == INFORMATICS) {
            cout << "Введіть оцінку з чисельних методів: ";
            cin >> students[i].thirdGrade.numericalMethodsGrade;
        }
        else {
            cout << "Введіть оцінку з педагогіки: ";
            cin >> students[i].thirdGrade.pedagogyGrade;
        }

        // Обчислення середнього балу студента
        calculateAverage(students[i]);
    }
}

// Виведення таблиці студентів
void printStudents(Student students[], int count) {
    cout << left << setw(4) << "ID"
        << setw(15) << "Прізвище"
        << setw(30) << "Спеціальність"
        << setw(8) << "Фізика"
        << setw(12) << "Математика"
        << setw(14) << "Третя оцінка"
        << setw(12) << "Середній бал" << endl;
    cout << string(84, '-') << endl;

    for (int i = 0; i < count; ++i) {
        cout << left << setw(4) << students[i].id
            << setw(15) << students[i].lastName;

        // Виведення спеціальності
        switch (students[i].speciality) {
        case COMPUTER_SCIENCE: cout << setw(30) << "Комп’ютерні науки"; break;
        case MATHEMATICS_AND_ECONOMICS: cout << setw(30) << "Математика та економіка"; break;
        case PHYSICS_AND_INFORMATICS: cout << setw(30) << "Фізика та інформатика"; break;
        case EDUCATION: cout << setw(30) << "Трудове навчання"; break;
        case INFORMATICS: cout << setw(30) << "Інформатика"; break;
        }

        cout << setw(8) << students[i].physicsGrade
            << setw(12) << students[i].mathGrade;

        // Виведення третьої оцінки залежно від спеціальності
        if (students[i].speciality == COMPUTER_SCIENCE) {
            cout << setw(12) << students[i].thirdGrade.programmingGrade;
        }
        else if (students[i].speciality == INFORMATICS) {
            cout << setw(12) << students[i].thirdGrade.numericalMethodsGrade;
        }
        else {
            cout << setw(14) << students[i].thirdGrade.pedagogyGrade;
        }

        cout << setw(12) << students[i].averageGrade << endl;
    }
    cout << string(84, '-') << endl;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int count;
    Student students[100];  // Максимальна кількість студентів = 100

    inputStudentData(students, count);  // Введення даних про студентів

    sortStudents(students, count);  // Сортування студентів
    printStudents(students, count); // Виведення таблиці студентів

    // Пошук студента за прізвищем, спеціальністю та середнім балом
    string lastName;
    int specialityChoice;
    double averageGrade;

    cout << "Введіть прізвище студента: ";
    cin >> lastName;
    cout << "Виберіть спеціальність (0 - Комп’ютерні науки, 1 - Математика та економіка, 2 - Фізика та інформатика, 3 - Трудове навчання, 4 - Інформатика): ";
    cin >> specialityChoice;
    Speciality speciality = static_cast<Speciality>(specialityChoice);
    cout << "Введіть середній бал студента: ";
    cin >> averageGrade;

    if (binarySearchStudent(students, count, lastName, speciality, averageGrade)) {
        cout << "Студент знайдений!" << endl;
    }
    else {
        cout << "Студента не знайдено!" << endl;
    }

    return 0;
}
