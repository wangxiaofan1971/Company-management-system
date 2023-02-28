#include"Ordinary employees.h"
#include<iostream>
#include<string>
using namespace std;
ord_emp::ord_emp(int inid, string inname, int inpost)
{
	this->id = inid;
	this->name = inname;
	this->post = inpost;
}
void ord_emp::show()
{
	cout << "职工编号：" << this->id << '\t'
		<< "职工姓名：" << this->name << '\t'
		<< "岗位：员工" << '\t'
		<< "岗位职责：完成经理交给的任务" << endl;
}
