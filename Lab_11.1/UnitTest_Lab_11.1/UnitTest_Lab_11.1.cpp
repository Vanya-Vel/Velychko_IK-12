#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_11.1/Lab_11.1.cpp"
using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab111
{
	TEST_CLASS(UnitTestLab111)
	{
	public:
		
		TEST_METHOD(TestMethod_FindComma)
		{
            string line = { ",Hello, World, ! " };
            int position = findThirdCommaPosition(line);

            Assert::AreEqual(14, position);
            
		}

        TEST_METHOD(TestMethod_NoComma) {
            string line = "Hello World!";
            int position = findThirdCommaPosition(line);

            Assert::AreEqual(-1, position); // Очікуємо, що повернеться -1, оскільки немає трьох ком
        }

        TEST_METHOD(TestMethod_TwoCommas) {
            string line = "Hello, World!";
            int position = findThirdCommaPosition(line);

            Assert::AreEqual(-1, position); // Очікуємо -1, бо менше трьох ком
        }
	};
}
