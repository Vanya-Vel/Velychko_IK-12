// Lab_12_2 A.cpp
// < ������� ���� >
// ����������� ������ � 12.2 A
// ���������� ����� � �������� ����
// ������ 3

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip> // ��� ������������
#include <windows.h> // ��� ��������� Windows-1251

using namespace std;

// ������ ��������������
enum Speciality { ComputerScience, SoftwareEngineering, CyberSecurity, Physics, Math };

// ��������� ��������
struct Student {
    int id;             // ���������� �����
    char surname[50];   // �������
    int course;         // ����
    Speciality speciality; // ������������
    int physics;        // ������ � ������
    int math;           // ������ � ����������
    int informatics;    // ������ � �����������
};

// ������� ��� ��������� ����� ��������
void CreateStudentFile(const char* filename) {
    ofstream fout(filename, ios::binary); // ³�������� ���� ��� ������
    int n;
    cout << "ʳ������ ��������: ";
    cin >> n;

    // �������� ����� ��� ��������
    for (int i = 0; i < n; i++) {
        Student student;
        student.id = i + 1;
        cout << "������� ��������: ";
        cin >> student.surname;
        cout << "���� (1-5): ";
        cin >> student.course;

        int spec;
        cout << "������������ (0 - Computer Science, 1 - Software Engineering, 2 - Cyber Security, 3 - Physics, 4 - Math): ";
        cin >> spec;
        student.speciality = static_cast<Speciality>(spec); // ������������ � ��� Speciality

        // �������� ������
        cout << "������ � ������: ";
        cin >> student.physics;
        cout << "������ � ����������: ";
        cin >> student.math;
        cout << "������ � �����������: ";
        cin >> student.informatics;

        fout.write((char*)&student, sizeof(student)); // ����� � ����
    }
    fout.close(); // ��������� ����
}

// ������� ��������� �������� � ������� "5" � ������
void CountPhysicsFive(const char* filename, int& count) {
    ifstream fin(filename, ios::binary); // ³�������� ���� ��� �������
    Student student;
    count = 0;

    // ϳ�������� �������� � ������� "5" � ������
    while (fin.read((char*)&student, sizeof(student))) {
        if (student.physics == 5) {
            count++;
        }
    }
    fin.close();
}

// ������� ��������� �������� � �������
void PrintStudents(const char* filename) {
    ifstream fin(filename, ios::binary);
    Student student;

    // ������������ ���� �������
    cout << left << setw(5) << "ID" << setw(20) << "�������" << setw(10) << "����"
        << setw(25) << "������������" << setw(10) << "Գ����" << setw(10) << "����������"
        << setw(15) << "�����������" << endl;
    cout << "---------------------------------------------------------------" << endl;

    // ��������� ������� ��������
    while (fin.read((char*)&student, sizeof(student))) {
        cout << left << setw(5) << student.id
            << setw(20) << student.surname
            << setw(10) << student.course
            << setw(25) << (student.speciality == ComputerScience ? "Computer Science" :
                student.speciality == SoftwareEngineering ? "Software Engineering" :
                student.speciality == CyberSecurity ? "Cyber Security" :
                student.speciality == Physics ? "Physics" : "Math")
            << setw(10) << student.physics
            << setw(10) << student.math
            << setw(15) << student.informatics << endl;
    }
    fin.close();
}

// ������� ��������� �������� ��� �����
void PrintStudentsWithoutThrees(const char* filename) {
    ifstream fin(filename, ios::binary);
    Student student;

    cout << "�������� ��� �����:" << endl;

    // ��������� �������� ��� �����
    while (fin.read((char*)&student, sizeof(student))) {
        if (student.physics >= 4 && student.math >= 4 && student.informatics >= 4) {
            cout << student.surname << endl;
        }
    }
    fin.close();
}

int main() {
    // ������������ ��������� ��� �����/������
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char filename[100];
    cout << "������ ��'� �����: ";
    cin >> filename;

    // ��������� ����� � ������ ��������
    CreateStudentFile(filename);

    // ��������� ��� ��������
    PrintStudents(filename);

    // ��������� �������� ��� �����
    PrintStudentsWithoutThrees(filename);

    // ϳ�������� �������� � ������� "5" � ������
    int physicsFiveCount = 0;
    CountPhysicsFive(filename, physicsFiveCount);
    cout << "ʳ������ �������� � ������� '5' � ������: " << physicsFiveCount << endl;

    return 0; // ���������� ��������
}
