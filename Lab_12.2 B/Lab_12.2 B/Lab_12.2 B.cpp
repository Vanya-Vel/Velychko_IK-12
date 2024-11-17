// Lab_12_2 B.cpp
// < ������� ���� >
// ����������� ������ � 12.2 B
// ���������� ����� � �������� ����
// ������ 3

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <windows.h>  // ��� ������� SetConsoleCP �� SetConsoleOutputCP, �� ���������� �������� ���������

using namespace std;

// ������ ��������������, �� �������� ��������������� ���� ��������� �������� ������ �����
enum Speciality {
    ComputerScience,        // 0 - �����������
    SoftwareEngineering,    // 1 - ��������� ��������
    CyberSecurity,          // 2 - ʳ����������
    Physics,                // 3 - Գ����
    Math                    // 4 - ����������
};

// ��������� ��� ��������� ����� ��� ��������
struct Student {
    int id;                   // ���������� ����� ��������
    char surname[50];         // ������� �������� (����� ��� ��������� �� 50 �������)
    int course;               // ���� �������� (����� �� 1 �� 5)
    Speciality speciality;    // ������������ �������� (���� � ������� enum Speciality)
    int physics;              // ������ � ������ (�� 1 �� 5)
    int math;                 // ������ � ���������� (�� 1 �� 5)
    int programming;          // ������ � ������������� (����� ��� �������� ������������ ComputerScience)
    int numericalMethods;     // ������ � ��������� ������ (��� �������������� SoftwareEngineering, CyberSecurity)
    int pedagogy;             // ������ � ��������� (��� �������������� Physics, Math)
};

// ������� ��� ��������� �������� ����� � ����������
void CreateStudentFile(const char* filename) {
    ofstream fout(filename, ios::binary); // ³�������� ���� ��� ������ � �������� �����
    int n;
    cout << "ʳ������ ��������: ";  // �������� ������� ��������, ���� ����� ������ � ����
    cin >> n;

    for (int i = 0; i < n; i++) {  // ���� ��� �������� ����� ������� ��������
        Student student;  // ��������� ����� ��� ��������� ���������� ��� ��������
        student.id = i + 1;  // ���������� ���������� ����� ��������

        // �������� ����� ��������
        cout << "������� ��������: ";  // �������� �������
        cin >> student.surname;
        cout << "���� (1-5): ";  // �������� ���� ��������
        cin >> student.course;

        int spec;
        // �������� ������������ �������� (��������� �����, ��� �������������� � �������� enum)
        cout << "������������ (0 - Computer Science, 1 - Software Engineering, 2 - Cyber Security, 3 - Physics, 4 - Math): ";
        cin >> spec;
        student.speciality = static_cast<Speciality>(spec);  // ����������� ������� ����� � ��� Speciality

        // �������� ������ ��� ����� ���������
        cout << "������ � ������: ";
        cin >> student.physics;
        cout << "������ � ����������: ";
        cin >> student.math;

        // ��������� ������ � �������������, ��������� ������ �� ���������, � ��������� �� ������������
        if (student.speciality == ComputerScience) {
            cout << "������ � �������������: ";
            cin >> student.programming;
        }
        else {
            student.programming = -1;  // ���� ������������ �� "Computer Science", �� �� ���� �� ���������������
        }

        if (student.speciality == SoftwareEngineering || student.speciality == CyberSecurity) {
            cout << "������ � ��������� ������: ";
            cin >> student.numericalMethods;
        }
        else {
            student.numericalMethods = -1;  // ���� ������������ �� "Software Engineering" ��� "Cyber Security", �� �� ���� �� ���������������
        }

        if (student.speciality == Physics || student.speciality == Math) {
            cout << "������ � ���������: ";
            cin >> student.pedagogy;
        }
        else {
            student.pedagogy = -1;  // ���� ������������ �� "Physics" ��� "Math", �� �� ���� �� ���������������
        }

        // �������� ���������� ��� �������� � ������� ����
        fout.write((char*)&student, sizeof(student));
    }

    fout.close();  // ��������� ���� ���� ������
}

