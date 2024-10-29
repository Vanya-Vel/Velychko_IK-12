#include <iostream>
using namespace std;

// Підрахунок кількості ком у рядку
int CountCommas(char* str)
{
    int commaCount = 0; // Кількість ком
    int searchPos = 0;
    char* commaPtr;

    // Пошук ком
    while ((commaPtr = strchr(str + searchPos, ',')))
    {
        commaCount++;
        searchPos = commaPtr - str + 1; // Оновлення позиції
    }
    return commaCount;
}

// Зміна рядка, додаючи "**" після кожної коми
char* ModifyString(char* str)
{
    char* modifiedStr = new char[strlen(str) * 2 + 1]; // Виділення пам'яті
    char* commaPtr;
    int searchPos = 0;
    modifiedStr[0] = '\0';

    // Додавання частин рядка та "**"
    while (commaPtr = strchr(str + searchPos, ','))
    {
        strncat(modifiedStr, str + searchPos, commaPtr - (str + searchPos));
        strcat(modifiedStr, "**");
        searchPos = commaPtr - str + 1;
    }

    strcat(modifiedStr, str + searchPos); // Додаємо залишок
    strcpy(str, modifiedStr); // Копіюємо назад
    delete[] modifiedStr; // Звільнення пам'яті
    return str;
}

int main()
{
    char inputStr[101];
    cout << "Enter string:" << endl;
    cin.getline(inputStr, 100);
    cout << "String contained " << CountCommas(inputStr) << " of ','" << endl;

    ModifyString(inputStr); // Модифікація рядка
    cout << "Modified string: " << inputStr << endl;

    return 0;
}
