#include "WorkManage.h"
#include "Boss.h"
#include "executive.h"
#include "employee.h"

//��ʼ�����캯��
WorkManage::WorkManage() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	//1.�ļ�������
	if (!ifs.is_open()) {
		//cout << "����Ա��(������)" << endl;	//����
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
		//cout << "����Ա��(��������)" << endl;	//����
		//��ʼ����¼������
		this->EmpNum = 0;
		//��ʼ�������ָ��
		this->EmpArray = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->file_is_Empty = true;
		ifs.close();
		return;
	}

	//3.�ļ������Ҽ�¼������
	int num = this->get_empNum();
	//cout << "ְ������Ϊ��" << num << endl;	//����
	this->EmpNum = num;
	//��ʼ���ļ��Ƿ�Ϊ��
	this->file_is_Empty = false;
	//���ٿռ�
	this->EmpArray = new Worker * [EmpNum];
	//���ļ��е����ݣ��浽������
	this->initEmp();
	//����
	/*for (int i = 0; i < this->EmpNum; i++) {
		cout << "ְ��������" << this->EmpArray[i]->getName()
			 << "\tְ�����" << this->EmpArray[i]->getNum()
			 << "\t���ű��" << this->EmpArray[i]->getPos() << endl;
	}*/
}

//��ʼ��Ա����ʵ��
void WorkManage::initEmp() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	string name;
	int number;
	int position;

	int index = 0;		//����
	while (ifs >> name && ifs >> number && ifs >> position) {
		Worker* worker = NULL;
		if (position == 1) {
			worker = new employee(name, number, position);
		}
		else if (position == 2) {
			worker = new executive(name, number, position);
		}
		else {
			worker = new Boss(name, number, position);
		}
		this->EmpArray[index] = worker;
		index++;
	}	ifs.close();
}

//��ȡ��ְ�����ĸ���
int WorkManage::get_empNum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	string name;
	int number;
	int position;

	int num = 0;
	while (ifs >> name && ifs >> number && ifs >> position) {
		num++;
	}
	return num;
}

//�������ܣ���ʾ�˵�
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

//����0.��ʾ�˵�
void WorkManage::ExitSystem() {
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

//����1.���Ա��ʵ��
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
				cout << "����ѡ��" << endl;
				cout << "1.Ա��" << endl;
				cout << "2.����" << endl;
				cout << "3.�ϰ�" << endl;
				cin >> position;
			}

			Worker* worker = NULL;
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
			//��ʱ��Ա��Ϊ��
			this->file_is_Empty = false;
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


//����2.��ʾԱ����Ϣ
void WorkManage::showInformation() {
	//�ж��ļ��Ƿ�Ϊ��
	if (this->file_is_Empty) {
		cout << "��Ա���¼Ϊ��" << endl;
	}
	else {
		for (int i = 0; i < this->EmpNum; i++) {
			cout << "ְ����ţ�" << this->EmpArray[i]->getNum()
				 << "\t���ű�ţ�" << this->EmpArray[i]->getPos()
				 << "\tְ��������" << this->EmpArray[i]->getName() << endl;
		}
	}
	system("pause");
	system("cls");
}


//����ְ����Ϣ���б��е�λ��
int WorkManage::ReturnP(int id) {
	int index = -1;
	for (int i = 0; i < this->EmpNum; i++) {
		if (this->EmpArray[i]->getNum() == id) {
			//cout << "ְ������" << endl;
			index = i;
			break;
		}
	}
	//cout << "ְ��������" << endl;
	return index;
}

