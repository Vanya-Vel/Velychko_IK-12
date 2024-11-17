// Lab_12_4.cpp
// < ������� ���� >
// ����������� ������ � 12.4
// ����������� �������� �����
// ������ 3

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <windows.h>  // ��� SetConsoleCP �� SetConsoleOutputCP

using namespace std;

// ����������� ������� ������ �����
const int MAX_ROOMS = 15;  
// ʳ������ ��������� ������
const int SINGLE_ROOMS = 5;  
// ʳ������ �������� ������
const int DOUBLE_ROOMS = 10; 

// ��������� ��� ���������� ����� ��� ���������
struct Resident {
    string surname;      // ������� ��������
    string initials;     // ������� �������� (������ ���� ��������)
    int roomNumber;      // ����� ������
};

// ���������� ������� ��� ��������� ����� �������� � ������
void AddResident(const string& filename);
void EditResident(const string& filename);
void RemoveResident(const string& filename);
void FindResident(const string& filename);
void PrintResident(const Resident& resident);
void PrintMenu();

// ������� ��� �������� ���������� ��������� �������
bool IsValidSurname(const string& surname) {
    return !surname.empty();  // ������� �� ���� ��������
}

// ������� ��� �������� ���������� ������ ������
bool IsValidRoomNumber(int roomNumber) {
    return roomNumber >= 1 && roomNumber <= MAX_ROOMS;  // ����� ������ �� ���� �� 1 �� MAX_ROOMS
}

// ������� ������� ��������
int main() {
    // ������������ ��� �������� ������ � ��������� � ������
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string filename;
    // �������� ����� ����� ��� ���������� �����
    cout << "������ ��'� ����� ��� ���������� �����: ";
    cin >> filename;

    // ������� ���� ��������
    while (true) {
        PrintMenu();  // ��������� ����

        int choice;
        cout << "��� ����: ";
        cin >> choice;

        // ������� ������ �����������
        switch (choice) {
        case 1: 
            AddResident(filename);  // ������ ������ ��������
            break;
        case 2: 
            EditResident(filename);  // ���������� ��� ��������
            break;
        case 3: 
            RemoveResident(filename);  // �������� ��������
            break;
        case 4: 
            FindResident(filename);  // ������ ��������
            break;
        case 5: 
            return 0;  // ����� � ��������
        default: 
            cout << "������� ����. ��������� �� ���." << endl;  // ���� ���� �������
        }
    }
}

// ������� ��� ��������� ����
void PrintMenu() {
    cout << "\n����:\n";
    cout << "1. ������ ������ ��������\n";
    cout << "2. ���������� ��� ��������\n";
    cout << "3. �������� ��������\n";
    cout << "4. ������ ��������\n";
    cout << "5. �����\n";
}

// ������� ��� ��������� ������ ��������
void AddResident(const string& filename) {
    // ³������� ����� ��� ��������� ������ ��������
    fstream file(filename, ios::in | ios::out | ios::binary | ios::app);
    if (!file) {
        cout << "�� ������� ������� ����." << endl;
        return;
    }

    // �������� ����� ������ ��������
    Resident newResident;
    cout << "������ ������� ��������: ";
    cin >> newResident.surname;

    if (!IsValidSurname(newResident.surname)) {
        cout << "������ �������!" << endl;
        return;
    }

    cout << "������ ������� ��������: ";
    cin >> newResident.initials;

    int room;
    cout << "������ ����� ������ (1 - 15): ";
    cin >> room;

    if (!IsValidRoomNumber(room)) {
        cout << "������� ����� ������!" << endl;
        return;
    }

    newResident.roomNumber = room;

    // ����� ������ �������� � ������� ����
    file.write(reinterpret_cast<const char*>(&newResident), sizeof(newResident));
    file.close();

    cout << "�������� ������ ������!" << endl;
}

