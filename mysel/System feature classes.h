#pragma once
#include<iostream>
#include"people.h"
using namespace std;
class sys_fun//ϵͳ����
{
public:
	sys_fun();
	void System_interface();//��ʼ���溯��
	void Add_emp_inf();//����ְԱ��Ϣ
	void Show_emp_inf();//��ʾְԱ��Ϣ
	bool Eixt_sym();//�˳�ϵͳ
	void Save_file();//�����ļ�
	void Imput_file();//�����ļ�
	void getnum();//��ȡ�ļ���Ϣ
	void ini_inf();//��ʼ����Ϣϵͳ
	void del_emp();//ɾ��ְ��
	void isexist(int id);//��ѯ�Ƿ����
	void modify();//�޸ĳ�Ա����
	void findemp();//Ѱ�ҳ�Ա
	void Sort_Emp();//����ְ��
	void Clean_File();//����ļ�
	~sys_fun();
	int empnum;//Ա������
	people ** empinf;//Ա����Ϣ����ָ��
	int indentfile;//�����ļ���ʶ����
	int indentinf;//�����ļ����ݱ�ʶ����
	bool Isexist;//������Ա�Ƿ����
};