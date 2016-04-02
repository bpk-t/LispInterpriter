#pragma once

#include <boost/lexical_cast.hpp>
#include "Atom.hpp"
#include "List.hpp"
#include "Integer.hpp"
#include "Double.hpp"
#include "Nil.hpp"
#include "Function.hpp"
#include "Evaluator.hpp"
#include "AtomPool.hpp"
#include "ConvertPrimitive.hpp"

class BuiltInFunctionBaseCalculation
	: virtual public Function
{
public:
	BuiltInFunctionBaseCalculation()
		//関数のベースの為、名前はなし
		: Symbol("")
		, Function("")
	{}
public:
	~BuiltInFunctionBaseCalculation(){}
public:
	Atom* run(Atom* a)
	{
		List *current = dynamic_cast<List*>(a);
		Atom *result = 0;

		while (true) {
			Atom *elem = Evaluator::eval(current->getCar());
			if (Integer *tmp = dynamic_cast<Integer*>(elem)) {
				if (result == 0) {
					result = new Integer(tmp->getValue());
				} else {
					result = calc(result, tmp);
				}
			} else if (Double *tmp = dynamic_cast<Double*>(elem)) {
				if (result == 0) {
					result = new Double(tmp->getValue());
				} else {
					if (0 != dynamic_cast<Integer*>(result)) {
						//拡大型変換
						Double *tmp = new Double(boost::lexical_cast<double>(getInt(result)));
						delete result;
						result = dynamic_cast<Atom*>(tmp);
					}
					result = calc(result, tmp);
				}
			}

			if (current->getCdr() == Nil) {
				break;
			} else {
				current = dynamic_cast<List*>(current->getCdr());
			}
		}
		//計算途中で型が拡大することがあるので最後に登録する
		return AtomPool::construct(result);
	}
private:
	//計算部分
	//サブクラスで実装する
	virtual Atom* calc(Atom *result, Atom* nextValue) = 0;
protected:
	template<class T>
	T getNextValue(Atom *a)
	{
		if (Integer *addValue = dynamic_cast<Integer*>(a)) {
			return boost::lexical_cast<T>(addValue->getValue());
		} else if (Double *addValue = dynamic_cast<Double*>(a)) {
			return boost::lexical_cast<T>(addValue->getValue());
		}
		throw 0;
	}
};
