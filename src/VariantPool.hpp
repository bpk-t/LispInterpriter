#pragma once

#include <vector>
#include <boost/shared_ptr.hpp>
#include "Symbol.hpp"
#include "Variant.hpp"

class VariantPool
{
private:
	VariantPool(){}
	~VariantPool(){}
private:
	static VariantPool VariantPool::instance;
public:
	static VariantPool& getInstance()
	{
		return instance;
	}
public:
	typedef boost::shared_ptr<Variant> VariantPointer;
	typedef std::vector<VariantPointer> VariantList;
private:
	VariantList data;
public:
	Variant* findVariant(Symbol* s)
	{
		Variant *ret = 0;
		VariantList::iterator it = data.begin();
		while (it != data.end()) {
			if ((*(*it)).getName() == s->getName()) {
				ret = &(*(*it));
			}
			++it;
		}
		return ret;
	}
public:
	void addVariant(Variant *func)
	{
		data.push_back(VariantPointer(func));
	}
};


