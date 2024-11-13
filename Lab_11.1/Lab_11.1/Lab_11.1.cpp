// Lab_11_1.cpp
// < ������� ���� >
// ����������� ������ � 11.1
// ����� ������� � ���������� ����
// ������ 3

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// ������� ��� ������ ������� ������ ���� � �����
int findThirdCommaPosition(const string& line) {
    int commaCount = 0; // ˳������� ��� ���
    for (size_t i = 0; i < line.size(); i++) { // ���������� �� ������� �����
        if (line[i] == ',') {  // ���� ������ - �� ����
            commaCount++;  // �������� �������� ���
            if (commaCount == 3) {  // ���� �� ������� ����� ����
                return i + 1; // ��������� ������� ������ ���� (��������� � 1)
            }
        }
    }
    return -1; // ���� ������ ���� ����, ��������� -1
}

// ������� ��� ����������� ������ ����� � ������� ������ ���� � ����
void findThirdCommaLocation(const char* fname, int& lineNumber, int& commaPosition) {
    ifstream fin(fname); // ³�������� ���� ��� �������
    if (!fin.is_open()) {  // ���� �� ������� ������� ����
        cerr << "Error: cannot open file " << fname << endl; // �������� �������
        lineNumber = -1; // ������������ �������� -1 ��� ������ �����
        commaPosition = -1; // ������������ �������� -1 ��� ������� ����
        return;
    }

    string line;  // ����� ��� ��������� ������� ����� � �����
    lineNumber = 0;  // ���������� ����� �����
    commaPosition = -1;  // ���������� ������� ���� �� -1

    // ������ ���� ����� �� ������
    while (getline(fin, line)) {
        lineNumber++; // �������� ����� �����
        int position = findThirdCommaPosition(line);  // ������ ����� ���� � ��������� �����
        if (position != -1) {  // ���� ����� ���� ��������
            commaPosition = position; // �������� ������� ����
            return; // ��������� ������ �������, ���� ������� ����� ����
        }
    }

    // ���� ���� �� ��������, ������������ �������� -1
    lineNumber = -1;  // ������������ �������� -1 ��� ������ �����
    commaPosition = -1;  // ������������ �������� -1 ��� ������� ����
}

int main() {
    char fname[100];  // ����� ��� ��������� ���� �����
    cout << "Enter file name: ";  // �������� ����� �� �������� ���� �����
    cin >> fname;  // ������� ��'� �����

    int lineNumber, commaPosition;  // ���� ��� ��������� ���������� ������
    findThirdCommaLocation(fname, lineNumber, commaPosition);  // ��������� ������� ��� ������

    // ��������, �� ���� �������� ����� ����
    if (lineNumber != -1) {
        // ���� ���� ��������, �������� ����� ����� � ������� ����
        cout << "The third comma is located at line " << lineNumber
            << ", position " << commaPosition << "." << endl;
    }
    else {
        // ���� ���� �� ��������, �������� �����������
        cout << "The third comma was not found in the file." << endl;
    }

    return 0;
}
