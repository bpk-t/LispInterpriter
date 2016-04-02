#pragma once
#include <string>
#include <boost/format.hpp>
#include "Atom.hpp"

class List
	: public virtual Atom
{
private:
	Atom *car;
	Atom *cdr;
public:
	List(Atom * _car, Atom * _cdr)
		: car(_car)
		, cdr(_cdr)
	{}
public:
	Atom* getCar(){return this->car;}
	Atom* getCdr(){return this->cdr;}
	void setCar(Atom *_car){this->car = _car;}
	void setCdr(Atom *_cdr){this->cdr = _cdr;}
public:
	std::string getType()
	{
		return "List";
	}
public:
	std::string toString()
	{
		return (boost::format("[car=%x,cdr=%x]") % car % cdr).str();
	}
public:
	Atom* clone()
	{
		List* tmp = new List(*this);
		return tmp;
	}
};
