#include"boss.h"
#include<iostream>
#include<string>
using namespace std;
boss::boss(int inid,string inname,int inpost)
{
	this->id = inid;
	this->name = inname;
	this->post = inpost;
}
void boss::show()
{
	cout << "职工编号：" << this->id << '\t' 
		<< "职工姓名：" << this->name << '\t' 
		<< "岗位：老板" << '\t'
		<< "岗位职责：管理公司所有事务" << endl;
}