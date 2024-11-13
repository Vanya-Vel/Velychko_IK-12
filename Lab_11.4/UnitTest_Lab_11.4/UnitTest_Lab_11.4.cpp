#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_11.4/Lab_11.4.cpp"
using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab114
{
	TEST_CLASS(UnitTestLab114)
	{
	public:
		
		TEST_METHOD(Test_findLongestWord)
		{
			string line = { "One Two Three Five" };

			string LongestWord = findLongestWord(line);

			Assert::AreEqual("Three", LongestWord.c_str());
		}
	};
}
