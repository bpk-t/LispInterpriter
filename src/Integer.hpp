#pragma once 

#include <string>
#include <boost/format.hpp>
#include "Data.hpp"

class Integer
	: virtual public Data<int>
{
public:
	Integer(int _value)
		: Data(_value)
	{}
public:
	std::string getType()
	{
		return "Integer";
	}
public:
	std::string toString()
	{
		return (boost::format("%d") % this->getValue()).str();
	}
public:
	Atom* clone()
	{
		Integer *tmp = new Integer(*this);
		return tmp;
	}
};
