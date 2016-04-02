#pragma once

#include <exception>
#include <string>

//Atom型として渡された値を無効な型に変換した場合にThrowする
class AtomCastException
	: public virtual std::exception
{
public:
	AtomCastException(const char *const& message)
		: std::exception(message)
	{}
public:
	~AtomCastException(){}
};