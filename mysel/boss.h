#pragma once
#include"people.h"
class boss :public people
{
public:
	boss(int inid, string inname, int inpost);
	void show();
};
