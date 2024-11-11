#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_10.2 B/Lab_10.2 B.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab102B
{
	TEST_CLASS(UnitTestLab102B)
	{
	public:
		
        TEST_METHOD(CalculateAverage_ComputerScience)
        {
            // ��������� �������� � ��������
            Student student;
            student.speciality = COMPUTER_SCIENCE;
            student.physicsGrade = 4;
            student.mathGrade = 5;
            student.thirdGrade.programmingGrade = 5;

            // ���������� ������� ���
            calculateAverage(student);

            // �������� �� ���������� ���������
            Assert::AreEqual(4.67, student.averageGrade);
        }

        TEST_METHOD(CalculateAverage_Informatics)
        {
            // ��������� �������� � ��������
            Student student;
            student.speciality = INFORMATICS;
            student.physicsGrade = 3;
            student.mathGrade = 4;
            student.thirdGrade.numericalMethodsGrade = 5;

            // ���������� ������� ���
            calculateAverage(student);

            // �������� �� ���������� ���������
            Assert::AreEqual(4.0, student.averageGrade);
        }

        TEST_METHOD(CalculateAverage_Education)
        {
            // ��������� �������� � ��������
            Student student;
            student.speciality = EDUCATION;
            student.physicsGrade = 3;
            student.mathGrade = 4;
            student.thirdGrade.pedagogyGrade = 5;

            // ���������� ������� ���
            calculateAverage(student);

            // �������� �� ���������� ���������
            Assert::AreEqual(4.0, student.averageGrade);
        }
	};
}
