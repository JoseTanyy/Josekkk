#include "Boss.h"

Boss::Boss(string name, int num, int pos) {
	this->putName(name);
	this->putNum(num);
	this->putPos(pos);
}

void Boss::WokerInfor() {
	cout << "��ţ� " << this->getNum()
		<< "\t������" << this->getName()
		<< "\t��λ��" << this->Position()
		<< endl;
}

string Boss::Position() {
	return string("�ܲ�");
}