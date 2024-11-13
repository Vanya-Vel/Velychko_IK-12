// Lab_11_4.cpp
// < Величко Іван >
// Лабораторна робота № 11.4
// Опрацювання рядків текстового файлу
// Варіант 3

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include<Windows.h>

using namespace std;

// Функція для знаходження найбільшого слова в рядку
string findLongestWord(const string& line) {
    stringstream ss(line);
    string word, longestWord;
    size_t maxLength = 0;

    while (ss >> word) {
        if (word.length() > maxLength) {
            maxLength = word.length();
            longestWord = word;
        }
    }
    return longestWord;
}

// Функція для обробки файлів: створює новий файл на основі першого
void processFiles(const string& inputFilename, const string& outputFilename) {
    ifstream inputFile(inputFilename);
    if (!inputFile.is_open()) {
        cerr << "Помилка відкриття вхідного файлу!" << endl;
        return;
    }

    ofstream outputFile(outputFilename);
    if (!outputFile.is_open()) {
        cerr << "Помилка відкриття вихідного файлу!" << endl;
        inputFile.close();
        return;
    }

    string line, prevLongestWord;
    bool isEvenLine = false;

    while (getline(inputFile, line)) {
        if (isEvenLine) {
            prevLongestWord = findLongestWord(line);
            outputFile << line << endl;
        }
        else {
            outputFile << line << " " << prevLongestWord << endl;
        }

        isEvenLine = !isEvenLine;
    }

    inputFile.close();
    outputFile.close();
}

// Функція для відображення меню
void displayMenu() {
    cout << "\nМеню:\n";
    cout << "1. Обробити файл\n";
    cout << "0. Вихід\n";
}

int main() {
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
    string inputFilename, outputFilename;

    cout << "Введіть ім'я вхідного файлу: ";
    cin >> inputFilename;
    cout << "Введіть ім'я вихідного файлу: ";
    cin >> outputFilename;

    int choice;
    do {
        displayMenu();
        cout << "Виберіть дію: ";
        cin >> choice;

        switch (choice) {
        case 1:
            processFiles(inputFilename, outputFilename);
            cout << "Завдання успішно виконано." << endl;
            break;
        case 0:
            cout << "Програму завершено." << endl;
            break;
        default:
            cout << "Неправильний вибір. Спробуйте ще раз." << endl;
        }
    } while (choice != 0);

    return 0;
}
