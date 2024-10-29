// Lab_8_1.cpp
// < Величко Іван >
// Лабораторна робота № 8.1
// Пошук та заміна символів у літерному рядку
// Варіант 3

#include <iostream>
#include <cstring>  // Додано для роботи з strlen і strcat

using namespace std;

// Функція для підрахунку кількості ком у рядку
int Count(char* str) 
{
    if (strlen(str) < 3)
        return 0;

    int commaCount = 0;  // Лічильник ком
    for (int i = 0; str[i] != '\0'; i++) 
    {
        if (str[i] == ',')
            commaCount++;
    }
    return commaCount;
}

// Функція для зміни рядка, замінюючи коми на '**'
char* Change(char* str) 
{
    size_t len = strlen(str);
    if (len < 3)
        return str;

    char* tmp = new char[len * 3 / 2 + 1];  // Виділяємо пам'ять для нового рядка
    char* t = tmp;           // Вказівник на новий рядок
    tmp[0] = '\0';           // Ініціалізуємо новий рядок

    size_t i = 0;
    while (i < len) 
    {        // Ітеруємо по старому рядку
        if (str[i] == ',') 
        {  
            strcat(t, "**");  
            t += 2;   
            i++;         
        }
        else 
        {
            *t++ = str[i++];
            *t = '\0';        // Завершуємо рядок
        }
    }
    // Завершуємо новий рядок
    *t = '\0';
    return tmp;             // Повертаємо новий рядок
}

int main() {
    char str[101];          // Оригінальний рядок
    cout << "Enter string:" << endl;
    cin.getline(str, 100);  // Зчитуємо рядок

    cout << "String contained " << Count(str) << " of ','" << endl;
    char* dest = Change(str);  // Змінюємо рядок

    cout << "Modified string (param): " << str << endl;
    cout << "Modified string (result): " << dest << endl; 

    delete[] dest;

    return 0;
}
