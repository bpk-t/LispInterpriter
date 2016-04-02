#pragma once

#include <boost/lexical_cast.hpp>
#include "ArithmeticException.hpp"
#include "Atom.hpp"
#include "Integer.hpp"
#include "Double.hpp"
#include "Symbol.hpp"
#include "Function.hpp"
#include "ConvertPrimitive.hpp"
#include "BuiltInFunctionBaseCalculation.hpp"

class BuiltInFunctionDiv
	: virtual public BuiltInFunctionBaseCalculation
{
public:
	BuiltInFunctionDiv()
		: Symbol("/")
		, Function("/")
		, BuiltInFunctionBaseCalculation()
	{}
public:
	~BuiltInFunctionDiv(){}
private:
	virtual Atom* calc(Atom *result, Atom* nextValue)
	{
		if (Integer *tmp = dynamic_cast<Integer*>(result)) {
			int divValue = getNextValue<int>(nextValue);
			if (divValue != 0) {
				tmp->setValue(getInt(result) / divValue);
			} else {
				throw ArithmeticException("0で割りました");
			}
		} else if (Double *tmp = dynamic_cast<Double*>(result)) {
			//実数での0.0は整数の0と同等の扱いをしない
			//IEEE 754に従う
			double divValue = getNextValue<double>(nextValue);
			tmp->setValue(getDouble(result) / divValue);
		}
		return result;
	}
};
