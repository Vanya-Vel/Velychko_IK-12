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

            // ��������� ���������� ������
            int** array = new int* [rowCount];
            for (int i = 0; i < rowCount; i++) {
                array[i] = new int[colCount];
            }

            // ���������� ������
            array[0][0] = -8;
            array[0][1] = -5;
            array[0][2] = 10;
            array[1][0] = 9;
            array[1][1] = 4;
            array[1][2] = -3;
            array[2][0] = 4;
            array[2][1] = 6;
            array[2][2] = -1;

            int ExpectedSum = -8 - 3 - 1; // ��������� ���� ��������� ��������
            int ActualSum = 0;

            // ������ ������� ��� ���������� ���� ��������� ��������
            SumMinElementsInRow(array, rowCount, colCount, ActualSum);

            // �������� �� ���������� �������� �� ��������� ����
            Assert::AreEqual(ExpectedSum, ActualSum);

            // �������� ���'��
            for (int i = 0; i < rowCount; i++) {
                delete[] array[i];
            }
            delete[] array;
        }
    };
}
