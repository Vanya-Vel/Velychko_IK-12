// Lab_12_3 B.cpp
// < Величко Іван >
// Лабораторна робота № 12.3 B
// Впорядкування та бінарний пошук у бінарному файлі
// Варіант 3

#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <iomanip>

using namespace std;

// Перерахування спеціальностей
enum Speciality {
    ComputerScience = 0,
    SoftwareEngineering,
    CyberSecurity,
    PhysicsAndInformatics,
    MathematicsAndEconomics,
    Pedagogy
};

// Оцінки залежно від спеціальності
union Grades {
    int programming;
    int numericalMethods;
    int pedagogy;
};

// Структура студентів
struct Student {
    int id;
    char surname[50];
    int course;
    Speciality speciality;
    int physics;
    int math;
    Grades thirdGrade;
};

// Налаштування української локалі для консолі
void SetConsole() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
}

// Отримання назви спеціальності
string GetSpecialityName(Speciality speciality) {
    switch (speciality) {
    case ComputerScience: return "Комп'ютерні науки";
    case SoftwareEngineering: return "Програмна інженерія";
    case CyberSecurity: return "Кібербезпека";
    case PhysicsAndInformatics: return "Фізика та інформатика";
    case MathematicsAndEconomics: return "Математика та економіка";
    case Pedagogy: return "Педагогіка";
    default: return "Невідома спеціальність";
    }
}

// Вивід інформації про одного студента
void PrintStudent(const Student& student) {
    cout << left << setw(5) << student.id
        << setw(20) << student.surname
        << setw(10) << student.course
        << setw(20) << GetSpecialityName(student.speciality)
        << setw(10) << student.physics
        << setw(13) << student.math;

    switch (student.speciality) {
    case ComputerScience:
    case SoftwareEngineering:
    case CyberSecurity:
        cout << setw(15) << student.thirdGrade.programming;
        break;
    case PhysicsAndInformatics:
        cout << setw(15) << student.thirdGrade.numericalMethods;
        break;
    case MathematicsAndEconomics:
    case Pedagogy:
        cout << setw(15) << student.thirdGrade.pedagogy;
        break;
    default:
        cout << setw(15) << "N/A";
    }
    cout << endl;
}

// Введення даних студента
void InputStudent(Student& student, int& id) {
    student.id = id++;
    cin.ignore();

    cout << "Введіть прізвище: ";
    cin.getline(student.surname, 50);

    cout << "Введіть курс (1-5): ";
    cin >> student.course;

    int spec;
    cout << "Введіть спеціальність (0 - Комп'ютерні науки, 1 - Програмна інженерія, 2 - Кібербезпека, 3 - Фізика та інформатика, 4 - Математика та економіка, 5 - Педагогіка): ";
    cin >> spec;
    student.speciality = static_cast<Speciality>(spec);

    cout << "Введіть оцінку з фізики: ";
    cin >> student.physics;

    cout << "Введіть оцінку з математики: ";
    cin >> student.math;

    switch (student.speciality) {
    case ComputerScience:
    case SoftwareEngineering:
    case CyberSecurity:
        cout << "Введіть оцінку з програмування: ";
        cin >> student.thirdGrade.programming;
        break;
    case PhysicsAndInformatics:
        cout << "Введіть оцінку з чисельних методів: ";
        cin >> student.thirdGrade.numericalMethods;
        break;
    case MathematicsAndEconomics:
    case Pedagogy:
        cout << "Введіть оцінку з педагогіки: ";
        cin >> student.thirdGrade.pedagogy;
        break;
    }
}

// Створення нового файлу студентів
void CreateFile(const string& filename) {
    ofstream fout(filename, ios::binary);
    if (!fout) {
        cout << "Не вдалося відкрити файл для запису!" << endl;
        return;
    }

    int n;
    int id = 1; // Початкове значення для ID
    cout << "Введіть кількість студентів: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        Student student;
        InputStudent(student, id);
        fout.write(reinterpret_cast<const char*>(&student), sizeof(student));
    }

    fout.close();
    cout << "Файл успішно створено." << endl;
}

// Вивід усіх студентів з файлу
void PrintFile(const string& filename) {
    ifstream fin(filename, ios::binary);
    if (!fin) {
        cout << "Не вдалося відкрити файл для читання!" << endl;
        return;
    }

    cout << left << setw(5) << "ID"
        << setw(20) << "Прізвище"
        << setw(10) << "Курс"
        << setw(20) << "Спеціальність"
        << setw(10) << "Фізика"
        << setw(13) << "Математика"
        << setw(15) << "Третя оцінка" << endl;
    cout << string(88, '-') << endl;

    Student student;
    while (fin.read(reinterpret_cast<char*>(&student), sizeof(student))) {
        PrintStudent(student);
    }

    fin.close();
}

// Додавання нового студента до існуючого файлу
void AddStudentToFile(const string& filename) {
    ofstream fout(filename, ios::binary | ios::app);
    if (!fout) {
        cout << "Не вдалося відкрити файл для додавання!" << endl;
        return;
    }

    ifstream fin(filename, ios::binary);
    fin.seekg(0, ios::end);
    int fileSize = fin.tellg();
    int id = fileSize / sizeof(Student) + 1;  // Визначаємо наступний ID
    fin.close();

    Student student;
    InputStudent(student, id);

    fout.write(reinterpret_cast<const char*>(&student), sizeof(student));
    fout.close();
    cout << "Студента додано успішно." << endl;
}

// Головна функція
int main() {
    SetConsole();

    string filename;

    cout << "Введіть назву файлу для роботи: ";
    cin >> filename;

    while (true) {
        int choice;
        cout << "\nМеню:\n";
        cout << "1. Створити новий файл\n";
        cout << "2. Вивести файл\n";
        cout << "3. Додати студента\n";
        cout << "4. Вийти\n";
        cout << "Введіть вибір: ";
        cin >> choice;

        switch (choice) {
        case 1:
            CreateFile(filename);
            break;
        case 2:
            PrintFile(filename);
            break;
        case 3:
            AddStudentToFile(filename);
            break;
        case 4:
            return 0;
        default:
            cout << "Невірний вибір. Спробуйте ще раз." << endl;
        }
    }
}
