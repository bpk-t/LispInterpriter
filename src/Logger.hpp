#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <boost/format.hpp>
//#include <boost/date_time/posix_time/posix_time.hpp>
#include "Writeble.hpp"

class Logger
	: virtual public Writeble
{
private:
	static Logger instance;
public:
	static Logger& getInstance()
	{
		return instance;
	}
public:
	static void logFunction(const std::string &funcName, const std::string &args)
	{
		Logger& ins = getInstance();
/*
		//時間取得
		using boost::posix_time::ptime;
		using boost::posix_time::second_clock;

		if (ins.isEnable()) {
			ptime now = second_clock::local_time();
			std::string now_as_simple = boost::posix_time::to_simple_string(now);
			ins.write((boost::format("%s\t%s\targs = %s") % now_as_simple % funcName % args).str());
		}
*/
		return ;
	}
public:
	typedef std::vector<std::string> Buffer;
private:
	//インスタンス所有者はこのクラス
	Writeble *writer;
	Buffer buf;
	//バッファに貯めるサイズ、このサイズを超えたら出力する
	unsigned int putSize;
	bool enable;
private:
	Logger()
		: writer(0)
		, putSize(30)
		, enable(true)
	{
	}
public:
	void setWriter(Writeble *_writer)
	{
		writer = _writer;
	}
public:
	void setPutSize(unsigned int value){this->putSize = value;}
	unsigned int getPutSize(){return this->putSize;}
public:
	void setEnable(bool b){this->enable = b;}
	bool isEnable(){return this->enable;}
public:
	~Logger()
	{
		if (writer) {
			delete writer;
		}
	}
public:
	virtual bool write(const std::string & data)
	{
		if (writer) {
			writer->write(data);
		} else {
			buf.push_back(data);
			if (buf.size() > putSize) {
				output();
				buf.clear();
			}
		}
		return true;
	}
private:
	void output()
	{
		Buffer::iterator it = buf.begin();
		while (it != buf.end()) {
			std::cout << *it << std::endl;
			++it;
		}
		return ;
	}
};
