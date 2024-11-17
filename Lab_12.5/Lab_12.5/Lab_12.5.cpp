// Lab_12_5.cpp
// < Величко Іван >
// Лабораторна робота № 12.5
// Структури, об’єднання та бінарні файли
// Варіант 3

#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>  // Для SetConsoleCP і SetConsoleOutputCP (для коректного відображення кирилиці)

using namespace std;

// Структура для студента
// Зберігає прізвище студента та його оцінки (масив з 5 оцінок)
struct Student {
    char surname[50];          // Прізвище студента
    int grades[5];             // Масив з оцінками (макс. 5 оцінок)
};

// Структура для групи
// Зберігає інформацію про групу: назва групи, кількість студентів та самі студенти
struct Group {
    char groupName[20];        // Назва групи
    int numStudents;           // Кількість студентів в групі
    Student students[30];      // Масив студентів (макс. 30 студентів в групі)
};

// Структура для факультету
// Зберігає інформацію про факультет: назва факультету, курс та групи факультету
struct Faculty {
    char name[50];             // Назва факультету
    int course;                // Курс факультету
    int numGroups;             // Кількість груп на факультеті
    Group groups[10];          // Масив груп факультету (макс. 10 груп на факультет)
};

// Функція для запису даних до файлу
// Записує всі дані про факультети, групи та студентів у бінарний файл
void SaveToFile(const Faculty* faculties, int numFaculties, const string& filename) {
    ofstream fout(filename, ios::binary);  // Відкриває файл для запису в бінарному режимі
    if (!fout) {                          // Перевірка чи вдалося відкрити файл
        cout << "Не вдалося відкрити файл для запису!" << endl;
        return;
    }

    // Проходимо по кожному факультету
    for (int i = 0; i < numFaculties; ++i) {
        // Записуємо факультет
        fout.write(reinterpret_cast<const char*>(&faculties[i]), sizeof(Faculty));

        // Проходимо по кожній групі на факультеті
        for (int j = 0; j < faculties[i].numGroups; ++j) {
            // Записуємо групу
            fout.write(reinterpret_cast<const char*>(&faculties[i].groups[j]), sizeof(Group));

            // Проходимо по кожному студенту в групі
            for (int k = 0; k < faculties[i].groups[j].numStudents; ++k) {
                // Записуємо студента
                fout.write(reinterpret_cast<const char*>(&faculties[i].groups[j].students[k]), sizeof(Student));
            }
        }
    }

    fout.close();  // Закриваємо файл
    cout << "Дані успішно записані в файл!" << endl;
}

// Функція для зчитування даних з файлу
// Зчитує дані з бінарного файлу і зберігає їх у масиві факультетів
void LoadFromFile(Faculty* faculties, int& numFaculties, const string& filename) {
    ifstream fin(filename, ios::binary);  // Відкриваємо файл для читання в бінарному режимі
    if (!fin) {                          // Перевірка чи вдалося відкрити файл
        cout << "Не вдалося відкрити файл для читання!" << endl;
        return;
    }

    // Читаємо факультети, поки є що зчитувати
    while (fin.read(reinterpret_cast<char*>(&faculties[numFaculties]), sizeof(Faculty))) {
        // Читаємо групи для поточного факультету
        for (int i = 0; i < faculties[numFaculties].numGroups; ++i) {
            fin.read(reinterpret_cast<char*>(&faculties[numFaculties].groups[i]), sizeof(Group));

            // Читаємо студентів для поточної групи
            for (int j = 0; j < faculties[numFaculties].groups[i].numStudents; ++j) {
                fin.read(reinterpret_cast<char*>(&faculties[numFaculties].groups[i].students[j]), sizeof(Student));
            }
        }
        ++numFaculties;  // Збільшуємо кількість факультетів
    }

    fin.close();  // Закриваємо файл
    cout << "Дані успішно зчитано з файлу!" << endl;
}

