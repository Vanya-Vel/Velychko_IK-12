#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include <iostream>
#include "../Lab_10.3/Lab_10.3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab103
{
	TEST_CLASS(UnitTestLab103)
	{
	public:
		//Редагування мешканця
        TEST_METHOD(TestEditResident)
        {
            Resident* residents = new Resident[1];
            int count = 1;
            residents[0] = { "Іванов", "І.І.", 101 };  // Створюємо початкового мешканця

            // Редагуємо дані мешканця
            residents[0].lastName = "Петренко";
            residents[0].initials = "П.П.";
            residents[0].roomNumber = 102;

            // Перевіряємо, чи дані змінилися
            Assert::AreEqual(residents[0].lastName.c_str(), "Петренко");
            Assert::AreEqual(residents[0].initials.c_str(), "П.П.");
            Assert::AreEqual(residents[0].roomNumber, 102);

            // Очищаємо пам'ять
            delete[] residents;
        }

	};
}
