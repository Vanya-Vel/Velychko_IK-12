#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_5.0/Lab_5.0.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab51
{
	TEST_CLASS(UnitTestLab51)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int t;
			t = sum(2, 3);
			Assert::AreEqual(t, 5);
		}
	};
}
