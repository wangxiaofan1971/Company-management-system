#pragma once
#include<iostream>
#include<string>
using namespace std;
/*ְ���ķ���Ϊ����ͨԱ���������ϰ�

������ְ������һ���ࣨworker����, ���ö�̬����ְͬ������

ְ��������Ϊ��ְ����š�ְ��������ְ�����ڲ��ű��

ְ������ΪΪ����λְ����Ϣ��������ȡ��λ����*/
class Worker
{
public:

	//��ʾ������Ϣ
	virtual void showInfo() = 0;
	//��ȡ��λ����
	virtual string getDeptName() = 0;

	int m_Id; //ְ�����
	string m_Name; //ְ������
	int m_DeptId; //ְ�����ڲ������Ʊ��
};