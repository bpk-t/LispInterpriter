#pragma once

#include <string>
#include <exception>
#include "Atom.hpp"
#include "Symbol.hpp"
#include "Function.hpp"
#include "Variant.hpp"
#include "FunctionPool.hpp"
#include "VariantPool.hpp"

class SymbolDecision
{
public:
	static Atom* decision(Atom *a)
	{
		Symbol *s = dynamic_cast<Symbol*>(a);
		Atom *ret = 0;

		if (s) {
			ret = findFunction(s);
			if (ret == 0) {
				ret = findVariant(s);
			}
		} else {
			throw std::exception("Symbol型以外のAtomを指定しました");
		}
		return ret;
	}
public:
	static Function* findFunction(Symbol* s)
	{
		FunctionPool &fp = FunctionPool::getInstance();
		return fp.findFunction(s);
	}
public:
	static Variant* findVariant(Symbol* s)
	{
		VariantPool &vp = VariantPool::getInstance();
		return vp.findVariant(s);
	}
};
