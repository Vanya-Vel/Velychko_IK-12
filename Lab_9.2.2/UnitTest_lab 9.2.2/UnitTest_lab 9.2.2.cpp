#include "pch.h"
#include "CppUnitTest.h"
#include <cctype>  // Для функцій класифікації символів

#define IS_ALPHABETIC(c) (isalpha(c))    // Алфавітні символи
#define IS_DIGIT(c) (isdigit(c))          // Цифрові символи

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestlab922
{
	TEST_CLASS(UnitTestlab922)
	{
	public:
		// Тест для макросу IS_ALPHABETIC
		TEST_METHOD(Test_IS_ALPHABETIC)
		{
			// Перевірка для різних символів у вигляді масиву
			const struct {
				char character;
				bool expectedResult;
			} testCases[] = {
				{'A', true},  // Алфавітний символ
				{'z', true},  // Алфавітний символ
				{'1', false}, // Цифра, не алфавіт
				{'$', false}, // Спеціальний символ, не алфавіт
				{' ', false}  // Пробіл, не алфавіт
			};

			// Проходимо через всі тестові випадки
			for (const auto& testCase : testCases) {
				// Перевіряємо, чи результат відповідає очікуваному
				Assert::AreEqual(IS_ALPHABETIC(testCase.character), testCase.expectedResult);
			}
		}

		// Тест для макросу IS_DIGIT
		TEST_METHOD(Test_IS_DIGIT)
		{
			// Перевірка для різних символів у вигляді масиву
			const struct {
				char character;
				bool expectedResult;
			} testCases[] = {
				{'0', true},  // Цифра
				{'9', true},  // Цифра
				{'A', false}, // Алфавітний символ
				{'$', false}, // Спеціальний символ
				{' ', false}  // Пробіл
			};

			// Проходимо через всі тестові випадки
			for (const auto& testCase : testCases) {
				// Перевіряємо, чи результат відповідає очікуваному
				Assert::AreEqual(IS_DIGIT(testCase.character), testCase.expectedResult);
			}
		}
	};
}
