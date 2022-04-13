#include "Boss.h"

Boss::Boss(string name, int num, int pos) {
	this->putName(name);
	this->putNum(num);
	this->putPos(pos);
}

void Boss::WokerInfor() {
	cout << "±àºÅ£º " << this->getNum()
		<< "\tÐÕÃû£º" << this->getName()
		<< "\t¸ÚÎ»£º" << this->Position()
		<< endl;
}

string Boss::Position() {
	return string("×Ü²Ã");
}