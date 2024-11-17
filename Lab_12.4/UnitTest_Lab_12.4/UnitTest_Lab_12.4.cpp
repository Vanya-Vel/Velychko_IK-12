#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_12.4/Lab_12.4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab124
{
	TEST_CLASS(UnitTestLab124)
	{
	public:
		
        TEST_METHOD(TestPrintResident)
        {
            // ��������� ��'��� Resident ��� ����������
            Resident testResident = { "������", "�.�.", 10 };

            // ������������ ���� ��������� � stringstream
            stringstream buffer;
            streambuf* original = std::cout.rdbuf();  // �������� ����������� �����
            cout.rdbuf(buffer.rdbuf());  // ��������������� cout � stringstream

            // ��������� �������, �� ���������
            PrintResident(testResident);

            // ��������� ����������� �����
            cout.rdbuf(original);

            // �������� ��������� �����
            string output = buffer.str();

            // ���������� ��������� �����
            string expected_output = "�������: ������\n�������: �.�.\n����� ������: 10\n";

            // ��������, �� �������� ��, �� ���������
            Assert::AreEqual(expected_output, output);
        }
	};
}
