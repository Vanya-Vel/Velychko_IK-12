// Lab_11_2.cpp
// < Величко Іван >
// Лабораторна робота № 11.2
// Пошук слів у текстовому файлі
// Варіант 3

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Функція, яка перевіряє наявність вкладених дужок
bool hasNestedBrackets(const string& line) {
    int openBracketCount = 0;
    for (char ch : line) {
        if (ch == '(') {
            openBracketCount++;
            if (openBracketCount > 1) {
                return true; // Якщо кількість відкритих дужок більше однієї, є вкладені дужки
            }
        }
        else if (ch == ')') {
            openBracketCount--;
        }
    }
    return false;
}

// Функція, яка видаляє вміст між дужками разом з дужками
string removeBracketContent(const string& line) {
    string result;
    bool insideBrackets = false;
    for (char ch : line) {
        if (ch == '(') {
            insideBrackets = true; // Початок групи в дужках
        }
        else if (ch == ')') {
            insideBrackets = false; // Кінець групи в дужках
        }
        else if (!insideBrackets) {
            result += ch; // Додаємо символ, якщо він поза дужками
        }
    }
    return result;
}

// Функція, яка обробляє вміст файлу і записує в інший файл
void processFileContent(const char* inputFileName, const char* outputFileName) {
    ifstream fin(inputFileName);
    ofstream fout(outputFileName);

    if (!fin.is_open() || !fout.is_open()) {
        cerr << "Error: cannot open file." << endl;
        return;
    }

    string line;
    while (getline(fin, line)) {
        // Перевірка на вкладені дужки
        if (hasNestedBrackets(line)) {
            cerr << "Error: nested brackets detected." << endl;
            return;
        }

        // Видалення вмісту в дужках
        string modifiedLine = removeBracketContent(line);
        fout << modifiedLine << endl; // Записуємо результат у файл
    }

    fin.close();
    fout.close();
}

int main() {
    char inputFileName[100];
    char outputFileName[100];

    cout << "Enter input file name (t1): ";
    cin >> inputFileName;

    cout << "Enter output file name (t2): ";
    cin >> outputFileName;

    // Обробка файлу
    processFileContent(inputFileName, outputFileName);

    return 0;
}
