#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_8.1 string/Lab_8.1 string.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestlab81string
{
	TEST_CLASS(UnitTestlab81string)
	{
	public:
		
		TEST_METHOD(Test_Count) 
		{
			char strActual[20] = { '.', ',', 'a', ',', 'c', 'd', 'e', ',', 'j', 'o', ',', '\0' };  // Тестовий рядок
			Assert::AreEqual(4, Count(strActual));  // Перевірка, чи функція Count повертає правильну кількість ком
		}
	};
}
