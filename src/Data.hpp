#pragma once

#include <string>
#include <exception>
#include "Atom.hpp"

template<class T>
class Data
	: virtual public Atom
{
public:
	typedef T Type;
private:
	Type value;
public:
	Data(const Type& _value)
		: value(_value)
	{}
public:
	Type getValue(){return value;}
	void setValue(const Type & _value){this->value = _value;}
public:
	Atom* clone()
	{
		throw std::exception("抽象クラスのインスタンス複製はできません。");
	}
};
