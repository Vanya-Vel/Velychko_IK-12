#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_10.2 A/Lab_10.2 A.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab102A
{
	TEST_CLASS(UnitTestLab102A)
	{
	public:
		
		TEST_METHOD(Test_calculateAverage)
		{
			int count = 0;
			Student students[5] = {
			   {1, "Іваненко", 1, Speciality::COMPUTER_SCIENCE, 5, 5, 4}
			};

			int actualAverage1 = calculateAverage(students[0]);
			int expectedAverage1 = 4.7;

			Assert::AreEqual(expectedAverage1, actualAverage1);
		}
	};
}
