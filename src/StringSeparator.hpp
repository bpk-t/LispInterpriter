#pragma once

#include <string>
#include <vector>

class StringSeparator
{
public:
	typedef std::vector<std::string> StrList;
private:
	StrList strList;
	bool _isList;
public:
	StringSeparator(const std::string & str)
		: _isList(false)
	{
		separate(str);
	}
private:
	enum {
		NONE,
		LIST,
		ATOM
	};
private:
	void separate(const std::string &str)
	{
		const char *p = str.c_str();
		int mode = NONE;
		std::string tmp;
		int nest = 0;

		while (*p != '\0') {
			if (mode == NONE)
			{
				if (*p == '(') {
					mode = LIST;
					this->_isList = true;
				} else if (isSeparateChar(*p)) {
				} else {
					mode = ATOM;
					tmp += *p;
				}
			} else {
				if (mode == LIST) {
					if (*p == '(') {
						nest ++;
					} else if (*p == ')') {
						nest--;
						if (nest == 0) {
							tmp += *p;
							this->strList.push_back(tmp);
							tmp.clear();
						}
					}
					if (isSeparateChar(*p) && nest <= 0) {
						if (!tmp.empty()) {
							this->strList.push_back(tmp);
							tmp.clear();
						}
					} else if (*p == ')') {
						if (nest > 0) {
							tmp += *p;
						}
					} else {
						tmp += *p;
					}
				} else if (mode == ATOM) {
					tmp += *p;
				}
			}
			p++;
		}
		if (!tmp.empty()) {
			this->strList.push_back(tmp);
		}
	}
private:
	bool isSeparateChar(char ch)
	{
		return ch == ' ' 
			|| ch == '\n'
			|| ch == '\t';
	}
public:
	void addElement(const std::string &str)
	{
		strList.push_back(str);
	}
public:
	StrList::size_type getSize()
	{
		return strList.size();
	}
public:
	std::string getElement(StrList::size_type at)
	{
		return strList[at];
	}
public:
	bool isList(){return this->_isList;}
	void setList(bool b){this->_isList = b;}
};
