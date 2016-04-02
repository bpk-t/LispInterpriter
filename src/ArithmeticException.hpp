#pragma once

#include <exception>
#include <string>

//計算処理により、例外的条件が発生した場合、Throwされる例外です
class ArithmeticException
	: public virtual std::exception
{
public:
	ArithmeticException(const char *const& message)
		: std::exception(message)
	{}
public:
	~ArithmeticException(){}
};
