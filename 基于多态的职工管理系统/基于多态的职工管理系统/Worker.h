#pragma once
#include <iostream>
#include <string>
using namespace std;

class Worker {
public:
	virtual void WokerInfor() = 0;
	virtual string Position() = 0;

	//添加新人员的姓名、编号、职位
	void putName(string name) {
		Name = name;
	}
	void putNum(int num){
		Num = num;
	}
	void putPos(int pos){
		Pos = pos;
	}

	//获取新人员的姓名、编号、职位
	string getName() {
		return Name;
	}
	int getNum() {
		return Num;
	}
	int getPos() {
		return Pos;		//问题点！
	}

private:
	string Name;	//姓名
	int Num;		//工号
	int Pos;		//职位
};