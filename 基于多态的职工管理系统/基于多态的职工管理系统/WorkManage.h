#pragma once
#include <iostream>
#include "Worker.h"
#include <fstream>
using namespace std;

#define FILENAME "empFile.txt"

class WorkManage {
public:
	//���캯��
	WorkManage();

	//��ʾ�˵�����
	void Show_Menu();

	//�뿪ϵͳ����
	void ExitSystem();

	//���ְ������
	void AddEmp();
	//ְ������ ��Ա����
	int EmpNum;
	//ְ�������ָ��
	Worker** EmpArray;

	//�����ļ�
	void safe();

	//���ļ�	�ļ�Ϊ�յı�־
	bool file_is_Empty;

	//ͳ���ļ��е�ְ������
	int get_empNum();

	//��ʼ����ְ��Ա
	void initEmp();

	//��������
	~WorkManage();
};