#pragma once

#include <string>
#include <boost/format.hpp>
#include "Data.hpp"

class Double
	: virtual public Data<double>
{
public:
	Double(double d)
		: Data(d)
	{}
public:
	std::string getType()
	{
		return "Double";
	}
public:
	std::string toString()
	{
		return (boost::format("%f") % this->getValue()).str();
	}
public:
	Atom* clone()
	{
		Double* tmp = new Double(*this);
		return tmp;
	}
};
