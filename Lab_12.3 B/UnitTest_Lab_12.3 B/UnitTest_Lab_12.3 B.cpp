#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_12.3 B/Lab_12.3 B.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab123B
{
	TEST_CLASS(UnitTestLab123B)
	{
	public:
		
        TEST_METHOD(TestInputStudentID)
        {
            // Початкове значення ID
            int id = 1;

            // Підготовка студентів
            Student student1, student2;

            // Симулюємо дані для першого студента
            istringstream mockInput1(
                "Петренко\n"  // surname
                "2\n"         // course
                "0\n"         // speciality (ComputerScience)
                "85\n"        // physics
                "90\n"        // math
                "95\n"        // programming
            );

            // Симулюємо дані для другого студента
            istringstream mockInput2(
                "Іваненко\n"  // surname
                "3\n"         // course
                "1\n"         // speciality (SoftwareEngineering)
                "88\n"        // physics
                "89\n"        // math
                "94\n"        // programming
            );

            // Перехоплюємо стандартний ввід
            cin.rdbuf(mockInput1.rdbuf());
            InputStudent(student1, id);

            cin.rdbuf(mockInput2.rdbuf());
            InputStudent(student2, id);

            // Перевірка ID
            Assert::AreEqual(1, student1.id, L"ID першого студента має бути 1.");
            Assert::AreEqual(2, student2.id, L"ID другого студента має бути 2.");
        }
	};
}
