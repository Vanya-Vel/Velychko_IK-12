#include <stdio.h>  // ��� ������������ ��������/���������
#include <fstream>  // ��� ������ � ������� (std::ifstream, std::ofstream)
#include <cctype>  // ��� ������� ������������ �������
#include <cassert> // ��� assert

#define IS_ALPHABETIC(c) (isalpha(c))    // ������� �������
#define IS_DIGIT(c) (isdigit(c))          // ������ �������
#define IS_CONTROL(c) (iscntrl(c))       // ������� �������
#define IS_PUNCTUATION(c) (ispunct(c))   // ����� ����������
#define IS_OTHER(c) (!isprint(c))         // ���� �������

// ������� ��� ������������ ������� � ����
void classifyCharacters(const char* filename, char lowerBound, char upperBound) {
    std::ifstream file(filename); // ³�������� ����
    if (!file.is_open()) { // �������� �� ������ �������� �����
        printf("Failed to open the file!\n"); // ���� ����������� ��� �������
        return; // ���������� �������
    }

    int alphabeticCount = 0; // ʳ������ ��������� �������
    int digitCount = 0;      // ʳ������ �������� �������
    int controlCount = 0;    // ʳ������ �������� �������
    int punctuationCount = 0; // ʳ������ ����� ����������
    int otherCount = 0;      // ʳ������ ����� �������

    char ch; // ����� ��� ���������� �������
    while (file.get(ch)) { // ������ ���� ������ �� ��������
        if (IS_ALPHABETIC(ch)) {
            alphabeticCount++; // �������� �������� ��������� �������
        }
        else if (IS_DIGIT(ch)) {
            digitCount++; // �������� �������� �������� �������
            if (ch >= lowerBound && ch <= upperBound) { // �������� �� ���
                printf("Digit character in range: %c\n", ch); // ���� ��������� ������� � �����
            }
        }
        else if (IS_CONTROL(ch)) {
            controlCount++; // �������� �������� �������� �������
        }
        else if (IS_PUNCTUATION(ch)) {
            punctuationCount++; // �������� �������� ����� ����������
        }
        else if (IS_OTHER(ch)) {
            otherCount++; // �������� �������� ����� �������
        }
    }

    // ��������� ����������
    printf("Number of alphabetic characters: %d\n", alphabeticCount); // ���� ������� ��������� �������
    printf("Number of digit characters: %d\n", digitCount); // ���� ������� �������� �������
    printf("Number of control characters: %d\n", controlCount); // ���� ������� �������� �������
    printf("Number of punctuation characters: %d\n", punctuationCount); // ���� ������� ����� ����������
    printf("Number of other characters: %d\n", otherCount); // ���� ������� ����� �������

    file.close(); // ��������� ����
}

int main() {
    char filename[256]; // ����� ��� ��������� ���� �����
    char lowerBound, upperBound; // ��� ��� �������� �������

    printf("Enter the filename: "); // ����� ���� �����
    if (scanf("%s", filename) != 1) { // �������� ����������� ��������
        printf("Error reading filename!\n");
        return 1; // ���������� �������� � ��������
    }

    printf("Enter the lower bound for digit characters: "); // ����� ������ ���
    if (scanf(" %c", &lowerBound) != 1) { // �������� ����������� ��������
        printf("Error reading lower bound!\n");
        return 1; // ���������� �������� � ��������
    }

    printf("Enter the upper bound for digit characters: "); // ����� ������� ���
    if (scanf(" %c", &upperBound) != 1) { // �������� ����������� ��������
        printf("Error reading upper bound!\n");
        return 1; // ���������� �������� � ��������
    }

    // �������� ����������� ���
    assert(lowerBound >= '0' && lowerBound <= '9'); // �������� ������ ���
    assert(upperBound >= '0' && upperBound <= '9'); // �������� ������� ���
    assert(lowerBound <= upperBound); // �������� �� ����������� ������� ���

    classifyCharacters(filename, lowerBound, upperBound); // ������ �������

    return 0; // ���������� ��������
}
