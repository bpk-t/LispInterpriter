#pragma once

#include "FunctionPool.hpp"
#include "VariantPool.hpp"
#include "BuiltInFunctionAdd.hpp"
#include "BuiltInFunctionSub.hpp"
#include "BuiltInFunctionAnd.hpp"
#include "BuiltInFunctionPrint.hpp"
#include "BuiltInFunctionEqual.hpp"
#include "BuiltInFunctionDiv.hpp"
#include "BuiltInFunctionMul.hpp"
#include "BuiltInFunctionIf.hpp"
#include "BuiltInFunctionCar.hpp"
#include "BuiltInFunctionList.hpp"
#include "BuiltInFunctionCons.hpp"

#include "Nil.hpp"
#include "True.hpp"

class Initializer
{
public:
	void initialize()
	{
		setBuiltInVariant();
		setBuiltInFunction();
	}
private:
	void setBuiltInFunction()
	{
		FunctionPool &fp = FunctionPool::getInstance();

		fp.addFunction(new BuiltInFunctionAdd());
		fp.addFunction(new BuiltInFunctionSub());
		fp.addFunction(new BuiltInFunctionAnd());
		fp.addFunction(new BuiltInFunctionPrint());
		fp.addFunction(new BuiltInFunctionEqual());
		fp.addFunction(new BuiltInFunctionDiv());
		fp.addFunction(new BuiltInFunctionMul());
		fp.addFunction(new BuiltInFunctionIf());
		fp.addFunction(new BuiltInFunctionCar());
		fp.addFunction(new BuiltInFunctionList());
		fp.addFunction(new BuiltInFunctionCons());
	}
private:
	void setBuiltInVariant()
	{
		VariantPool &vp = VariantPool::getInstance();

		vp.addVariant(new Variant("Nil", Nil));
		vp.addVariant(new Variant("T", True));
	}
};
