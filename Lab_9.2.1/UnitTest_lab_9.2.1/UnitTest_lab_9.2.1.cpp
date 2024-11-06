#include "pch.h"
#include "CppUnitTest.h"
#include <cctype>  // ��� ������� ������������ �������

#define IS_ALPHABETIC(c) (isalpha(c))    // ������� �������
#define IS_DIGIT(c) (isdigit(c))          // ������ �������

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestlab922
{
	TEST_CLASS(UnitTestlab922)
	{
	public:
		// ���� ��� ������� IS_ALPHABETIC
		TEST_METHOD(Test_IS_ALPHABETIC)
		{
			// �������� ��� ��������� �������
			Assert::IsTrue(IS_ALPHABETIC('A')); // ��������� ������
			Assert::IsTrue(IS_ALPHABETIC('z')); // ��������� ������

			// �������� ��� ����������� �������
			Assert::IsFalse(IS_ALPHABETIC('1')); // �����
			Assert::IsFalse(IS_ALPHABETIC('$')); // ����������� ������
			Assert::IsFalse(IS_ALPHABETIC(' ')); // �����
		}

		// ���� ��� ������� IS_DIGIT
		TEST_METHOD(Test_IS_DIGIT)
		{
			// �������� ��� ����
			Assert::IsTrue(IS_DIGIT('0')); // �����
			Assert::IsTrue(IS_DIGIT('9')); // �����

			// �������� ��� ���������� �������
			Assert::IsFalse(IS_DIGIT('A')); // ��������� ������
			Assert::IsFalse(IS_DIGIT('$')); // ����������� ������
			Assert::IsFalse(IS_DIGIT(' ')); // �����
		}
	};
}
