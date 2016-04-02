#pragma once

#include <string>
#include <exception>
#include "Atom.hpp"
#include "Symbol.hpp"

class Function
	: virtual public Symbol
{
public:
	typedef Atom* (*RunFunction)(Atom*);
private:
	RunFunction func;
public:
	Function(const std::string &_name)
		: Symbol(_name)
		, func(0)
	{}
public:
	Function(const std::string &_name, RunFunction _func)
		: Symbol(_name)
		, func(_func)
	{}
public:
	virtual Atom* run(Atom* a)
	{
		if (func) {
			return (*func)(a);
		} else {
			throw std::exception("呼び出し関数が指定されていません");
		}
	}
public:
	//サブクラスでオーバーライドしないでください
	std::string getType()
	{
		return "Function";
	}
public:
	std::string toString()
	{
		return "Function::+";
	}
public:
	Atom* clone()
	{
		Function* tmp = new Function(*this);
		return tmp;
	}
};
