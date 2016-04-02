#pragma once

#include <TestComponent/TestUnit.hpp>
#include "ListGenerator.hpp"

class ListGenerator_test
	: virtual public TestUnit
{
public:
	ListGenerator_test()
		: TestUnit(__FUNCTION__)
	{}
protected:
	virtual void initialize()
	{
		addTestCase(&ListGenerator_test::Test001);
		addTestCase(&ListGenerator_test::Test002);
		addTestCase(&ListGenerator_test::Test003);
		addTestCase(&ListGenerator_test::Test004);
		addTestCase(&ListGenerator_test::Test005);
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
		
		StringSeparator ss("500");
		Atom *a = ListGenerator::generate(ss);

		tu->assertTrue(a->getType() == "Integer", __LINE__);

		Integer *it = dynamic_cast<Integer*>(a);
		tu->assertTrue(it->getValue() == 500, __LINE__);
		return ;
	}
private:
	static void Test002(TestUnit *tu)
	{
		tu->runTestCase(__FUNCTION__);
		
		StringSeparator ss("0.25");
		Atom *a = ListGenerator::generate(ss);

		tu->assertTrue(a->getType() == "Double", __LINE__);

		Double *it = dynamic_cast<Double*>(a);
		tu->assertTrue(it->getValue() == 0.25, __LINE__);
		return ;
	}
private:
	static void Test003(TestUnit *tu)
	{
		tu->runTestCase(__FUNCTION__);
		
		StringSeparator ss("PI");
		Atom *a = ListGenerator::generate(ss);

		tu->assertTrue(a->getType() == "Symbol", __LINE__);
		return ;
	}
private:
	static void common001(TestUnit *tu, Atom *a)
	{
		//(+ 1 2)の解析テスト
		//ネストテストでも使用できるので共通化
		tu->assertTrue(a->getType() == "List", __LINE__);
		List *tmpList = dynamic_cast<List*>(a);
		
		Symbol *elem1 = dynamic_cast<Symbol*>(tmpList->getCar());
		tu->assertTrue(elem1->getType() == "Symbol", __LINE__);
		tu->assertTrue(elem1->getName() == "+", __LINE__);

		tmpList = dynamic_cast<List*>(tmpList->getCdr());

		Integer *elem2 = dynamic_cast<Integer*>(tmpList->getCar());
		tu->assertTrue(elem2->getValue() == 1, __LINE__);

		tmpList = dynamic_cast<List*>(tmpList->getCdr());

		Integer *elem3 = dynamic_cast<Integer*>(tmpList->getCar());
		tu->assertTrue(elem3->getValue() == 2, __LINE__);

		tu->assertTrue(tmpList->getCdr()->getType() == "Nil", __LINE__);

		return ;
	}
private:
	static void Test004(TestUnit *tu)
	{
		tu->runTestCase(__FUNCTION__);
		
		StringSeparator ss("(+ 1 2)");
		common001(tu, ListGenerator::generate(ss));
		return ;
	}
private:
	static void Test005(TestUnit *tu)
	{
		tu->runTestCase(__FUNCTION__);
		
		StringSeparator ss("(+ 1 (+ 1 2))");
		List *tmpList = dynamic_cast<List*>(ListGenerator::generate(ss));

		Symbol *elem1 = dynamic_cast<Symbol*>(tmpList->getCar());
		tu->assertTrue(elem1->getName() == "+", __LINE__);

		tmpList = dynamic_cast<List*>(tmpList->getCdr());

		Integer *elem2 = dynamic_cast<Integer*>(tmpList->getCar());
		tu->assertTrue(elem2->getValue() == 1, __LINE__);

		tmpList = dynamic_cast<List*>(tmpList->getCdr());

		List *nestList = dynamic_cast<List*>(tmpList->getCar());
		common001(tu, nestList);

		tu->assertTrue(tmpList->getCdr()->getType() == "Nil", __LINE__);
		return ;
	}
};
