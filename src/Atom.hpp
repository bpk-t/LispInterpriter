#pragma once

#include <string>

class Atom
{
public:
	virtual ~Atom(){}
public:
	virtual std::string getType() = 0;
public:
	virtual std::string toString() = 0;
public:
	//自分のインスタンスのコピーを返す
	//制約：
	//　・ヒープ領域に作成する
	//　・生存期間は無期限(破棄を外部に委譲する)
	virtual Atom* clone() = 0;
};
