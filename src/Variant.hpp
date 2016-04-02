#pragma once

#include <string>
#include <boost/format.hpp>
#include "Symbol.hpp"

class Variant
	: virtual public Symbol
{
private:
	Atom * var;
	bool constant;
public:
	Variant(const std::string & _name, Atom * _var)
		: Symbol(_name)
		, var(_var)
		, constant(false)
	{}
public:
	Atom* getPointer(){return var;}
public:
	bool isConstant(){return constant;}
	void setConstant(bool b){constant = b;}
public:
	std::string getType()
	{
		return "Variant";
	}
public:
	std::string toString()
	{
		return (boost::format("%x") % var).str();
	}
public:
	Atom* clone()
	{
		Variant *tmp = new Variant(*this);
		return tmp;
	}
};
