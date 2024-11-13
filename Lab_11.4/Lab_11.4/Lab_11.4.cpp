// Lab_11_4.cpp
// < ������� ���� >
// ����������� ������ � 11.4
// ����������� ����� ���������� �����
// ������ 3

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include<Windows.h>

using namespace std;

// ������� ��� ����������� ���������� ����� � �����
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

// ������� ��� ������� �����: ������� ����� ���� �� ����� �������
void processFiles(const string& inputFilename, const string& outputFilename) {
    ifstream inputFile(inputFilename);
    if (!inputFile.is_open()) {
        cerr << "������� �������� �������� �����!" << endl;
        return;
    }

    ofstream outputFile(outputFilename);
    if (!outputFile.is_open()) {
        cerr << "������� �������� ��������� �����!" << endl;
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

// ������� ��� ����������� ����
void displayMenu() {
    cout << "\n����:\n";
    cout << "1. �������� ����\n";
    cout << "0. �����\n";
}

int main() {
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
    string inputFilename, outputFilename;

    cout << "������ ��'� �������� �����: ";
    cin >> inputFilename;
    cout << "������ ��'� ��������� �����: ";
    cin >> outputFilename;

    int choice;
    do {
        displayMenu();
        cout << "������� ��: ";
        cin >> choice;

        switch (choice) {
        case 1:
            processFiles(inputFilename, outputFilename);
            cout << "�������� ������ ��������." << endl;
            break;
        case 0:
            cout << "�������� ���������." << endl;
            break;
        default:
            cout << "������������ ����. ��������� �� ���." << endl;
        }
    } while (choice != 0);

    return 0;
}
