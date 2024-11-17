#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_12.4/Lab_12.4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab124
{
	TEST_CLASS(UnitTestLab124)
	{
	public:
		
        TEST_METHOD(TestPrintResident)
        {
            // Створюємо об'єкт Resident для тестування
            Resident testResident = { "Іванов", "І.І.", 10 };

            // Перехоплюємо потік виведення в stringstream
            stringstream buffer;
            streambuf* original = std::cout.rdbuf();  // Зберігаємо оригінальний буфер
            cout.rdbuf(buffer.rdbuf());  // Перенаправляємо cout в stringstream

            // Викликаємо функцію, що тестується
            PrintResident(testResident);

            // Повертаємо стандартний буфер
            cout.rdbuf(original);

            // Отримаємо виведений текст
            string output = buffer.str();

            // Очікуваний виведений текст
            string expected_output = "Прізвище: Іванов\nІніціали: І.І.\nНомер кімнати: 10\n";

            // Перевірка, чи виведено те, що очікується
            Assert::AreEqual(expected_output, output);
        }
	};
}
