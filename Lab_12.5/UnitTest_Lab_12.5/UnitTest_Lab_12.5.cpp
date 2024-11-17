#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>
#include "../Lab_12.5/Lab_12.5.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab125
{
	TEST_CLASS(UnitTestLab125)
	{
	public:
		
        TEST_METHOD(TestInputStudentGrades)
        {
            // ���-��� ��� ����� (���������, ������ 5, 4, 3)
            string input = "5 4 3";
            std::istringstream inputStream(input);

            // ��������������� cin �� inputStream, ��� ��������� ��������
            streambuf* originalCin = cin.rdbuf(inputStream.rdbuf());

            // ��������� ������� � ��������� ������� ��� ����� ������
            Student student;
            int maxGrades = 3;  // ������� ��� 3 ������

            InputStudentGrades(student, maxGrades);  // ��������� ������� ��� ����� ������

            // ��������: �� ��������� ���������� ����� ������
            Assert::AreEqual(student.grades[0], 5);
            Assert::AreEqual(student.grades[1], 4);
            Assert::AreEqual(student.grades[2], 3);

            // ³��������� ����������� ���� �����
            cin.rdbuf(originalCin);
        }
	};
}
