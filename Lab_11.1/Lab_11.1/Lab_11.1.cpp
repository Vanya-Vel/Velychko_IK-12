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
    int commaCount = 0;
    for (size_t i = 0; i < line.size(); i++) {
        if (line[i] == ',') {
            commaCount++;
            if (commaCount == 3) {
                return i + 1; // Повертаємо позицію коми (нумерація з 1)
            }
        }
    }
    return -1; // Якщо третьої коми немає
}

// Функція для знаходження номера рядка і позиції третьої коми у файлі
void findThirdCommaLocation(const char* fname, int& lineNumber, int& commaPosition) {
    ifstream fin(fname); // Відкриваємо файл для читання
    if (!fin.is_open()) {
        cerr << "Error: cannot open file " << fname << endl;
        lineNumber = -1;
        commaPosition = -1;
        return;
    }

    string line;
    lineNumber = 0;
    commaPosition = -1;

    // Читаємо файл рядок за рядком
    while (getline(fin, line)) {
        lineNumber++;
        int position = findThirdCommaPosition(line);
        if (position != -1) {
            commaPosition = position; // Записуємо позицію коми
            return; // Зупиняємось, якщо знайшли третю кому
        }
    }

    // Якщо коми не знайдено, встановлюємо значення -1
    lineNumber = -1;
    commaPosition = -1;
}

int main() {
    char fname[100];
    cout << "Enter file name: ";
    cin >> fname;

    int lineNumber, commaPosition;
    findThirdCommaLocation(fname, lineNumber, commaPosition);

    if (lineNumber != -1) {
        cout << "The third comma is located at line " << lineNumber
            << ", position " << commaPosition << "." << endl;
    }
    else {
        cout << "The third comma was not found in the file." << endl;
    }

    return 0;
}
