#include <iostream>
#include <cstring>
using namespace std;

// ������� ��� ��������� ��� � �����
int Count(char* str, int& k, int i = 0) 
{
    if (strlen(str) < 3) 
    {
        return 0;
    }

    if (str[i] == '\0') 
    {
        return (k >= 3) ? k : 0;  // ��������� k, ���� 3 ��� �����
    }

    if (str[i] == ',')
    { 
        k++; 
    }

    return Count(str, k, i + 1);
}

// ������� ��� ���� �����, �������� ���� �� '**'
char* Change(const char* str, char* t, int i) {
    if (str[i] != 0) 
    {  // ���� �� ��������� ���� �����
        if (str[i] == ',') 
        { 
            strcat_s(t, 3, "**"); 
            return Change(str, t + 2, i + 1);  // ����������� ������
        }
        else {
            *t++ = str[i++];  // ������� ������
            *t = '\0';  // ��������� �����
            return Change(str, t, i);  // ����������� ������
        }
    }
    else 
    {
        *t++ = str[i++];  // ������ ������� ������
        *t++ = str[i++];  // ������ ��������� ������
        *t = '\0';  // ��������� �����
        return t;  // ��������� ����� ������ �����
    }
}

int main() {
    char str[101];  // ����������� �����
    cout << "Enter string:" << endl;
    cin.getline(str, 100);  // ���������� �����
    int k = 0;
    cout << "String contained " << Count(str, k) << " commas." << endl;  // �������� ������� ���

    char* dest1 = new char[151];  // �������� ���'��� ��� ������ �����
    dest1[0] = '\0';  // ���������� ����� �����
    Change(str, dest1, 0);  // ���� �����

    cout << "Modified string (result): " << dest1 << endl; 

    delete[] dest1;  // ��������� ���'���

    return 0;
}
