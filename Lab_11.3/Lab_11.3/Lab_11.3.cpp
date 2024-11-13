// Lab_11_3.cpp
// < ������� ���� >
// ����������� ������ � 11.3
// ����������� ���������� �����
// ������ 3

#include <iostream>
#include <fstream>
#include <string>
#include<windows.h>

using namespace std;

// ������� ��� ��������� �������� � ����
void addResident(const string& filename) {
    ofstream file(filename, ios::app);
    if (!file.is_open()) {
        cerr << "������� �������� ����� ��� ������." << endl;
        return;
    }

    string lastName, initials;
    int roomNumber;

    cout << "������ ������� ��������: ";
    cin >> lastName;
    cout << "������ ������� ��������: ";
    cin >> initials;
    cout << "������ ����� ������ (1-15): ";
    cin >> roomNumber;

    // �������� �� �������� ������ ������
    if (roomNumber < 1 || roomNumber > 15) {
        cerr << "������������ ����� ������." << endl;
        file.close();
        return;
    }

    // ����� �������� � ����
    file << lastName << " " << initials << " " << roomNumber << endl;
    cout << "�������� ������." << endl;

    file.close();
}

// ������� ��� ������ �������� �� �������� (� �� ���������, ���� �������)
void findResident(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "������� �������� ����� ��� �������." << endl;
        return;
    }

    string lastName, searchLastName, initials, searchInitials;
    int roomNumber;
    bool found = false;
    int count = 0;

    cout << "������ ������� ��� ������: ";
    cin >> searchLastName;

    // ����� ��������� � ��������� ��������
    while (file >> lastName >> initials >> roomNumber) {
        if (lastName == searchLastName) {
            count++;
            if (count == 1) {
                searchInitials = initials;
                roomNumber = roomNumber;
            }
            else if (count > 1) {
                break;
            }
            found = true;
        }
    }

    file.clear();
    file.seekg(0); // ����������� �� ������� ����� ��� ���������� �������, ���� ������� ���������

    if (!found) {
        cout << "�������� � ����� �������� �� ��������." << endl;
    }
    else if (count == 1) {
        cout << "���������: " << searchLastName << " " << searchInitials
            << " ����������� � ����� " << roomNumber << "." << endl;
    }
    else {
        cout << "�������� ������� ��������� � �������� " << searchLastName << "." << endl;
        cout << "������ ������� ��� ���������: ";
        cin >> searchInitials;

        found = false;
        while (file >> lastName >> initials >> roomNumber) {
            if (lastName == searchLastName && initials == searchInitials) {
                cout << "���������: " << searchLastName << " " << searchInitials
                    << " ����������� � ����� " << roomNumber << "." << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "�������� � ����� �������� � ��������� �� ��������." << endl;
        }
    }

    file.close();
}

// ������� ��� ����������� ����
void displayMenu() {
    cout << "\n����:\n";
    cout << "1. ������ ��������\n";
    cout << "2. ������ �������� �� ��������\n";
    cout << "0. �����\n";
}

int main() {
    SetConsoleCP(1251);           // ������������ ��������� ��������� ��� �����
    SetConsoleOutputCP(1251);     // ������������ ��������� ��������� ��� ������

    string filename;
    cout << "������ ��'� ����� ��� ��������� �����: ";
    cin >> filename;

    int choice;
    do {
        displayMenu();
        cout << "������� ��: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addResident(filename);
            break;
        case 2:
            findResident(filename);
            break;
        case 0:
            cout << "���������� ��������." << endl;
            break;
        default:
            cout << "������������ ����. ��������� �� ���." << endl;
        }
    } while (choice != 0);

    return 0;
}
