#include<iostream>
using namespace std;
#include"System feature classes.h"
#include"people.h"
#include"boss.h"
#include"handle.h"
#include"Ordinary employees.h"
#include"fstream"
sys_fun::sys_fun()
{
	this->empnum = 0;
	this->empinf = NULL;
	//this->indentfile = 0;
	//this->indentinf = 0;
	this->Imput_file();
	this->Isexist = false;
}

void sys_fun:: System_interface()
{
	cout << "********************************************" << endl <<
			"*********  欢迎使用职工管理系统！ **********" << endl <<
			"*************  0.退出管理程序  *************" << endl <<
			"*************  1.增加职工信息  *************" << endl <<
			"*************  2.显示职工信息  *************" << endl <<
			"*************  3.删除离职职工  *************" << endl <<
			"*************  4.修改职工信息  *************" << endl <<
			"*************  5.查找职工信息  *************" << endl <<
			"*************  6.按照编号排序  *************" << endl <<
			"*************  7.清空所有文档  *************" << endl <<
			"********************************************" << endl;
}

void sys_fun::Add_emp_inf()
{
	int n = 0;//添加职工数量
	int newempnum = 0;//新总员工数量
	int inid;
	string inname;
	int inpost;
	people*worker = NULL;
	cout << "请输入添加职工数量：" << endl;
	cin >> n;
	newempnum = this->empnum + n;//总员工数量

	people* *newempinf = new people*[newempnum];
	//将旧数组空间数据放到新的数组空间
	if (empinf!=NULL)
	{
		for (size_t i = 0; i < unsigned(this->empnum); i++)
			{
				newempinf[i] = this->empinf[i];
			};
	}
	
	for (size_t i = 0; i < unsigned(n); i++)
	{
		cout << "请输入第" << n << "个新职工编号：" << endl;
		cin >> inid;
		cout << "请输入第" << n << "个新职工姓名：" << endl;
		cin >> inname;
		cout << "请选择改职工岗位" << endl << "1、普通职工" << endl << "2、经理" << endl << "3、老板" << endl;
		cin >> inpost;
		switch (inpost)
		{
		case 1:
			worker = new ord_emp(inid, inname, inpost);//匿名对象放到堆区
			break;
		case 2:
			worker = new handle(inid, inname, inpost);
			break;
		case 3:
			worker = new boss(inid, inname, inpost);
			break;
		default:
			break;
		};
		newempinf[this->empnum+i] = worker;
	}
	//提示信息
	cout << "成功添加" << n << "名新职工！" << endl;
	cout << "总共员工" << newempnum << endl;
	this->empinf = newempinf;
	this->empnum = newempnum;
	
}
void sys_fun::Show_emp_inf()
{
	for (size_t i = 0; i < unsigned(this->empnum); i++)
	{
		this->empinf[i]->show();
	}
}
bool sys_fun::Eixt_sym()
{
	int choose = 0;
	cout << "您确认退出系统吗？" << endl << "1:YES" << endl << "2:NO" << endl;
	cin >> choose;
	if (choose == 1)
	{
		this->Save_file();
		return false;
	}

}

void sys_fun::Save_file()//保存文件
{
	ofstream ofs;
	ofs.open("savefile.txt", ios::out);
	for (size_t i = 0; i < unsigned(this->empnum); i++)
	{
		ofs << this->empinf[i]->id << '\t'
			<< this->empinf[i]->name << '\t'
			<< this->empinf[i]->post << '\t' << endl;
	}
	cout << "保存员工" << this->empnum << endl;
	ofs.close();
}

void sys_fun::Imput_file()//写入文件
{
	ifstream ifs;
	ifs.open("savefile.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "员工信息文件不存在";
		this->indentfile = 0;
		this->indentinf = 0;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "员工信息文件存在，内容为空" << endl;
		this->indentfile = 1;
		this->indentinf = 0;
	}
	else
	{
		cout << "员工信息文件存在，内容不为空" << endl;
		this->indentfile = 1;
		this->indentinf = 1;
		this->getnum();
		this->ini_inf();
	}
	ifs.close();
}

void sys_fun::getnum()
{
	ifstream ifs;
	ifs.open("savefile.txt", ios::in);
	if (ifs.is_open())
	{
		cout << "成功打开系统文件" << endl;
	}
	int id;
	string name;
	int post;
	while (ifs >> id&&ifs >> name&&ifs >> post)
	{
		this->empnum++;
		
	}
	cout << "存在" << this->empnum << "名员工" << endl;
	ifs.close();
}

