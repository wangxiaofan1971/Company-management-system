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
	cout << "ְ����ţ�" << this->id << '\t' 
		<< "ְ��������" << this->name << '\t' 
		<< "��λ���ϰ�" << '\t'
		<< "��λְ�𣺹���˾��������" << endl;
}