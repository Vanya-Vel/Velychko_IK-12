#include <iostream>
#include <string>
using namespace std;

// Функція для підрахунку ком у рядку
int Count(const string s) {
    int k = 0;  // Лічильник ком
    size_t pos = 0;  // Позиція пошуку
    while ((pos = s.find(',', pos)) != string::npos) 
    {  // Знайти кому
        pos++;
        k++;
    }
    return k;
}

// Функція для заміни ком на '**'
string Change(string& s) {
    size_t pos = 0;  // Позиція пошуку
    while ((pos = s.find(',', pos)) != string::npos) 
    {  // Знайти кому
        s.replace(pos, 1, "**");  // Заміна
        pos += 2;  // Пропускаємо символи '**'
    }
    return s;  // Повертаємо модифікований рядок
}

int main() {
    string str;  // Вхідний рядок
    cout << "Enter string:" << endl;
    getline(cin, str);  // Зчитування рядка
    cout << "String contained " << Count(str) << " of ','" << endl;  // Вивід кількості ком
    string dest = Change(str);  // Зміна рядка
    cout << "Modified string (result): " << dest << endl;  // Вивід модифікованого рядка
    return 0;
}
