#include <TestComponent/TestRunner.hpp>
#include "StringSeparator_test.hpp"
#include "ListGenerator_test.hpp"
#include "List_test.hpp"
#include "FunctionPool_test.hpp"
#include "BuiltInFunctionAdd_test.hpp"
#include "Evaluator_test.hpp"
#include "BuiltInFunctionSub_test.hpp"
#include "BuiltInFunctionAnd_test.hpp"
#include "BuiltInFunctionIf_test.hpp"
#include "BuiltInFunctionMul_test.hpp"
#include "BuiltInFunctionDiv_test.hpp"
#include "BuiltInFunctionList_test.hpp"

#include "Initializer.hpp"

static StringSeparator_test stringSeparator;
static ListGenerator_test listGenerator;
static List_test list;
static FunctionPool_test functionPool;
static BuiltInFunctionAdd_test builtInFunctionAdd;
static Evaluator_test ev;
static BuiltInFunctionSub_test builtInFunctionSub;
static BuiltInFunctionAnd_test builtInFunctionAnd;
static BuiltInFunctionIf_test builtInFunctionIf;
static BuiltInFunctionMul_test builtInFunctionMul;
static BuiltInFunctionDiv_test builtInFunctionDiv;
static BuiltInFunctionList_test builtInFunctionList;

TestUnit *tuList[] = {
	&stringSeparator,
	&listGenerator,
	&list,
	&functionPool,
	&builtInFunctionAdd,
	&ev,
	&builtInFunctionSub,
	&builtInFunctionAnd,
	&builtInFunctionIf,
	&builtInFunctionMul,
	&builtInFunctionDiv,
	&builtInFunctionList,
	NULL
};

#include <iostream>
static void out(const std::string & str)
{
	std::cout << str << std::endl;
}

#include <boost/timer.hpp>
#include <sstream>
int main()
{
	Initializer init;
	init.initialize();
	TestRunner::runTest(tuList, out);
	return 0;
}
