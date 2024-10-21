#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_7.2 it/Lab_7.2 it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab72it
{
    TEST_CLASS(UnitTestLab72it)
    {
    public:

        TEST_METHOD(Test_SumMinElementsInRow)
        {
            const int rowCount = 3;
            const int colCount = 3;

            // Створення динамічного масиву
            int** array = new int* [rowCount];
            for (int i = 0; i < rowCount; i++) {
                array[i] = new int[colCount];
            }

            // Заповнення масиву
            array[0][0] = -8;
            array[0][1] = -5;
            array[0][2] = 10;
            array[1][0] = 9;
            array[1][1] = 4;
            array[1][2] = -3;
            array[2][0] = 4;
            array[2][1] = 6;
            array[2][2] = -1;

            int ExpectedSum = -8 - 3 - 1; // Очікувана сума мінімальних елементів
            int ActualSum = 0;

            // Виклик функції для обчислення суми мінімальних елементів
            SumMinElementsInRow(array, rowCount, colCount, ActualSum);

            // Перевірка на відповідність фактичної та очікуваної суми
            Assert::AreEqual(ExpectedSum, ActualSum);

            // Очищення пам'яті
            for (int i = 0; i < rowCount; i++) {
                delete[] array[i];
            }
            delete[] array;
        }
    };
}
