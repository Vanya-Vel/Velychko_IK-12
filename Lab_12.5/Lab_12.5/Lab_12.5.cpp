// Lab_12_5.cpp
// < ������� ���� >
// ����������� ������ � 12.5
// ���������, �ᒺ������ �� ����� �����
// ������ 3

#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>  // ��� SetConsoleCP � SetConsoleOutputCP

using namespace std;

// ��������� ��� ��������
struct Student {
    char surname[50];          // ������� ��������
    int grades[5];             // ����� � ��������
};

// ��������� ��� �����
struct Group {
    char groupName[20];        // ����� �����
    int numStudents;           // ʳ������ �������� � ����
    Student students[30];      // ����� ��������
};

// ��������� ��� ����������
struct Faculty {
    char name[50];             // ����� ����������
    int course;                // ���� ����������
    int numGroups;             // ʳ������ ����
    Group groups[10];          // ����� ����
};

// ������� ��� ������ ����� �� �����
void SaveToFile(const Faculty* faculties, int numFaculties, const string& filename) {
    ofstream fout(filename, ios::binary);
    if (!fout) {
        cout << "�� ������� ������� ���� ��� ������!" << endl;
        return;
    }

    for (int i = 0; i < numFaculties; ++i) {
        fout.write(reinterpret_cast<const char*>(&faculties[i]), sizeof(Faculty));
        for (int j = 0; j < faculties[i].numGroups; ++j) {
            fout.write(reinterpret_cast<const char*>(&faculties[i].groups[j]), sizeof(Group));
            for (int k = 0; k < faculties[i].groups[j].numStudents; ++k) {
                fout.write(reinterpret_cast<const char*>(&faculties[i].groups[j].students[k]), sizeof(Student));
            }
        }
    }

    fout.close();
    cout << "��� ������ ������� � ����!" << endl;
}

// ������� ��� ���������� � �����
void LoadFromFile(Faculty* faculties, int& numFaculties, const string& filename) {
    ifstream fin(filename, ios::binary);
    if (!fin) {
        cout << "�� ������� ������� ���� ��� �������!" << endl;
        return;
    }

    while (fin.read(reinterpret_cast<char*>(&faculties[numFaculties]), sizeof(Faculty))) {
        for (int i = 0; i < faculties[numFaculties].numGroups; ++i) {
            fin.read(reinterpret_cast<char*>(&faculties[numFaculties].groups[i]), sizeof(Group));
            for (int j = 0; j < faculties[numFaculties].groups[i].numStudents; ++j) {
                fin.read(reinterpret_cast<char*>(&faculties[numFaculties].groups[i].students[j]), sizeof(Student));
            }
        }
        ++numFaculties;
    }

    fin.close();
    cout << "��� ������ ������� � �����!" << endl;
}

// ������� ��� ���������� ������ ��������
void InputStudentGrades(Student& student, int maxGrades) {
    for (int i = 0; i < maxGrades; ++i) {
        cout << "������ ������ #" << i + 1 << ": ";
        cin >> student.grades[i];
    }
}

// ������� ��� �������� �������� � �����
void InputGroup(Group& group, int maxStudents, int maxGrades) {
    cout << "������ ����� �����: ";
    cin.ignore();
    cin.getline(group.groupName, 20);
    cout << "������ ������� �������� � ����: ";
    cin >> group.numStudents;

    for (int i = 0; i < group.numStudents; ++i) {
        cout << "������ ������� �������� #" << i + 1 << ": ";
        cin.ignore();
        cin.getline(group.students[i].surname, 50);
        InputStudentGrades(group.students[i], maxGrades);
    }
}

// ������� ��� �������� ����������
void InputFaculty(Faculty& faculty, int maxGroups, int maxStudents, int maxGrades) {
    cout << "������ ����� ����������: ";
    cin.ignore();
    cin.getline(faculty.name, 50);
    cout << "������ ���� ����������: ";
    cin >> faculty.course;
    cout << "������ ������� ����: ";
    cin >> faculty.numGroups;

    for (int i = 0; i < faculty.numGroups; ++i) {
        InputGroup(faculty.groups[i], maxStudents, maxGrades);
    }
}

// ������� ��� ��������� ��� ��������
void PrintAllStudents(const Faculty* faculties, int numFaculties) {
    cout << "������ ��� ��������:\n";
    for (int i = 0; i < numFaculties; ++i) {
        for (int j = 0; j < faculties[i].numGroups; ++j) {
            cout << "�����: " << faculties[i].groups[j].groupName << endl;
            for (int k = 0; k < faculties[i].groups[j].numStudents; ++k) {
                cout << "�������: " << faculties[i].groups[j].students[k].surname << " | ������: ";
                for (int l = 0; l < 5; ++l) {
                    cout << faculties[i].groups[j].students[k].grades[l] << " ";
                }
                cout << endl;
            }
        }
    }
}

