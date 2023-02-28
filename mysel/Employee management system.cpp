#include<iostream>
using namespace std;
#include"System feature classes.h"
#include"boss.h"
#include"handle.h"
#include"Ordinary employees.h"
int main()
{
	bool flag = true;
	sys_fun ceshi;
	char choose = '1';
	//boss a(1,"wang",1);
	//handle b(1, "yu", 2);
	//ord_emp c(1, "fan", 3);
	while (flag)
	{
		ceshi.System_interface();
		cout << "请输入您的选择：" << endl;
		cin >> choose;
		switch (choose)
		{
		case '1':
			ceshi.Add_emp_inf();
			//1.增加职工信息
			break;
		case '2':
			//2.显示职工信息
			//a.show();
			//b.show();
			//c.show();
			ceshi.Show_emp_inf();
			break;
		case '3':
			//3.删除离职职工
			ceshi.del_emp();
			break;
		case '4':
			ceshi.modify();
			//4.修改职工信息
			break;
		case '5':
			ceshi.findemp();
			//5.查找职工信息 
			break;
		case '6':
			ceshi.Sort_Emp();
			//6.按照编号排序
			break;
		case '7':
			//7.清空所有文档 
			ceshi.Clean_File();
			break;
		case '0':
			//0.退出管理程序
			flag = ceshi.Eixt_sym();
			break;
		default:
			cout << "请输入正确的选项" << endl;
			break;
		}
		system("pause");
		system("cls");
	}
	return 0;
}