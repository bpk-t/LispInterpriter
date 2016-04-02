#pragma once

#include <exception>
#include "List.hpp"
#include "Function.hpp"
#include "Symbol.hpp"
#include "Variant.hpp"
#include "FunctionPool.hpp"
#include "SymbolDecision.hpp"

class Evaluator
{
private:
	Evaluator(){}
	~Evaluator(){}
public:
	static Atom* eval(Atom* a)
	{
		Atom *result = a;

		if (a->getType() == "List") {
			List *li = dynamic_cast<List*>(a);
			Atom *ea = eval(li->getCar());
			if (ea->getType() == "Function") {
				Function *fc = dynamic_cast<Function*>(ea);
				result = fc->run(li->getCdr());
			}
		} else if (a->getType() == "Symbol") {
			result = SymbolDecision::decision(a);
			if (result == 0) {
			} else {
				result = eval(result);
			}
		} else if (a->getType() == "Variant") {
			Variant * v = dynamic_cast<Variant*>(a);
			result = eval(v->getPointer());
		}
		return result;
	}
};
