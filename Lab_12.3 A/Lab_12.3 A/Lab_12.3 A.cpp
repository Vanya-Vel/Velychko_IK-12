// Lab_12_3 A.cpp
// < ������� ���� >
// ����������� ������ � 12.3 A
// ������������� �� ������� ����� � �������� ����
// ������ 3

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <windows.h> // ��� SetConsoleCP �� SetConsoleOutputCP

using namespace std;

// ������ ��������������
enum Speciality { ComputerScience, SoftwareEngineering, CyberSecurity, Physics, Math };

// ��������� ��������
struct Student {
    int id;              // ���������� ����� ��������
    char surname[50];    // �������
    int course;          // ����
    Speciality speciality;  // ������������
    int physics;         // ������ � ������
    int math;            // ������ � ����������
    int informatics;     // ������ � �����������
};

// ������� ��� ��������� ����� � ������ ��������
void CreateFile(const char* filename) {
    ofstream fout(filename, ios::binary);
    if (!fout) {
        cout << "�� ������� ������� ���� ��� ������." << endl;
        return;
    }

    int n;
    cout << "������ ������� ��������: ";
    cin >> n;
    cin.ignore(); // �������� ����� �����

    for (int i = 0; i < n; i++) {
        Student student;
        student.id = i + 1;

        cout << "������� ��������: ";
        cin.getline(student.surname, 50);

        cout << "���� (1-5): ";
        while (!(cin >> student.course) || student.course < 1 || student.course > 5) {
            cout << "������� ���. ������ ���� (1-5): ";
            cin.clear();
            cin.ignore(100, '\n');
        }

        cout << "������������ (0 - Computer Science, 1 - Software Engineering, 2 - Cyber Security, 3 - Physics, 4 - Math): ";
        int spec;
        while (!(cin >> spec) || spec < 0 || spec > 4) {
            cout << "������� ���. ������ ������������ (0-4): ";
            cin.clear();
            cin.ignore(100, '\n');
        }
        student.speciality = static_cast<Speciality>(spec);

        cout << "������ � ������: ";
        cin >> student.physics;
        cout << "������ � ����������: ";
        cin >> student.math;
        cout << "������ � �����������: ";
        cin >> student.informatics;
        cin.ignore(); // �������� ����� �����

        fout.write((char*)&student, sizeof(student));
    }

    fout.close();
    cout << "���� ������ ��������." << endl;
}

// ������� ��� ��������� �������� � ����
void AddStudent(const char* filename) {
    ofstream fout(filename, ios::binary | ios::app);
    if (!fout) {
        cout << "�� ������� ������� ���� ��� ���������." << endl;
        return;
    }

    // �������� ������� ID ��������
    ifstream fin(filename, ios::binary);
    Student lastStudent;
    int lastId = 0;

    fin.seekg(-static_cast<int>(sizeof(Student)), ios::end);
    if (fin.read((char*)&lastStudent, sizeof(Student))) {
        lastId = lastStudent.id;
    }
    fin.close();

    Student student;
    student.id = lastId + 1;

    cout << "������� ��������: ";
    cin.ignore();
    cin.getline(student.surname, 50);

    cout << "���� (1-5): ";
    while (!(cin >> student.course) || student.course < 1 || student.course > 5) {
        cout << "������� ���. ������ ���� (1-5): ";
        cin.clear();
        cin.ignore(100, '\n');
    }

    cout << "������������ (0 - Computer Science, 1 - Software Engineering, 2 - Cyber Security, 3 - Physics, 4 - Math): ";
    int spec;
    while (!(cin >> spec) || spec < 0 || spec > 4) {
        cout << "������� ���. ������ ������������ (0-4): ";
        cin.clear();
        cin.ignore(100, '\n');
    }
    student.speciality = static_cast<Speciality>(spec);

    cout << "������ � ������: ";
    cin >> student.physics;
    cout << "������ � ����������: ";
    cin >> student.math;
    cout << "������ � �����������: ";
    cin >> student.informatics;

    fout.write((char*)&student, sizeof(student));
    fout.close();
    cout << "������� ������ �������." << endl;
}

// ������� ��� ��������� ������ ��������
void PrintFile(const char* filename) {
    ifstream fin(filename, ios::binary);
    if (!fin) {
        cout << "�� ������� ������� ���� ��� �������." << endl;
        return;
    }

    cout << left << setw(5) << "ID" << setw(20) << "�������" << setw(10) << "����"
        << setw(20) << "������������" << setw(10) << "Գ����" << setw(13) << "����������"
        << setw(10) << "�����������" << endl;
    cout << string(85, '-') << endl;

    Student student;
    while (fin.read((char*)&student, sizeof(student))) {
        cout << left << setw(5) << student.id
            << setw(20) << student.surname
            << setw(10) << student.course
            << setw(20) << (student.speciality == ComputerScience ? "Computer Science" :
                student.speciality == SoftwareEngineering ? "Software Engineering" :
                student.speciality == CyberSecurity ? "Cyber Security" :
                student.speciality == Physics ? "Physics" : "Math")
            << setw(10) << student.physics
            << setw(13) << student.math
            << setw(10) << student.informatics << endl;
    }

    fin.close();
}

// ���� ��������
void Menu() {
    char filename[100];
    cout << "������ ��'� �����: ";
    cin.getline(filename, 100);

    int choice;
    do {
        cout << "\n����:\n";
        cout << "1. �������� ����\n";
        cout << "2. ������� ����\n";
        cout << "3. ������ ��������\n";
        cout << "0. �����\n";
        cout << "��� ����: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            CreateFile(filename);
            break;
        case 2:
            PrintFile(filename);
            break;
        case 3:
            AddStudent(filename);
            break;
        case 0:
            cout << "����� � ��������." << endl;
            break;
        default:
            cout << "������� ����. ��������� �� ���." << endl;
        }
    } while (choice != 0);
}

// ������� �������
int main() {
    // ������������ ��������� Windows-1251 ��� �������� �� ���������
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Menu();
    return 0;
}
