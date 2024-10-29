#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_8.1 it/Lab_8.1 it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestlab81it
{
	TEST_CLASS(UnitTestlab81it)
	{
	public:
		
		TEST_METHOD(Test_Count_NoCommas) {
			char str[12] = { 'a', 'b', 'c', 'd', 'e', '\0' };
			Assert::AreEqual(0, Count(str)); // Має повертати 0
		}

		TEST_METHOD(Test_Count_EmptyString) {
			char str[1] = { '\0' };
			Assert::AreEqual(0, Count(str)); // Має повертати 0
		}

		TEST_METHOD(Test_Count_LessThanThreeCommas) {
			char str[12] = { ',', 'f', ',', ',', 'a', ',', 'b', '\0' };
			Assert::AreEqual(4, Count(str)); // Має повертати 0
		}

	};
}
