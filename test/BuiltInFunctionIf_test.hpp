#pragma once

#include <exception>
#include <TestComponent/TestUnit.hpp>
#include "StringSeparator.hpp"
#include "ListGenerator.hpp"
#include "Integer.hpp"
#include "Nil.hpp"
#include "BuiltInFunctionIf.hpp"
#include "Evaluator.hpp"

class BuiltInFunctionIf_test
	: virtual public TestUnit
{
public:
	BuiltInFunctionIf_test()
		: TestUnit(__FUNCTION__)
	{}
protected:
	virtual void initialize()
	{
		addTestCase(&BuiltInFunctionIf_test::Test001);
		addTestCase(&BuiltInFunctionIf_test::Test002);
		addTestCase(&BuiltInFunctionIf_test::Test003);
		addTestCase(&BuiltInFunctionIf_test::Test004);
		addTestCase(&BuiltInFunctionIf_test::Test005);
		addTestCase(&BuiltInFunctionIf_test::Test006);
		addTestCase(&BuiltInFunctionIf_test::Test007);
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
						StringSeparator("(if 1 2 3)")
					));

		Integer *result = dynamic_cast<Integer*>(a);

		if (result) {
			tu->assertTrue(result->getType() == "Integer", __LINE__);
			tu->assertTrue(result->getValue() == 2, __LINE__);
		} else {
			tu->assertTrue(false, __LINE__);
		}
		return ;
	}
private:
	static void Test002(TestUnit *tu)
	{
		tu->runTestCase(__FUNCTION__);
		
		Atom *a = Evaluator::eval(
					ListGenerator::generate(
						StringSeparator("(if Nil 2 3)")
					));

		Integer *result = dynamic_cast<Integer*>(a);

		if (result) {
			tu->assertTrue(result->getType() == "Integer", __LINE__);
			tu->assertTrue(result->getValue() == 3, __LINE__);
		} else {
			tu->assertTrue(false, __LINE__);
		}
		return ;
	}
private:
	static void Test003(TestUnit *tu)
	{
		tu->runTestCase(__FUNCTION__);
		
		Atom *a = Evaluator::eval(
					ListGenerator::generate(
						StringSeparator("(if 10 1)")
					));

		Integer *result = dynamic_cast<Integer*>(a);

		if (result) {
			tu->assertTrue(result->getType() == "Integer", __LINE__);
			tu->assertTrue(result->getValue() == 1, __LINE__);
		} else {
			tu->assertTrue(false, __LINE__);
		}
		return ;
	}
private:
	static void Test004(TestUnit *tu)
	{
		tu->runTestCase(__FUNCTION__);
		
		bool flg = false;
		try {
			Atom *a = Evaluator::eval(
					ListGenerator::generate(
						StringSeparator("(if Nil 5)")
					));
		} catch (std::exception exce) {
			flg = true;
		}
		tu->assertTrue(flg, __LINE__);
		return ;
	}
private:
	static void Test005(TestUnit *tu)
	{
		tu->runTestCase(__FUNCTION__);
		
		Atom *a = Evaluator::eval(
					ListGenerator::generate(
						StringSeparator("(if (= 1 2) 1 5)")
					));

		Integer *result = dynamic_cast<Integer*>(a);

		if (result) {
			tu->assertTrue(result->getType() == "Integer", __LINE__);
			tu->assertTrue(result->getValue() == 5, __LINE__);
		} else {
			tu->assertTrue(false, __LINE__);
		}
		return ;
	}
private:
	static void Test006(TestUnit *tu)
	{
		tu->runTestCase(__FUNCTION__);
		
		Atom *a = Evaluator::eval(
					ListGenerator::generate(
						StringSeparator("(if T (+ 1 2 3) 4)")
					));

		Integer *result = dynamic_cast<Integer*>(a);

		if (result) {
			tu->assertTrue(result->getType() == "Integer", __LINE__);
			tu->assertTrue(result->getValue() == 6, __LINE__);
		} else {
			tu->assertTrue(false, __LINE__);
		}
		return ;
	}
private:
	static void Test007(TestUnit *tu)
	{
		tu->runTestCase(__FUNCTION__);
		
		Atom *a = Evaluator::eval(
					ListGenerator::generate(
						StringSeparator("(if Nil 1 (+ 2 3 4))")
					));

		Integer *result = dynamic_cast<Integer*>(a);

		if (result) {
			tu->assertTrue(result->getType() == "Integer", __LINE__);
			tu->assertTrue(result->getValue() == 9, __LINE__);
		} else {
			tu->assertTrue(false, __LINE__);
		}
		return ;
	}
};