// ������� ��� ����������� ����� ��������
void EditResident(const string& filename) {
    // ³������� ����� ��� �����������
    fstream file(filename, ios::in | ios::out | ios::binary);
    if (!file) {
        cout << "�� ������� ������� ����." << endl;
        return;
    }

    string surname;
    cout << "������ ������� �������� ��� �����������: ";
    cin >> surname;

    bool found = false;
    Resident resident;
    
    // �������� ����� ��� ������ �������� �� ��������
    while (file.read(reinterpret_cast<char*>(&resident), sizeof(resident))) {
        if (resident.surname == surname) {
            found = true;
            cout << "��������� ���������: " << endl;
            PrintResident(resident);  // ��������� �������� ����� ��������

            // �������� ����� �����
            cout << "������ ��� �������: ";
            cin >> resident.initials;

            cout << "������ ����� ����� ������ (1 - 15): ";
            cin >> resident.roomNumber;

            if (!IsValidRoomNumber(resident.roomNumber)) {
                cout << "������� ����� ������!" << endl;
                return;
            }

            // ��������� �������� �� ������� � ��������� �����
            file.seekp(-static_cast<int>(sizeof(resident)), ios::cur);
            file.write(reinterpret_cast<const char*>(&resident), sizeof(resident));
            cout << "��� ������ ��������!" << endl;
            break;
        }
    }

    if (!found) {
        cout << "�������� � ����� �������� �� ��������!" << endl;
    }

    file.close();
}

// ������� ��� ��������� ��������
void RemoveResident(const string& filename) {
    // ³������� ����� ��� ������� �� ������
    fstream file(filename, ios::in | ios::out | ios::binary);
    if (!file) {
        cout << "�� ������� ������� ����." << endl;
        return;
    }

    string surname;
    cout << "������ ������� �������� ��� ���������: ";
    cin >> surname;

    // ��������� ���������� ���� ��� ���������� ��� �����, ���� ����, �� ������� ��������
    fstream tempFile("temp.dat", ios::out | ios::binary);
    bool found = false;
    Resident resident;

    // �������� ����� �� ��������� ����� � ���������� ����
    while (file.read(reinterpret_cast<char*>(&resident), sizeof(resident))) {
        if (resident.surname == surname) {
            found = true;
            cout << "��������� ���������: " << endl;
            PrintResident(resident);  // ��������� ����� ��������, ����� ���������
        }
        else {
            tempFile.write(reinterpret_cast<const char*>(&resident), sizeof(resident));
        }
    }

    if (!found) {
        cout << "�������� � ����� �������� �� ��������!" << endl;
        file.close();
        tempFile.close();
        return;
    }

    file.close();
    tempFile.close();

    // ��������� ������� ����� �� �������������� �����������
    remove(filename.c_str());
    rename("temp.dat", filename.c_str());

    cout << "��������� ������ ���������!" << endl;
}

// ������� ��� ������ ��������
void FindResident(const string& filename) {
    fstream file(filename, ios::in | ios::binary);
    if (!file) {
        cout << "�� ������� ������� ����." << endl;
        return;
    }

    string surname;
    cout << "������ ������� �������� ��� ������: ";
    cin >> surname;

    bool found = false;
    int count = 0;
    Resident resident;

    // �������� ����� ��� ������ �������� �� ��������
    while (file.read(reinterpret_cast<char*>(&resident), sizeof(resident))) {
        if (resident.surname == surname) {
            count++;
            if (count == 1) {
                cout << "��������� ���������: " << endl;
                PrintResident(resident);  // ��������� ����� ���������� ��������
            }
        }
    }

    if (count == 0) {
        cout << "�������� � ����� �������� �� ��������!" << endl;
    }
    else if (count > 1) {
        // ���� �������� ����� ��������� � ����� ��������
        cout << "��������� � ����� �������� �������. ������ ������� ��� ������� ������: ";
        string initials;
        cin >> initials;
        file.clear();
        file.seekg(0, ios::beg);
        found = false;
        
        // ������ ����� �� ���������
        while (file.read(reinterpret_cast<char*>(&resident), sizeof(resident))) {
            if (resident.surname == surname && resident.initials == initials) {
                found = true;
                PrintResident(resident);  // ��������� ���������� ��������
                break;
            }
        }
        if (!found) {
            cout << "�������� � ������ ��������� �� ��������!" << endl;
        }
    }

    file.close();
}

// ������� ��� ��������� ����� ��� ��������
void PrintResident(const Resident& resident) {
    cout << "�������: " << resident.surname << endl;
    cout << "�������: " << resident.initials << endl;
    cout << "����� ������: " << resident.roomNumber << endl;
}
