#pragma once

#include <boost/lexical_cast.hpp>
#include "Atom.hpp"
#include "Integer.hpp"
#include "Double.hpp"
#include "Symbol.hpp"
#include "Function.hpp"
#include "ConvertPrimitive.hpp"
#include "BuiltInFunctionBaseCalculation.hpp"

class BuiltInFunctionMul
	: virtual public BuiltInFunctionBaseCalculation
{
public:
	BuiltInFunctionMul()
		: Symbol("*")
		, Function("*")
		, BuiltInFunctionBaseCalculation()
	{}
public:
	~BuiltInFunctionMul(){}
private:
	virtual Atom* calc(Atom *result, Atom* nextValue)
	{
		if (Integer *tmp = dynamic_cast<Integer*>(result)) {
			tmp->setValue(getInt(result) * getNextValue<int>(nextValue));
		} else if (Double *tmp = dynamic_cast<Double*>(result)) {
			tmp->setValue(getDouble(result) * getNextValue<double>(nextValue));
		}
		return result;
	}
};
