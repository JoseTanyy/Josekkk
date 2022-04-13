#pragma once
#include <iostream>
#include "Worker.h"
#include <fstream>
using namespace std;

#define FILENAME "empFile.txt"

class WorkManage {
public:
	//构造函数
	WorkManage();

	//显示菜单函数
	void Show_Menu();

	//离开系统函数
	void ExitSystem();

	//添加职工声明
	void AddEmp();
	//职工人数 成员属性
	int EmpNum;
	//职工数组的指针
	Worker** EmpArray;

	//保存文件
	void safe();

	//读文件	文件为空的标志
	bool file_is_Empty;

	//统计文件中的职工人数
	int get_empNum();

	//初始化在职人员
	void initEmp();

	//析构函数
	~WorkManage();
};