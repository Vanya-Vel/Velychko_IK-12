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
            // ��������� �������� ID
            int id = 1;

            // ϳ�������� ��������
            Student student1, student2;

            // ��������� ��� ��� ������� ��������
            istringstream mockInput1(
                "��������\n"  // surname
                "2\n"         // course
                "0\n"         // speciality (ComputerScience)
                "85\n"        // physics
                "90\n"        // math
                "95\n"        // programming
            );

            // ��������� ��� ��� ������� ��������
            istringstream mockInput2(
                "��������\n"  // surname
                "3\n"         // course
                "1\n"         // speciality (SoftwareEngineering)
                "88\n"        // physics
                "89\n"        // math
                "94\n"        // programming
            );

            // ������������ ����������� ���
            cin.rdbuf(mockInput1.rdbuf());
            InputStudent(student1, id);

            cin.rdbuf(mockInput2.rdbuf());
            InputStudent(student2, id);

            // �������� ID
            Assert::AreEqual(1, student1.id, L"ID ������� �������� �� ���� 1.");
            Assert::AreEqual(2, student2.id, L"ID ������� �������� �� ���� 2.");
        }
	};
}
