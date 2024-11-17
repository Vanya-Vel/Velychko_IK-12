// Lab_12_4.cpp
// < Величко Іван >
// Лабораторна робота № 12.4
// Опрацювання бінарного файлу
// Варіант 3

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <windows.h>  // Для SetConsoleCP та SetConsoleOutputCP

using namespace std;

// Максимальна кількість номерів кімнат
const int MAX_ROOMS = 15;  
// Кількість одномісних номерів
const int SINGLE_ROOMS = 5;  
// Кількість двомісних номерів
const int DOUBLE_ROOMS = 10; 

// Структура для збереження даних про мешканців
struct Resident {
    string surname;      // Прізвище мешканця
    string initials;     // Ініціали мешканця (можуть бути порожніми)
    int roomNumber;      // Номер кімнати
};

// Оголошення функцій для виконання різних операцій з файлом
void AddResident(const string& filename);
void EditResident(const string& filename);
void RemoveResident(const string& filename);
void FindResident(const string& filename);
void PrintResident(const Resident& resident);
void PrintMenu();

// Функція для перевірки коректності введеного прізвища
bool IsValidSurname(const string& surname) {
    return !surname.empty();  // Прізвище має бути непустим
}

// Функція для перевірки коректності номера кімнати
bool IsValidRoomNumber(int roomNumber) {
    return roomNumber >= 1 && roomNumber <= MAX_ROOMS;  // Номер кімнати має бути від 1 до MAX_ROOMS
}

// Головна функція програми
int main() {
    // Налаштування для коректної роботи з кирилицею в консолі
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string filename;
    // Введення назви файлу для збереження даних
    cout << "Введіть ім'я файлу для збереження даних: ";
    cin >> filename;

    // Основне меню програми
    while (true) {
        PrintMenu();  // Виведення меню

        int choice;
        cout << "Ваш вибір: ";
        cin >> choice;

        // Обробка вибору користувача
        switch (choice) {
        case 1: 
            AddResident(filename);  // Додати нового мешканця
            break;
        case 2: 
            EditResident(filename);  // Редагувати дані мешканця
            break;
        case 3: 
            RemoveResident(filename);  // Видалити мешканця
            break;
        case 4: 
            FindResident(filename);  // Знайти мешканця
            break;
        case 5: 
            return 0;  // Вихід з програми
        default: 
            cout << "Невірний вибір. Спробуйте ще раз." << endl;  // Якщо вибір невірний
        }
    }
}

// Функція для виведення меню
void PrintMenu() {
    cout << "\nМеню:\n";
    cout << "1. Додати нового мешканця\n";
    cout << "2. Редагувати дані мешканця\n";
    cout << "3. Видалити мешканця\n";
    cout << "4. Знайти мешканця\n";
    cout << "5. Вийти\n";
}

// Функція для додавання нового мешканця
void AddResident(const string& filename) {
    // Відкриття файлу для додавання нового мешканця
    fstream file(filename, ios::in | ios::out | ios::binary | ios::app);
    if (!file) {
        cout << "Не вдалося відкрити файл." << endl;
        return;
    }

    // Введення даних нового мешканця
    Resident newResident;
    cout << "Введіть прізвище мешканця: ";
    cin >> newResident.surname;

    if (!IsValidSurname(newResident.surname)) {
        cout << "Невірне прізвище!" << endl;
        return;
    }

    cout << "Введіть ініціали мешканця: ";
    cin >> newResident.initials;

    int room;
    cout << "Введіть номер кімнати (1 - 15): ";
    cin >> room;

    if (!IsValidRoomNumber(room)) {
        cout << "Невірний номер кімнати!" << endl;
        return;
    }

    newResident.roomNumber = room;

    // Запис нового мешканця в бінарний файл
    file.write(reinterpret_cast<const char*>(&newResident), sizeof(newResident));
    file.close();

    cout << "Мешканця успішно додано!" << endl;
}

