#include "employee.h"

employee::employee(string name, int num, int pos) {
	this->putName(name);
	this->putNum(num);
	this->putPos(pos);
}

void employee::WokerInfor() {
	cout << "��ţ� " << this->getNum()
		<< "\t������" << this->getName()
		<< "\t��λ��" << this->Position()
		<< endl;
}

string employee::Position() {
	return string("Ա��");
}