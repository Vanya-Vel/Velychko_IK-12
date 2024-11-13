// Lab_10_2 A.cpp
// < ������� ���� >
// ����������� ������ � 10.2 A
// ������������� �� ������� ����� � ����� ��������
// ������ 3

#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>  // ��� �������� �������� � ������

using namespace std;

// ������ ��������������
enum Speciality { COMPUTER_SCIENCE, MATHEMATICS, PHYSICS };

// ��������� ��� ��������� ���������� ��� ��������
struct Student {
    int id;                    // ������������� ��������
    string lastName;           // ������� ��������
    int course;                // ���� ��������
    Speciality speciality;     // ������������ ��������
    int physicsGrade;          // ������ � ������
    int mathGrade;             // ������ � ����������
    int informaticsGrade;      // ������ � �����������
};

// ������� ��� ���������� ���������� ���� ��������
double calculateAverage(const Student& student) {
    // �������� ������ �������� ������ � ������, ���������� �� �����������,
    // ��������� �� ���� ����� ���� ����.
    return round((student.physicsGrade + student.mathGrade + student.informaticsGrade) / 3.0 * 100) / 100.0;
}

// ������� ��� ���������� �������� �� ������������, ������� ����� � ��������
void sortStudents(Student students[], int count) {
    // ���������� �� ���������� "���������", �������������� ��� ������:
    // ������������, ������� ��� � �������.
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            // ��������� ������������, ���������� ���� �� �������
            if (students[j].speciality > students[j + 1].speciality ||
                (students[j].speciality == students[j + 1].speciality && calculateAverage(students[j]) > calculateAverage(students[j + 1])) ||
                (students[j].speciality == students[j + 1].speciality && calculateAverage(students[j]) == calculateAverage(students[j + 1]) && students[j].lastName > students[j + 1].lastName)) {
                // ���� ������ �������� � ��� ��������� �������
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

// ������� ��� �������� ���������� ������
void indexSortStudents(Student students[], int indexArray[], int count) {
    // ���������� ���������� ������ �������� ��������
    for (int i = 0; i < count; i++) {
        indexArray[i] = i;
    }

    // ���������� ���������� ������ �� ���� � ���������, �� � ����� ��������
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            int index1 = indexArray[j];
            int index2 = indexArray[j + 1];
            // ��������� �������� ����� ������� ������
            if (students[index1].speciality > students[index2].speciality ||
                (students[index1].speciality == students[index2].speciality && calculateAverage(students[index1]) > calculateAverage(students[index2])) ||
                (students[index1].speciality == students[index2].speciality && calculateAverage(students[index1]) == calculateAverage(students[index2]) && students[index1].lastName > students[index2].lastName)) {
                // ���� ������� ��� ���� ������� � �����
                int temp = indexArray[j];
                indexArray[j] = indexArray[j + 1];
                indexArray[j + 1] = temp;
            }
        }
    }
}

// ������� ��� �������� ������ �������� �� ��������, ������������ �� ������� �����
bool binarySearchStudent(Student students[], int count, const string& lastName, Speciality speciality, double average) {
    int left = 0, right = count - 1; // ��� ������ � ������������� �����
    while (left <= right) {
        int mid = left + (right - left) / 2; // �������� ������
        double studentAvg = calculateAverage(students[mid]);
        // ���� ������� ��������, �� ������� ��������
        if (students[mid].speciality == speciality && studentAvg == average && students[mid].lastName == lastName) {
            return true;
        }
        // ���� ������� ������� �� ���� ��� �� ��������
        if (students[mid].speciality < speciality ||
            (students[mid].speciality == speciality && studentAvg < average) ||
            (students[mid].speciality == speciality && studentAvg == average && students[mid].lastName < lastName)) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return false; // ������� �� ���������
}

// ������� ��� �������� ����� ��� ��������
void inputStudentData(Student students[], int& count) {
    cout << "������ ������� ��������: ";
    cin >> count;

    // �������� ����� ��� ������� ��������
    for (int i = 0; i < count; ++i) {
        students[i].id = i + 1;

        cout << "������ ������� ��������: ";
        cin >> students[i].lastName;

        cout << "������ ���� ��������: ";
        cin >> students[i].course;

        int specialityChoice;
        cout << "������� ������������ (0 - ����'����� �����, 1 - ����������, 2 - Գ����): ";
        cin >> specialityChoice;
        students[i].speciality = static_cast<Speciality>(specialityChoice);

        cout << "������ ������ � ������: ";
        cin >> students[i].physicsGrade;

        cout << "������ ������ � ����������: ";
        cin >> students[i].mathGrade;

        cout << "������ ������ � �����������: ";
        cin >> students[i].informaticsGrade;
    }
}

// ������� ��� ��������� ����� �������� � ������ �������
void printStudents(Student students[], int count) {
    // ��������� ��������� �������
    cout << left << setw(4) << "ID"
        << setw(15) << "�������"
        << setw(6) << "����"
        << setw(16) << "������������"
        << setw(8) << "Գ����"
        << setw(12) << "����������"
        << setw(12) << "�����������" << endl;
    cout << string(72, '-') << endl;

    // ��������� ����� ��� ������� ��������
    for (int i = 0; i < count; ++i) {
        cout << left << setw(4) << students[i].id
            << setw(15) << students[i].lastName
            << setw(6) << students[i].course
            << setw(16) << students[i].speciality
            << setw(8) << students[i].physicsGrade
            << setw(12) << students[i].mathGrade
            << setw(12) << students[i].informaticsGrade << endl;
    }
    cout << string(72, '-') << endl;
}

int main() {
    // ������������ �������� �������� � ������
    SetConsoleCP(1251);          // ��������� ��������� ��� ��������
    SetConsoleOutputCP(1251);    // ��������� ��������� ��� ���������

    int count;
    Student students[100];  // ����� ��������, ����������� ������� 100

    inputStudentData(students, count);  // �������� ����� ��������

    sortStudents(students, count);  // ���������� ��������
    printStudents(students, count); // ��������� ������� ��������

    int indexArray[100];  // ��������� ����� ��� ���������� ������� ��������
    indexSortStudents(students, indexArray, count);  // ���������� �������

    // ����� �������� � �������� ���������
    string lastName;
    Speciality speciality;
    double average;

    cout << "������ ������� �������� ��� ������: ";
    cin >> lastName;

    int specialityChoice;
    cout << "������� ������������ ��� ������ (0 - ����'����� �����, 1 - ����������, 2 - Գ����): ";
    cin >> specialityChoice;
    // ���������� ���� ����� specialityChoice �� ���� Speciality �� ��������� static_cast.
    // �� ������, �� ������� ����� ����� ���������� �� �������� ������������� Speciality, � �� ������ �� �����.
    speciality = static_cast<Speciality>(specialityChoice);

    cout << "������ ������� ��� ��� ������: ";
    cin >> average;

    bool found = binarySearchStudent(students, count, lastName, speciality, average);
    if (found) {
        cout << "�������� ��������!\n";
    }
    else {
        cout << "�������� �� ��������.\n";
    }

    return 0;
}
