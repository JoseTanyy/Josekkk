#pragma once
#include <iostream>
#include <string>
using namespace std;

class Worker {
public:
	virtual void WokerInfor() = 0;
	virtual string Position() = 0;

	//�������Ա����������š�ְλ
	void putName(string name) {
		Name = name;
	}
	void putNum(int num){
		Num = num;
	}
	void putPos(int pos){
		Pos = pos;
	}

	//��ȡ����Ա����������š�ְλ
	string getName() {
		return Name;
	}
	int getNum() {
		return Num;
	}
	int getPos() {
		return Pos;		//����㣡
	}

private:
	string Name;	//����
	int Num;		//����
	int Pos;		//ְλ
};