// Функція для редагування даних мешканця
void EditResident(const string& filename) {
    // Відкриття файлу для редагування
    fstream file(filename, ios::in | ios::out | ios::binary);
    if (!file) {
        cout << "Не вдалося відкрити файл." << endl;
        return;
    }

    string surname;
    cout << "Введіть прізвище мешканця для редагування: ";
    cin >> surname;

    bool found = false;
    Resident resident;
    
    // Перегляд файлу для пошуку мешканця за прізвищем
    while (file.read(reinterpret_cast<char*>(&resident), sizeof(resident))) {
        if (resident.surname == surname) {
            found = true;
            cout << "Мешканець знайдений: " << endl;
            PrintResident(resident);  // Виведення поточних даних мешканця

            // Введення нових даних
            cout << "Введіть нові ініціали: ";
            cin >> resident.initials;

            cout << "Введіть новий номер кімнати (1 - 15): ";
            cin >> resident.roomNumber;

            if (!IsValidRoomNumber(resident.roomNumber)) {
                cout << "Невірний номер кімнати!" << endl;
                return;
            }

            // Повертаємо вказівник на початок і оновлюємо запис
            file.seekp(-static_cast<int>(sizeof(resident)), ios::cur);
            file.write(reinterpret_cast<const char*>(&resident), sizeof(resident));
            cout << "Дані успішно оновлено!" << endl;
            break;
        }
    }

    if (!found) {
        cout << "Мешканця з таким прізвищем не знайдено!" << endl;
    }

    file.close();
}

// Функція для видалення мешканця
void RemoveResident(const string& filename) {
    // Відкриття файлу для читання та запису
    fstream file(filename, ios::in | ios::out | ios::binary);
    if (!file) {
        cout << "Не вдалося відкрити файл." << endl;
        return;
    }

    string surname;
    cout << "Введіть прізвище мешканця для видалення: ";
    cin >> surname;

    // Створюємо тимчасовий файл для збереження всіх даних, окрім того, що потрібно видалити
    fstream tempFile("temp.dat", ios::out | ios::binary);
    bool found = false;
    Resident resident;

    // Перегляд файлу та копіювання даних в тимчасовий файл
    while (file.read(reinterpret_cast<char*>(&resident), sizeof(resident))) {
        if (resident.surname == surname) {
            found = true;
            cout << "Мешканець знайдений: " << endl;
            PrintResident(resident);  // Виведення даних мешканця, якого видаляють
        }
        else {
            tempFile.write(reinterpret_cast<const char*>(&resident), sizeof(resident));
        }
    }

    if (!found) {
        cout << "Мешканця з таким прізвищем не знайдено!" << endl;
        file.close();
        tempFile.close();
        return;
    }

    file.close();
    tempFile.close();

    // Видалення старого файлу та перейменування тимчасового
    remove(filename.c_str());
    rename("temp.dat", filename.c_str());

    cout << "Мешканець успішно видалений!" << endl;
}

// Функція для пошуку мешканця
void FindResident(const string& filename) {
    fstream file(filename, ios::in | ios::binary);
    if (!file) {
        cout << "Не вдалося відкрити файл." << endl;
        return;
    }

    string surname;
    cout << "Введіть прізвище мешканця для пошуку: ";
    cin >> surname;

    bool found = false;
    int count = 0;
    Resident resident;

    // Перегляд файлу для пошуку мешканця за прізвищем
    while (file.read(reinterpret_cast<char*>(&resident), sizeof(resident))) {
        if (resident.surname == surname) {
            count++;
            if (count == 1) {
                cout << "Мешканець знайдений: " << endl;
                PrintResident(resident);  // Виведення даних знайденого мешканця
            }
        }
    }

    if (count == 0) {
        cout << "Мешканця з таким прізвищем не знайдено!" << endl;
    }
    else if (count > 1) {
        // Якщо знайдено кілька мешканців з таким прізвищем
        cout << "Мешканців з таким прізвищем декілька. Введіть ініціали для точного пошуку: ";
        string initials;
        cin >> initials;
        file.clear();
        file.seekg(0, ios::beg);
        found = false;
        
        // Точний пошук за ініціалами
        while (file.read(reinterpret_cast<char*>(&resident), sizeof(resident))) {
            if (resident.surname == surname && resident.initials == initials) {
                found = true;
                PrintResident(resident);  // Виведення знайденого мешканця
                break;
            }
        }
        if (!found) {
            cout << "Мешканця з такими ініціалами не знайдено!" << endl;
        }
    }

    file.close();
}

// Функція для виведення даних про мешканця
void PrintResident(const Resident& resident) {
    cout << "Прізвище: " << resident.surname << endl;
    cout << "Ініціали: " << resident.initials << endl;
    cout << "Номер кімнати: " << resident.roomNumber << endl;
}
