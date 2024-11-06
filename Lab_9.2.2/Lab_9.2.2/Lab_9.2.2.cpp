#include <stdio.h>  // Для стандартного введення/виведення
#include <fstream>  // Для роботи з файлами (std::ifstream, std::ofstream)
#include <cctype>  // Для функцій класифікації символів
#include <cassert> // Для assert

#define IS_ALPHABETIC(c) (isalpha(c))    // Алфавітні символи
#define IS_DIGIT(c) (isdigit(c))          // Цифрові символи
#define IS_CONTROL(c) (iscntrl(c))       // Керуючі символи
#define IS_PUNCTUATION(c) (ispunct(c))   // Знаки пунктуації
#define IS_OTHER(c) (!isprint(c))         // Інші символи

// Функція для класифікації символів у файлі
void classifyCharacters(const char* filename, char lowerBound, char upperBound) {
    std::ifstream file(filename); // Відкриваємо файл
    if (!file.is_open()) { // Перевірка на успішне відкриття файлу
        printf("Failed to open the file!\n"); // Вивід повідомлення про помилку
        return; // Завершення функції
    }

    int alphabeticCount = 0; // Кількість алфавітних символів
    int digitCount = 0;      // Кількість цифрових символів
    int controlCount = 0;    // Кількість керуючих символів
    int punctuationCount = 0; // Кількість знаків пунктуації
    int otherCount = 0;      // Кількість інших символів

    char ch; // Змінна для зчитування символів
    while (file.get(ch)) { // Читаємо файл символ за символом
        if (IS_ALPHABETIC(ch)) {
            alphabeticCount++; // Збільшуємо лічильник алфавітних символів
        }
        else if (IS_DIGIT(ch)) {
            digitCount++; // Збільшуємо лічильник цифрових символів
            if (ch >= lowerBound && ch <= upperBound) { // Перевірка на межі
                printf("Digit character in range: %c\n", ch); // Вивід цифрового символу в межах
            }
        }
        else if (IS_CONTROL(ch)) {
            controlCount++; // Збільшуємо лічильник керуючих символів
        }
        else if (IS_PUNCTUATION(ch)) {
            punctuationCount++; // Збільшуємо лічильник знаків пунктуації
        }
        else if (IS_OTHER(ch)) {
            otherCount++; // Збільшуємо лічильник інших символів
        }
    }

    // Виведення результатів
    printf("Number of alphabetic characters: %d\n", alphabeticCount); // Вивід кількості алфавітних символів
    printf("Number of digit characters: %d\n", digitCount); // Вивід кількості цифрових символів
    printf("Number of control characters: %d\n", controlCount); // Вивід кількості керуючих символів
    printf("Number of punctuation characters: %d\n", punctuationCount); // Вивід кількості знаків пунктуації
    printf("Number of other characters: %d\n", otherCount); // Вивід кількості інших символів

    file.close(); // Закриваємо файл
}

int main() {
    char filename[256]; // Змінна для зберігання імені файлу
    char lowerBound, upperBound; // Межі для цифрових символів

    printf("Enter the filename: "); // Запит імені файлу
    if (scanf("%s", filename) != 1) { // Перевірка поверненого значення
        printf("Error reading filename!\n");
        return 1; // Завершення програми з помилкою
    }

    printf("Enter the lower bound for digit characters: "); // Запит нижньої межі
    if (scanf(" %c", &lowerBound) != 1) { // Перевірка поверненого значення
        printf("Error reading lower bound!\n");
        return 1; // Завершення програми з помилкою
    }

    printf("Enter the upper bound for digit characters: "); // Запит верхньої межі
    if (scanf(" %c", &upperBound) != 1) { // Перевірка поверненого значення
        printf("Error reading upper bound!\n");
        return 1; // Завершення програми з помилкою
    }

    // Перевірка правильності меж
    assert(lowerBound >= '0' && lowerBound <= '9'); // Перевірка нижньої межі
    assert(upperBound >= '0' && upperBound <= '9'); // Перевірка верхньої межі
    assert(lowerBound <= upperBound); // Перевірка на правильність порядку меж

    classifyCharacters(filename, lowerBound, upperBound); // Виклик функції

    return 0; // Завершення програми
}
