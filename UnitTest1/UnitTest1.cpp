#include "pch.h"
#include "CppUnitTest.h"
#include "../PR9.3/PR9.3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Student s = { "Aaaaa","AA",4.5,5,5,5,5, };
			Student s2 = { "Bbbbb","BB",5,5,5,5,5, };
			Student S[2] = { s,s2 };
			int index = 0;
			All5(S, 2, index);
			Assert::AreEqual(index, 1);
		}
	};
}
