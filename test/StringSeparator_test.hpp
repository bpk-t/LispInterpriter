#pragma once

#include <TestComponent/TestUnit.hpp>
#include "StringSeparator.hpp"

class StringSeparator_test
	: virtual public TestUnit
{
public:
	StringSeparator_test()
		: TestUnit(__FUNCTION__)
	{}
protected:
	virtual void initialize()
	{
		addTestCase(&StringSeparator_test::Test001);
		addTestCase(&StringSeparator_test::Test002);
		addTestCase(&StringSeparator_test::Test003);
		addTestCase(&StringSeparator_test::Test004);
		addTestCase(&StringSeparator_test::Test005);
		addTestCase(&StringSeparator_test::Test006);
		addTestCase(&StringSeparator_test::Test007);
		addTestCase(&StringSeparator_test::Test008);
		addTestCase(&StringSeparator_test::Test009);
		addTestCase(&StringSeparator_test::Test010);
		addTestCase(&StringSeparator_test::Test011);
		addTestCase(&StringSeparator_test::Test012);
		addTestCase(&StringSeparator_test::Test013);
		addTestCase(&StringSeparator_test::Test014);
		addTestCase(&StringSeparator_test::Test015);
		addTestCase(&StringSeparator_test::Test016);
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
		
		StringSeparator ss("(+ 1 2)");

		tu->assertTrue(ss.getSize() == 3, __LINE__);
		tu->assertTrue(ss.getElement(0) == "+", __LINE__);
		tu->assertTrue(ss.getElement(1) == "1", __LINE__);
		tu->assertTrue(ss.getElement(2) == "2", __LINE__);
		return ;
	}
private:
	static void Test002(TestUnit *tu)
	{
		tu->runTestCase(__FUNCTION__);
		
		StringSeparator ss("(+ 20 30)");

		tu->assertTrue(ss.getSize() == 3, __LINE__);
		tu->assertTrue(ss.isList(), __LINE__);
		tu->assertTrue(ss.getElement(0) == "+", __LINE__);
		tu->assertTrue(ss.getElement(1) == "20", __LINE__);
		tu->assertTrue(ss.getElement(2) == "30", __LINE__);
		return ;
	}
private:
	static void Test003(TestUnit *tu)
	{
		tu->runTestCase(__FUNCTION__);
		
		StringSeparator ss("300");

		tu->assertTrue(ss.getSize() == 1, __LINE__);
		tu->assertFalse(ss.isList(), __LINE__);
		tu->assertTrue(ss.getElement(0) == "300", __LINE__);
		return ;
	}
private:
	static void Test004(TestUnit *tu)
	{
		tu->runTestCase(__FUNCTION__);
		
		StringSeparator ss("(+ 1 20 300)");

		tu->assertTrue(ss.getSize() == 4, __LINE__);
		tu->assertTrue(ss.getElement(0) == "+", __LINE__);
		tu->assertTrue(ss.getElement(1) == "1", __LINE__);
		tu->assertTrue(ss.getElement(2) == "20", __LINE__);
		tu->assertTrue(ss.getElement(3) == "300", __LINE__);
		return ;
	}
static void Test005(TestUnit *tu)
	{
		tu->runTestCase(__FUNCTION__);
		
		StringSeparator ss("C Plus Plus");

		tu->assertTrue(ss.getSize() == 1, __LINE__);
		tu->assertTrue(ss.getElement(0) == "C Plus Plus", __LINE__);
		return ;
	}
static void Test006(TestUnit *tu)
	{
		tu->runTestCase(__FUNCTION__);
		
		StringSeparator ss("(func 32 (+ 1 2))");

		tu->assertTrue(ss.getSize() == 3, __LINE__);
		tu->assertTrue(ss.getElement(0) == "func", __LINE__);
		tu->assertTrue(ss.getElement(1) == "32", __LINE__);
		tu->assertTrue(ss.getElement(2) == "(+ 1 2)", __LINE__);
		return ;
	}
static void Test007(TestUnit *tu)
	{
		tu->runTestCase(__FUNCTION__);
		
		StringSeparator ss("(func (+ 20 30) (+ 1 2))");

		tu->assertTrue(ss.getSize() == 3, __LINE__);
		tu->assertTrue(ss.getElement(0) == "func", __LINE__);
		tu->assertTrue(ss.getElement(1) == "(+ 20 30)", __LINE__);
		tu->assertTrue(ss.getElement(2) == "(+ 1 2)", __LINE__);
		return ;
	}
static void Test008(TestUnit *tu)
	{
		tu->runTestCase(__FUNCTION__);
		
		StringSeparator ss("(func (+ 20 (+ 1 2)) (+ 1 2))");

		tu->assertTrue(ss.getSize() == 3, __LINE__);
		tu->assertTrue(ss.getElement(0) == "func", __LINE__);
		tu->assertTrue(ss.getElement(1) == "(+ 20 (+ 1 2))", __LINE__);
		tu->assertTrue(ss.getElement(2) == "(+ 1 2)", __LINE__);
		return ;
	}
static void Test009(TestUnit *tu)
	{
		tu->runTestCase(__FUNCTION__);
		
		StringSeparator ss("(func (+ 20 (+ (+ 3 4) 5)) (+ 1 2))");

		tu->assertTrue(ss.getSize() == 3, __LINE__);
		tu->assertTrue(ss.getElement(0) == "func", __LINE__);
		tu->assertTrue(ss.getElement(1) == "(+ 20 (+ (+ 3 4) 5))", __LINE__);
		tu->assertTrue(ss.getElement(2) == "(+ 1 2)", __LINE__);
		return ;
	}
static void Test010(TestUnit *tu)
	{
		tu->runTestCase(__FUNCTION__);
		
		StringSeparator ss("(+ (+ 1 2) (+ 2 3) (+ 5 6))");

		tu->assertTrue(ss.getSize() == 4, __LINE__);
		tu->assertTrue(ss.getElement(0) == "+", __LINE__);
		tu->assertTrue(ss.getElement(1) == "(+ 1 2)", __LINE__);
		tu->assertTrue(ss.getElement(2) == "(+ 2 3)", __LINE__);
		tu->assertTrue(ss.getElement(3) == "(+ 5 6)", __LINE__);
		return ;
	}
static void Test011(TestUnit *tu)
	{
		tu->runTestCase(__FUNCTION__);
		
		StringSeparator ss("(+   1    2)");

		tu->assertTrue(ss.getSize() == 3, __LINE__);
		tu->assertTrue(ss.getElement(0) == "+", __LINE__);
		tu->assertTrue(ss.getElement(1) == "1", __LINE__);
		tu->assertTrue(ss.getElement(2) == "2", __LINE__);
		return ;
	}
static void Test012(TestUnit *tu)
	{
		tu->runTestCase(__FUNCTION__);
		
		StringSeparator ss("   (+ 1 2)    ");

		tu->assertTrue(ss.getSize() == 3, __LINE__);
		tu->assertTrue(ss.getElement(0) == "+", __LINE__);
		tu->assertTrue(ss.getElement(1) == "1", __LINE__);
		tu->assertTrue(ss.getElement(2) == "2", __LINE__);
		return ;
	}
static void Test013(TestUnit *tu)
	{
		tu->runTestCase(__FUNCTION__);
		
		StringSeparator ss("(+\n1\n2)");

		tu->assertTrue(ss.getSize() == 3, __LINE__);
		tu->assertTrue(ss.getElement(0) == "+", __LINE__);
		tu->assertTrue(ss.getElement(1) == "1", __LINE__);
		tu->assertTrue(ss.getElement(2) == "2", __LINE__);
		return ;
	}
static void Test014(TestUnit *tu)
	{
		tu->runTestCase(__FUNCTION__);
		
		StringSeparator ss("(+\t1\t2)");

		tu->assertTrue(ss.getSize() == 3, __LINE__);
		tu->assertTrue(ss.getElement(0) == "+", __LINE__);
		tu->assertTrue(ss.getElement(1) == "1", __LINE__);
		tu->assertTrue(ss.getElement(2) == "2", __LINE__);
		return ;
	}
static void Test015(TestUnit *tu)
	{
		tu->runTestCase(__FUNCTION__);
		
		StringSeparator ss("(string \"abs\")");

		tu->assertTrue(ss.getSize() == 2, __LINE__);
		tu->assertTrue(ss.getElement(0) == "string", __LINE__);
		tu->assertTrue(ss.getElement(1) == "\"abs\"", __LINE__);
		return ;
	}
static void Test016(TestUnit *tu)
	{
		tu->runTestCase(__FUNCTION__);
		
		StringSeparator ss("(string \"abc  def\")");

		tu->assertTrue(ss.getSize() == 2, __LINE__);
		tu->assertTrue(ss.getElement(0) == "string", __LINE__);
		tu->assertTrue(ss.getElement(1) == "\"abc  def\"", __LINE__);
		return ;
	}
};
