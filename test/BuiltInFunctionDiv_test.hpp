#pragma once

#include <TestComponent/TestUnit.hpp>
#include "StringSeparator.hpp"
#include "ListGenerator.hpp"
#include "Integer.hpp"
#include "Double.hpp"
#include "BuiltInFunctionDiv.hpp"
#include "Evaluator.hpp"
#include "ArithmeticException.hpp"

class BuiltInFunctionDiv_test
	: virtual public TestUnit
{
public:
	BuiltInFunctionDiv_test()
		: TestUnit(__FUNCTION__)
	{}
protected:
	virtual void initialize()
	{
		addTestCase(&BuiltInFunctionDiv_test::Test001);
		addTestCase(&BuiltInFunctionDiv_test::Test002);
		addTestCase(&BuiltInFunctionDiv_test::Test003);
		addTestCase(&BuiltInFunctionDiv_test::Test004);
		addTestCase(&BuiltInFunctionDiv_test::Test005);
		addTestCase(&BuiltInFunctionDiv_test::Test006);
		addTestCase(&BuiltInFunctionDiv_test::Test007);
		addTestCase(&BuiltInFunctionDiv_test::Test008);
		addTestCase(&BuiltInFunctionDiv_test::Test009);
		addTestCase(&BuiltInFunctionDiv_test::Test010);
		addTestCase(&BuiltInFunctionDiv_test::Test011);
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
						StringSeparator("(/ 10 2)")
					));

		Integer *result = dynamic_cast<Integer*>(a);

		tu->assertTrue(result->getType() == "Integer", __LINE__);
		tu->assertTrue(result->getValue() == 5, __LINE__);
		return ;
	}
private:
	static void Test002(TestUnit *tu)
	{
		tu->runTestCase(__FUNCTION__);
		
		Atom *a = Evaluator::eval(
					ListGenerator::generate(
						StringSeparator("(/ 100 5 5)")
					));

		Integer *result = dynamic_cast<Integer*>(a);

		tu->assertTrue(result->getType() == "Integer", __LINE__);
		tu->assertTrue(result->getValue() == 4, __LINE__);
		return ;
	}
private:
	static void Test003(TestUnit *tu)
	{
		tu->runTestCase(__FUNCTION__);
		
		Atom *a = Evaluator::eval(
					ListGenerator::generate(
						StringSeparator("(/ 0.50 0.25)")
					));

		Double *result = dynamic_cast<Double*>(a);

		tu->assertTrue(result->getType() == "Double", __LINE__);
		tu->assertTrue(result->getValue() == 2.0, __LINE__);
		return ;
	}
private:
	static void Test004(TestUnit *tu)
	{
		tu->runTestCase(__FUNCTION__);
		
		Atom *a = Evaluator::eval(
					ListGenerator::generate(
						StringSeparator("(/ 10 2 0.5)")
					));

		Double *result = dynamic_cast<Double*>(a);

		tu->assertTrue(result->getType() == "Double", __LINE__);
		tu->assertTrue(result->getValue() == 10.0, __LINE__);
		return ;
	}
private:
	static void Test005(TestUnit *tu)
	{
		tu->runTestCase(__FUNCTION__);
		
		Atom *a = Evaluator::eval(
					ListGenerator::generate(
						StringSeparator("(/ 5 2.5 1)")
					));

		Double *result = dynamic_cast<Double*>(a);

		tu->assertTrue(result->getType() == "Double", __LINE__);
		tu->assertTrue(result->getValue() == 2.0, __LINE__);
		return ;
	}
private:
	static void Test006(TestUnit *tu)
	{
		tu->runTestCase(__FUNCTION__);
		
		Atom *a = Evaluator::eval(
					ListGenerator::generate(
						StringSeparator("(/ 10 (/ 8 4))")
					));

		Integer *result = dynamic_cast<Integer*>(a);

		tu->assertTrue(result->getType() == "Integer", __LINE__);
		tu->assertTrue(result->getValue() == 5, __LINE__);
		return ;
	}
private:
	static void Test007(TestUnit *tu)
	{
		tu->runTestCase(__FUNCTION__);
		
		Atom *a = Evaluator::eval(
					ListGenerator::generate(
						StringSeparator("(/ 40 (/ 8 (/ 4 2)))")
					));

		Integer *result = dynamic_cast<Integer*>(a);

		tu->assertTrue(result->getType() == "Integer", __LINE__);
		tu->assertTrue(result->getValue() == 10, __LINE__);
		return ;
	}
private:
	static void Test008(TestUnit *tu)
	{
		tu->runTestCase(__FUNCTION__);
		//整数値を整数値0で割ると例外を発生する
		bool flg = false;
		try {
			Atom *a = Evaluator::eval(
						ListGenerator::generate(
							StringSeparator("(/ 10 0)")
						));
		} catch (ArithmeticException ae) {
			flg = true;
		}
		tu->assertTrue(flg, __LINE__);
		return ;
	}
private:
	static void Test009(TestUnit *tu)
	{
		tu->runTestCase(__FUNCTION__);
		//整数値を実数値0.0で割っても例外は発生しない
		bool flg = true;
		try {
			Atom *a = Evaluator::eval(
						ListGenerator::generate(
							StringSeparator("(/ 10 0.0)")
						));
		} catch (ArithmeticException ae) {
			flg = false;
		}
		tu->assertTrue(flg, __LINE__);
		return ;
	}
private:
	static void Test010(TestUnit *tu)
	{
		tu->runTestCase(__FUNCTION__);
		//実数値を整数値0で割っても例外は発生しない
		bool flg = true;
		try {
			Atom *a = Evaluator::eval(
						ListGenerator::generate(
							StringSeparator("(/ 5.0 0)")
						));
		} catch (ArithmeticException ae) {
			flg = false;
		}
		tu->assertTrue(flg, __LINE__);
		return ;
	}
private:
	static void Test011(TestUnit *tu)
	{
		//TODO：仕様が固まっていない為、実装を保留
		//以下の2パターンいずれかの仕様が考えられる
		//1．整数値を整数値で割った解が実数値の場合は、解の型を実数値として返す
		//2．整数及び、実数を整数及び、実数で割った解は、全て実数型の値として返す
#if 0
		tu->runTestCase(__FUNCTION__);
		
		//整数値を整数値で割った解が実数値の場合、実数型の値を返す
		Atom *a = Evaluator::eval(
					ListGenerator::generate(
						StringSeparator("(/ 3 2)")
					));

		Double *result = dynamic_cast<Double*>(a);

		if (result) {
			tu->assertTrue(result->getType() == "Double", __LINE__);
			tu->assertTrue(result->getValue() == 1.5, __LINE__);
		} else {
			tu->assertTrue(false, __LINE__);
		}
		return ;
#endif
	}
};
