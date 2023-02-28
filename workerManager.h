#pragma once//是一个比较常用的C/C++预处理指令，只要在头文件的最开始加入这条预处理指令，就能够保证头文件只被编译一次，防止头文件被重复引用。
#include<iostream>
using namespace std;
#include"worker.h"
#include"employee.h"
#include <fstream>
#define  FILENAME "empFile.txt"

//设计管理类 
//与用户的沟通菜单界面
//对职工增删改查的操作
//与文件的读写交互



class WorkerManager
{
public:

	//构造函数
	WorkerManager();
	//与用户的沟通菜单界面
	void Show_Menu();
	//退出管理程序
	void exitSystem();
	//增加职工
	void Add_Emp();
	//保存文件
	void save();
	//显示职工
	void Show_Emp();
	//统计人数
	int get_EmpNum();
	//初始化员工
	void init_Emp();
	//删除职工
	void Del_Emp();
	//按照职工编号判断职工是否存在,若存在返回职工在数组中位置，不存在返回-1
	int IsExist(int id);
	//修改职工
	void Mod_Emp();
	//查找职工
	void Find_Emp();
	//排序职工
	void Sort_Emp();
	//清空文件
	void Clean_File();


	//析构函数
	~WorkerManager();


	//记录文件中的人数个数
	int m_EmpNum;

	//员工数组的指针
	Worker ** m_EmpArray;

	//标志文件是否为空
	bool m_FileIsEmpty;
};