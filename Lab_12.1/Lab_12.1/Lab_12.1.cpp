// Lab_12_1.cpp
// < ������� ���� >
// ����������� ������ � 12.1
// ������ �����
// ������ 3

#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

// ��������� �������� ����� � �������� �����
void CreateBIN(const char* fname) {
    ofstream fout(fname, ios::binary);
    string ch, s;

    do {
        cin.ignore();  // �������� ������
        cout << "������ �����: ";
        getline(cin, s);
        for (unsigned i = 0; i < s.length(); i++) {
            fout.write((char*)&s[i], sizeof(s[i]));
        }
        cout << "����������? (���/�): ";
        cin >> ch;
    } while (ch == "���" || ch == "���");
    fout.close();
}

// ��������� ����� �������� ����� �� �����
void PrintBIN(const char* fname) {
    ifstream fin(fname, ios::binary);
    char c;
    cout << "���� ����� (" << fname << "): ";
    while (fin.read((char*)&c, sizeof(c))) {
        cout << c;
    }
    cout << endl;
    fin.close();
}

// ������������� �������, �� �� ������� � ����� "��������"
void ProcessBIN(const char* fname, const char* gname) {
    ifstream f(fname, ios::binary);
    ofstream g(gname, ios::binary);

    const string excluded = "��������";
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
    SetConsoleCP(1251);  // ������������ ��������� Windows-1251 ��� ��������
    SetConsoleOutputCP(1251);  // ������������ ��������� Windows-1251 ��� ���������

    char fname[100], gname[100];

    // �������� ���� ������� �����
    cout << "������ ��'� ������� �����: ";
    cin >> fname;

    // ��������� �����
    CreateBIN(fname);

    // ��������� ����� ������� �����
    PrintBIN(fname);

    // �������� ���� ������� �����
    cout << "������ ��'� ������� �����: ";
    cin >> gname;

    // ������������� �������
    ProcessBIN(fname, gname);

    // ��������� ����� ������� �����
    PrintBIN(gname);

    return 0;
}
