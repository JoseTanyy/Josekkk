#include "WorkManage.h"
#include "Boss.h"
#include "executive.h"
#include "employee.h"

//��ʼ�����캯��
WorkManage::WorkManage() {
	//1.�ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	if (!ifs.is_open()) {
		cout << "����Ա��(������)" << endl;
		//��ʼ����¼������
		this->EmpNum = 0;
		//��ʼ�������ָ��
		this->EmpArray = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->file_is_Empty = true;
		ifs.close();
		return;
	}

	//2.�ļ����ڣ�����Ϊ��
	//c++�ж��ļ��Ƿ�Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		cout << "����Ա��(��������)" << endl;
		//��ʼ����¼������
		this->EmpNum = 0;
		//��ʼ�������ָ��
		this->EmpArray = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->file_is_Empty = true;
		ifs.close();
		return;
	}
}

void WorkManage::Show_Menu() {
	cout << "******************************************" << endl;
	cout << "*********** ��ӭʹ��ְ������ϵͳ *********" << endl;
	cout << "************* 0.�˳�����ϵͳ *************" << endl;
	cout << "************* 1.����ְ����Ϣ *************" << endl;
	cout << "************* 2.��ʾְ����Ϣ *************" << endl;
	cout << "************* 3.ɾ����ְְ�� *************" << endl;
	cout << "************* 4.�޸�ְ����Ϣ *************" << endl;
	cout << "************* 5.����ְ����Ϣ *************" << endl;
	cout << "************* 6.���ձ������ *************" << endl;
	cout << "************* 7.����������� *************" << endl;
	cout << "******************************************" << endl;
	cout << endl;
}

void WorkManage::ExitSystem() {
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

//���Ա��ʵ��
void WorkManage::AddEmp() {
	cout << "��������ְ����(����������ڻ����1)��" << endl;
	int addNum = 0;	//�����û����������
	cin >> addNum;

	if (addNum > 0) {
		//�¿ռ�Ĵ�С = ����������С + ����ӵĴ�С
		int newsize = this->EmpNum + addNum;
		//�����¿ռ�	newSpace��һ������ָ��
		Worker** newSpace = new Worker * [newsize];
		//��ԭ���ռ��µ����ݣ�ȫ���������µĿռ�֮��
		if (this->EmpArray != NULL) {
			for (int i = 0; i < this->EmpNum; i++) {
				//�����е�Ա����Ϣ������º��Ա���ռ���
				//newSpace[]Ϊһ��ָ��
				newSpace[i] = this->EmpArray[i];
			}
		}
		//�û���ǰ������������ӵ�������������������������û�����Ĵ�������ѭ���Ĵ���
		for (int i = 0; i < addNum; i++) {
			int number;
			string names;
			int position;

			//���û��ṩ�������ʾ
			cout << "�������" << i + 1 << "����Ա���ı�ţ�" << endl;
			cin >> number;
			cout << "�������" << i + 1 << "����Ա����������" << endl;
			cin >> names;
			cout << "��ѡ���ְ���ĸ�λ��" << endl;
			cout << "1.Ա��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
			cin >> position;

			while (position != 1 && position != 2 && position != 3) {
				//����ְλ�Ĳ�ͬ���Բ�ͬ����µ���Ա����ʼ�������
				Worker* worker = NULL;
				cout << "����ѡ��" << endl;
				cout << "1.Ա��" << endl;
				cout << "2.����" << endl;
				cout << "3.�ϰ�" << endl;
				cin >> position;
				switch (position) {
				case 1:
					worker = new employee(names, number, position);
					break;
				case 2:
					worker = new executive(names, number, position);
					break;
				case 3:
					worker = new Boss(names, number, position);
					break;
				}
				//����ְ��ְ�𣬱��浽������
			newSpace[this->EmpNum + i] = worker;
			}
		}
		//���ͷ�ԭ�����ڵĶ����ռ�EmpArray
		delete[] this->EmpArray;
		//�����¿ռ��ָ��
		this->EmpArray = newSpace;
		//����ְ������
		this->EmpNum = newsize;
		//�ɹ���Ӻ󱣴浽�ļ���
		this->safe();
		//��ʾ��ӳɹ�
		cout << "����ְ" << addNum << "����Ա��" << endl;
	}
	else {
		cout << "��������" << endl;
	}

	system("pause");	//�����������
	system("cls");		//��������
}

void WorkManage::safe() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	//��ÿ��������д�뵽�ļ���
	for (int i = 0; i < this->EmpNum; i++) {
		ofs << this->EmpArray[i]->getName() << " "
			<< this->EmpArray[i]->getNum() << " "
			<< this->EmpArray[i]->getPos() << endl;
	}
	ofs.close();
}

//��������
WorkManage::~WorkManage() {
	if (this->EmpArray != NULL) {
		delete[] this->EmpArray;
		this->EmpArray = NULL;
	}
}