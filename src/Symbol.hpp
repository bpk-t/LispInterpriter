#pragma once

#include <string>
#include <boost/format.hpp>
#include "Atom.hpp"

class Symbol
	: virtual public Atom
{
public:
	std::string name;
public:
	Symbol(const std::string & _name)
		: name(_name)
	{}
public:
	std::string getName()
	{
		return name;
	}
public:
	std::string getType()
	{
		return "Symbol";
	}
public:
	std::string toString()
	{
		return (boost::format("%s:%s") % getType() % getName()).str();
	}
public:
	Atom* clone()
	{
		Symbol* tmp = new Symbol(*this);
		return tmp;
	}
};
