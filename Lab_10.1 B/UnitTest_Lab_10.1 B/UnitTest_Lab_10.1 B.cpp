#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_10.1 B/Lab_10.1 B.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab101B
{
	TEST_CLASS(UnitTestLab101B)
	{
	public:
		
		TEST_METHOD(Test_countStudentsWithFiveInPhysics)
		{
			int count = 0;
			Student students[5] = {
		       {1, "Іваненко", 1, Speciality::COMPUTER_SCIENCE, 5, 4},
		       {2, "Петренко", 2, Speciality::INFORMATICS, 4, 4},
		       {3, "Сидоренко", 1, Speciality::MATH_ECONOMICS, 3, 5},
		       {4, "Коваленко", 3, Speciality::PHYSICS_INFORMATICS, 5, 5},
		       {5, "Гриценко", 2, Speciality::LABOR_TRAINING, 4, 3}
			};

			countStudentsWithFiveInPhysics(students, 5, count);
			int expectedCount = 2;

			Assert::AreEqual(expectedCount, count);
		}
	};
}
