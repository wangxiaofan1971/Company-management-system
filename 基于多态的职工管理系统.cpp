/*ְ������ϵͳ������������˾������Ա������Ϣ

���̳���Ҫ����C++��ʵ��һ�����ڶ�̬��ְ������ϵͳ



��˾��ְ����Ϊ���ࣺ��ͨԱ���������ϰ壬��ʾ��Ϣʱ����Ҫ��ʾְ����š�ְ��������ְ����λ���Լ�ְ��

��ͨԱ��ְ����ɾ�����������

����ְ������ϰ彻�������񣬲��·������Ա��

�ϰ�ְ�𣺹���˾��������



����ϵͳ����Ҫʵ�ֵĹ������£�

* �˳���������˳���ǰ����ϵͳ

- ����ְ����Ϣ��ʵ���������ְ�����ܣ�����Ϣ¼�뵽�ļ��У�ְ����ϢΪ��ְ����š����������ű��
- ��ʾְ����Ϣ����ʾ��˾�ڲ�����ְ������Ϣ
- ɾ����ְְ�������ձ��ɾ��ָ����ְ��
- �޸�ְ����Ϣ�����ձ���޸�ְ��������Ϣ
- ����ְ����Ϣ������ְ���ı�Ż���ְ�����������в�����ص���Ա��Ϣ
- ���ձ�����򣺰���ְ����ţ�������������������û�ָ��
- ��������ĵ�������ļ��м�¼������ְ����Ϣ �����ǰ��Ҫ�ٴ�ȷ�ϣ���ֹ��ɾ��*/
#include<iostream>
using namespace std;
#include"workerManager.h"
#include "worker.h"
#include"manager.h"
#include"employee.h"
#include"boss.h"
int main()
{
	WorkerManager ceshi;
	char choic = '0';
	while (true)
	{
		ceshi.Show_Menu();
		cout << "����������ѡ��" << endl;
		cin >> choic;
		switch (choic)
		{
		case '0'://�˳��������
		{
			ceshi.exitSystem();
			break;
		}
		case '1'://����ְ����Ϣ
		{
			ceshi.Add_Emp();
			break;
		}
		case '2'://��ʾְ����Ϣ
		{
			ceshi.Show_Emp();
			break;
		}
		case '3'://ɾ����ְְ��
		{
			ceshi.Del_Emp();
			break;
		}
		case '4'://�޸�ְ����Ϣ
		{
			ceshi.Mod_Emp();
			break;
		}
		case '5'://����ְ����Ϣ
		{
			ceshi.Find_Emp();
			break;
		}
		case '6'://���ձ������
		{
			ceshi.Sort_Emp();
			break;
		}
		case '7'://��������ĵ�
		{
			ceshi.Clean_File();
			break;
		}
		default:
			system("cls");
			cout << "��������ȷ��ѡ��"<<endl;
			break;
		}
		system("pause");
		system("cls");
	}
}


	
