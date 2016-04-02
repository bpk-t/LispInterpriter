#pragma once

#include <string>
#include "Atom.hpp"

class TrueObject
	: virtual public Atom
{
public:
	std::string getType()
	{
		return "T";
	}
public:
	std::string toString()
	{
		return "T";
	}
public:
	Atom* clone()
	{
		throw std::exception("Trueは複製禁止です");
	}
}True_t;

#define True (&True_t)

