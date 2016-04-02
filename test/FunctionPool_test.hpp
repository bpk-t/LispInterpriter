#pragma once

#include <TestComponent/TestUnit.hpp>
#include "FunctionPool.hpp"

class FunctionPool_test
	: virtual public TestUnit
{
public:
	FunctionPool_test()
		: TestUnit(__FUNCTION__)
	{}
protected:
	virtual void initialize()
	{
		addTestCase(&FunctionPool_test::Test001);
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
		//FunctionPoolがメモリ開放するのでdeleteはしない
		Function *func = new Function("Test001_Func");

		FunctionPool& fp = FunctionPool::getInstance();
		fp.addFunction(func);

		Symbol s("Test001_Func");
	
		Function *ret = fp.findFunction(&s);
		tu->assertTrue(func == ret, __LINE__);

		return ;
	}
};
