// Lab_10_1 B.cpp
// < ������� ���� >
// ����������� ������ � 10.1 B
// ���������� ����� � ����� ��������
// ������ 3

#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>  // ��� SetConsoleCP �� SetConsoleOutputCP

using namespace std;

// ������ ��������������
enum class Speciality {
    COMPUTER_SCIENCE,
    INFORMATICS,
    MATH_ECONOMICS,
    PHYSICS_INFORMATICS,
    LABOR_TRAINING
};

// ������� ��� ������������ ������������ � ��������� ������
string getSpecialityName(Speciality speciality) {
    switch (speciality) {
    case Speciality::COMPUTER_SCIENCE: return "����'����� �����";
    case Speciality::INFORMATICS: return "�����������";
    case Speciality::MATH_ECONOMICS: return "���������� �� ��������";
    case Speciality::PHYSICS_INFORMATICS: return "Գ���� �� �����������";
    case Speciality::LABOR_TRAINING: return "������� ��������";
    default: return "�������";
    }
}

// ��������� ��� ��������� ���������� ��� ��������
struct Student {
    int id;                    // ���������� ����� �������� � ����
    string surname;            // ������� ��������
    int course;                // ���� ��������
    Speciality speciality;     // ������������ ��������
    int physicsGrade;          // ������ � ������
    int mathGrade;             // ������ � ����������
    union {
        int programmingGrade;  // ������ � ������������� (��� COMPUTER_SCIENCE)
        int numericalMethodsGrade; // ������ � ��������� ������ (��� INFORMATICS)
        int pedagogyGrade;     // ������ � ��������� (��� ����� ��������������)
    } additionalGrade;         // ��'������� ��� ������ ������
};

// ������� ��� ��������� ������� � ����������� ��� ��������
void printStudentTable(const Student students[], int size) {
    cout << left << setw(4) << "ID"
        << setw(15) << "�������"
        << setw(6) << "����"
        << setw(25) << "������������"
        << setw(8) << "Գ����"
        << setw(12) << "����������"
        << setw(15) << "�������������" 
        << setw(17) << "������� ������" 
        << setw(10) << "���������" << endl;
    cout << string(112, '-') << endl;

    for (int i = 0; i < size; ++i) {
        cout << left << setw(4) << students[i].id
            << setw(15) << students[i].surname
            << setw(6) << students[i].course
            << setw(25) << getSpecialityName(students[i].speciality)
            << setw(8) << students[i].physicsGrade
            << setw(12) << students[i].mathGrade;

        // ���� ��������� ������ ������� �� ������������
        if (students[i].speciality == Speciality::COMPUTER_SCIENCE) {
            cout << setw(15) << students[i].additionalGrade.programmingGrade
                << setw(17) << "-"  // ������ ���� ��� ��������� ������
                << setw(10) << "-"; // ������ ���� ��� ���������
        }
        else if (students[i].speciality == Speciality::INFORMATICS) {
            cout << setw(15) << "-"  // ������ ���� ��� �������������
                << setw(17) << students[i].additionalGrade.numericalMethodsGrade
                << setw(10) << "-"; // ������ ���� ��� ���������
        }
        else {
            cout << setw(15) << "-"  // ������ ���� ��� �������������
                << setw(17) << "-"  // ������ ���� ��� ��������� ������
                << setw(10) << students[i].additionalGrade.pedagogyGrade;
        }
        cout << endl;
    }
    cout << string(112, '-') << endl;
}

// ������� ��� ��������� �������� ��� �����
void printStudentsWithoutThrees(const Student students[], int size) {
    cout << "\n��������, �� ������� ��� �����:\n";
    cout << left << setw(15) << "�������" << setw(10) << "����" << setw(20) << "������������" << endl;
    cout << string(46, '-') << endl;
    for (int i = 0; i < size; ++i) {
        if (students[i].physicsGrade >= 4 && 
            students[i].mathGrade >= 4 && 
            students[i].additionalGrade.programmingGrade >= 4 &&
            students[i].additionalGrade.numericalMethodsGrade >= 4 &&
            students[i].additionalGrade.pedagogyGrade >= 4) {
            cout << left << setw(15) << students[i].surname
                 << setw(10) << students[i].course
                 << setw(20) << getSpecialityName(students[i].speciality)
                 << endl;
        }
    }
    cout << string(46, '-') << endl;
}

// ������� ��� ��������� �������� � ������� "5" � ������
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
    Student students[studentCount] = {
        {1, "��������", 1, Speciality::COMPUTER_SCIENCE, 5, 4},
        {2, "��������", 2, Speciality::INFORMATICS, 4, 4},
        {3, "���������", 1, Speciality::MATH_ECONOMICS, 3, 5},
        {4, "���������", 3, Speciality::PHYSICS_INFORMATICS, 5, 5},
        {5, "��������", 2, Speciality::LABOR_TRAINING, 4, 3}
    };

    // ����������� ���������� ������
    students[0].additionalGrade.programmingGrade = 5;
    students[1].additionalGrade.numericalMethodsGrade = 4;
    students[2].additionalGrade.pedagogyGrade = 5;
    students[3].additionalGrade.pedagogyGrade = 4;
    students[4].additionalGrade.pedagogyGrade = 3;

    // ��������� ������� ��������
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
