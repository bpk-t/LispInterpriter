#pragma once

#include "Atom.hpp"
#include "List.hpp"
#include "True.hpp"
#include "Nil.hpp"

class BuiltInFunctionEqual
	: virtual public Function
{
public:
	BuiltInFunctionEqual()
		: Symbol("=")
		, Function("=")
	{}
public:
	Atom* run(Atom* a)
	{
		List *list1 = dynamic_cast<List*>(a);
		List *list2 = dynamic_cast<List*>(list1->getCdr());

		Atom *result = Nil;
		Atom *elem1 = Evaluator::eval(list1->getCar());
		Atom *elem2 = Evaluator::eval(list2->getCar());

		if (elem1 == elem2) {
			result = True;
		}
		return result;
	}
};