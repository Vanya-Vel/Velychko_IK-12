#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_11.2/Lab_11.2.cpp"
using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab111
{
	TEST_CLASS(UnitTestLab111)
	{
	public:
		
		TEST_METHOD(Test_Nested_Brackets)
		{
            string line = { "Lor(em imp(sum)" };

            bool brackets = hasNestedBrackets(line);
            
            Assert::AreEqual(true, brackets);
            
		}

		TEST_METHOD(Test_Not_Nested_Brackets)
		{
			string line = { "L(orem )imp(sum)" };

			bool brackets = hasNestedBrackets(line);

			Assert::AreEqual(false, brackets);

		}
	};
}
