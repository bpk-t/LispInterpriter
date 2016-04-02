#pragma once

#include <vector>
#include <boost/shared_ptr.hpp>
#include "Symbol.hpp"
#include "Function.hpp"

class FunctionPool
{
private:
	FunctionPool(){}
	~FunctionPool(){}
private:
	static FunctionPool FunctionPool::instance;
public:
	static FunctionPool& getInstance()
	{
		return instance;
	}
public:
	typedef boost::shared_ptr<Function> FunctionPointer;
	typedef std::vector<FunctionPointer> FunctionList;
private:
	FunctionList data;
public:
	Function* findFunction(Symbol* s)
	{
		Function *ret = 0;
		FunctionList::iterator it = data.begin();
		while (it != data.end()) {
			if ((*(*it)).getName() == s->getName()) {
				ret = &(*(*it));
			}
			++it;
		}
		return ret;
	}
public:
	void addFunction(Function *func)
	{
		data.push_back(FunctionPointer(func));
	}
};


