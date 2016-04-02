#pragma once

#include "Atom.hpp"
#include "List.hpp"
#include "Nil.hpp"
#include "AtomPool.hpp"

class BuiltInFunctionList
	: virtual public Function
{
public:
	BuiltInFunctionList()
		: Symbol("list")
		, Function("list")
	{}
public:
	//新しいインスタンスを作成して返す
	Atom* run(Atom* a)
	{
		List* result = new List(0,0);
		AtomPool::construct(result);
		List* current = result;

		List* param = dynamic_cast<List*>(a);

		while (true) {
			
			current->setCar(
				AtomPool::construct(
					param->getCar()->clone()));

			if (param->getCdr() == Nil) {
				current->setCdr(Nil);
				break;
			} else {
				
				param = dynamic_cast<List*>(param->getCdr());
				List *tmp = new List(0,0);
				current->setCdr(AtomPool::construct(tmp));
				current = tmp;
			}
		} 
		return result;
	}
};
