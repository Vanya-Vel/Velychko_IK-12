
#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_8.1 char/Lab_8.1 char.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestlab81char
{
	TEST_CLASS(UnitTestlab81char)
	{
	public:
		
		TEST_METHOD(Test_Change)
		{
			char strActual[20] = { '.', ',', 'a', ',', 'c', 'd', 'e', ',', 'j', 'o', ',', '\0' };
			char strExpected[20] = ".**a**cde**jo**";

			// Використовуємо ModifyString для зміни strActual
			ModifyString(strActual);

			// Порівнюємо результат з очікуваним значенням
			Assert::IsTrue(strcmp(strExpected, strActual) == 0);
		}
	};
}
