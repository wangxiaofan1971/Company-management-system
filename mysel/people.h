#pragma once
#include<string>
using namespace std;
class people
{
public:
	virtual void show() = 0;
	int id;//ְ�����
	string name;//ְ������
	int post;//���ű��
	virtual ~people();
};