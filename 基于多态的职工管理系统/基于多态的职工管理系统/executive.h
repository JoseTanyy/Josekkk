#pragma once
#include <iostream>
#include <string>
#include"Worker.h"
using namespace std;

class executive :public Worker {
public:
	executive(string name, int num, int pos);

	virtual void WokerInfor();

	virtual string Position();
};