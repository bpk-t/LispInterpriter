#pragma once

#include <TestComponent/TestUnit.hpp>
#include "List.hpp"

class List_test
	: virtual public TestUnit
{
public:
	List_test()
		: TestUnit(__FUNCTION__)
	{}
protected:
	virtual void initialize()
	{
		addTestCase(&List_test::Test001);
		addTestCase(&List_test::Test002);
		addTestCase(&List_test::Test003);
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
		//Atom形のサブクラスであること
		List *li = new List(0, 0);
		tu->assertTrue(dynamic_cast<Atom*>(li) != 0, __LINE__);

		tu->assertTrue(li->getType() == "List", __LINE__);
		delete li;
		return ;
	}
private:
	static void Test002(TestUnit *tu)
	{
		tu->runTestCase(__FUNCTION__);

		List *li = new List(0, 0);
		tu->assertTrue(li->getCar() == 0, __LINE__);
		tu->assertTrue(li->getCdr() == 0, __LINE__);

		delete li;
		return ;
	}
private:
	static void Test003(TestUnit *tu)
	{
		tu->runTestCase(__FUNCTION__);

		List *li = new List(0, 0);

		Atom *car = new List(0,0);
		Atom *cdr = new List(0,0);

		li->setCar(car);
		li->setCdr(cdr);

		tu->assertTrue(li->getCar() == car, __LINE__);
		tu->assertTrue(li->getCdr() == cdr, __LINE__);

		delete li;
		delete car;
		delete cdr;
		return ;
	}
};
