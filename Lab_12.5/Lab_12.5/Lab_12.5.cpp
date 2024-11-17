// Lab_12_5.cpp
// < Величко Іван >
// Лабораторна робота № 12.5
// Структури, об’єднання та бінарні файли
// Варіант 3

#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>  // Для SetConsoleCP і SetConsoleOutputCP

using namespace std;

// Структура для студента
struct Student {
    char surname[50];          // Прізвище студента
    int grades[5];             // Масив з оцінками
};

// Структура для групи
struct Group {
    char groupName[20];        // Назва групи
    int numStudents;           // Кількість студентів у групі
    Student students[30];      // Масив студентів
};

// Структура для факультету
struct Faculty {
    char name[50];             // Назва факультету
    int course;                // Курс факультету
    int numGroups;             // Кількість груп
    Group groups[10];          // Масив груп
};

// Функція для запису даних до файлу
void SaveToFile(const Faculty* faculties, int numFaculties, const string& filename) {
    ofstream fout(filename, ios::binary);
    if (!fout) {
        cout << "Не вдалося відкрити файл для запису!" << endl;
        return;
    }

    for (int i = 0; i < numFaculties; ++i) {
        fout.write(reinterpret_cast<const char*>(&faculties[i]), sizeof(Faculty));
        for (int j = 0; j < faculties[i].numGroups; ++j) {
            fout.write(reinterpret_cast<const char*>(&faculties[i].groups[j]), sizeof(Group));
            for (int k = 0; k < faculties[i].groups[j].numStudents; ++k) {
                fout.write(reinterpret_cast<const char*>(&faculties[i].groups[j].students[k]), sizeof(Student));
            }
        }
    }

    fout.close();
    cout << "Дані успішно записані в файл!" << endl;
}

// Функція для зчитування з файлу
void LoadFromFile(Faculty* faculties, int& numFaculties, const string& filename) {
    ifstream fin(filename, ios::binary);
    if (!fin) {
        cout << "Не вдалося відкрити файл для читання!" << endl;
        return;
    }

    while (fin.read(reinterpret_cast<char*>(&faculties[numFaculties]), sizeof(Faculty))) {
        for (int i = 0; i < faculties[numFaculties].numGroups; ++i) {
            fin.read(reinterpret_cast<char*>(&faculties[numFaculties].groups[i]), sizeof(Group));
            for (int j = 0; j < faculties[numFaculties].groups[i].numStudents; ++j) {
                fin.read(reinterpret_cast<char*>(&faculties[numFaculties].groups[i].students[j]), sizeof(Student));
            }
        }
        ++numFaculties;
    }

    fin.close();
    cout << "Дані успішно зчитано з файлу!" << endl;
}

// Функція для зчитування оцінок студента
void InputStudentGrades(Student& student, int maxGrades) {
    for (int i = 0; i < maxGrades; ++i) {
        cout << "Введіть оцінку #" << i + 1 << ": ";
        cin >> student.grades[i];
    }
}

// Функція для введення студентів в групу
void InputGroup(Group& group, int maxStudents, int maxGrades) {
    cout << "Введіть назву групи: ";
    cin.ignore();
    cin.getline(group.groupName, 20);
    cout << "Введіть кількість студентів в групі: ";
    cin >> group.numStudents;

    for (int i = 0; i < group.numStudents; ++i) {
        cout << "Введіть прізвище студента #" << i + 1 << ": ";
        cin.ignore();
        cin.getline(group.students[i].surname, 50);
        InputStudentGrades(group.students[i], maxGrades);
    }
}

// Функція для введення факультету
void InputFaculty(Faculty& faculty, int maxGroups, int maxStudents, int maxGrades) {
    cout << "Введіть назву факультету: ";
    cin.ignore();
    cin.getline(faculty.name, 50);
    cout << "Введіть курс факультету: ";
    cin >> faculty.course;
    cout << "Введіть кількість груп: ";
    cin >> faculty.numGroups;

    for (int i = 0; i < faculty.numGroups; ++i) {
        InputGroup(faculty.groups[i], maxStudents, maxGrades);
    }
}

// Функція для виведення всіх студентів
void PrintAllStudents(const Faculty* faculties, int numFaculties) {
    cout << "Список всіх студентів:\n";
    for (int i = 0; i < numFaculties; ++i) {
        for (int j = 0; j < faculties[i].numGroups; ++j) {
            cout << "Група: " << faculties[i].groups[j].groupName << endl;
            for (int k = 0; k < faculties[i].groups[j].numStudents; ++k) {
                cout << "Прізвище: " << faculties[i].groups[j].students[k].surname << " | Оцінки: ";
                for (int l = 0; l < 5; ++l) {
                    cout << faculties[i].groups[j].students[k].grades[l] << " ";
                }
                cout << endl;
            }
        }
    }
}

// Функція для виведення відмінників
void PrintExcellentStudents(const Faculty* faculties, int numFaculties, int maxGrades) {
    cout << "Список відмінників:\n";
    for (int i = 0; i < numFaculties; ++i) {
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
                    cout << faculties[i].groups[j].students[k].surname << endl;
                }
            }
        }
    }
}

// Функція для пошуку факультету з найбільшою кількістю відмінників
void FindFacultyWithMostExcellentStudents(const Faculty* faculties, int numFaculties, int maxGrades) {
    int maxExcellent = 0;
    Faculty maxFaculty;

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

        if (excellentCount > maxExcellent) {
            maxExcellent = excellentCount;
            maxFaculty = faculties[i];
        }
    }

    cout << "Факультет з найбільшою кількістю відмінників: " << maxFaculty.name << endl;
}

// Функція для знаходження групи без двієчників
void FindGroupWithoutFailures(const Faculty* faculties, int numFaculties, int maxGrades) {
    for (int i = 0; i < numFaculties; ++i) {
        for (int j = 0; j < faculties[i].numGroups; ++j) {
            bool hasFailures = false;
            for (int k = 0; k < faculties[i].groups[j].numStudents; ++k) {
                for (int l = 0; l < maxGrades; ++l) {
                    if (faculties[i].groups[j].students[k].grades[l] == 2) {
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

    Faculty faculties[MAX_FACULTIES];
    int numFaculties = 0;

    string filename;

    int choice;

    while (true) {
        ShowMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Введіть ім'я файлу для збереження: ";
            cin >> filename;
            SaveToFile(faculties, numFaculties, filename);
            break;
        case 2:
            cout << "Введіть ім'я файлу для зчитування: ";
            cin >> filename;
            LoadFromFile(faculties, numFaculties, filename);
            break;
        case 3:
            PrintAllStudents(faculties, numFaculties);
            break;
        case 4:
            PrintExcellentStudents(faculties, numFaculties, MAX_GRADES);
            break;
        case 5:
            FindFacultyWithMostExcellentStudents(faculties, numFaculties, MAX_GRADES);
            break;
        case 6:
            FindGroupWithoutFailures(faculties, numFaculties, MAX_GRADES);
            break;
        case 7:
            return 0;
        default:
            cout << "Невірний вибір! Спробуйте ще раз." << endl;
        }
    }

    return 0;
}
