#pragma once

#include <TestComponent/TestUnit.hpp>
#include "StringSeparator.hpp"
#include "ListGenerator.hpp"
#include "Integer.hpp"
#include "Nil.hpp"
#include "BuiltInFunctionList.hpp"
#include "Evaluator.hpp"

class BuiltInFunctionList_test
	: virtual public TestUnit
{
public:
	BuiltInFunctionList_test()
		: TestUnit(__FUNCTION__)
	{}
protected:
	virtual void initialize()
	{
		addTestCase(&BuiltInFunctionList_test::Test001);
		addTestCase(&BuiltInFunctionList_test::Test002);
		addTestCase(&BuiltInFunctionList_test::Test003);
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
						StringSeparator("(list 1)")
					));

		List *result = dynamic_cast<List*>(a);

		tu->assertTrue(result->getType() == "List", __LINE__);
		
		Integer * car = dynamic_cast<Integer*>(result->getCar());
		if (car) {
			tu->assertTrue(car->getValue() == 1, __LINE__);
		} else {
			tu->assertTrue(false, __LINE__);
		}
		
		Atom* cdr = result->getCdr();
		tu->assertTrue(cdr == Nil, __LINE__);
		
		return ;
	}
private:
	static void Test002(TestUnit *tu)
	{
		tu->runTestCase(__FUNCTION__);
		
		Atom *a = Evaluator::eval(
					ListGenerator::generate(
						StringSeparator("(list 1 2)")
					));

		List *result = dynamic_cast<List*>(a);

		tu->assertTrue(result->getType() == "List", __LINE__);
		
		Integer * car = dynamic_cast<Integer*>(result->getCar());
		if (car) {
			tu->assertTrue(car->getValue() == 1, __LINE__);
		} else {
			tu->assertTrue(false, __LINE__);
		}
		
		List* cdr = dynamic_cast<List*>(result->getCdr());
		Integer *car2 = dynamic_cast<Integer*>(cdr->getCar());
		if (car2) {
			tu->assertTrue(car2->getValue() == 2, __LINE__);
		} else {
			tu->assertTrue(false, __LINE__);
		}

		tu->assertTrue(cdr->getCdr() == Nil, __LINE__);

		return ;
	}
private:
	static void Test003(TestUnit *tu)
	{
#if 0
		tu->runTestCase(__FUNCTION__);
		
		Atom *a = Evaluator::eval(
					ListGenerator::generate(
						StringSeparator("(list (1 2))")
					));

		List *result = dynamic_cast<List*>(a);
		


		tu->assertTrue(result->getType() == "List", __LINE__);
		
		Integer * car = dynamic_cast<Integer*>(result->getCar());
		if (car) {
			tu->assertTrue(car->getValue() == 1, __LINE__);
		} else {
			tu->assertTrue(false, __LINE__);
		}
		
		List* cdr = dynamic_cast<List*>(result->getCdr());
		Integer *car2 = dynamic_cast<Integer*>(cdr->getCar());
		if (car2) {
			tu->assertTrue(car2->getValue() == 2, __LINE__);
		} else {
			tu->assertTrue(false, __LINE__);
		}

		tu->assertTrue(cdr->getCdr() == Nil, __LINE__);
#endif
		return ;
	}
};
