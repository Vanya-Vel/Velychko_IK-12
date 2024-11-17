// Lab_12_3 B.cpp
// < ������� ���� >
// ����������� ������ � 12.3 B
// ������������� �� ������� ����� � �������� ����
// ������ 3

#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <iomanip>

using namespace std;

// ������������� ��������������
enum Speciality {
    ComputerScience = 0,
    SoftwareEngineering,
    CyberSecurity,
    PhysicsAndInformatics,
    MathematicsAndEconomics,
    Pedagogy
};

// ������ ������� �� ������������
union Grades {
    int programming;
    int numericalMethods;
    int pedagogy;
};

// ��������� ��������
struct Student {
    int id;
    char surname[50];
    int course;
    Speciality speciality;
    int physics;
    int math;
    Grades thirdGrade;
};

// ������������ ��������� ����� ��� ������
void SetConsole() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
}

// ��������� ����� ������������
string GetSpecialityName(Speciality speciality) {
    switch (speciality) {
    case ComputerScience: return "����'����� �����";
    case SoftwareEngineering: return "��������� ��������";
    case CyberSecurity: return "ʳ����������";
    case PhysicsAndInformatics: return "Գ���� �� �����������";
    case MathematicsAndEconomics: return "���������� �� ��������";
    case Pedagogy: return "���������";
    default: return "������� ������������";
    }
}

// ���� ���������� ��� ������ ��������
void PrintStudent(const Student& student) {
    cout << left << setw(5) << student.id
        << setw(20) << student.surname
        << setw(10) << student.course
        << setw(20) << GetSpecialityName(student.speciality)
        << setw(10) << student.physics
        << setw(13) << student.math;

    switch (student.speciality) {
    case ComputerScience:
    case SoftwareEngineering:
    case CyberSecurity:
        cout << setw(15) << student.thirdGrade.programming;
        break;
    case PhysicsAndInformatics:
        cout << setw(15) << student.thirdGrade.numericalMethods;
        break;
    case MathematicsAndEconomics:
    case Pedagogy:
        cout << setw(15) << student.thirdGrade.pedagogy;
        break;
    default:
        cout << setw(15) << "N/A";
    }
    cout << endl;
}

// �������� ����� ��������
void InputStudent(Student& student, int& id) {
    student.id = id++;
    cin.ignore();

    cout << "������ �������: ";
    cin.getline(student.surname, 50);

    cout << "������ ���� (1-5): ";
    cin >> student.course;

    int spec;
    cout << "������ ������������ (0 - ����'����� �����, 1 - ��������� ��������, 2 - ʳ����������, 3 - Գ���� �� �����������, 4 - ���������� �� ��������, 5 - ���������): ";
    cin >> spec;
    student.speciality = static_cast<Speciality>(spec);

    cout << "������ ������ � ������: ";
    cin >> student.physics;

    cout << "������ ������ � ����������: ";
    cin >> student.math;

    switch (student.speciality) {
    case ComputerScience:
    case SoftwareEngineering:
    case CyberSecurity:
        cout << "������ ������ � �������������: ";
        cin >> student.thirdGrade.programming;
        break;
    case PhysicsAndInformatics:
        cout << "������ ������ � ��������� ������: ";
        cin >> student.thirdGrade.numericalMethods;
        break;
    case MathematicsAndEconomics:
    case Pedagogy:
        cout << "������ ������ � ���������: ";
        cin >> student.thirdGrade.pedagogy;
        break;
    }
}

// ��������� ������ ����� ��������
void CreateFile(const string& filename) {
    ofstream fout(filename, ios::binary);
    if (!fout) {
        cout << "�� ������� ������� ���� ��� ������!" << endl;
        return;
    }

    int n;
    int id = 1; // ��������� �������� ��� ID
    cout << "������ ������� ��������: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        Student student;
        InputStudent(student, id);
        fout.write(reinterpret_cast<const char*>(&student), sizeof(student));
    }

    fout.close();
    cout << "���� ������ ��������." << endl;
}

// ���� ��� �������� � �����
void PrintFile(const string& filename) {
    ifstream fin(filename, ios::binary);
    if (!fin) {
        cout << "�� ������� ������� ���� ��� �������!" << endl;
        return;
    }

    cout << left << setw(5) << "ID"
        << setw(20) << "�������"
        << setw(10) << "����"
        << setw(20) << "������������"
        << setw(10) << "Գ����"
        << setw(13) << "����������"
        << setw(15) << "����� ������" << endl;
    cout << string(88, '-') << endl;

    Student student;
    while (fin.read(reinterpret_cast<char*>(&student), sizeof(student))) {
        PrintStudent(student);
    }

    fin.close();
}

// ��������� ������ �������� �� ��������� �����
void AddStudentToFile(const string& filename) {
    ofstream fout(filename, ios::binary | ios::app);
    if (!fout) {
        cout << "�� ������� ������� ���� ��� ���������!" << endl;
        return;
    }

    ifstream fin(filename, ios::binary);
    fin.seekg(0, ios::end);
    int fileSize = fin.tellg();
    int id = fileSize / sizeof(Student) + 1;  // ��������� ��������� ID
    fin.close();

    Student student;
    InputStudent(student, id);

    fout.write(reinterpret_cast<const char*>(&student), sizeof(student));
    fout.close();
    cout << "�������� ������ ������." << endl;
}

// ������� �������
int main() {
    SetConsole();

    string filename;

    cout << "������ ����� ����� ��� ������: ";
    cin >> filename;

    while (true) {
        int choice;
        cout << "\n����:\n";
        cout << "1. �������� ����� ����\n";
        cout << "2. ������� ����\n";
        cout << "3. ������ ��������\n";
        cout << "4. �����\n";
        cout << "������ ����: ";
        cin >> choice;

        switch (choice) {
        case 1:
            CreateFile(filename);
            break;
        case 2:
            PrintFile(filename);
            break;
        case 3:
            AddStudentToFile(filename);
            break;
        case 4:
            return 0;
        default:
            cout << "������� ����. ��������� �� ���." << endl;
        }
    }
}