//����3.ɾ����ְԱ��
void WorkManage::DeleteMem() {
	if (this->file_is_Empty) {
		cout << "������ְ��Ա" << endl;
	}
	else {
		int id;
		cout << "��������ְԱ���Ĺ���:" << endl;
		cin >> id;
		int result = ReturnP(id);

		if (result != -1) {
			for (int i = result; i < this->EmpNum - 1; i++) {
				this->EmpArray[i] = this->EmpArray[i + 1];
			}
			this->EmpNum--;	//�������������м�¼������
			cout << "ɾ���ɹ�" << endl;
			//����ͬ�����µ��ļ���
			this->safe();
		}
		else {
			cout << "���޴���" << endl;
		}
	}

	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		//cout << "����Ա��(��������)" << endl;	//����
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

//����4���޸�Ա����Ϣ
void WorkManage::Modify() {
	if (this->file_is_Empty) {
		cout << "������ְ��Ա" << endl;
	}
	else {
		int id;
		cout << "������Ҫ�޸ĵ�Ա����Ϣ�Ĺ���:" << endl;
		cin >> id;
		int result = ReturnP(id);

		if (result != -1) {
			delete this->EmpArray[result];
			int m_id;
			int m_pos;
			string m_name;

			cout << "�޸�Ա��������" << endl;
			cin >> m_name;
			cout << "�޸�Ա�����ţ�" << endl;
			cin >> m_id;
			cout << "�޸�Ա��ְλ��" << endl;
			cin >> m_pos;

			Worker* worker = NULL;
			switch (m_pos) {
			case 1:
				worker = new employee(m_name, m_id, m_pos);
				break;
			case 2:
				worker = new executive(m_name, m_id, m_pos);
				break;
			case 3:
				worker = new Boss(m_name, m_id, m_pos);
				break;
			}
			this->EmpArray[result] = worker;
			cout << "�޸ĳɹ�!" << endl;
			this->safe();
		}
		else {
			cout << "���޴���" << endl;
		}
	}
	system("pause");
	system("cls");
}

//����5������Ա����Ϣ
void WorkManage::Search() {
	if (this->file_is_Empty) {
		cout << "������ְ��Ա" << endl;
	}
	else {
		int id;
		cout << "������Ҫ���ҵ�Ա���Ĺ���:" << endl;
		cin >> id;
		int result = ReturnP(id);

		if (result != -1) {
			cout << "��Ա����ϢΪ��" << endl;
			cout << "ְ����ţ�" << this->EmpArray[result]->getNum()
				 << "\t���ű�ţ�" << this->EmpArray[result]->getPos()
				 << "\tְ��������" << this->EmpArray[result]->getName() << endl;
		}
		else {
			cout << "���޴���" << endl;
		}
	}
	system("pause");
	system("cls");
}

//����6�������Ŵ�С˳������
void WorkManage::Sort() {
	if (this->file_is_Empty) {
		cout << "������ְ��Ա" << endl;
	}
	else {
		//ð������
		int choice;
		cout << "��ѡ������ʽ��" << endl;
		cout << "1.����"
			 << "\n2.����" << endl;
		cin >> choice;
		if (choice == 1) {
			int num = this->get_empNum();
			for (int i = 0; i < num; i++) {
				for (int j = 0; j < num - i; j++) {
					if (this->EmpArray[j]->getNum() < this->EmpArray[j + 1]->getNum()) {
						int t_num = this->EmpArray[j]->getNum();
						int t_pos = this->EmpArray[j]->getPos();
						string t_name = this->EmpArray[j]->getName();
						//������������Ա��֮�����Ϣ���������
						this->EmpArray[j]->putName(this->EmpArray[j + 1]->getName());
						this->EmpArray[j + 1]->putName(t_name);

						this->EmpArray[j]->putNum(this->EmpArray[j + 1]->getNum());
						this->EmpArray[j + 1]->putNum(t_num);

						this->EmpArray[j]->putPos(this->EmpArray[j + 1]->getPos());
						this->EmpArray[j + 1]->putPos(t_pos);
					}
				}
			}
		}
		else {
			int num = this->get_empNum();
			for (int i = 0; i < num; i++) {
				for (int j = 0; j < num - i; j++) {
					if (this->EmpArray[j]->getNum() > this->EmpArray[j + 1]->getNum()) {
						int t_num = this->EmpArray[j]->getNum();
						int t_pos = this->EmpArray[j]->getPos();
						string t_name = this->EmpArray[j]->getName();
						//������������Ա��֮�����Ϣ���������
						this->EmpArray[j]->putName(this->EmpArray[j + 1]->getName());
						this->EmpArray[j + 1]->putName(t_name);

						this->EmpArray[j]->putNum(this->EmpArray[j + 1]->getNum());
						this->EmpArray[j + 1]->putNum(t_num);

						this->EmpArray[j]->putPos(this->EmpArray[j + 1]->getPos());
						this->EmpArray[j + 1]->putPos(t_pos);
					}
				}
			}
		}
	}
	system("pause");
	system("cls");
}

//����7�����ְ����Ϣ
void WorkManage::Clear() {
	cout << "ȷ����գ�" << endl;
	cout << "1.ȷ��"
		 << "2.����" << endl;
	int select;
	cin >> select;

	if (select == 1) {
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		if (this->EmpArray != NULL) {
			for (int i = 0; i < this->EmpNum; i++) {
				if (this->EmpArray[i] != NULL) {
					delete this->EmpArray[i];
				}
			}
			this->EmpNum = 0;
			delete[] this->EmpArray;
			this->EmpArray = NULL;
			this->file_is_Empty = true;
		}
		cout << "����ɹ�" << endl;
	}
	system("pause");
	system("cls");
}

//��������
WorkManage::~WorkManage() {
	if (this->EmpArray != NULL) {
		for (int i = 0; i < this->EmpNum; i++) {
			if (this->EmpArray[i] != NULL) {
				delete this->EmpArray[i];
			}
		}
		delete[] this->EmpArray;
		this->EmpArray = NULL;
	}
}