// Функція для введення оцінок студента
// Вводить оцінки для одного студента
void InputStudentGrades(Student& student, int maxGrades) {
    for (int i = 0; i < maxGrades; ++i) {
        cout << "Введіть оцінку #" << i + 1 << ": ";
        cin >> student.grades[i];  // Вводимо кожну оцінку
    }
}

// Функція для введення студентів в групу
// Вводить всі дані для студентів в одній групі
void InputGroup(Group& group, int maxStudents, int maxGrades) {
    cout << "Введіть назву групи: ";
    cin.ignore();  // Очищаємо буфер введення
    cin.getline(group.groupName, 20);  // Вводимо назву групи
    cout << "Введіть кількість студентів в групі: ";
    cin >> group.numStudents;  // Вводимо кількість студентів в групі

    // Вводимо студентів
    for (int i = 0; i < group.numStudents; ++i) {
        cout << "Введіть прізвище студента #" << i + 1 << ": ";
        cin.ignore();  // Очищаємо буфер введення
        cin.getline(group.students[i].surname, 50);  // Вводимо прізвище студента
        InputStudentGrades(group.students[i], maxGrades);  // Вводимо оцінки студента
    }
}

// Функція для введення факультету
// Вводить дані про факультет, включаючи групи та студентів
void InputFaculty(Faculty& faculty, int maxGroups, int maxStudents, int maxGrades) {
    cout << "Введіть назву факультету: ";
    cin.ignore();  // Очищаємо буфер введення
    cin.getline(faculty.name, 50);  // Вводимо назву факультету
    cout << "Введіть курс факультету: ";
    cin >> faculty.course;  // Вводимо курс факультету
    cout << "Введіть кількість груп: ";
    cin >> faculty.numGroups;  // Вводимо кількість груп на факультеті

    // Вводимо групи
    for (int i = 0; i < faculty.numGroups; ++i) {
        InputGroup(faculty.groups[i], maxStudents, maxGrades);  // Вводимо кожну групу
    }
}

// Функція для виведення всіх студентів
// Виводить список всіх студентів на всіх факультетах
void PrintAllStudents(const Faculty* faculties, int numFaculties) {
    cout << "Список всіх студентів:\n";
    for (int i = 0; i < numFaculties; ++i) {
        for (int j = 0; j < faculties[i].numGroups; ++j) {
            cout << "Група: " << faculties[i].groups[j].groupName << endl;
            for (int k = 0; k < faculties[i].groups[j].numStudents; ++k) {
                cout << "Прізвище: " << faculties[i].groups[j].students[k].surname << " | Оцінки: ";
                for (int l = 0; l < 5; ++l) {
                    cout << faculties[i].groups[j].students[k].grades[l] << " ";  // Виводимо оцінки студента
                }
                cout << endl;
            }
        }
    }
}

// Функція для виведення відмінників
// Виводить список студентів, які мають оцінки 4 або 5 у всіх предметах
void PrintExcellentStudents(const Faculty* faculties, int numFaculties, int maxGrades) {
    cout << "Список відмінників:\n";
    for (int i = 0; i < numFaculties; ++i) {
        for (int j = 0; j < faculties[i].numGroups; ++j) {
            for (int k = 0; k < faculties[i].groups[j].numStudents; ++k) {
                bool isExcellent = true;
                for (int l = 0; l < maxGrades; ++l) {
                    if (faculties[i].groups[j].students[k].grades[l] < 4) {  // Перевірка на відмінні оцінки
                        isExcellent = false;
                        break;
                    }
                }
                if (isExcellent) {
                    cout << faculties[i].groups[j].students[k].surname << endl;  // Виводимо відмінника
                }
            }
        }
    }
}

