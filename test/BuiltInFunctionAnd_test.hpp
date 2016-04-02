#pragma once

#include <TestComponent/TestUnit.hpp>
#include "StringSeparator.hpp"
#include "ListGenerator.hpp"
#include "Integer.hpp"
#include "Nil.hpp"
#include "BuiltInFunctionAnd.hpp"
#include "Evaluator.hpp"

class BuiltInFunctionAnd_test
	: virtual public TestUnit
{
public:
	BuiltInFunctionAnd_test()
		: TestUnit(__FUNCTION__)
	{}
protected:
	virtual void initialize()
	{
		addTestCase(&BuiltInFunctionAnd_test::Test001);
		addTestCase(&BuiltInFunctionAnd_test::Test002);
		addTestCase(&BuiltInFunctionAnd_test::Test003);
		addTestCase(&BuiltInFunctionAnd_test::Test004);
		addTestCase(&BuiltInFunctionAnd_test::Test005);
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
private:
	static void Test003(TestUnit *tu)
	{
		tu->runTestCase(__FUNCTION__);
		
		Atom *a = Evaluator::eval(
					ListGenerator::generate(
						StringSeparator("(and 1 2 3 4 0.5 7)")
					));

		Integer *result = dynamic_cast<Integer*>(a);

		tu->assertTrue(result->getType() == "Integer", __LINE__);
		tu->assertTrue(result->getValue() == 7, __LINE__);
		return ;
	}
private:
	static void Test004(TestUnit *tu)
	{
		tu->runTestCase(__FUNCTION__);
		
		Atom *a = Evaluator::eval(
					ListGenerator::generate(
						StringSeparator("(and 1 2 Nil 4 0.5 7)")
					));

		tu->assertTrue(a->getType() == "Nil", __LINE__);
		tu->assertTrue(a == Nil, __LINE__);
		return ;
	}
private:
	static void Test005(TestUnit *tu)
	{
		tu->runTestCase(__FUNCTION__);
		
		Atom *a = Evaluator::eval(
					ListGenerator::generate(
						StringSeparator("(and 1 2 3 Nil)")
					));

		tu->assertTrue(a->getType() == "Nil", __LINE__);
		tu->assertTrue(a == Nil, __LINE__);
		return ;
	}
};
