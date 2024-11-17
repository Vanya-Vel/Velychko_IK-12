#include "pch.h"
#include "CppUnitTest.h"
#include <fstream>
#include "../Lab_12.2 A/Lab_12.2 A.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab122A
{
	TEST_CLASS(UnitTestLab122A)
	{
	public:
		
        TEST_METHOD(Test_CountPhysicsFive)
        {
            const char* filename = "List_file.bin";

            // Створення тестового файлу
            ofstream fout(filename, ios::binary);
            Student students[5] = {
                {1, "Student1", 1, ComputerScience, 5, 4, 3},
                {2, "Student2", 2, Math, 4, 5, 5},
                {3, "Student3", 3, Physics, 5, 5, 4},
                {4, "Student4", 4, SoftwareEngineering, 3, 4, 4},
                {5, "Student5", 5, CyberSecurity, 5, 5, 5}
            };

            for (int i = 0; i < 5; i++) {
                fout.write((char*)&students[i], sizeof(students[i]));
            }
            fout.close();

            // Викликаємо функцію та перевіряємо результат
            int count = 0;
            CountPhysicsFive(filename, count);
            Assert::AreEqual(3, count);  // Очікуємо, що буде 4 студенти з оцінкою '5'
        }
	};
}
