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

const int MAX_ROOMS = 15;  // Максимальна кількість номерів
const int SINGLE_ROOMS = 5;  // Кількість одномісних номерів
const int DOUBLE_ROOMS = 10; // Кількість двомісних номерів

// Структура для збереження даних про мешканців
struct Resident {
    string surname;
    string initials;  // Ініціали (можуть бути порожніми)
    int roomNumber;   // Номер кімнати
};

// Функції для виконання операцій
void AddResident(const string& filename);
void EditResident(const string& filename);
void RemoveResident(const string& filename);
void FindResident(const string& filename);
void PrintResident(const Resident& resident);
void PrintMenu();

// Перевірка на коректність введеного прізвища
bool IsValidSurname(const string& surname) {
    return !surname.empty();
}

// Перевірка коректності введеного номера кімнати
bool IsValidRoomNumber(int roomNumber) {
    return roomNumber >= 1 && roomNumber <= MAX_ROOMS;
}

// Головна функція
int main() {
    // Налаштування для коректної роботи з кирилицею в консолі
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string filename;
    cout << "Введіть ім'я файлу для збереження даних: ";
    cin >> filename;

    while (true) {
        PrintMenu();

        int choice;
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice) {
        case 1:
            AddResident(filename);
            break;
        case 2:
            EditResident(filename);
            break;
        case 3:
            RemoveResident(filename);
            break;
        case 4:
            FindResident(filename);
            break;
        case 5:
            return 0;
        default:
            cout << "Невірний вибір. Спробуйте ще раз." << endl;
        }
    }
}

void PrintMenu() {
    cout << "\nМеню:\n";
    cout << "1. Додати нового мешканця\n";
    cout << "2. Редагувати дані мешканця\n";
    cout << "3. Видалити мешканця\n";
    cout << "4. Знайти мешканця\n";
    cout << "5. Вийти\n";
}

void AddResident(const string& filename) {
    fstream file(filename, ios::in | ios::out | ios::binary | ios::app);
    if (!file) {
        cout << "Не вдалося відкрити файл." << endl;
        return;
    }

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

    // Записуємо нового мешканця в файл
    file.write(reinterpret_cast<const char*>(&newResident), sizeof(newResident));
    file.close();

    cout << "Мешканця успішно додано!" << endl;
}

void EditResident(const string& filename) {
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
    while (file.read(reinterpret_cast<char*>(&resident), sizeof(resident))) {
        if (resident.surname == surname) {
            found = true;
            cout << "Мешканець знайдений: " << endl;
            PrintResident(resident);

            cout << "Введіть нові ініціали: ";
            cin >> resident.initials;

            cout << "Введіть новий номер кімнати (1 - 15): ";
            cin >> resident.roomNumber;

            if (!IsValidRoomNumber(resident.roomNumber)) {
                cout << "Невірний номер кімнати!" << endl;
                return;
            }

            // Повертаємо файл на початок і оновлюємо запис
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

void RemoveResident(const string& filename) {
    fstream file(filename, ios::in | ios::out | ios::binary);
    if (!file) {
        cout << "Не вдалося відкрити файл." << endl;
        return;
    }

    string surname;
    cout << "Введіть прізвище мешканця для видалення: ";
    cin >> surname;

    fstream tempFile("temp.dat", ios::out | ios::binary);
    bool found = false;
    Resident resident;
    while (file.read(reinterpret_cast<char*>(&resident), sizeof(resident))) {
        if (resident.surname == surname) {
            found = true;
            cout << "Мешканець знайдений: " << endl;
            PrintResident(resident);
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

    // Видаляємо старий файл і перейменовуємо тимчасовий
    remove(filename.c_str());
    rename("temp.dat", filename.c_str());

    cout << "Мешканець успішно видалений!" << endl;
}

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
    while (file.read(reinterpret_cast<char*>(&resident), sizeof(resident))) {
        if (resident.surname == surname) {
            count++;
            if (count == 1) {
                cout << "Мешканець знайдений: " << endl;
                PrintResident(resident);
            }
        }
    }

    if (count == 0) {
        cout << "Мешканця з таким прізвищем не знайдено!" << endl;
    }
    else if (count > 1) {
        cout << "Мешканців з таким прізвищем декілька. Введіть ініціали для точного пошуку: ";
        string initials;
        cin >> initials;
        file.clear();
        file.seekg(0, ios::beg);
        found = false;
        while (file.read(reinterpret_cast<char*>(&resident), sizeof(resident))) {
            if (resident.surname == surname && resident.initials == initials) {
                found = true;
                PrintResident(resident);
                break;
            }
        }
        if (!found) {
            cout << "Мешканця з такими ініціалами не знайдено!" << endl;
        }
    }

    file.close();
}

void PrintResident(const Resident& resident) {
    cout << "Прізвище: " << resident.surname << endl;
    cout << "Ініціали: " << resident.initials << endl;
    cout << "Номер кімнати: " << resident.roomNumber << endl;
}
