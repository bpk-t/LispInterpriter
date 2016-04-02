#pragma once

#include <string>

//書き込みインタフェース
class Writeble
{
public:
	Writeble(){}
	virtual ~Writeble(){}
public:
	virtual bool write(const std::string & data) = 0;
};
