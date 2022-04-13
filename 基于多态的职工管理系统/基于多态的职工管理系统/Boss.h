#pragma once
#include <iostream>
#include <string>
#include"Worker.h"
using namespace std;

class Boss :public Worker {
public:
	Boss(string name, int num, int pos);

	virtual void WokerInfor();

	virtual string Position();
};