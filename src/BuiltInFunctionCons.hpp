#pragma once

#include "AtomCastException.hpp"
#include "Atom.hpp"
#include "List.hpp"
#include "Nil.hpp"
#include "Evaluator.hpp"

class BuiltInFunctionCons
	: virtual public Function
{
public:
	BuiltInFunctionCons()
		: Symbol("cons")
		, Function("cons")
	{}
public:
	Atom* run(Atom* a)
	{
		List *current = dynamic_cast<List*>(a);
		Atom *result = Nil;
/*
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
*/
		return result;
	}
};