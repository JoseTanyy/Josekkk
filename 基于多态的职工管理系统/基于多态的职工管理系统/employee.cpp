#include "employee.h"

employee::employee(string name, int num, int pos) {
	this->putName(name);
	this->putNum(num);
	this->putPos(pos);
}

void employee::WokerInfor() {
	cout << "编号： " << this->getNum()
		<< "\t姓名：" << this->getName()
		<< "\t岗位：" << this->Position()
		<< endl;
}

string employee::Position() {
	return string("员工");
}