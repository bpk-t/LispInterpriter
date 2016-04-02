#pragma once

#include <TestComponent/TestUnit.hpp>
#include "StringSeparator.hpp"
#include "ListGenerator.hpp"
#include "Integer.hpp"
#include "BuiltInFunctionAdd.hpp"

class BuiltInFunctionAdd_test
	: virtual public TestUnit
{
public:
	BuiltInFunctionAdd_test()
		: TestUnit(__FUNCTION__)
	{}
protected:
	virtual void initialize()
	{
		addTestCase(&BuiltInFunctionAdd_test::Test001);
		addTestCase(&BuiltInFunctionAdd_test::Test002);
		addTestCase(&BuiltInFunctionAdd_test::Test003);
		addTestCase(&BuiltInFunctionAdd_test::Test004);
		addTestCase(&BuiltInFunctionAdd_test::Test005);
		addTestCase(&BuiltInFunctionAdd_test::Test006);
		addTestCase(&BuiltInFunctionAdd_test::Test007);
		addTestCase(&BuiltInFunctionAdd_test::Test008);
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
		
		StringSeparator ss("(1 2)");
		Atom *p = ListGenerator::generate(ss);

		BuiltInFunctionAdd func;

		Integer *result = dynamic_cast<Integer*>(func.run(p));

		tu->assertTrue(result->getType() == "Integer", __LINE__);
		tu->assertTrue(result->getValue() == 3, __LINE__);
		return ;
	}
private:
	static void Test002(TestUnit *tu)
	{
		tu->runTestCase(__FUNCTION__);
		
		StringSeparator ss("(1 2 3 4)");
		Atom *p = ListGenerator::generate(ss);

		BuiltInFunctionAdd func;

		Integer *result = dynamic_cast<Integer*>(func.run(p));

		tu->assertTrue(result->getType() == "Integer", __LINE__);
		tu->assertTrue(result->getValue() == 10, __LINE__);
		return ;
	}
private:
	static void Test003(TestUnit *tu)
	{
		tu->runTestCase(__FUNCTION__);
		
		StringSeparator ss("(0.5 0.5)");
		Atom *p = ListGenerator::generate(ss);

		BuiltInFunctionAdd func;

		Double *result = dynamic_cast<Double*>(func.run(p));

		tu->assertTrue(result->getType() == "Double", __LINE__);
		tu->assertTrue(result->getValue() == 1.0, __LINE__);
		return ;
	}
private:
	static void Test004(TestUnit *tu)
	{
		tu->runTestCase(__FUNCTION__);
		
		StringSeparator ss("(1 2 3.5)");
		Atom *p = ListGenerator::generate(ss);

		BuiltInFunctionAdd func;

		Double *result = dynamic_cast<Double*>(func.run(p));

		tu->assertTrue(result->getType() == "Double", __LINE__);
		tu->assertTrue(result->getValue() == 6.5, __LINE__);
		return ;
	}
private:
	static void Test005(TestUnit *tu)
	{
		tu->runTestCase(__FUNCTION__);
		
		StringSeparator ss("(2 0.5 4)");
		Atom *p = ListGenerator::generate(ss);

		BuiltInFunctionAdd func;

		Double *result = dynamic_cast<Double*>(func.run(p));

		tu->assertTrue(result->getType() == "Double", __LINE__);
		tu->assertTrue(result->getValue() == 6.5, __LINE__);
		return ;
	}
private:
	static void Test006(TestUnit *tu)
	{
		tu->runTestCase(__FUNCTION__);
		
		StringSeparator ss("(2 (+ 1 2))");
		Atom *p = ListGenerator::generate(ss);

		BuiltInFunctionAdd func;

		Integer *result = dynamic_cast<Integer*>(func.run(p));

		tu->assertTrue(result->getType() == "Integer", __LINE__);
		tu->assertTrue(result->getValue() == 5, __LINE__);
		return ;
	}
private:
	static void Test007(TestUnit *tu)
	{
		tu->runTestCase(__FUNCTION__);
		
		StringSeparator ss("(1 (+ 1 (+ 3 4)))");
		Atom *p = ListGenerator::generate(ss);

		BuiltInFunctionAdd func;

		Integer *result = dynamic_cast<Integer*>(func.run(p));

		tu->assertTrue(result->getType() == "Integer", __LINE__);
		tu->assertTrue(result->getValue() == 9, __LINE__);
		return ;
	}
private:
	static void Test008(TestUnit *tu)
	{
		tu->runTestCase(__FUNCTION__);
		
		StringSeparator ss("(10 -5)");
		Atom *p = ListGenerator::generate(ss);

		BuiltInFunctionAdd func;

		Integer *result = dynamic_cast<Integer*>(func.run(p));

		tu->assertTrue(result->getType() == "Integer", __LINE__);
		tu->assertTrue(result->getValue() == 5, __LINE__);
		return ;
	}
};
