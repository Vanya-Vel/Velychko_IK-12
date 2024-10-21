#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_7.1 it/Lab_7.1 it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab71it
{
	TEST_CLASS(UnitTestLab71it)
	{
	public:
		
        TEST_METHOD(Test_Number)
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
            array[1][1] = 15;
            array[1][2] = -3;
            array[2][0] = 4;
            array[2][1] = 6;
            array[2][2] = 5;

            int ExpectedNum = 3; // ��������� ���� ��������� ��������
            int ActualNum = 0;

            // ������ ������� ��� ���������� ���� ��������� ��������
            Number(array, rowCount, colCount, ActualNum);

            // �������� �� ���������� �������� �� ��������� ����
            Assert::AreEqual(ExpectedNum, ActualNum);

            // �������� ���'��
            for (int i = 0; i < rowCount; i++) {
                delete[] array[i];
            }
            delete[] array;
        }
	};
}
