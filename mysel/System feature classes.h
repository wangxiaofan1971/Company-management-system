#pragma once
#include<iostream>
#include"people.h"
using namespace std;
class sys_fun//系统函数
{
public:
	sys_fun();
	void System_interface();//初始界面函数
	void Add_emp_inf();//增加职员信息
	void Show_emp_inf();//显示职员信息
	bool Eixt_sym();//退出系统
	void Save_file();//保存文件
	void Imput_file();//导入文件
	void getnum();//获取文件信息
	void ini_inf();//初始化信息系统
	void del_emp();//删除职工
	void isexist(int id);//查询是否存在
	void modify();//修改成员函数
	void findemp();//寻找成员
	void Sort_Emp();//排序职工
	void Clean_File();//清空文件
	~sys_fun();
	int empnum;//员工人数
	people ** empinf;//员工信息数组指针
	int indentfile;//储存文件辨识参数
	int indentinf;//储存文件内容辨识参数
	bool Isexist;//搜索成员是否存在
};