#pragma once
#include <iostream>
#include <string>
#include"Worker.h"
using namespace std;

class employee :public Worker {
public:
	employee(string name, int num, int pos);

	virtual void WokerInfor();

	virtual string Position();
};