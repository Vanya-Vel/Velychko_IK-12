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
			// �������� ��� ����� ������� � ������ ������
			const struct {
				char character;
				bool expectedResult;
			} testCases[] = {
				{'A', true},  // ��������� ������
				{'z', true},  // ��������� ������
				{'1', false}, // �����, �� ������
				{'$', false}, // ����������� ������, �� ������
				{' ', false}  // �����, �� ������
			};

			// ��������� ����� �� ������ �������
			for (const auto& testCase : testCases) {
				// ����������, �� ��������� ������� �����������
				Assert::AreEqual(IS_ALPHABETIC(testCase.character), testCase.expectedResult);
			}
		}

		// ���� ��� ������� IS_DIGIT
		TEST_METHOD(Test_IS_DIGIT)
		{
			// �������� ��� ����� ������� � ������ ������
			const struct {
				char character;
				bool expectedResult;
			} testCases[] = {
				{'0', true},  // �����
				{'9', true},  // �����
				{'A', false}, // ��������� ������
				{'$', false}, // ����������� ������
				{' ', false}  // �����
			};

			// ��������� ����� �� ������ �������
			for (const auto& testCase : testCases) {
				// ����������, �� ��������� ������� �����������
				Assert::AreEqual(IS_DIGIT(testCase.character), testCase.expectedResult);
			}
		}
	};
}
