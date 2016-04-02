#pragma once

#include "AtomCastException.hpp"
#include "Atom.hpp"
#include "List.hpp"
#include "Nil.hpp"
#include "Evaluator.hpp"

class BuiltInFunctionCar
	: virtual public Function
{
public:
	BuiltInFunctionCar()
		: Symbol("car")
		, Function("car")
	{}
public:
	Atom* run(Atom* a)
	{
		List *current = dynamic_cast<List*>(a);
		Atom *result = Nil;

		if (current) {
			result = current->getCar();
		} else {
			current = dynamic_cast<List*>(Evaluator::eval(a));
			if (current) {
				result = current->getCar();
			} else {
				throw AtomCastException("List型以外でcarを指定しました");
			}
		}

		return result;
	}
};