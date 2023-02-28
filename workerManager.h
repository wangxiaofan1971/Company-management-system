#pragma once//��һ���Ƚϳ��õ�C/C++Ԥ����ָ�ֻҪ��ͷ�ļ����ʼ��������Ԥ����ָ����ܹ���֤ͷ�ļ�ֻ������һ�Σ���ֹͷ�ļ����ظ����á�
#include<iostream>
using namespace std;
#include"worker.h"
#include"employee.h"
#include <fstream>
#define  FILENAME "empFile.txt"

//��ƹ����� 
//���û��Ĺ�ͨ�˵�����
//��ְ����ɾ�Ĳ�Ĳ���
//���ļ��Ķ�д����



class WorkerManager
{
public:

	//���캯��
	WorkerManager();
	//���û��Ĺ�ͨ�˵�����
	void Show_Menu();
	//�˳��������
	void exitSystem();
	//����ְ��
	void Add_Emp();
	//�����ļ�
	void save();
	//��ʾְ��
	void Show_Emp();
	//ͳ������
	int get_EmpNum();
	//��ʼ��Ա��
	void init_Emp();
	//ɾ��ְ��
	void Del_Emp();
	//����ְ������ж�ְ���Ƿ����,�����ڷ���ְ����������λ�ã������ڷ���-1
	int IsExist(int id);
	//�޸�ְ��
	void Mod_Emp();
	//����ְ��
	void Find_Emp();
	//����ְ��
	void Sort_Emp();
	//����ļ�
	void Clean_File();


	//��������
	~WorkerManager();


	//��¼�ļ��е���������
	int m_EmpNum;

	//Ա�������ָ��
	Worker ** m_EmpArray;

	//��־�ļ��Ƿ�Ϊ��
	bool m_FileIsEmpty;
};