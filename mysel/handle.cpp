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
	cout << "ְ����ţ�" << this->id << '\t'
		<< "ְ��������" << this->name << '\t'
		<< "��λ������" << '\t'
		<< "��λְ������ϰ彻�������񣬲��·������Ա��" << endl;
}
