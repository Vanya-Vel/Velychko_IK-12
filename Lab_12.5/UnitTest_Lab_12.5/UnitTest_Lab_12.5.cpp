#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>
#include "../Lab_12.5/Lab_12.5.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab125
{
	TEST_CLASS(UnitTestLab125)
	{
	public:
		
        TEST_METHOD(TestInputStudentGrades)
        {
            // Мок-дані для вводу (наприклад, оцінки 5, 4, 3)
            string input = "5 4 3";
            std::istringstream inputStream(input);

            // Перенаправляємо cin на inputStream, щоб тестувати введення
            streambuf* originalCin = cin.rdbuf(inputStream.rdbuf());

            // Створюємо студент і викликаємо функцію для вводу оцінок
            Student student;
            int maxGrades = 3;  // Тестуємо для 3 оцінок

            InputStudentGrades(student, maxGrades);  // Викликаємо функцію для вводу оцінок

            // Перевірка: чи правильно заповнився масив оцінок
            Assert::AreEqual(student.grades[0], 5);
            Assert::AreEqual(student.grades[1], 4);
            Assert::AreEqual(student.grades[2], 3);

            // Відновлюємо оригінальний потік вводу
            cin.rdbuf(originalCin);
        }
	};
}
