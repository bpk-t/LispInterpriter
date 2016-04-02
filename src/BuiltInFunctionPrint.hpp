#pragma once

#include <iostream>
#include "Atom.hpp"
#include "List.hpp"
#include "Nil.hpp"
#include "True.hpp"
#include "Evaluator.hpp"

class BuiltInFunctionPrint
	: virtual public Function
{
public:
	BuiltInFunctionPrint()
		: Symbol("print")
		, Function("print")
	{}
public:
	Atom* run(Atom* a)
	{
		List *current = dynamic_cast<List*>(a);
		Atom *result = True;

		while (true) {
			Atom *elem = Evaluator::eval(current->getCar());

			std::cout << elem->toString();

			if (current->getCdr() == Nil) {
				break;
			} else {
				current = dynamic_cast<List*>(current->getCdr());
			}
		}
		return result;
	}
};