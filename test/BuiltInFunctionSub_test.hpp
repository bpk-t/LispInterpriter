#pragma once

#include <TestComponent/TestUnit.hpp>
#include "StringSeparator.hpp"
#include "ListGenerator.hpp"
#include "Integer.hpp"
#include "BuiltInFunctionSub.hpp"
#include "Evaluator.hpp"

class BuiltInFunctionSub_test
	: virtual public TestUnit
{
public:
	BuiltInFunctionSub_test()
		: TestUnit(__FUNCTION__)
	{}
protected:
	virtual void initialize()
	{
		addTestCase(&BuiltInFunctionSub_test::Test001);
		addTestCase(&BuiltInFunctionSub_test::Test002);
		addTestCase(&BuiltInFunctionSub_test::Test003);
		addTestCase(&BuiltInFunctionSub_test::Test004);
		addTestCase(&BuiltInFunctionSub_test::Test005);
		addTestCase(&BuiltInFunctionSub_test::Test006);
		addTestCase(&BuiltInFunctionSub_test::Test007);
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
						StringSeparator("(- 5 2)")
					));

		Integer *result = dynamic_cast<Integer*>(a);

		tu->assertTrue(result->getType() == "Integer", __LINE__);
		tu->assertTrue(result->getValue() == 3, __LINE__);
		return ;
	}
private:
	static void Test002(TestUnit *tu)
	{
		tu->runTestCase(__FUNCTION__);
		
		Atom *a = Evaluator::eval(
					ListGenerator::generate(
						StringSeparator("(- 30 2 3 5)")
					));

		Integer *result = dynamic_cast<Integer*>(a);

		tu->assertTrue(result->getType() == "Integer", __LINE__);
		tu->assertTrue(result->getValue() == 20, __LINE__);
		return ;
	}
private:
	static void Test003(TestUnit *tu)
	{
		tu->runTestCase(__FUNCTION__);
		
		Atom *a = Evaluator::eval(
					ListGenerator::generate(
						StringSeparator("(- 0.50 0.25)")
					));

		Double *result = dynamic_cast<Double*>(a);

		tu->assertTrue(result->getType() == "Double", __LINE__);
		tu->assertTrue(result->getValue() == 0.25, __LINE__);
		return ;
	}
private:
	static void Test004(TestUnit *tu)
	{
		tu->runTestCase(__FUNCTION__);
		
		Atom *a = Evaluator::eval(
					ListGenerator::generate(
						StringSeparator("(- 10 3 1.5)")
					));

		Double *result = dynamic_cast<Double*>(a);

		tu->assertTrue(result->getType() == "Double", __LINE__);
		tu->assertTrue(result->getValue() == 5.5, __LINE__);
		return ;
	}
private:
	static void Test005(TestUnit *tu)
	{
		tu->runTestCase(__FUNCTION__);
		
		Atom *a = Evaluator::eval(
					ListGenerator::generate(
						StringSeparator("(- 5 2.5 1)")
					));

		Double *result = dynamic_cast<Double*>(a);

		tu->assertTrue(result->getType() == "Double", __LINE__);
		tu->assertTrue(result->getValue() == 1.5, __LINE__);
		return ;
	}
private:
	static void Test006(TestUnit *tu)
	{
		tu->runTestCase(__FUNCTION__);
		
		Atom *a = Evaluator::eval(
					ListGenerator::generate(
						StringSeparator("(- 10 (- 8 4))")
					));

		Integer *result = dynamic_cast<Integer*>(a);

		tu->assertTrue(result->getType() == "Integer", __LINE__);
		tu->assertTrue(result->getValue() == 6, __LINE__);
		return ;
	}
private:
	static void Test007(TestUnit *tu)
	{
		tu->runTestCase(__FUNCTION__);
		
		Atom *a = Evaluator::eval(
					ListGenerator::generate(
						StringSeparator("(- 10 (- 8 (- 5 3)))")
					));

		Integer *result = dynamic_cast<Integer*>(a);

		tu->assertTrue(result->getType() == "Integer", __LINE__);
		tu->assertTrue(result->getValue() == 4, __LINE__);
		return ;
	}
};
