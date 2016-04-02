#pragma once

#include <string>
#include <exception>
#include "Atom.hpp"

class NilObject
	: virtual public Atom
{
public:
	std::string getType()
	{
		return "Nil";
	}
public:
	std::string toString()
	{
		return "Nil";
	}
public:
	Atom* clone()
	{
		throw std::exception("Nilは複製禁止です");
	}
}Nil_t;

#define Nil (&Nil_t)
