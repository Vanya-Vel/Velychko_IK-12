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

// Перерахування спеціальностей студентів
// Перерахування дозволяє присвоювати студентам різні спеціальності, які потім будуть відображатись у програмі.
enum Speciality {
    ComputerScience = 0,      // 0: Комп'ютерні науки
    SoftwareEngineering,      // 1: Програмна інженерія
    CyberSecurity,            // 2: Кібербезпека
    PhysicsAndInformatics,    // 3: Фізика та інформатика
    MathematicsAndEconomics,  // 4: Математика та економіка
    Pedagogy                  // 5: Педагогіка
};

// Спеціальний тип даних для оцінок
// За допомогою union можна економити пам'ять, оскільки всі оцінки зберігаються в одній області пам'яті.
union Grades {
    int programming;           // Оцінка з програмування
    int numericalMethods;      // Оцінка з чисельних методів
    int pedagogy;              // Оцінка з педагогіки
};

// Структура для зберігання даних студентів
// Всі основні дані про студента зберігаються в цій структурі.
struct Student {
    int id;                    // ID студента
    char surname[50];          // Прізвище студента
    int course;                // Курс студента (1-5)
    Speciality speciality;     // Спеціальність студента
    int physics;               // Оцінка з фізики
    int math;                  // Оцінка з математики
    Grades thirdGrade;         // Третя оцінка залежить від спеціальності
};

// Налаштування української локалі для коректного відображення кирилиці
void SetConsole() {
    SetConsoleCP(1251);       // Встановлюємо кодування для введення з консолі
    SetConsoleOutputCP(1251); // Встановлюємо кодування для виведення в консоль
}

// Отримання назви спеціальності з перерахунку Speciality
// В залежності від значення спеціальності повертається її назва.
string GetSpecialityName(Speciality speciality) {
    switch (speciality) {
    case ComputerScience: return "Комп'ютерні науки";
    case SoftwareEngineering: return "Програмна інженерія";
    case CyberSecurity: return "Кібербезпека";
    case PhysicsAndInformatics: return "Фізика та інформатика";
    case MathematicsAndEconomics: return "Математика та економіка";
    case Pedagogy: return "Педагогіка";
    default: return "Невідома спеціальність"; // Якщо спеціальність не знайдена
    }
}

// Функція для виведення інформації про одного студента
// Для кожного студента виводиться його ID, прізвище, курс, спеціальність та оцінки.
void PrintStudent(const Student& student) {
    cout << left << setw(5) << student.id                      // Виведення ID студента
        << setw(20) << student.surname                          // Виведення прізвища студента
        << setw(10) << student.course                           // Виведення курсу студента
        << setw(20) << GetSpecialityName(student.speciality)    // Виведення спеціальності студента
        << setw(10) << student.physics                          // Виведення оцінки з фізики
        << setw(13) << student.math                             // Виведення оцінки з математики
        ;

    // Виведення третьої оцінки в залежності від спеціальності
    switch (student.speciality) {
    case ComputerScience:
    case SoftwareEngineering:
    case CyberSecurity:
        cout << setw(15) << student.thirdGrade.programming;       // Програмування
        break;
    case PhysicsAndInformatics:
        cout << setw(15) << student.thirdGrade.numericalMethods; // Чисельні методи
        break;
    case MathematicsAndEconomics:
    case Pedagogy:
        cout << setw(15) << student.thirdGrade.pedagogy;         // Педагогіка
        break;
    default:
        cout << setw(15) << "N/A";                               // Якщо спеціальність не визначена
    }
    cout << endl;
}

