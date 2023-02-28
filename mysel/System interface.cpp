#include<iostream>
using namespace std;
#include"System feature classes.h"
#include"people.h"
#include"boss.h"
#include"handle.h"
#include"Ordinary employees.h"
#include"fstream"
sys_fun::sys_fun()
{
	this->empnum = 0;
	this->empinf = NULL;
	//this->indentfile = 0;
	//this->indentinf = 0;
	this->Imput_file();
	this->Isexist = false;
}

void sys_fun:: System_interface()
{
	cout << "********************************************" << endl <<
			"*********  ��ӭʹ��ְ������ϵͳ�� **********" << endl <<
			"*************  0.�˳��������  *************" << endl <<
			"*************  1.����ְ����Ϣ  *************" << endl <<
			"*************  2.��ʾְ����Ϣ  *************" << endl <<
			"*************  3.ɾ����ְְ��  *************" << endl <<
			"*************  4.�޸�ְ����Ϣ  *************" << endl <<
			"*************  5.����ְ����Ϣ  *************" << endl <<
			"*************  6.���ձ������  *************" << endl <<
			"*************  7.��������ĵ�  *************" << endl <<
			"********************************************" << endl;
}

void sys_fun::Add_emp_inf()
{
	int n = 0;//���ְ������
	int newempnum = 0;//����Ա������
	int inid;
	string inname;
	int inpost;
	people*worker = NULL;
	cout << "���������ְ��������" << endl;
	cin >> n;
	newempnum = this->empnum + n;//��Ա������

	people* *newempinf = new people*[newempnum];
	//��������ռ����ݷŵ��µ�����ռ�
	if (empinf!=NULL)
	{
		for (size_t i = 0; i < unsigned(this->empnum); i++)
			{
				newempinf[i] = this->empinf[i];
			};
	}
	
	for (size_t i = 0; i < unsigned(n); i++)
	{
		cout << "�������" << n << "����ְ����ţ�" << endl;
		cin >> inid;
		cout << "�������" << n << "����ְ��������" << endl;
		cin >> inname;
		cout << "��ѡ���ְ����λ" << endl << "1����ְͨ��" << endl << "2������" << endl << "3���ϰ�" << endl;
		cin >> inpost;
		switch (inpost)
		{
		case 1:
			worker = new ord_emp(inid, inname, inpost);//��������ŵ�����
			break;
		case 2:
			worker = new handle(inid, inname, inpost);
			break;
		case 3:
			worker = new boss(inid, inname, inpost);
			break;
		default:
			break;
		};
		newempinf[this->empnum+i] = worker;
	}
	//��ʾ��Ϣ
	cout << "�ɹ����" << n << "����ְ����" << endl;
	cout << "�ܹ�Ա��" << newempnum << endl;
	this->empinf = newempinf;
	this->empnum = newempnum;
	
}
void sys_fun::Show_emp_inf()
{
	for (size_t i = 0; i < unsigned(this->empnum); i++)
	{
		this->empinf[i]->show();
	}
}
bool sys_fun::Eixt_sym()
{
	int choose = 0;
	cout << "��ȷ���˳�ϵͳ��" << endl << "1:YES" << endl << "2:NO" << endl;
	cin >> choose;
	if (choose == 1)
	{
		this->Save_file();
		return false;
	}

}

void sys_fun::Save_file()//�����ļ�
{
	ofstream ofs;
	ofs.open("savefile.txt", ios::out);
	for (size_t i = 0; i < unsigned(this->empnum); i++)
	{
		ofs << this->empinf[i]->id << '\t'
			<< this->empinf[i]->name << '\t'
			<< this->empinf[i]->post << '\t' << endl;
	}
	cout << "����Ա��" << this->empnum << endl;
	ofs.close();
}

void sys_fun::Imput_file()//д���ļ�
{
	ifstream ifs;
	ifs.open("savefile.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "Ա����Ϣ�ļ�������";
		this->indentfile = 0;
		this->indentinf = 0;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "Ա����Ϣ�ļ����ڣ�����Ϊ��" << endl;
		this->indentfile = 1;
		this->indentinf = 0;
	}
	else
	{
		cout << "Ա����Ϣ�ļ����ڣ����ݲ�Ϊ��" << endl;
		this->indentfile = 1;
		this->indentinf = 1;
		this->getnum();
		this->ini_inf();
	}
	ifs.close();
}

void sys_fun::getnum()
{
	ifstream ifs;
	ifs.open("savefile.txt", ios::in);
	if (ifs.is_open())
	{
		cout << "�ɹ���ϵͳ�ļ�" << endl;
	}
	int id;
	string name;
	int post;
	while (ifs >> id&&ifs >> name&&ifs >> post)
	{
		this->empnum++;
		
	}
	cout << "����" << this->empnum << "��Ա��" << endl;
	ifs.close();
}

