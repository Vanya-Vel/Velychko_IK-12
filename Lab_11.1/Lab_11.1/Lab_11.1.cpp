// Lab_11_1.cpp
// < Величко Іван >
// Лабораторна робота № 11.1
// Пошук символів у текстовому файлі
// Варіант 3

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Функція для пошуку позиції третьої коми в рядку
int findThirdCommaPosition(const string& line) {
    int commaCount = 0; // Лічильник для ком
    for (size_t i = 0; i < line.size(); i++) { // Перебираємо всі символи рядка
        if (line[i] == ',') {  // Якщо символ - це кома
            commaCount++;  // Збільшуємо лічильник ком
            if (commaCount == 3) {  // Якщо ми знайшли третю кому
                return i + 1; // Повертаємо позицію третьої коми (нумерація з 1)
            }
        }
    }
    return -1; // Якщо третьої коми немає, повертаємо -1
}

// Функція для знаходження номера рядка і позиції третьої коми у файлі
void findThirdCommaLocation(const char* fname, int& lineNumber, int& commaPosition) {
    ifstream fin(fname); // Відкриваємо файл для читання
    if (!fin.is_open()) {  // Якщо не вдалося відкрити файл
        cerr << "Error: cannot open file " << fname << endl; // Виводимо помилку
        lineNumber = -1; // Встановлюємо значення -1 для номера рядка
        commaPosition = -1; // Встановлюємо значення -1 для позиції коми
        return;
    }

    string line;  // Змінна для зберігання кожного рядка з файлу
    lineNumber = 0;  // Ініціалізуємо номер рядка
    commaPosition = -1;  // Ініціалізуємо позицію коми як -1

    // Читаємо файл рядок за рядком
    while (getline(fin, line)) {
        lineNumber++; // Збільшуємо номер рядка
        int position = findThirdCommaPosition(line);  // Шукаємо третю кому в поточному рядку
        if (position != -1) {  // Якщо третя кома знайдена
            commaPosition = position; // Записуємо позицію коми
            return; // Завершуємо роботу функції, якщо знайшли третю кому
        }
    }

    // Якщо коми не знайдено, встановлюємо значення -1
    lineNumber = -1;  // Встановлюємо значення -1 для номера рядка
    commaPosition = -1;  // Встановлюємо значення -1 для позиції коми
}

int main() {
    char fname[100];  // Масив для зберігання імені файлу
    cout << "Enter file name: ";  // Виводимо запит на введення імені файлу
    cin >> fname;  // Зчитуємо ім'я файлу

    int lineNumber, commaPosition;  // Змінні для зберігання результатів пошуку
    findThirdCommaLocation(fname, lineNumber, commaPosition);  // Викликаємо функцію для пошуку

    // Перевірка, чи була знайдена третя кома
    if (lineNumber != -1) {
        // Якщо кома знайдена, виводимо номер рядка і позицію коми
        cout << "The third comma is located at line " << lineNumber
            << ", position " << commaPosition << "." << endl;
    }
    else {
        // Якщо кома не знайдена, виводимо повідомлення
        cout << "The third comma was not found in the file." << endl;
    }

    return 0;
}
