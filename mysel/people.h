#pragma once
#include<string>
using namespace std;
class people
{
public:
	virtual void show() = 0;
	int id;//职工编号
	string name;//职工姓名
	int post;//部门编号
	virtual ~people();
};