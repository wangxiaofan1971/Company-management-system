#include<iostream>
using namespace std;
#include"System feature classes.h"
#include"boss.h"
#include"handle.h"
#include"Ordinary employees.h"
int main()
{
	bool flag = true;
	sys_fun ceshi;
	char choose = '1';
	//boss a(1,"wang",1);
	//handle b(1, "yu", 2);
	//ord_emp c(1, "fan", 3);
	while (flag)
	{
		ceshi.System_interface();
		cout << "����������ѡ��" << endl;
		cin >> choose;
		switch (choose)
		{
		case '1':
			ceshi.Add_emp_inf();
			//1.����ְ����Ϣ
			break;
		case '2':
			//2.��ʾְ����Ϣ
			//a.show();
			//b.show();
			//c.show();
			ceshi.Show_emp_inf();
			break;
		case '3':
			//3.ɾ����ְְ��
			ceshi.del_emp();
			break;
		case '4':
			ceshi.modify();
			//4.�޸�ְ����Ϣ
			break;
		case '5':
			ceshi.findemp();
			//5.����ְ����Ϣ 
			break;
		case '6':
			ceshi.Sort_Emp();
			//6.���ձ������
			break;
		case '7':
			//7.��������ĵ� 
			ceshi.Clean_File();
			break;
		case '0':
			//0.�˳��������
			flag = ceshi.Eixt_sym();
			break;
		default:
			cout << "��������ȷ��ѡ��" << endl;
			break;
		}
		system("pause");
		system("cls");
	}
	return 0;
}