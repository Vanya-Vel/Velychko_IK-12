#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_9.1/Lab_9.1.cpp"
#include "../Lab_9.1/dod.cpp"
#include "../Lab_9.1/var.cpp"
#include "../Lab_9.1/sum.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestlab91it
{
	TEST_CLASS(UnitTestlab91it)
	{
	public:

        TEST_METHOD(TestSumFunction)
        {
            double x = 4.0; // Приклад значення для x
            double n = 2.0; // Приклад значення для n
            double a;

            a = (x * x) / n;

            Assert::AreEqual(a, 8.0, 0.001); // Перевірка
        }
	};
}
