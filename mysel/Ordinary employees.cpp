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
	cout << "ְ����ţ�" << this->id << '\t'
		<< "ְ��������" << this->name << '\t'
		<< "��λ��Ա��" << '\t'
		<< "��λְ����ɾ�����������" << endl;
}
