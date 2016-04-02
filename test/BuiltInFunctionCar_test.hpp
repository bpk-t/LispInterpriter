#pragma once

#include <TestComponent/TestUnit.hpp>
#include "StringSeparator.hpp"
#include "ListGenerator.hpp"
#include "Integer.hpp"
#include "Nil.hpp"
#include "BuiltInFunctionCar.hpp"
#include "Evaluator.hpp"

class BuiltInFunctionCar_test
	: virtual public TestUnit
{
public:
	BuiltInFunctionCar_test()
		: TestUnit(__FUNCTION__)
	{}
protected:
	virtual void initialize()
	{
		addTestCase(&BuiltInFunctionCar_test::Test001);
		addTestCase(&BuiltInFunctionCar_test::Test002);
		return;
	}
protected:
	//テストケースを実行する前に呼ばれる
	virtual void setUp()
	{
	}
protected:
	//テストケースを実行した後に呼ばれる
	virtual void tearDown()
	{
	}
private:
	static void Test001(TestUnit *tu)
	{
		tu->runTestCase(__FUNCTION__);
		
		Atom *a = Evaluator::eval(
					ListGenerator::generate(
						StringSeparator("(and 2)")
					));

		Integer *result = dynamic_cast<Integer*>(a);

		tu->assertTrue(result->getType() == "Integer", __LINE__);
		tu->assertTrue(result->getValue() == 2, __LINE__);
		return ;
	}
private:
	static void Test002(TestUnit *tu)
	{
		tu->runTestCase(__FUNCTION__);
		
		Atom *a = Evaluator::eval(
					ListGenerator::generate(
						StringSeparator("(and 5 2)")
					));

		Integer *result = dynamic_cast<Integer*>(a);

		tu->assertTrue(result->getType() == "Integer", __LINE__);
		tu->assertTrue(result->getValue() == 2, __LINE__);
		return ;
	}
};