void sys_fun::ini_inf()
{
	ifstream ifs;
	ifs.open("savefile.txt", ios::in);
	int id;
	string name;
	int post;
	int n = 0;
	this->empinf = new people*[this->empnum];
	people* worker = NULL;
	while (ifs >> id&&ifs >> name&&ifs >> post)
		{
			switch (post)
			{
			case 1:
				worker = new ord_emp(id, name, post);
				break;
			case 2:
				worker = new handle(id, name, post);
				break;
			case 3:
				worker = new boss(id, name, post);
				break;
			default:
				break;
			}
			this->empinf[n] = worker;
			n++;
		}
		
	ifs.close();
}

void sys_fun::del_emp()
{
	int id = 0;
	int choose = 0;
	int findidnum = 0;
	cout << "请输入您要删除员工的ID:" << endl;
	cin >> id;
	while (true)
	{
		this->isexist(id);
		if (this->Isexist)
		{
			for (size_t i = 0; i < this->empnum; i++)
			{
				if (this->empinf[i]->id==id)
				{
					findidnum = i;
					break;
				}
			}//找到id查询位置
			
			for (size_t j = findidnum; j < this->empnum- 1; j++)
			{
				this->empinf[j] = this->empinf[j + 1];
			}//覆盖删除信息
			people**newspace = new people*[this->empnum - 1];
			for (size_t j = 0; j < this->empnum - 1; j++)
			{
				newspace[j] = this->empinf[j];
			}//覆盖删除信息
			this->empnum--;
			delete this->empinf;
			this->empinf = newspace;
		}
		else
		{
			break;
		}
	}
}

void sys_fun::isexist(int id)
{
	for (size_t i = 0; i < this->empnum; i++)
	{
		this->Isexist = false;
		if (this->empinf[i]->id==id)
		{
			cout << "您要查找员工：" << endl;
			this->empinf[i]->show();
			this->Isexist = true;
			break;
		}
	}
}

void sys_fun::modify()
{
	int id;
	cout << "请输入您想要修改的员工的id" << endl;
	cin >> id;
	int npost;
	string nname;
	int nid;
	people* worker=nullptr;
	isexist(id);
	while (Isexist)
	{
			for (size_t i = 0; i < this->empnum; i++)
			{
				if (this->empinf[i]->id == id)
				{
					//this->empinf[i]->show();
					cout << "请输入新的员工id" << endl;
					cin >> nid;
					cout << "请输入新的员工name" << endl;
					cin >> nname;
					cout << "请输入新的员工post" << endl;
					cin >> npost;
					switch (npost)
					{
					case 1:
						worker = new ord_emp(nid, nname, npost);//匿名对象放到堆区
						break;
					case 2:
						worker = new handle(nid, nname, npost);
						break;
					case 3:
						worker = new boss(nid, nname, npost);
						break;
					default:
						break;
					}
					delete this->empinf[i];
					this->empinf[i] = worker;

				}
			}
			break;
	}
}

void sys_fun::findemp()
{
	int choose = 0;
	int id;
	string name;
	cout << "提供两种查找职工方式:" << endl <<
		"1、种按照职工编号" << endl <<
		"2、种按照职工姓名" << endl;
	cin >> choose;
	switch (choose)
	{
	case 1:
		cout << "请输入员工编号:" << endl;
		cin >> id;
		for (size_t i = 0; i < this->empnum; i++)
		{
			if (this->empinf[i]->id== id)
			{
				this->empinf[i]->show();
			}
		}
		break;
	case 2:
		cout << "请输入员工姓名"<< endl;
		cin >> name;
		for (size_t i = 0; i < this->empnum; i++)
		{
			if (this->empinf[i]->name == name)
			{
				this->empinf[i]->show();
			}
		}
		break;
	default:
		break;
	}
}

void sys_fun::Sort_Emp()
{
	int choose = 0;
	cout << "请输入排序方式" << endl;
	cout << "1、正序" << endl;
	cout << "2、反序"<< endl;
	cin >> choose;
	people* tmp;
	for (size_t i = 0; i < this->empnum-1; i++)
	{
		for (size_t j =0; j < this->empnum-1-i; j++)
		{
			if (this->empinf[j]->id>this->empinf[j+1]->id)
			{
				tmp = this->empinf[j + 1];
				this->empinf[j + 1] = this->empinf[j];
				this->empinf[j] = tmp;

			}
		}
	}
	//从小到大排序



	switch (choose)
	{
	case 1:
		for (size_t i = 0; i < this->empnum; i++)
		{
			this->empinf[i]->show();
		}
		break;
	case 2:
		for (size_t i = 0; i < this->empnum; i++)
		{
			this->empinf[this->empnum-1-i]->show();
		}
		break;
	default:
		break;
	}
}

void sys_fun::Clean_File()
{
	this->empnum = 0;
	delete []this->empinf;
	Save_file();
}

sys_fun::~sys_fun()
{
	if (this->empinf != NULL)
	{
		delete[] this->empinf;
	}
	
}