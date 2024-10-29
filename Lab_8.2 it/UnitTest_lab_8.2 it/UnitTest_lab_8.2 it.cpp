#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_8.2 it/Lab_8.2 it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestlab82it
{
	TEST_CLASS(UnitTestlab82it)
	{
	public:

        TEST_METHOD(RemoveTextInsideParentheses) 
        {
            // ���� �� ��������� ������ �������� �����
            Assert::AreEqual(string("Hello world!"), removeParenthesesContent("Hello (test)world!"));
        }

        TEST_METHOD(MultipleParenthesesGroups) 
        {
            // ���� �� ������� ������ ���� �����
            Assert::AreEqual(string("Hello world!"), removeParenthesesContent("Hello(first) world(second)!"));
        }

        TEST_METHOD(NoParentheses) 
        {
            // ���� �� ����� ��� �����
            Assert::AreEqual(string("Hello world!"), removeParenthesesContent("Hello world!"));
        }

	};
}
