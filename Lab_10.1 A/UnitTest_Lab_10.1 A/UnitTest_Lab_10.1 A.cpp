#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_10.1 A/Lab_10.1 A.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab101A
{
	TEST_CLASS(UnitTestLab101A)
	{
	public:
		
		TEST_METHOD(Test_countStudentsWithFiveInPhysics)
		{
			int count = 0;
			Student students[5] = 
			{
		      {1, "Іваненко", 1, Speciality::COMPUTER_SCIENCE, 5, 4, 5},
		      {2, "Петренко", 2, Speciality::MATHEMATICS, 5, 4, 4},
		      {3, "Сидоренко", 1, Speciality::PHYSICS, 3, 5, 4},
		      {4, "Коваленко", 3, Speciality::ENGINEERING, 5, 5, 5},
		      {5, "Гриценко", 2, Speciality::COMPUTER_SCIENCE, 4, 5, 4}
			};

			countStudentsWithFiveInPhysics(students, 5, count);
			int expectedCount = 3;

			Assert::AreEqual(expectedCount, count);
		}
	};
}
