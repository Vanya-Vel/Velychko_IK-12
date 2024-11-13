// Lab_10_1 A.cpp
// < ������� ���� >
// ����������� ������ � 10.1 A
// ���������� ����� � ����� ��������
// ������ 3

#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>  // ��� SetConsoleCP �� SetConsoleOutputCP

using namespace std;

// ������ ��������������
// ��������� ������ �������������� (����������), �� ������ ���� ��������
enum class Speciality {
    COMPUTER_SCIENCE,
    MATHEMATICS,
    PHYSICS,
    ENGINEERING
};

// ������� ��� ������������ ������������ � ��������� ������
// ������� ����� ������������ � ������ �����, ������� �� �������� �������� Speciality
string getSpecialityName(Speciality speciality) {
    switch (speciality) {
    case Speciality::COMPUTER_SCIENCE: return "����'����� �����";
    case Speciality::MATHEMATICS: return "����������";
    case Speciality::PHYSICS: return "Գ����";
    case Speciality::ENGINEERING: return "��������";
    default: return "�������";
    }
}

// ��������� ��� ��������� ���������� ��� ��������
// ��������� ��������� Student, ��� ������ ID ��������, �������, ����, ������������ �� ������
struct Student {
    int id;                    // ���������� ����� �������� � ����
    string surname;            // ������� ��������
    int course;                // ���� ��������
    Speciality speciality;     // ������������ ��������
    int physicsGrade;          // ������ � ������
    int mathGrade;             // ������ � ����������
    int informaticsGrade;      // ������ � �����������
};

// ������� ��� ��������� ������� � ����������� ��� ��������
// �������� �� ����� ������������� ������� � �������� ����������� ��� ������� ��������
void printStudentTable(const Student students[], int size) {
    cout << left << setw(5) << "ID" << setw(15) << "�������" << setw(8) << "����"
        << setw(20) << "������������" << setw(10) << "Գ����" << setw(15) << "����������"
        << setw(15) << "�����������" << endl;
    cout << string(84, '-') << endl;
    for (int i = 0; i < size; ++i) {
        cout << left << setw(5) << students[i].id
            << setw(15) << students[i].surname
            << setw(8) << students[i].course
            << setw(22) << getSpecialityName(students[i].speciality)
            << setw(12) << students[i].physicsGrade
            << setw(16) << students[i].mathGrade
            << setw(15) << students[i].informaticsGrade
            << endl;
    }
    cout << string(84, '-') << endl;
}

// ������� ��� ��������� �������� ��� �����
// �������� ������� �� ���������� ��� ��������, �� �� ����� ������ "3" � ����-����� ��������
void printStudentsWithoutThrees(const Student students[], int size) {
    cout << "\n��������, �� ������� ��� �����:\n";
    cout << left << setw(15) << "�������" << setw(10) << "����" << setw(20) << "������������" << endl;
    cout << string(42, '-') << endl;
    for (int i = 0; i < size; ++i) {
        if (students[i].physicsGrade >= 4 && students[i].mathGrade >= 4 && students[i].informaticsGrade >= 4) {
            cout << left << setw(15) << students[i].surname
                << setw(10) << students[i].course
                << setw(20) << getSpecialityName(students[i].speciality)
                << endl;
        }
    }
    cout << string(42, '-') << endl;
}

// ������� ��� ��������� �������� � ������� "5" � ������
// ϳ������� ������� ��������, �� �������� ����������� ������ � ������ (5)
void countStudentsWithFiveInPhysics(const Student students[], int size, int& count) {
    for (int i = 0; i < size; ++i) {
        if (students[i].physicsGrade == 5) {
            count++;
        }
    }
}

int main() {
    // ������������ ��������� ��� Windows
    SetConsoleCP(1251);          // ������������ ������� win-cp1251 ��� �����
    SetConsoleOutputCP(1251);    // ������������ ������� win-cp1251 ��� ������

    const int studentCount = 5; // ʳ������ ��������
    // ����������� ������ �������� � ���������� ������� ������
    Student students[studentCount] = {
        {1, "��������", 1, Speciality::COMPUTER_SCIENCE, 5, 4, 5},
        {2, "��������", 2, Speciality::MATHEMATICS, 4, 4, 4},
        {3, "���������", 1, Speciality::PHYSICS, 3, 5, 4},
        {4, "���������", 3, Speciality::ENGINEERING, 5, 5, 5},
        {5, "��������", 2, Speciality::COMPUTER_SCIENCE, 4, 3, 4}
    };

    // ��������� ����� ������� ��������
    cout << "������� ��������:\n";
    printStudentTable(students, studentCount);

    // ��������� �������� ��� �����
    printStudentsWithoutThrees(students, studentCount);

    // ϳ�������� ��������, �� �������� ������ "5" � ������
    int count = 0;
    countStudentsWithFiveInPhysics(students, studentCount, count);
    cout << "\nʳ������ ��������, �� �������� ������ '5' � ������: " << count << endl;

    return 0;
}