// Введення даних одного студента
// Функція дозволяє вводити всі дані студента: ID, прізвище, курс, спеціальність та оцінки.
void InputStudent(Student& student, int& id) {
    student.id = id++;  // Присвоюємо студенту унікальний ID
    cin.ignore();       // Очищаємо буфер вводу

    cout << "Введіть прізвище: ";
    cin.getline(student.surname, 50);  // Вводимо прізвище студента

    cout << "Введіть курс (1-5): ";
    cin >> student.course;  // Вводимо курс студента

    int spec;
    cout << "Введіть спеціальність (0 - Комп'ютерні науки, 1 - Програмна інженерія, 2 - Кібербезпека, 3 - Фізика та інформатика, 4 - Математика та економіка, 5 - Педагогіка): ";
    cin >> spec;  // Вводимо спеціальність студента
    student.speciality = static_cast<Speciality>(spec);

    cout << "Введіть оцінку з фізики: ";
    cin >> student.physics;  // Вводимо оцінку з фізики

    cout << "Введіть оцінку з математики: ";
    cin >> student.math;  // Вводимо оцінку з математики

    // Вводимо оцінку для третього предмета в залежності від спеціальності
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

// Створення нового бінарного файлу студентів
// Функція створює файл і записує в нього інформацію про студентів.
void CreateFile(const string& filename) {
    ofstream fout(filename, ios::binary);  // Відкриваємо файл для запису в бінарному форматі
    if (!fout) {
        cout << "Не вдалося відкрити файл для запису!" << endl;
        return;
    }

    int n;
    int id = 1;  // Початкове значення для ID
    cout << "Введіть кількість студентів: ";
    cin >> n;

    // Вводимо інформацію для кожного студента
    for (int i = 0; i < n; i++) {
        Student student;
        InputStudent(student, id);  // Викликаємо функцію для введення даних студента
        fout.write(reinterpret_cast<const char*>(&student), sizeof(student));  // Записуємо студента у файл
    }

    fout.close();  // Закриваємо файл після запису
    cout << "Файл успішно створено." << endl;
}

// Виведення інформації про всіх студентів з бінарного файлу
// Читаємо та виводимо кожного студента з файлу.
void PrintFile(const string& filename) {
    ifstream fin(filename, ios::binary);  // Відкриваємо файл для читання в бінарному форматі
    if (!fin) {
        cout << "Не вдалося відкрити файл для читання!" << endl;
        return;
    }

    // Виведення заголовку таблиці
    cout << left << setw(5) << "ID"
        << setw(20) << "Прізвище"
        << setw(10) << "Курс"
        << setw(20) << "Спеціальність"
        << setw(10) << "Фізика"
        << setw(13) << "Математика"
        << setw(15) << "Третя оцінка" << endl;
    cout << string(88, '-') << endl;

    Student student;
    // Читаємо кожного студента з файлу і виводимо його дані
    while (fin.read(reinterpret_cast<char*>(&student), sizeof(student))) {
        PrintStudent(student);
    }

    fin.close();  // Закриваємо файл після читання
}

// Додавання нового студента до існуючого файлу
// Додаємо нового студента в кінець існуючого бінарного файлу.
void AddStudentToFile(const string& filename) {
    ofstream fout(filename, ios::binary | ios::app);  // Відкриваємо файл для додавання в кінець
    if (!fout) {
        cout << "Не вдалося відкрити файл для додавання!" << endl;
        return;
    }

    ifstream fin(filename, ios::binary);  // Відкриваємо файл для читання
    fin.seekg(0, ios::end);  // Переміщаємо вказівник на кінець файлу
    int fileSize = fin.tellg();  // Визначаємо розмір файлу
    int id = fileSize / sizeof(Student) + 1;  // Визначаємо наступний ID для нового студента
    fin.close();

    Student student;
    InputStudent(student, id);  // Вводимо дані для нового студента

    fout.write(reinterpret_cast<const char*>(&student), sizeof(student));  // Записуємо студента в файл
    fout.close();  // Закриваємо файл після додавання
    cout << "Студента додано успішно." << endl;
}

// Головна функція програми
int main() {
    SetConsole();  // Налаштування консолі

    string filename;
    cout << "Введіть назву файлу для роботи: ";
    cin >> filename;  // Вводимо ім'я файлу для роботи

    while (true) {
        int choice;
        // Меню для вибору операції
        cout << "\nМеню:\n";
        cout << "1. Створити новий файл\n";
        cout << "2. Вивести файл\n";
        cout << "3. Додати студента\n";
        cout << "4. Вийти\n";
        cout << "Введіть вибір: ";
        cin >> choice;

        switch (choice) {
        case 1:
            CreateFile(filename);  // Створення нового файлу
            break;
        case 2:
            PrintFile(filename);  // Виведення вмісту файлу
            break;
        case 3:
            AddStudentToFile(filename);  // Додавання студента до файлу
            break;
        case 4:
            return 0;  // Вихід з програми
        default:
            cout << "Невірний вибір. Спробуйте ще раз." << endl;  // Обробка невірного вибору
        }
    }
}
