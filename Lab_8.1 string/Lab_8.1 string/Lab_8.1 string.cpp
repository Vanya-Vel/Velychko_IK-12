#include <iostream>
#include <string>
using namespace std;

// ������� ��� ��������� ��� � �����
int Count(const string s) {
    int k = 0;  // ˳������� ���
    size_t pos = 0;  // ������� ������
    while ((pos = s.find(',', pos)) != string::npos) 
    {  // ������ ����
        pos++;
        k++;
    }
    return k;
}

// ������� ��� ����� ��� �� '**'
string Change(string& s) {
    size_t pos = 0;  // ������� ������
    while ((pos = s.find(',', pos)) != string::npos) 
    {  // ������ ����
        s.replace(pos, 1, "**");  // �����
        pos += 2;  // ���������� ������� '**'
    }
    return s;  // ��������� ������������� �����
}

int main() {
    string str;  // ������� �����
    cout << "Enter string:" << endl;
    getline(cin, str);  // ���������� �����
    cout << "String contained " << Count(str) << " of ','" << endl;  // ���� ������� ���
    string dest = Change(str);  // ���� �����
    cout << "Modified string (result): " << dest << endl;  // ���� �������������� �����
    return 0;
}
