// Lab_12_1.cpp
// < Величко Іван >
// Лабораторна робота № 12.1
// Бінарні файли
// Варіант 3

#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

// Створення бінарного файлу з введених рядків
void CreateBIN(const char* fname) {
    ofstream fout(fname, ios::binary);
    string ch, s;

    do {
        cin.ignore();  // Очищення буфера
        cout << "Введіть текст: ";
        getline(cin, s);
        for (unsigned i = 0; i < s.length(); i++) {
            fout.write((char*)&s[i], sizeof(s[i]));
        }
        cout << "Продовжити? (так/ні): ";
        cin >> ch;
    } while (ch == "так" || ch == "ТАК");
    fout.close();
}

// Виведення вмісту бінарного файлу на екран
void PrintBIN(const char* fname) {
    ifstream fin(fname, ios::binary);
    char c;
    cout << "Вміст файла (" << fname << "): ";
    while (fin.read((char*)&c, sizeof(c))) {
        cout << c;
    }
    cout << endl;
    fin.close();
}

// Переписування символів, які не входять в слово "геометрія"
void ProcessBIN(const char* fname, const char* gname) {
    ifstream f(fname, ios::binary);
    ofstream g(gname, ios::binary);

    const string excluded = "геометрія";
    char c;

    while (f.read((char*)&c, sizeof(c))) {
        if (excluded.find(c) == string::npos) {
            g.write((char*)&c, sizeof(c));
        }
    }
    f.close();
    g.close();
}

int main()
{
    SetConsoleCP(1251);  // Встановлення кодування Windows-1251 для введення
    SetConsoleOutputCP(1251);  // Встановлення кодування Windows-1251 для виведення

    char fname[100], gname[100];

    // Введення імені першого файлу
    cout << "Введіть ім'я першого файла: ";
    cin >> fname;

    // Створення файлу
    CreateBIN(fname);

    // Виведення вмісту першого файлу
    PrintBIN(fname);

    // Введення імені другого файлу
    cout << "Введіть ім'я другого файла: ";
    cin >> gname;

    // Переписування символів
    ProcessBIN(fname, gname);

    // Виведення вмісту другого файлу
    PrintBIN(gname);

    return 0;
}
