#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_8.1 rec/Lab_8.1 rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestlab81rec
{
	TEST_CLASS(UnitTestlab81rec)
	{
	public:
		
		TEST_METHOD(Test_Count_NoCommas) 
		{
			int k = 0;
			char str[12] = { 'a', 'b', 'c', 'd', 'e', '\0' };
			Assert::AreEqual(0, Count(str, k)); // Має повертати 0
		}

		TEST_METHOD(Test_Count_EmptyString) 
		{
			int k = 0;
			char str[1] = { '\0' };
			Assert::AreEqual(0, Count(str, k)); // Має повертати 0
		}

		TEST_METHOD(Test_Count_LessThanThreeCommas) 
		{
			int k = 0;
			char str[12] = { ',', 'a', ',', 'b', '\0' };
			Assert::AreEqual(0, Count(str, k)); // Має повертати 0
		}
	};
}
