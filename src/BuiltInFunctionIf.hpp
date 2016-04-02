#pragma once

#include <exception>
#include "List.hpp"
#include "Atom.hpp"
#include "True.hpp"
#include "Nil.hpp"
#include "Evaluator.hpp"

class BuiltInFunctionIf
	: virtual public Function
{
public:
	BuiltInFunctionIf()
		: Symbol("if")
		, Function("if")
	{}
public:
	Atom* run(Atom* a)
	{
		List *list1 = dynamic_cast<List*>(a);
		List *list2 = dynamic_cast<List*>(list1->getCdr());

		Atom *result = Nil;
		Atom *expression = Evaluator::eval(list1->getCar());

		if (expression != Nil) {
			result = Evaluator::eval(list2->getCar());
		} else {
			List *list3 = dynamic_cast<List*>(list2->getCdr());
			if (!list3) {
				throw std::exception("評価結果がNilでNil式がありません");
			} else {
				result = Evaluator::eval(list3->getCar());
			}
		}
		return result;
	}
};