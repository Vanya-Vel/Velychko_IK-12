#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>  // ��� �������� �������� � ������

using namespace std;

enum Speciality { COMPUTER_SCIENCE, MATHEMATICS_AND_ECONOMICS, PHYSICS_AND_INFORMATICS, EDUCATION, INFORMATICS };

// ��'������� ��� ������ ������ � ��������� �� ������������
union Grade {
    int physicsGrade;           // ������ � ������
    int programmingGrade;       // ������ � ������������� (��� "��������� �����")
    int numericalMethodsGrade;  // ������ � ��������� ������ (��� "�����������")
    int pedagogyGrade;          // ������ � ��������� (��� ����� ��������������)
};

// ��������� ��� ��������� ���������� ��� ��������
struct Student {
    int id;                    // ������������� ��������
    string lastName;           // ������� ��������
    Speciality speciality;     // ������������ ��������
    int physicsGrade;          // ������ � ������
    int mathGrade;             // ������ � ����������
    Grade thirdGrade;          // ����� ������ (�������� �� ������������)
    double averageGrade;       // ������� ���
};

// ������� ��� ���������� ���������� ���� ��������
void calculateAverage(Student& student) {
    if (student.speciality == COMPUTER_SCIENCE)
        student.averageGrade = (student.physicsGrade + student.mathGrade + student.thirdGrade.programmingGrade) / 3.0;
    else if (student.speciality == INFORMATICS)
        student.averageGrade = (student.physicsGrade + student.mathGrade + student.thirdGrade.numericalMethodsGrade) / 3.0;
    else
        student.averageGrade = (student.physicsGrade + student.mathGrade + student.thirdGrade.pedagogyGrade) / 3.0;

    student.averageGrade = round(student.averageGrade * 100) / 100.0; // ���������� �� 2 ����� ���� ����
}

// ���������� �������� �� ������������ �� ������� �����
void sortStudents(Student students[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (students[j].speciality > students[j + 1].speciality ||
                (students[j].speciality == students[j + 1].speciality && students[j].averageGrade < students[j + 1].averageGrade) ||
                (students[j].speciality == students[j + 1].speciality && students[j].averageGrade == students[j + 1].averageGrade && students[j].lastName > students[j + 1].lastName)) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

// �������� ����� �������� �� ��������, ������������ �� ������� �����
bool binarySearchStudent(Student students[], int count, const string& lastName, Speciality speciality, double averageGrade) {
    int left = 0, right = count - 1; // ��� ������
    while (left <= right) {
        int mid = left + (right - left) / 2;

        // ��������� �������� �� ������������, ������� ����� � ��������
        if (students[mid].speciality == speciality && students[mid].averageGrade == averageGrade && students[mid].lastName == lastName) {
            return true;
        }

        if (students[mid].speciality < speciality ||
            (students[mid].speciality == speciality && students[mid].averageGrade < averageGrade) ||
            (students[mid].speciality == speciality && students[mid].averageGrade == averageGrade && students[mid].lastName < lastName)) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return false;
}

// �������� ����� ��� ��������
void inputStudentData(Student students[], int& count) {
    cout << "������ ������� ��������: ";
    cin >> count;

    for (int i = 0; i < count; ++i) {
        students[i].id = i + 1;

        cout << "������ ������� ��������: ";
        cin >> students[i].lastName;

        int specialityChoice;
        cout << "������� ������������ (0 - ��������� �����, 1 - ���������� �� ��������, 2 - Գ���� �� �����������, 3 - ������� ��������, 4 - �����������): ";
        cin >> specialityChoice;
        students[i].speciality = static_cast<Speciality>(specialityChoice);

        cout << "������ ������ � ������: ";
        cin >> students[i].physicsGrade;

        cout << "������ ������ � ����������: ";
        cin >> students[i].mathGrade;

        // �������� ������ ������ � ��������� �� ������������
        if (students[i].speciality == COMPUTER_SCIENCE) {
            cout << "������ ������ � �������������: ";
            cin >> students[i].thirdGrade.programmingGrade;
        }
        else if (students[i].speciality == INFORMATICS) {
            cout << "������ ������ � ��������� ������: ";
            cin >> students[i].thirdGrade.numericalMethodsGrade;
        }
        else {
            cout << "������ ������ � ���������: ";
            cin >> students[i].thirdGrade.pedagogyGrade;
        }

        // ���������� ���������� ���� ��������
        calculateAverage(students[i]);
    }
}

// ��������� ������� ��������
void printStudents(Student students[], int count) {
    cout << left << setw(4) << "ID"
        << setw(15) << "�������"
        << setw(30) << "������������"
        << setw(8) << "Գ����"
        << setw(12) << "����������"
        << setw(14) << "����� ������"
        << setw(12) << "������� ���" << endl;
    cout << string(84, '-') << endl;

    for (int i = 0; i < count; ++i) {
        cout << left << setw(4) << students[i].id
            << setw(15) << students[i].lastName;

        // ��������� ������������
        switch (students[i].speciality) {
        case COMPUTER_SCIENCE: cout << setw(30) << "��������� �����"; break;
        case MATHEMATICS_AND_ECONOMICS: cout << setw(30) << "���������� �� ��������"; break;
        case PHYSICS_AND_INFORMATICS: cout << setw(30) << "Գ���� �� �����������"; break;
        case EDUCATION: cout << setw(30) << "������� ��������"; break;
        case INFORMATICS: cout << setw(30) << "�����������"; break;
        }

        cout << setw(8) << students[i].physicsGrade
            << setw(12) << students[i].mathGrade;

        // ��������� ������ ������ ������� �� ������������
        if (students[i].speciality == COMPUTER_SCIENCE) {
            cout << setw(12) << students[i].thirdGrade.programmingGrade;
        }
        else if (students[i].speciality == INFORMATICS) {
            cout << setw(12) << students[i].thirdGrade.numericalMethodsGrade;
        }
        else {
            cout << setw(14) << students[i].thirdGrade.pedagogyGrade;
        }

        cout << setw(12) << students[i].averageGrade << endl;
    }
    cout << string(84, '-') << endl;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int count;
    Student students[100];  // ����������� ������� �������� = 100

    inputStudentData(students, count);  // �������� ����� ��� ��������

    sortStudents(students, count);  // ���������� ��������
    printStudents(students, count); // ��������� ������� ��������

    // ����� �������� �� ��������, ������������ �� ������� �����
    string lastName;
    int specialityChoice;
    double averageGrade;

    cout << "������ ������� ��������: ";
    cin >> lastName;
    cout << "������� ������������ (0 - ��������� �����, 1 - ���������� �� ��������, 2 - Գ���� �� �����������, 3 - ������� ��������, 4 - �����������): ";
    cin >> specialityChoice;
    Speciality speciality = static_cast<Speciality>(specialityChoice);
    cout << "������ ������� ��� ��������: ";
    cin >> averageGrade;

    if (binarySearchStudent(students, count, lastName, speciality, averageGrade)) {
        cout << "������� ���������!" << endl;
    }
    else {
        cout << "�������� �� ��������!" << endl;
    }

    return 0;
}
