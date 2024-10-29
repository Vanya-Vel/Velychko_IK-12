#include <iostream>
using namespace std;

// ϳ�������� ������� ��� � �����
int CountCommas(char* str)
{
    int commaCount = 0; // ʳ������ ���
    int searchPos = 0;
    char* commaPtr;

    // ����� ���
    while ((commaPtr = strchr(str + searchPos, ',')))
    {
        commaCount++;
        searchPos = commaPtr - str + 1; // ��������� �������
    }
    return commaCount;
}

// ���� �����, ������� "**" ���� ����� ����
char* ModifyString(char* str)
{
    char* modifiedStr = new char[strlen(str) * 2 + 1]; // �������� ���'��
    char* commaPtr;
    int searchPos = 0;
    modifiedStr[0] = '\0';

    // ��������� ������ ����� �� "**"
    while (commaPtr = strchr(str + searchPos, ','))
    {
        strncat(modifiedStr, str + searchPos, commaPtr - (str + searchPos));
        strcat(modifiedStr, "**");
        searchPos = commaPtr - str + 1;
    }

    strcat(modifiedStr, str + searchPos); // ������ �������
    strcpy(str, modifiedStr); // ������� �����
    delete[] modifiedStr; // ��������� ���'��
    return str;
}

int main()
{
    char inputStr[101];
    cout << "Enter string:" << endl;
    cin.getline(inputStr, 100);
    cout << "String contained " << CountCommas(inputStr) << " of ','" << endl;

    ModifyString(inputStr); // ����������� �����
    cout << "Modified string: " << inputStr << endl;

    return 0;
}
