#pragma once
#include"people.h"
class handle :public people
{
public:
	handle(int inid, string inname, int inpost);
	void show();
};
