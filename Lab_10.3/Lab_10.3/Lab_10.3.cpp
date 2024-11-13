#include <iostream>
#include <fstream>
#include <string>
#include <windows.h> 

using namespace std;

// Структура для зберігання даних про мешканця
struct Resident {
    string lastName;    // Прізвище мешканця
    string initials;    // Ініціали мешканця
    int roomNumber;     // Номер кімнати
};

// Прототипи функцій
void displayMenu(); // Відображає меню для користувача
void addResident(Resident*& residents, int& count, int maxRooms); // Додає нового мешканця
void editResident(Resident* residents, int count); // Редагує інформацію про мешканця
void deleteResident(Resident*& residents, int& count); // Видаляє мешканця з масиву
void findResident(const Resident* residents, int count); // Знаходить мешканця за прізвищем
void loadFromFile(Resident*& residents, int& count, const string& filename); // Завантажує дані з файлу
void saveToFile(const Resident* residents, int count, const string& filename); // Зберігає дані у файл

int main() {
    SetConsoleCP(1251);           // Налаштування кириличної кодування для вводу
    SetConsoleOutputCP(1251);     // Налаштування кириличної кодування для виводу
    Resident* residents = nullptr;  // Динамічний масив мешканців
    int count = 0;                  // Кількість мешканців
    const int maxRooms = 15;        // Максимальна кількість кімнат
    string filename;                // Ім'я файлу для збереження/завантаження

    // Запитуємо ім'я файлу
    cout << "Введіть ім'я файлу: ";
    cin >> filename;
    loadFromFile(residents, count, filename); // Завантаження даних з файлу

    int choice; // Змінна для збереження вибору користувача
    do {
        displayMenu(); // Відображення меню
        cout << "Виберіть опцію: ";
        cin >> choice;

        // Виконання дії на основі вибору користувача
        switch (choice) {
        case 1: addResident(residents, count, maxRooms); break;
        case 2: editResident(residents, count); break;
        case 3: deleteResident(residents, count); break;
        case 4: findResident(residents, count); break;
        case 5: saveToFile(residents, count, filename); break;
        case 0: saveToFile(residents, count, filename); break; // Зберігає дані перед виходом
        default: cout << "Неправильний вибір!\n"; break;
        }
    } while (choice != 0);

    delete[] residents; // Звільнення пам'яті перед завершенням програми
    return 0;
}

// Відображення меню програми
void displayMenu() {
    cout << "\nМеню:\n"
        << "1. Додати мешканця\n"
        << "2. Редагувати мешканця\n"
        << "3. Видалити мешканця\n"
        << "4. Знайти мешканця за прізвищем\n"
        << "5. Зберегти дані у файл\n"
        << "0. Вихід\n";
}

// Додає нового мешканця в масив
void addResident(Resident*& residents, int& count, int maxRooms) {
    // Перевірка, чи є вільні номери
    if (count >= maxRooms) {
        cout << "Усі номери зайняті!\n";
        return;
    }

    Resident newResident;
    cout << "Введіть прізвище: ";
    cin >> newResident.lastName;
    cout << "Введіть ініціали: ";
    cin >> newResident.initials;
    cout << "Введіть номер кімнати: ";
    cin >> newResident.roomNumber;

    // Створення нового масиву з додатковим місцем для нового мешканця
    Resident* temp = new Resident[count + 1];
    for (int i = 0; i < count; ++i) {
        temp[i] = residents[i]; // Копіювання існуючих даних
    }
    temp[count++] = newResident; // Додавання нового мешканця
    delete[] residents; // Звільнення старого масиву
    residents = temp;   // Вказівник на новий масив
}

// Редагує інформацію про мешканця за прізвищем
void editResident(Resident* residents, int count) {
    string lastName;
    cout << "Введіть прізвище для редагування: ";
    cin >> lastName;

    // Пошук мешканця за прізвищем
    for (int i = 0; i < count; ++i) {
        if (residents[i].lastName == lastName) {
            cout << "Ініціали: ";
            cin >> residents[i].initials;
            cout << "Номер кімнати: ";
            cin >> residents[i].roomNumber;
            return;
        }
    }
    cout << "Мешканця не знайдено.\n";
}

// Видаляє мешканця за прізвищем
void deleteResident(Resident*& residents, int& count) {
    string lastName;
    cout << "Введіть прізвище для видалення: ";
    cin >> lastName;

    for (int i = 0; i < count; ++i) {
        if (residents[i].lastName == lastName) {
            // Створення нового масиву на одиницю менше
            Resident* temp = new Resident[count - 1];
            for (int j = 0, k = 0; j < count; ++j) {
                if (j != i) temp[k++] = residents[j]; // Копіювання даних без видаленого мешканця
            }
            delete[] residents;
            residents = temp;
            --count;
            cout << "Мешканця видалено.\n";
            return;
        }
    }
    cout << "Мешканця не знайдено.\n";
}

// Шукає мешканця за прізвищем, запитує ініціали при необхідності
void findResident(const Resident* residents, int count) {
    string lastName, initials;
    cout << "Введіть прізвище для пошуку: ";
    cin >> lastName;

    int found = 0, index = -1;
    for (int i = 0; i < count; ++i) {
        if (residents[i].lastName == lastName) {
            found++; // Підраховує кількість мешканців з таким прізвищем
            index = i;
        }
    }

    if (found == 0) {
        cout << "Мешканця не знайдено.\n";
    }
    else if (found == 1) {
        // Виводить дані, якщо знайдено тільки одного мешканця з таким прізвищем
        cout << "Кімната: " << residents[index].roomNumber << "\n";
    }
    else {
        // Якщо знайдено більше одного мешканця, запитуємо ініціали
        cout << "Введіть ініціали: ";
        cin >> initials;
        for (int i = 0; i < count; ++i) {
            if (residents[i].lastName == lastName && residents[i].initials == initials) {
                cout << "Кімната: " << residents[i].roomNumber << "\n";
                return;
            }
        }
        cout << "Мешканця з такими ініціалами не знайдено.\n";
    }
}

// Завантажує дані про мешканців з файлу
void loadFromFile(Resident*& residents, int& count, const string& filename) {
    ifstream file(filename); // дозволяє зчитувати дані з файлів
    if (!file) {
        cout << "Не вдалося відкрити файл.\n";
        return;
    }

    file >> count; // Читає кількість мешканців
    residents = new Resident[count]; // Виділення пам'яті для масиву
    for (int i = 0; i < count; ++i) {
        file >> residents[i].lastName >> residents[i].initials >> residents[i].roomNumber; // Читання даних мешканців
    }
    file.close();
}

// Зберігає всі дані про мешканців у файл
void saveToFile(const Resident* residents, int count, const string& filename) {
    ofstream file(filename); // використовується для запису даних у файл
    if (!file) {
        cout << "Не вдалося відкрити файл для запису.\n";
        return;
    }

    file << count << "\n"; // Запис кількості мешканців
    for (int i = 0; i < count; ++i) {
        // Записує кожного мешканця на новий рядок
        file << residents[i].lastName << " " << residents[i].initials << " " << residents[i].roomNumber << "\n";
    }
    file.close();
    cout << "Дані збережено у файл.\n";
}
