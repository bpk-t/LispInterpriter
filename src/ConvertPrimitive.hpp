#pragma once

#include <exception>
#include "Atom.hpp"
#include "Integer.hpp"
#include "Double.hpp"

int getInt(Atom *a)
{
	Integer *i = dynamic_cast<Integer*>(a);

#ifdef _DEBUG
	if (i == 0) {
		throw std::exception("Integer以外の型を変換しようとしました");
	}
#endif
	return i->getValue();
}

double getDouble(Atom *a)
{
	Double *d = dynamic_cast<Double*>(a);

#ifdef _DEBUG
	if (d == 0) {
		throw std::exception("Double以外の型を変換しようとしました");
	}
#endif
	return d->getValue();
}
