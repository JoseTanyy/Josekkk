#include "executive.h"

executive::executive(string name, int num, int pos) {
	this->putName(name);
	this->putNum(num);
	this->putPos(pos);
}

void executive::WokerInfor() {
	cout << "��ţ� " << this->getNum()
		<< "\t������" << this->getName()
		<< "\t��λ��" << this->Position()
		<< endl;
}

string executive::Position() {
	return string("����");
}