// Функція для пошуку факультету з найбільшою кількістю відмінників
// Шукає факультет з найбільшою кількістю студентів, які мають оцінки 4 або 5
void FindFacultyWithMostExcellentStudents(const Faculty* faculties, int numFaculties, int maxGrades) {
    int maxExcellent = 0;
    Faculty maxFaculty;

    // Шукаємо факультет з найбільшою кількістю відмінників
    for (int i = 0; i < numFaculties; ++i) {
        int excellentCount = 0;
        for (int j = 0; j < faculties[i].numGroups; ++j) {
            for (int k = 0; k < faculties[i].groups[j].numStudents; ++k) {
                bool isExcellent = true;
                for (int l = 0; l < maxGrades; ++l) {
                    if (faculties[i].groups[j].students[k].grades[l] < 4) {
                        isExcellent = false;
                        break;
                    }
                }
                if (isExcellent) {
                    ++excellentCount;
                }
            }
        }

        // Оновлюємо факультет з найбільшою кількістю відмінників
        if (excellentCount > maxExcellent) {
            maxExcellent = excellentCount;
            maxFaculty = faculties[i];
        }
    }

    cout << "Факультет з найбільшою кількістю відмінників: " << maxFaculty.name << endl;
}

// Функція для знаходження групи без двієчників
// Шукає групи, де немає студентів з оцінкою 2
void FindGroupWithoutFailures(const Faculty* faculties, int numFaculties, int maxGrades) {
    for (int i = 0; i < numFaculties; ++i) {
        for (int j = 0; j < faculties[i].numGroups; ++j) {
            bool hasFailures = false;
            for (int k = 0; k < faculties[i].groups[j].numStudents; ++k) {
                for (int l = 0; l < maxGrades; ++l) {
                    if (faculties[i].groups[j].students[k].grades[l] == 2) {  // Перевірка на двієчників
                        hasFailures = true;
                        break;
                    }
                }
                if (hasFailures) break;
            }
            if (!hasFailures) {
                cout << "Група без двієчників: " << faculties[i].groups[j].groupName << endl;
            }
        }
    }
}

// Основне меню
void ShowMenu() {
    cout << "\nМеню:\n";
    cout << "1. Створити новий файл\n";
    cout << "2. Зчитати з файлу\n";
    cout << "3. Вивести всіх студентів\n";
    cout << "4. Вивести відмінників\n";
    cout << "5. Знайти факультет з найбільшою кількістю відмінників\n";
    cout << "6. Знайти групу без двієчників\n";
    cout << "7. Вийти\n";
    cout << "Виберіть дію: ";
}

// Головна функція
int main() {
    // Встановлюємо кодову сторінку для консолі
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int MAX_FACULTIES = 10;
    const int MAX_GROUPS = 10;
    const int MAX_STUDENTS = 30;
    const int MAX_GRADES = 5;

    Faculty faculties[MAX_FACULTIES];  // Масив для збереження факультетів
    int numFaculties = 0;  // Кількість факультетів

    string filename;  // Ім'я файлу

    int choice;

    // Цикл для роботи з меню
    while (true) {
        ShowMenu();  // Показуємо меню
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Введіть ім'я файлу для збереження: ";
            cin >> filename;
            SaveToFile(faculties, numFaculties, filename);  // Зберігаємо дані у файл
            break;
        case 2:
            cout << "Введіть ім'я файлу для зчитування: ";
            cin >> filename;
            LoadFromFile(faculties, numFaculties, filename);  // Зчитуємо дані з файлу
            break;
        case 3:
            PrintAllStudents(faculties, numFaculties);  // Виводимо всіх студентів
            break;
        case 4:
            PrintExcellentStudents(faculties, numFaculties, MAX_GRADES);  // Виводимо відмінників
            break;
        case 5:
            FindFacultyWithMostExcellentStudents(faculties, numFaculties, MAX_GRADES);  // Знаходимо факультет з найбільшою кількістю відмінників
            break;
        case 6:
            FindGroupWithoutFailures(faculties, numFaculties, MAX_GRADES);  // Знаходимо групи без двієчників
            break;
        case 7:
            return 0;  // Завершуємо програму
        default:
            cout << "Невірний вибір! Спробуйте ще раз." << endl;
        }
    }

    return 0;  // Повернення значення, хоча цей код не досягне цього рядка
}
