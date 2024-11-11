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
		//����������� ��������
        TEST_METHOD(TestEditResident)
        {
            Resident* residents = new Resident[1];
            int count = 1;
            residents[0] = { "������", "�.�.", 101 };  // ��������� ����������� ��������

            // �������� ��� ��������
            residents[0].lastName = "��������";
            residents[0].initials = "�.�.";
            residents[0].roomNumber = 102;

            // ����������, �� ��� ��������
            Assert::AreEqual(residents[0].lastName.c_str(), "��������");
            Assert::AreEqual(residents[0].initials.c_str(), "�.�.");
            Assert::AreEqual(residents[0].roomNumber, 102);

            // ������� ���'���
            delete[] residents;
        }

	};
}
