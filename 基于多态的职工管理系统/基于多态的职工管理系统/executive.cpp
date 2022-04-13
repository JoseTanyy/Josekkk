#include "executive.h"

executive::executive(string name, int num, int pos) {
	this->putName(name);
	this->putNum(num);
	this->putPos(pos);
}

void executive::WokerInfor() {
	cout << "编号： " << this->getNum()
		<< "\t姓名：" << this->getName()
		<< "\t岗位：" << this->Position()
		<< endl;
}

string executive::Position() {
	return string("经理");
}