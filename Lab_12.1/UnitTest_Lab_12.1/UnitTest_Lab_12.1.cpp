#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_12.1/Lab_12.1.cpp"
using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

// Допоміжна функція для створення тестового файлу
void CreateTestFile(const char* fname, const string& content) {
    ofstream fout(fname, ios::binary);
    fout.write(content.c_str(), content.size());
    fout.close();
}

// Допоміжна функція для зчитування вмісту файлу
string ReadFileContent(const char* fname) {
    ifstream fin(fname, ios::binary);
    string content((istreambuf_iterator<char>(fin)), istreambuf_iterator<char>());
    fin.close();
    return content;
}

namespace UnitTestLab121
{
	TEST_CLASS(UnitTestLab121)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            const char* inputFile = "test_input.bin";
            const char* outputFile = "test_output.bin";

            // Вхідні дані для тесту
            string inputContent = "Привіт геометрія! Це тест.";

            // Очікуваний результат
            string expectedOutput = "Пив ! Ц с.";

            // Створюємо тестовий вхідний файл
            CreateTestFile(inputFile, inputContent);

            // Викликаємо функцію ProcessBIN
            ProcessBIN(inputFile, outputFile);

            // Читаємо вміст вихідного файлу
            string actualOutput = ReadFileContent(outputFile);

            // Перевіряємо результат
            Assert::AreEqual(expectedOutput, actualOutput);

            // Видаляємо тестові файли (опціонально)
            remove(inputFile);
            remove(outputFile);

		}
	};
}
