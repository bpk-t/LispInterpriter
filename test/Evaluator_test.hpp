#pragma once

#include <TestComponent/TestUnit.hpp>
#include "Evaluator.hpp"
#include "Integer.hpp"
#include "Symbol.hpp"
#include "Variant.hpp"
#include "VariantPool.hpp"

class Evaluator_test
	: virtual public TestUnit
{
public:
	Evaluator_test()
		: TestUnit(__FUNCTION__)
	{}
protected:
	virtual void initialize()
	{
		addTestCase(&Evaluator_test::Test001);
		addTestCase(&Evaluator_test::Test002);
		addTestCase(&Evaluator_test::Test003);
		addTestCase(&Evaluator_test::Test004);
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
		
		Integer it(10);
		Atom *a = Evaluator::eval(&it);

		tu->assertTrue(a == &it, __LINE__);
		return ;
	}
private:
	static void Test002(TestUnit *tu)
	{
		tu->runTestCase(__FUNCTION__);
		
		//Symbolが見つからない場合は0を返す
		Symbol s("XXX_YYY_ZZZ");

		Atom *a = Evaluator::eval(&s);

		tu->assertTrue(a == 0, __LINE__);
		return ;
	}
private:
	static void Test003(TestUnit *tu)
	{
		tu->runTestCase(__FUNCTION__);
		
		Symbol s("+");
		Atom *a = Evaluator::eval(&s);

		tu->assertTrue(a->getType() == "Function", __LINE__);
		return ;
	}
private:
	static void Test004(TestUnit *tu)
	{
		tu->runTestCase(__FUNCTION__);
		
		Integer i(333);

		Variant *v = new Variant("Test_Object",&i);
		VariantPool &vp = VariantPool::getInstance();
		vp.addVariant(v);

		Atom *a = Evaluator::eval(v);
		tu->assertTrue(a->getType() == "Integer", __LINE__);
		Integer *ret = dynamic_cast<Integer*>(a);
		tu->assertTrue(ret->getValue() == 333, __LINE__);
		return ;
	}
};
