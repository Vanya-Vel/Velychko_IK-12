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
            const int rowCount = 3;  // ʳ������ ����� � �����
            const int colCount = 3;   // ʳ������ �������� � �����

            // ��������� ���������� ������
            int** array = new int* [rowCount];
            for (int i = 0; i < rowCount; i++) {
                array[i] = new int[colCount]; // �������� ���'�� ��� ������� �����
            }

            // ���������� ������
            array[0][0] = -8;  // �������� � ������� �����, ������� �������
            array[0][1] = 0;   // �������� � ������� �����, ������� ������� (����)
            array[0][2] = 10;  // �������� � ������� �����, �������� �������
            array[1][0] = 9;   // �������� � ������� �����, ������� �������
            array[1][1] = 4;   // �������� � ������� �����, ������� �������
            array[1][2] = -3;  // �������� � ������� �����, �������� �������
            array[2][0] = 4;   // �������� � �������� �����, ������� �������
            array[2][1] = 6;   // �������� � �������� �����, ������� �������
            array[2][2] = 0;   // �������� � �������� �����, �������� ������� (����)

            int count = 0; // ˳������� ��� �������� ��������
            int ActualNumber = NumberColZeroElement(array, rowCount, colCount, count); // ������ ������� ��� ���������
            int ExpectedNumber = 2; // ��������� ������� �������� � ��������� ����������

            Assert::AreEqual(ExpectedNumber, ActualNumber); // ��������, �� ��������� �������� � ��������� ��������
        }
    };
}
