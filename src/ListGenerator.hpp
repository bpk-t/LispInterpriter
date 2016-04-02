#pragma once

#include <string>
#include <boost/lexical_cast.hpp>
#include <exception>
#include "Atom.hpp"
#include "List.hpp"
#include "Data.hpp"
#include "Integer.hpp"
#include "Double.hpp"
#include "Symbol.hpp"
#include "Nil.hpp"
#include "StringSeparator.hpp"
#include "AtomPool.hpp"

class ListGenerator
{
private:
	ListGenerator()
	{}
	~ListGenerator()
	{}
public:
	static Atom* generate(StringSeparator& ss)
	{
		Atom * ret = 0;

		if (ss.isList()) {
			List *current = 0;
			ret = current = AtomPool::construct(new List(0,0));
			for (StringSeparator::StrList::size_type i = 0; i < ss.getSize(); ++i) {
				std::string elem = ss.getElement(i);
				if (elem[0] == '(') {
					StringSeparator tmpSs(elem);
					if(tmpSs.isList()) {
						current->setCar(
							generate(tmpSs)
						);
					} else {
						throw std::exception("非リストの先頭文字が'('になっています。");
					}
				} else {
					current->setCar(convertElement(ss.getElement(i)));
				}
				if (i < ss.getSize() - 1) {
					//次の要素がある
					List *tmp = AtomPool::construct(new List(0,0));
					current->setCdr(tmp);
					current = tmp;
				} else {
					current->setCdr(Nil);
				}
			}
		} else {
			if (ss.getSize() == 1) {
				ret = convertElement(ss.getElement(0));
			} else {
				throw std::exception("非リストで複数の要素があります");
			}
		}

		return ret;
	}
private:
	static Atom* convertElement(const std::string & elem)
	{
		Atom *ret = 0;
		if (isNumber<int>(elem)) {
			ret = AtomPool::construct(
				new Integer(boost::lexical_cast<int>(elem))
				);
		} else if (isNumber<double>(elem)) {
			ret = AtomPool::construct(
				new Double(boost::lexical_cast<double>(elem))
				);
		} else {
			//数値型以外をシンボルとして扱う
			ret = AtomPool::construct(new Symbol(elem));
		}
		return ret;
	}
private:
	template<class T>
	static bool isNumber(const std::string& str)
	{
		try {
			T t = boost::lexical_cast<T>(str);
		} catch (boost::bad_lexical_cast be) {
			return false;
		}
		return true;
	}
};