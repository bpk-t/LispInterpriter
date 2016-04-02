#pragma once

#include <boost/shared_ptr.hpp>
#include <vector>
#include "Atom.hpp"

class AtomPool
{
public:
private:
	static AtomPool instance;
public:
	static AtomPool& getInstance()
	{
		return instance;
	}
public:
	template<class T>
	static T* construct(T* t)
	{
		AtomPool& ins = getInstance();
		return ins.construct_base<T>(t);
	}
public:
	typedef boost::shared_ptr<Atom> AtomPtr;
	typedef std::vector<AtomPtr> AtomPtrVector;
private:
	AtomPtrVector vect;
public:
	template<class T>
	T* construct_base(T* t)
	{
		vect.push_back(AtomPtr(t));
		return t;
	}
};