// ������� ��� ��������� ��������
void PrintExcellentStudents(const Faculty* faculties, int numFaculties, int maxGrades) {
    cout << "������ ��������:\n";
    for (int i = 0; i < numFaculties; ++i) {
        for (int j = 0; j < faculties[i].numGroups; ++j) {
            for (int k = 0; k < faculties[i].groups[j].numStudents; ++k) {
                bool isExcellent = true;
                for (int l = 0; l < maxGrades; ++l) {
                    if (faculties[i].groups[j].students[k].grades[l] < 4) {
                        isExcellent = false;
                        break;
                    }
                }
                if (isExcellent) {
                    cout << faculties[i].groups[j].students[k].surname << endl;
                }
            }
        }
    }
}

// ������� ��� ������ ���������� � ��������� ������� ��������
void FindFacultyWithMostExcellentStudents(const Faculty* faculties, int numFaculties, int maxGrades) {
    int maxExcellent = 0;
    Faculty maxFaculty;

    for (int i = 0; i < numFaculties; ++i) {
        int excellentCount = 0;
        for (int j = 0; j < faculties[i].numGroups; ++j) {
            for (int k = 0; k < faculties[i].groups[j].numStudents; ++k) {
                bool isExcellent = true;
                for (int l = 0; l < maxGrades; ++l) {
                    if (faculties[i].groups[j].students[k].grades[l] < 4) {
                        isExcellent = false;
                        break;
                    }
                }
                if (isExcellent) {
                    ++excellentCount;
                }
            }
        }

        if (excellentCount > maxExcellent) {
            maxExcellent = excellentCount;
            maxFaculty = faculties[i];
        }
    }

    cout << "��������� � ��������� ������� ��������: " << maxFaculty.name << endl;
}

// ������� ��� ����������� ����� ��� �⳺�����
void FindGroupWithoutFailures(const Faculty* faculties, int numFaculties, int maxGrades) {
    for (int i = 0; i < numFaculties; ++i) {
        for (int j = 0; j < faculties[i].numGroups; ++j) {
            bool hasFailures = false;
            for (int k = 0; k < faculties[i].groups[j].numStudents; ++k) {
                for (int l = 0; l < maxGrades; ++l) {
                    if (faculties[i].groups[j].students[k].grades[l] == 2) {
                        hasFailures = true;
                        break;
                    }
                }
                if (hasFailures) break;
            }
            if (!hasFailures) {
                cout << "����� ��� �⳺�����: " << faculties[i].groups[j].groupName << endl;
            }
        }
    }
}

// ������� ����
void ShowMenu() {
    cout << "\n����:\n";
    cout << "1. �������� ����� ����\n";
    cout << "2. ������� � �����\n";
    cout << "3. ������� ��� ��������\n";
    cout << "4. ������� ��������\n";
    cout << "5. ������ ��������� � ��������� ������� ��������\n";
    cout << "6. ������ ����� ��� �⳺�����\n";
    cout << "7. �����\n";
    cout << "������� ��: ";
}

// ������� �������
int main() {
    // ������������ ������ ������� ��� ������
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int MAX_FACULTIES = 10;
    const int MAX_GROUPS = 10;
    const int MAX_STUDENTS = 30;
    const int MAX_GRADES = 5;

    Faculty faculties[MAX_FACULTIES];
    int numFaculties = 0;

    string filename;

    int choice;

    while (true) {
        ShowMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "������ ��'� ����� ��� ����������: ";
            cin >> filename;
            SaveToFile(faculties, numFaculties, filename);
            break;
        case 2:
            cout << "������ ��'� ����� ��� ����������: ";
            cin >> filename;
            LoadFromFile(faculties, numFaculties, filename);
            break;
        case 3:
            PrintAllStudents(faculties, numFaculties);
            break;
        case 4:
            PrintExcellentStudents(faculties, numFaculties, MAX_GRADES);
            break;
        case 5:
            FindFacultyWithMostExcellentStudents(faculties, numFaculties, MAX_GRADES);
            break;
        case 6:
            FindGroupWithoutFailures(faculties, numFaculties, MAX_GRADES);
            break;
        case 7:
            return 0;
        default:
            cout << "������� ����! ��������� �� ���." << endl;
        }
    }

    return 0;
}
