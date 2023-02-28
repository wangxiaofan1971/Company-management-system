#include"handle.h"
#include<iostream>
#include<string>
using namespace std;
handle::handle(int inid, string inname, int inpost)
{
	this->id = inid;
	this->name = inname;
	this->post = inpost;
}
void handle::show()
{
	cout << "职工编号：" << this->id << '\t'
		<< "职工姓名：" << this->name << '\t'
		<< "岗位：经理" << '\t'
		<< "岗位职责：完成老板交给的任务，并下发任务给员工" << endl;
}
