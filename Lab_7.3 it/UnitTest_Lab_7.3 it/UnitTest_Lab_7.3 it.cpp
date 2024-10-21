#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_7.3 it/Lab_7.3 it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab73it
{
    TEST_CLASS(UnitTestLab73it)
    {
    public:

        TEST_METHOD(Test_AmountColZeroElement)
        {
            const int rowCount = 3;  // Кількість рядків у масиві
            const int colCount = 3;   // Кількість стовпців у масиві

            // Створення динамічного масиву
            int** array = new int* [rowCount];
            for (int i = 0; i < rowCount; i++) {
                array[i] = new int[colCount]; // Виділення пам'яті для кожного рядка
            }

            // Заповнення масиву
            array[0][0] = -8;  // Значення в першому рядку, першому стовпці
            array[0][1] = 0;   // Значення в першому рядку, другому стовпці (нуль)
            array[0][2] = 10;  // Значення в першому рядку, третьому стовпці
            array[1][0] = 9;   // Значення в другому рядку, першому стовпці
            array[1][1] = 4;   // Значення в другому рядку, другому стовпці
            array[1][2] = -3;  // Значення в другому рядку, третьому стовпці
            array[2][0] = 4;   // Значення в третьому рядку, першому стовпці
            array[2][1] = 6;   // Значення в третьому рядку, другому стовпці
            array[2][2] = 0;   // Значення в третьому рядку, третьому стовпці (нуль)

            int count = 0; // Лічильник для нульових елементів
            int ActualNumber = NumberColZeroElement(array, rowCount, colCount, count); // Виклик функції для підрахунку
            int ExpectedNumber = 2; // Очікувана кількість стовпців з нульовими елементами

            Assert::AreEqual(ExpectedNumber, ActualNumber); // Перевірка, чи дорівнюють фактичне і очікуване значення
        }
    };
}
