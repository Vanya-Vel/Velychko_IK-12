// Lab_11_2.cpp
// < ������� ���� >
// ����������� ������ � 11.2
// ����� ��� � ���������� ����
// ������ 3

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// �������, ��� �������� �������� ��������� �����
bool hasNestedBrackets(const string& line) {
    int openBracketCount = 0;
    for (char ch : line) {
        if (ch == '(') {
            openBracketCount++;
            if (openBracketCount > 1) {
                return true; // ���� ������� �������� ����� ����� ����, � ������� �����
            }
        }
        else if (ch == ')') {
            openBracketCount--;
        }
    }
    return false;
}

// �������, ��� ������� ���� �� ������� ����� � �������
string removeBracketContent(const string& line) {
    string result;
    bool insideBrackets = false;
    for (char ch : line) {
        if (ch == '(') {
            insideBrackets = true; // ������� ����� � ������
        }
        else if (ch == ')') {
            insideBrackets = false; // ʳ���� ����� � ������
        }
        else if (!insideBrackets) {
            result += ch; // ������ ������, ���� �� ���� �������
        }
    }
    return result;
}

// �������, ��� �������� ���� ����� � ������ � ����� ����
void processFileContent(const char* inputFileName, const char* outputFileName) {
    ifstream fin(inputFileName);
    ofstream fout(outputFileName);

    if (!fin.is_open() || !fout.is_open()) {
        cerr << "Error: cannot open file." << endl;
        return;
    }

    string line;
    while (getline(fin, line)) {
        // �������� �� ������� �����
        if (hasNestedBrackets(line)) {
            cerr << "Error: nested brackets detected." << endl;
            return;
        }

        // ��������� ����� � ������
        string modifiedLine = removeBracketContent(line);
        fout << modifiedLine << endl; // �������� ��������� � ����
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

    // ������� �����
    processFileContent(inputFileName, outputFileName);

    return 0;
}
