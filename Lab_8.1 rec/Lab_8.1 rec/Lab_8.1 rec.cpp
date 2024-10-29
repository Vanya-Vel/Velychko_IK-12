#include <iostream>
#include <cstring>
using namespace std;

// Функція для підрахунку ком у рядку
int Count(char* str, int& k, int i = 0) 
{
    if (strlen(str) < 3) 
    {
        return 0;
    }

    if (str[i] == '\0') 
    {
        return (k >= 3) ? k : 0;  // Повертаємо k, якщо 3 або більше
    }

    if (str[i] == ',')
    { 
        k++; 
    }

    return Count(str, k, i + 1);
}

// Функція для зміни рядка, замінюючи коми на '**'
char* Change(const char* str, char* t, int i) {
    if (str[i] != 0) 
    {  // Якщо не досягнуто кінця рядка
        if (str[i] == ',') 
        { 
            strcat_s(t, 3, "**"); 
            return Change(str, t + 2, i + 1);  // Рекурсивний виклик
        }
        else {
            *t++ = str[i++];  // Копіюємо символ
            *t = '\0';  // Завершуємо рядок
            return Change(str, t, i);  // Рекурсивний виклик
        }
    }
    else 
    {
        *t++ = str[i++];  // Додаємо останній символ
        *t++ = str[i++];  // Додаємо наступний символ
        *t = '\0';  // Завершуємо рядок
        return t;  // Повертаємо кінець нового рядка
    }
}

int main() {
    char str[101];  // Оригінальний рядок
    cout << "Enter string:" << endl;
    cin.getline(str, 100);  // Зчитування рядка
    int k = 0;
    cout << "String contained " << Count(str, k) << " commas." << endl;  // Виводимо кількість ком

    char* dest1 = new char[151];  // Виділяємо пам'ять для нового рядка
    dest1[0] = '\0';  // Ініціалізуємо новий рядок
    Change(str, dest1, 0);  // Зміна рядка

    cout << "Modified string (result): " << dest1 << endl; 

    delete[] dest1;  // Звільняємо пам'ять

    return 0;
}
