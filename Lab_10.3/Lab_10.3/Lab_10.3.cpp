#include <iostream>
#include <fstream>
#include <string>
#include <windows.h> 

using namespace std;

// ��������� ��� ��������� ����� ��� ��������
struct Resident {
    string lastName;    // ������� ��������
    string initials;    // ������� ��������
    int roomNumber;     // ����� ������
};

// ��������� �������
void displayMenu(); // ³������� ���� ��� �����������
void addResident(Resident*& residents, int& count, int maxRooms); // ���� ������ ��������
void editResident(Resident* residents, int count); // ������ ���������� ��� ��������
void deleteResident(Resident*& residents, int& count); // ������� �������� � ������
void findResident(const Resident* residents, int count); // ��������� �������� �� ��������
void loadFromFile(Resident*& residents, int& count, const string& filename); // ��������� ��� � �����
void saveToFile(const Resident* residents, int count, const string& filename); // ������ ��� � ����

int main() {
    SetConsoleCP(1251);           // ������������ ��������� ��������� ��� �����
    SetConsoleOutputCP(1251);     // ������������ ��������� ��������� ��� ������
    Resident* residents = nullptr;  // ��������� ����� ���������
    int count = 0;                  // ʳ������ ���������
    const int maxRooms = 15;        // ����������� ������� �����
    string filename;                // ��'� ����� ��� ����������/������������

    // �������� ��'� �����
    cout << "������ ��'� �����: ";
    cin >> filename;
    loadFromFile(residents, count, filename); // ������������ ����� � �����

    int choice; // ����� ��� ���������� ������ �����������
    do {
        displayMenu(); // ³���������� ����
        cout << "������� �����: ";
        cin >> choice;

        // ��������� 䳿 �� ����� ������ �����������
        switch (choice) {
        case 1: addResident(residents, count, maxRooms); break;
        case 2: editResident(residents, count); break;
        case 3: deleteResident(residents, count); break;
        case 4: findResident(residents, count); break;
        case 5: saveToFile(residents, count, filename); break;
        case 0: saveToFile(residents, count, filename); break; // ������ ��� ����� �������
        default: cout << "������������ ����!\n"; break;
        }
    } while (choice != 0);

    delete[] residents; // ��������� ���'�� ����� ����������� ��������
    return 0;
}

// ³���������� ���� ��������
void displayMenu() {
    cout << "\n����:\n"
        << "1. ������ ��������\n"
        << "2. ���������� ��������\n"
        << "3. �������� ��������\n"
        << "4. ������ �������� �� ��������\n"
        << "5. �������� ��� � ����\n"
        << "0. �����\n";
}

// ���� ������ �������� � �����
void addResident(Resident*& residents, int& count, int maxRooms) {
    // ��������, �� � ���� ������
    if (count >= maxRooms) {
        cout << "�� ������ ������!\n";
        return;
    }

    Resident newResident;
    cout << "������ �������: ";
    cin >> newResident.lastName;
    cout << "������ �������: ";
    cin >> newResident.initials;
    cout << "������ ����� ������: ";
    cin >> newResident.roomNumber;

    // ��������� ������ ������ � ���������� ����� ��� ������ ��������
    Resident* temp = new Resident[count + 1];
    for (int i = 0; i < count; ++i) {
        temp[i] = residents[i]; // ��������� �������� �����
    }
    temp[count++] = newResident; // ��������� ������ ��������
    delete[] residents; // ��������� ������� ������
    residents = temp;   // �������� �� ����� �����
}

// ������ ���������� ��� �������� �� ��������
void editResident(Resident* residents, int count) {
    string lastName;
    cout << "������ ������� ��� �����������: ";
    cin >> lastName;

    // ����� �������� �� ��������
    for (int i = 0; i < count; ++i) {
        if (residents[i].lastName == lastName) {
            cout << "�������: ";
            cin >> residents[i].initials;
            cout << "����� ������: ";
            cin >> residents[i].roomNumber;
            return;
        }
    }
    cout << "�������� �� ��������.\n";
}

// ������� �������� �� ��������
void deleteResident(Resident*& residents, int& count) {
    string lastName;
    cout << "������ ������� ��� ���������: ";
    cin >> lastName;

    for (int i = 0; i < count; ++i) {
        if (residents[i].lastName == lastName) {
            // ��������� ������ ������ �� ������� �����
            Resident* temp = new Resident[count - 1];
            for (int j = 0, k = 0; j < count; ++j) {
                if (j != i) temp[k++] = residents[j]; // ��������� ����� ��� ���������� ��������
            }
            delete[] residents;
            residents = temp;
            --count;
            cout << "�������� ��������.\n";
            return;
        }
    }
    cout << "�������� �� ��������.\n";
}

// ���� �������� �� ��������, ������ ������� ��� �����������
void findResident(const Resident* residents, int count) {
    string lastName, initials;
    cout << "������ ������� ��� ������: ";
    cin >> lastName;

    int found = 0, index = -1;
    for (int i = 0; i < count; ++i) {
        if (residents[i].lastName == lastName) {
            found++; // ϳ������� ������� ��������� � ����� ��������
            index = i;
        }
    }

    if (found == 0) {
        cout << "�������� �� ��������.\n";
    }
    else if (found == 1) {
        // �������� ���, ���� �������� ����� ������ �������� � ����� ��������
        cout << "ʳ�����: " << residents[index].roomNumber << "\n";
    }
    else {
        // ���� �������� ����� ������ ��������, �������� �������
        cout << "������ �������: ";
        cin >> initials;
        for (int i = 0; i < count; ++i) {
            if (residents[i].lastName == lastName && residents[i].initials == initials) {
                cout << "ʳ�����: " << residents[i].roomNumber << "\n";
                return;
            }
        }
        cout << "�������� � ������ ��������� �� ��������.\n";
    }
}

// ��������� ��� ��� ��������� � �����
void loadFromFile(Resident*& residents, int& count, const string& filename) {
    ifstream file(filename); // �������� ��������� ��� � �����
    if (!file) {
        cout << "�� ������� ������� ����.\n";
        return;
    }

    file >> count; // ���� ������� ���������
    residents = new Resident[count]; // �������� ���'�� ��� ������
    for (int i = 0; i < count; ++i) {
        file >> residents[i].lastName >> residents[i].initials >> residents[i].roomNumber; // ������� ����� ���������
    }
    file.close();
}

// ������ �� ��� ��� ��������� � ����
void saveToFile(const Resident* residents, int count, const string& filename) {
    ofstream file(filename); // ��������������� ��� ������ ����� � ����
    if (!file) {
        cout << "�� ������� ������� ���� ��� ������.\n";
        return;
    }

    file << count << "\n"; // ����� ������� ���������
    for (int i = 0; i < count; ++i) {
        // ������ ������� �������� �� ����� �����
        file << residents[i].lastName << " " << residents[i].initials << " " << residents[i].roomNumber << "\n";
    }
    file.close();
    cout << "��� ��������� � ����.\n";
}