// ������� ��� ��������� ������ ��� �������� � ������ �������
void PrintStudents(const char* filename) {
    ifstream fin(filename, ios::binary);  // ³�������� ���� ��� ������� � �������� ������
    Student student;

    // ������������ ���� ��������� �������
    cout << left << setw(5) << "ID" << setw(20) << "�������" << setw(10) << "����"
        << setw(25) << "������������" << setw(10) << "Գ����" << setw(13) << "����������"
        << setw(15) << "�������������" << setw(20) << "������� ������" << setw(15) << "���������" << endl;

    // ��������� ��������� �� ������� ���
    cout << setfill('-') << setw(5) << "-" << setw(20) << "-" << setw(10) << "-"
        << setw(25) << "-" << setw(10) << "-" << setw(10) << "-"
        << setw(15) << "-" << setw(20) << "-" << setw(15) << "-" << endl;
    cout << setfill(' ');  // ��������� ���������� ������������ �������� ��� ���������

    // ������ � �������� ������� ��������
    while (fin.read((char*)&student, sizeof(student))) {
        cout << left << setw(5) << student.id
            << setw(20) << student.surname
            << setw(10) << student.course
            << setw(25) << (student.speciality == ComputerScience ? "Computer Science" :
                student.speciality == SoftwareEngineering ? "Software Engineering" :
                student.speciality == CyberSecurity ? "Cyber Security" :
                student.speciality == Physics ? "Physics" : "Math")
            << setw(10) << student.physics
            << setw(13) << student.math;

        // �������� ������ ��� ����������� ��������
        cout << setw(15) << (student.programming != -1 ? to_string(student.programming) : "-")
            << setw(20) << (student.numericalMethods != -1 ? to_string(student.numericalMethods) : "-")
            << setw(15) << (student.pedagogy != -1 ? to_string(student.pedagogy) : "-") << endl;
    }

    fin.close();  // ��������� ���� ���� �������
}

// ������� ��� ��������� ��������, �� �� ����� �����
void PrintStudentsWithoutThrees(const char* filename) {
    ifstream fin(filename, ios::binary);  // ³�������� ���� ��� ������� � �������� ������
    Student student;

    cout << "�������� ��� �����:" << endl;
    // ������ � ���������� ������ ������� ��������
    while (fin.read((char*)&student, sizeof(student))) {
        // ���� ������� �� ������ �� ����� 4 � ������ � ����������
        if (student.physics >= 4 && student.math >= 4) {
            // ��� ������������ "Computer Science" ���������� ������ � �������������
            if (student.speciality == ComputerScience && student.programming >= 4) {
                cout << student.surname << endl;  // �������� ������� ��������
            }
            // ��� �������������� "Physics" ��� "Math" ���������� ������ � ���������
            else if (student.speciality == Physics || student.speciality == Math) {
                if (student.pedagogy >= 4) {
                    cout << student.surname << endl;  // �������� ������� ��������
                }
            }
        }
    }
    fin.close();  // ��������� ���� ���� �������
}

// ������� ��� ��������� �������� � ������� "5" � ������
void CountPhysicsFive(const char* filename, int& count) {
    ifstream fin(filename, ios::binary);  // ³�������� ���� ��� ������� � �������� ������
    Student student;
    count = 0;

    // ������ ������� �������� � ���������� ������ � ������
    while (fin.read((char*)&student, sizeof(student))) {
        if (student.physics == 5) {
            count++;  // ���� ������ � ������ ������� 5, �������� ��������
        }
    }
    fin.close();  // ��������� ���� ���� �������
}

int main() {
    // ������������ ��������� Windows-1251 ��� ���������� ��������� ��������
    SetConsoleCP(1251);  // ������������ ��������� ��� ��������
    SetConsoleOutputCP(1251);  // ������������ ��������� ��� ���������

    char filename[100];

    // �������� � ����������� ��'� ����� ��� ������
    cout << "������ ��'� �����: ";
    cin >> filename;

    // ��������� ���� � ����������
    CreateStudentFile(filename);

    // �������� ���� �����
    PrintStudents(filename);

    // �������� �������� ��� �����
    PrintStudentsWithoutThrees(filename);

    // ϳ��������� ������� �������� � ������� "5" � ������
    int physicsFiveCount = 0;
    CountPhysicsFive(filename, physicsFiveCount);
    cout << "ʳ������ �������� � ������� '5' � ������: " << physicsFiveCount << endl;

    return 0;
}
