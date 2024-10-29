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
            // Тест на видалення тексту всередині дужок
            Assert::AreEqual(string("Hello world!"), removeParenthesesContent("Hello (test)world!"));
        }

        TEST_METHOD(MultipleParenthesesGroups) 
        {
            // Тест на обробку кількох груп дужок
            Assert::AreEqual(string("Hello world!"), removeParenthesesContent("Hello(first) world(second)!"));
        }

        TEST_METHOD(NoParentheses) 
        {
            // Тест на рядок без дужок
            Assert::AreEqual(string("Hello world!"), removeParenthesesContent("Hello world!"));
        }

	};
}
