// Lab_11_3.cpp
// < Величко Іван >
// Лабораторна робота № 11.3
// Опрацювання текстового файлу
// Варіант 3

#include <iostream>
#include <fstream>
#include <string>
#include<windows.h>

using namespace std;

// Функція для додавання мешканця у файл
void addResident(const string& filename) {
    ofstream file(filename, ios::app);
    if (!file.is_open()) {
        cerr << "Помилка відкриття файлу для запису." << endl;
        return;
    }

    string lastName, initials;
    int roomNumber;

    cout << "Введіть прізвище мешканця: ";
    cin >> lastName;
    cout << "Введіть ініціали мешканця: ";
    cin >> initials;
    cout << "Введіть номер кімнати (1-15): ";
    cin >> roomNumber;

    // Перевірка на валідність номера кімнати
    if (roomNumber < 1 || roomNumber > 15) {
        cerr << "Неправильний номер кімнати." << endl;
        file.close();
        return;
    }

    // Запис мешканця у файл
    file << lastName << " " << initials << " " << roomNumber << endl;
    cout << "Мешканця додано." << endl;

    file.close();
}

// Функція для пошуку мешканця за прізвищем (і за ініціалами, якщо потрібно)
void findResident(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Помилка відкриття файлу для читання." << endl;
        return;
    }

    string lastName, searchLastName, initials, searchInitials;
    int roomNumber;
    bool found = false;
    int count = 0;

    cout << "Введіть прізвище для пошуку: ";
    cin >> searchLastName;

    // Пошук мешканців з відповідним прізвищем
    while (file >> lastName >> initials >> roomNumber) {
        if (lastName == searchLastName) {
            count++;
            if (count == 1) {
                searchInitials = initials;
                roomNumber = roomNumber;
            }
            else if (count > 1) {
                break;
            }
            found = true;
        }
    }

    file.clear();
    file.seekg(0); // Повертаємось на початок файлу для повторного проходу, якщо потрібно уточнення

    if (!found) {
        cout << "Мешканця з таким прізвищем не знайдено." << endl;
    }
    else if (count == 1) {
        cout << "Мешканець: " << searchLastName << " " << searchInitials
            << " знаходиться в номері " << roomNumber << "." << endl;
    }
    else {
        cout << "Знайдено декілька мешканців з прізвищем " << searchLastName << "." << endl;
        cout << "Введіть ініціали для уточнення: ";
        cin >> searchInitials;

        found = false;
        while (file >> lastName >> initials >> roomNumber) {
            if (lastName == searchLastName && initials == searchInitials) {
                cout << "Мешканець: " << searchLastName << " " << searchInitials
                    << " знаходиться в номері " << roomNumber << "." << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Мешканця з таким прізвищем і ініціалами не знайдено." << endl;
        }
    }

    file.close();
}

// Функція для відображення меню
void displayMenu() {
    cout << "\nМеню:\n";
    cout << "1. Додати мешканця\n";
    cout << "2. Знайти мешканця за прізвищем\n";
    cout << "0. Вихід\n";
}

int main() {
    SetConsoleCP(1251);           // Налаштування кириличної кодування для вводу
    SetConsoleOutputCP(1251);     // Налаштування кириличної кодування для виводу

    string filename;
    cout << "Введіть ім'я файлу для зберігання даних: ";
    cin >> filename;

    int choice;
    do {
        displayMenu();
        cout << "Виберіть дію: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addResident(filename);
            break;
        case 2:
            findResident(filename);
            break;
        case 0:
            cout << "Завершення програми." << endl;
            break;
        default:
            cout << "Неправильний вибір. Спробуйте ще раз." << endl;
        }
    } while (choice != 0);

    return 0;
}
