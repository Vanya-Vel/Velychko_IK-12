#include <iostream>
#include <string>
using namespace std;

// ������� ��� ��������� ����� � ������
string removeParenthesesContent(const string& input) {
    string result;  // ��������� ��� ����� � ������
    int depth = 0;  // ����� ��� ���������� ��������� �����

    for (char ch : input) {
        if (ch == '(') {
            depth++;
            if (depth > 1) {  // �������� �� ������� �����
                cout << "Error" << endl;
                return "";  // ��������� � ��� �������
            }
        }
        else if (ch == ')') {
            if (depth == 0) {  // �������, ���� ���������� ����� ��� �������� ����������
                cout << "Error" << endl;
                return "";
            }
            depth--;
        }
        else if (depth == 0) {  // ������ �������, �� �� � ������
            result += ch;
        }
    }

    if (depth != 0) {  // �������� �� �������� �����
        cout << "Error" << endl;
        return "";
    }

    return result;  // ��������� ���������
}

int main() {
    string input;
    cout << "Print: ";
    getline(cin, input);  // ���������� �����

    string output = removeParenthesesContent(input);  // ��������� ����� � ������
    if (!output.empty()) {
        cout << "Result: " << output << endl;  // ���� ����������
    }

    return 0;
}
