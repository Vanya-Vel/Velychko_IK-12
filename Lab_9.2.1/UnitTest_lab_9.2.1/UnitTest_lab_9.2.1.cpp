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
			// Перевірка для алфавітних символів
			Assert::IsTrue(IS_ALPHABETIC('A')); // Алфавітний символ
			Assert::IsTrue(IS_ALPHABETIC('z')); // Алфавітний символ

			// Перевірка для неалфавітних символів
			Assert::IsFalse(IS_ALPHABETIC('1')); // Цифра
			Assert::IsFalse(IS_ALPHABETIC('$')); // Спеціальний символ
			Assert::IsFalse(IS_ALPHABETIC(' ')); // Пробіл
		}

		// Тест для макросу IS_DIGIT
		TEST_METHOD(Test_IS_DIGIT)
		{
			// Перевірка для цифр
			Assert::IsTrue(IS_DIGIT('0')); // Цифра
			Assert::IsTrue(IS_DIGIT('9')); // Цифра

			// Перевірка для нецифрових символів
			Assert::IsFalse(IS_DIGIT('A')); // Алфавітний символ
			Assert::IsFalse(IS_DIGIT('$')); // Спеціальний символ
			Assert::IsFalse(IS_DIGIT(' ')); // Пробіл
		}
	};
}
