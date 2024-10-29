#include <iostream>
#include <string>
using namespace std;

// Функція для видалення вмісту в дужках
string removeParenthesesContent(const string& input) {
    string result;  // Результат без вмісту в дужках
    int depth = 0;  // Змінна для відстеження вкладених дужок

    for (char ch : input) {
        if (ch == '(') {
            depth++;
            if (depth > 1) {  // Перевірка на вкладені дужки
                cout << "Error" << endl;
                return "";  // Завершуємо в разі помилки
            }
        }
        else if (ch == ')') {
            if (depth == 0) {  // Випадок, якщо закриваюча дужка без відповідної відкриваючої
                cout << "Error" << endl;
                return "";
            }
            depth--;
        }
        else if (depth == 0) {  // Додаємо символи, які не в дужках
            result += ch;
        }
    }

    if (depth != 0) {  // Перевірка на незакриті дужки
        cout << "Error" << endl;
        return "";
    }

    return result;  // Повертаємо результат
}

int main() {
    string input;
    cout << "Print: ";
    getline(cin, input);  // Зчитування рядка

    string output = removeParenthesesContent(input);  // Видалення вмісту в дужках
    if (!output.empty()) {
        cout << "Result: " << output << endl;  // Вивід результату
    }

    return 0;
}
