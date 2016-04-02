#pragma once

#include <TestComponent/TestUnit.hpp>
#include "StringSeparator.hpp"
#include "ListGenerator.hpp"
#include "Integer.hpp"
#include "Double.hpp"
#include "BuiltInFunctionMul.hpp"
#include "Evaluator.hpp"

class BuiltInFunctionMul_test
	: virtual public TestUnit
{
public:
	BuiltInFunctionMul_test()
		: TestUnit(__FUNCTION__)
	{}
protected:
	virtual void initialize()
	{
		addTestCase(&BuiltInFunctionMul_test::Test001);
		addTestCase(&BuiltInFunctionMul_test::Test002);
		addTestCase(&BuiltInFunctionMul_test::Test003);
		addTestCase(&BuiltInFunctionMul_test::Test004);
		addTestCase(&BuiltInFunctionMul_test::Test005);
		addTestCase(&BuiltInFunctionMul_test::Test006);
		addTestCase(&BuiltInFunctionMul_test::Test007);
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
						StringSeparator("(* 5 2)")
					));

		Integer *result = dynamic_cast<Integer*>(a);

		tu->assertTrue(result->getType() == "Integer", __LINE__);
		tu->assertTrue(result->getValue() == 10, __LINE__);
		return ;
	}
private:
	static void Test002(TestUnit *tu)
	{
		tu->runTestCase(__FUNCTION__);
		
		Atom *a = Evaluator::eval(
					ListGenerator::generate(
						StringSeparator("(* 1 2 3 5)")
					));

		Integer *result = dynamic_cast<Integer*>(a);

		tu->assertTrue(result->getType() == "Integer", __LINE__);
		tu->assertTrue(result->getValue() == 30, __LINE__);
		return ;
	}
private:
	static void Test003(TestUnit *tu)
	{
		tu->runTestCase(__FUNCTION__);
		
		Atom *a = Evaluator::eval(
					ListGenerator::generate(
						StringSeparator("(* 0.50 0.50)")
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
						StringSeparator("(* 10 3 1.5)")
					));

		Double *result = dynamic_cast<Double*>(a);

		tu->assertTrue(result->getType() == "Double", __LINE__);
		tu->assertTrue(result->getValue() == 45.0, __LINE__);
		return ;
	}
private:
	static void Test005(TestUnit *tu)
	{
		tu->runTestCase(__FUNCTION__);
		
		Atom *a = Evaluator::eval(
					ListGenerator::generate(
						StringSeparator("(* 5 2.5 1)")
					));

		Double *result = dynamic_cast<Double*>(a);

		tu->assertTrue(result->getType() == "Double", __LINE__);
		tu->assertTrue(result->getValue() == 12.50, __LINE__);
		return ;
	}
private:
	static void Test006(TestUnit *tu)
	{
		tu->runTestCase(__FUNCTION__);
		
		Atom *a = Evaluator::eval(
					ListGenerator::generate(
						StringSeparator("(* 10 (* 8 4))")
					));

		Integer *result = dynamic_cast<Integer*>(a);

		tu->assertTrue(result->getType() == "Integer", __LINE__);
		tu->assertTrue(result->getValue() == 320, __LINE__);
		return ;
	}
private:
	static void Test007(TestUnit *tu)
	{
		tu->runTestCase(__FUNCTION__);
		
		Atom *a = Evaluator::eval(
					ListGenerator::generate(
						StringSeparator("(* 10 (* 8 (* 5 3)))")
					));

		Integer *result = dynamic_cast<Integer*>(a);

		tu->assertTrue(result->getType() == "Integer", __LINE__);
		tu->assertTrue(result->getValue() == 1200, __LINE__);
		return ;
	}
};