void sys_fun::ini_inf()
{
	ifstream ifs;
	ifs.open("savefile.txt", ios::in);
	int id;
	string name;
	int post;
	int n = 0;
	this->empinf = new people*[this->empnum];
	people* worker = NULL;
	while (ifs >> id&&ifs >> name&&ifs >> post)
		{
			switch (post)
			{
			case 1:
				worker = new ord_emp(id, name, post);
				break;
			case 2:
				worker = new handle(id, name, post);
				break;
			case 3:
				worker = new boss(id, name, post);
				break;
			default:
				break;
			}
			this->empinf[n] = worker;
			n++;
		}
		
	ifs.close();
}

void sys_fun::del_emp()
{
	int id = 0;
	int choose = 0;
	int findidnum = 0;
	cout << "��������Ҫɾ��Ա����ID:" << endl;
	cin >> id;
	while (true)
	{
		this->isexist(id);
		if (this->Isexist)
		{
			for (size_t i = 0; i < this->empnum; i++)
			{
				if (this->empinf[i]->id==id)
				{
					findidnum = i;
					break;
				}
			}//�ҵ�id��ѯλ��
			
			for (size_t j = findidnum; j < this->empnum- 1; j++)
			{
				this->empinf[j] = this->empinf[j + 1];
			}//����ɾ����Ϣ
			people**newspace = new people*[this->empnum - 1];
			for (size_t j = 0; j < this->empnum - 1; j++)
			{
				newspace[j] = this->empinf[j];
			}//����ɾ����Ϣ
			this->empnum--;
			delete this->empinf;
			this->empinf = newspace;
		}
		else
		{
			break;
		}
	}
}

void sys_fun::isexist(int id)
{
	for (size_t i = 0; i < this->empnum; i++)
	{
		this->Isexist = false;
		if (this->empinf[i]->id==id)
		{
			cout << "��Ҫ����Ա����" << endl;
			this->empinf[i]->show();
			this->Isexist = true;
			break;
		}
	}
}

void sys_fun::modify()
{
	int id;
	cout << "����������Ҫ�޸ĵ�Ա����id" << endl;
	cin >> id;
	int npost;
	string nname;
	int nid;
	people* worker=nullptr;
	isexist(id);
	while (Isexist)
	{
			for (size_t i = 0; i < this->empnum; i++)
			{
				if (this->empinf[i]->id == id)
				{
					//this->empinf[i]->show();
					cout << "�������µ�Ա��id" << endl;
					cin >> nid;
					cout << "�������µ�Ա��name" << endl;
					cin >> nname;
					cout << "�������µ�Ա��post" << endl;
					cin >> npost;
					switch (npost)
					{
					case 1:
						worker = new ord_emp(nid, nname, npost);//��������ŵ�����
						break;
					case 2:
						worker = new handle(nid, nname, npost);
						break;
					case 3:
						worker = new boss(nid, nname, npost);
						break;
					default:
						break;
					}
					delete this->empinf[i];
					this->empinf[i] = worker;

				}
			}
			break;
	}
}

void sys_fun::findemp()
{
	int choose = 0;
	int id;
	string name;
	cout << "�ṩ���ֲ���ְ����ʽ:" << endl <<
		"1���ְ���ְ�����" << endl <<
		"2���ְ���ְ������" << endl;
	cin >> choose;
	switch (choose)
	{
	case 1:
		cout << "������Ա�����:" << endl;
		cin >> id;
		for (size_t i = 0; i < this->empnum; i++)
		{
			if (this->empinf[i]->id== id)
			{
				this->empinf[i]->show();
			}
		}
		break;
	case 2:
		cout << "������Ա������"<< endl;
		cin >> name;
		for (size_t i = 0; i < this->empnum; i++)
		{
			if (this->empinf[i]->name == name)
			{
				this->empinf[i]->show();
			}
		}
		break;
	default:
		break;
	}
}

void sys_fun::Sort_Emp()
{
	int choose = 0;
	cout << "����������ʽ" << endl;
	cout << "1������" << endl;
	cout << "2������"<< endl;
	cin >> choose;
	people* tmp;
	for (size_t i = 0; i < this->empnum-1; i++)
	{
		for (size_t j =0; j < this->empnum-1-i; j++)
		{
			if (this->empinf[j]->id>this->empinf[j+1]->id)
			{
				tmp = this->empinf[j + 1];
				this->empinf[j + 1] = this->empinf[j];
				this->empinf[j] = tmp;

			}
		}
	}
	//��С��������



	switch (choose)
	{
	case 1:
		for (size_t i = 0; i < this->empnum; i++)
		{
			this->empinf[i]->show();
		}
		break;
	case 2:
		for (size_t i = 0; i < this->empnum; i++)
		{
			this->empinf[this->empnum-1-i]->show();
		}
		break;
	default:
		break;
	}
}

void sys_fun::Clean_File()
{
	this->empnum = 0;
	delete []this->empinf;
	Save_file();
}

sys_fun::~sys_fun()
{
	if (this->empinf != NULL)
	{
		delete[] this->empinf;
	}
	
}