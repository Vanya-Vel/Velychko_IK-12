// Lab_11_2.cpp
// < Величко Іван >
// Лабораторна робота № 11.2
// Пошук слів у текстовому файлі
// Варіант 3

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Перевірка на наявність вкладених дужок
bool hasNestedBrackets(const string& line) {
    int openBracketCount = 0;
    for (char ch : line) {
        if (ch == '(') {
            openBracketCount++;
            if (openBracketCount > 1) return true;  // Вкладені дужки знайдені
        }
        else if (ch == ')') {
            openBracketCount--;
        }
    }
    return false;
}

// Видалення вмісту між дужками разом з дужками
string removeBracketContent(const string& line) {
    string result;
    bool insideBrackets = false;
    for (char ch : line) {
        if (ch == '(') insideBrackets = true;
        else if (ch == ')') insideBrackets = false;
        else if (!insideBrackets) result += ch;
    }
    return result;
}

// Обробка файлу: перевірка на вкладені дужки та видалення вмісту в дужках
void processFileContent(const char* inputFileName, const char* outputFileName) {
    ifstream fin(inputFileName);
    ofstream fout(outputFileName);

    if (!fin.is_open() || !fout.is_open()) {
        cerr << "Error: cannot open file." << endl;
        return;
    }

    string line;
    while (getline(fin, line)) {
        if (hasNestedBrackets(line)) {
            cerr << "Error: nested brackets detected." << endl;
            return;
        }

        fout << removeBracketContent(line) << endl;  // Запис результату у файл
    }

    fin.close();
    fout.close();
}

int main() {
    char inputFileName[100], outputFileName[100];

    cout << "Enter input file name (t1): ";
    cin >> inputFileName;

    cout << "Enter output file name (t2): ";
    cin >> outputFileName;

    // Обробка файлу
    processFileContent(inputFileName, outputFileName);

    return 0;
}
