#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_1.8/Bill.h"
#include "../Lab_1.8/Bill.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest18
{
	TEST_CLASS(UnitTest18)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Bill B1;
			B1.SetSurname("Osadchuk");
			string surname = "Osadchuk";
			Assert::AreEqual(surname, B1.GetSurname());
		}
	};
}
