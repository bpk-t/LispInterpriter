#pragma once

#include "Atom.hpp"
#include "List.hpp"
#include "Nil.hpp"
#include "Evaluator.hpp"

class BuiltInFunctionAnd
	: virtual public Function
{
public:
	BuiltInFunctionAnd()
		: Symbol("and")
		, Function("and")
	{}
public:
	Atom* run(Atom* a)
	{
		List *current = dynamic_cast<List*>(a);
		Atom *result = 0;

		while (true) {
			Atom *elem = Evaluator::eval(current->getCar());

			if (elem == Nil) {
				result = elem;
				break;
			}
			if (current->getCdr() == Nil) {
				result = elem;
				break;
			} else {
				current = dynamic_cast<List*>(current->getCdr());
			}
		}
		return result;
	}
};
