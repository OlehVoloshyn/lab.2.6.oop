#include "pch.h"
#include "CppUnitTest.h"
#include "../lab.2.6/AlcoholL.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			AlcoholL::Liquid t, a;
			t.setDensity(9);
			a.setDensity(9);
			Assert::AreEqual(t.getDensity(), a.getDensity());
		}
	};
}
