#include <iostream>
#include <string>
#include "WorkManage.h"
#include "Worker.h"
#include "Boss.h"
#include "executive.h"
#include "employee.h"
using namespace std;

int main() {
	//��������ϵͳ��
	WorkManage wm;
	int choice;

	//����
	/*Worker* worker = NULL;
	worker = new executive("����",1, 1);
	worker->WokerInfor();
	delete worker;

	worker = new Boss("����", 2, 3);
	worker->WokerInfor();
	delete worker;*/

	//չʾ�˵�
	while (true) {

		wm.Show_Menu();
		cout << "ѡ��Ҫ���еĲ���" << endl;
		cin >> choice;

		switch (choice) {
		case 0:
			wm.ExitSystem();
			break;
		case 1:
			wm.AddEmp();
			break;
		case 2:
			wm.showInformation();
			break;
		case 3:
			wm.DeleteMem();
			system("pause");
			system("cls");
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		default:
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}