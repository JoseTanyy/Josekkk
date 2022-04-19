#include "WorkManage.h"
#include "Boss.h"
#include "executive.h"
#include "employee.h"

//初始化构造函数
WorkManage::WorkManage() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	//1.文件不存在
	if (!ifs.is_open()) {
		//cout << "暂无员工(无名单)" << endl;	//测试
		//初始化记录的人数
		this->EmpNum = 0;
		//初始化数组的指针
		this->EmpArray = NULL;
		//初始化文件是否为空
		this->file_is_Empty = true;
		ifs.close();
		return;
	}

	//2.文件存在，数据为空
	//c++判断文件是否为空
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		//cout << "暂无员工(名单存在)" << endl;	//测试
		//初始化记录的人数
		this->EmpNum = 0;
		//初始化数组的指针
		this->EmpArray = NULL;
		//初始化文件是否为空
		this->file_is_Empty = true;
		ifs.close();
		return;
	}

	//3.文件存在且记录了数据
	int num = this->get_empNum();
	//cout << "职工人数为：" << num << endl;	//测试
	this->EmpNum = num;
	//初始化文件是否为空
	this->file_is_Empty = false;
	//开辟空间
	this->EmpArray = new Worker * [EmpNum];
	//将文件中的数据，存到数组中
	this->initEmp();
	//测试
	/*for (int i = 0; i < this->EmpNum; i++) {
		cout << "职工姓名：" << this->EmpArray[i]->getName()
			 << "\t职工编号" << this->EmpArray[i]->getNum()
			 << "\t部门编号" << this->EmpArray[i]->getPos() << endl;
	}*/
}

//初始化员工的实现
void WorkManage::initEmp() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	string name;
	int number;
	int position;

	int index = 0;		//测试
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

//获取在职人数的个数
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

//基本功能，显示菜单
void WorkManage::Show_Menu() {
	cout << "******************************************" << endl;
	cout << "*********** 欢迎使用职工管理系统 *********" << endl;
	cout << "************* 0.退出管理系统 *************" << endl;
	cout << "************* 1.增加职工信息 *************" << endl;
	cout << "************* 2.显示职工信息 *************" << endl;
	cout << "************* 3.删除离职职工 *************" << endl;
	cout << "************* 4.修改职工信息 *************" << endl;
	cout << "************* 5.查找职工信息 *************" << endl;
	cout << "************* 6.按照编号排序 *************" << endl;
	cout << "************* 7.清空所有数据 *************" << endl;
	cout << "******************************************" << endl;
	cout << endl;
}

//功能0.显示菜单
void WorkManage::ExitSystem() {
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

//功能1.添加员工实现
void WorkManage::AddEmp() {
	cout << "请输入入职人数(人数必须大于或等于1)：" << endl;
	int addNum = 0;	//保存用户输入的数量
	cin >> addNum;

	if (addNum > 0) {
		//新空间的大小 = 已有人数大小 + 新添加的大小
		int newsize = this->EmpNum + addNum;
		//开辟新空间	newSpace是一个二级指针
		Worker** newSpace = new Worker * [newsize];
		//将原来空间下的数据，全部拷贝到新的空间之下
		if (this->EmpArray != NULL) {
			for (int i = 0; i < this->EmpNum; i++) {
				//将已有的员工信息放入更新后的员工空间里
				//newSpace[]为一级指针
				newSpace[i] = this->EmpArray[i];
			}
		}
		//用户在前面输入了新添加的人数，根据这个人数来决定用户输入的次数，即循环的次数
		for (int i = 0; i < addNum; i++) {
			int number;
			string names;
			int position;

			//给用户提供输入的提示
			cout << "请输入第" << i + 1 << "个新员工的编号：" << endl;
			cin >> number;
			cout << "请输入第" << i + 1 << "个新员工的姓名：" << endl;
			cin >> names;
			cout << "请选择该职工的岗位：" << endl;
			cout << "1.员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> position;

			while (position != 1 && position != 2 && position != 3) {
				//根据职位的不同，对不同情况下的新员工初始化其类别
				cout << "请重选：" << endl;
				cout << "1.员工" << endl;
				cout << "2.经理" << endl;
				cout << "3.老板" << endl;
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
			//创建职工职责，保存到数组中
			newSpace[this->EmpNum + i] = worker;
			//此时成员表不为空
			this->file_is_Empty = false;
		}
		//先释放原本存在的堆区空间EmpArray
		delete[] this->EmpArray;
		//更改新空间的指向
		this->EmpArray = newSpace;
		//更新职工人数
		this->EmpNum = newsize;
		//成功添加后保存到文件中
		this->safe();
		//提示添加成功
		cout << "新入职" << addNum << "名新员工" << endl;
	}
	else {
		cout << "输入有误！" << endl;
	}

	system("pause");	//按任意键继续
	system("cls");		//清屏操作
}

void WorkManage::safe() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	//将每个人数据写入到文件中
	for (int i = 0; i < this->EmpNum; i++) {
		ofs << this->EmpArray[i]->getName() << " "
			<< this->EmpArray[i]->getNum() << " "
			<< this->EmpArray[i]->getPos() << endl;
	}
	ofs.close();
}


//功能2.显示员工信息
void WorkManage::showInformation() {
	//判断文件是否为空
	if (this->file_is_Empty) {
		cout << "成员表记录为空" << endl;
	}
	else {
		for (int i = 0; i < this->EmpNum; i++) {
			cout << "职工编号：" << this->EmpArray[i]->getNum()
				 << "\t部门编号：" << this->EmpArray[i]->getPos()
				 << "\t职工姓名：" << this->EmpArray[i]->getName() << endl;
		}
	}
	system("pause");
	system("cls");
}


//返回职工信息在列表中的位置
int WorkManage::ReturnP(int id) {
	int index = -1;
	for (int i = 0; i < this->EmpNum; i++) {
		if (this->EmpArray[i]->getNum() == id) {
			//cout << "职工存在" << endl;
			index = i;
			break;
		}
	}
	//cout << "职工不存在" << endl;
	return index;
}

//功能3.删除离职员工
void WorkManage::DeleteMem() {
	if (this->file_is_Empty) {
		cout << "暂无在职人员" << endl;
	}
	else {
		int id;
		cout << "请输入离职员工的工号:" << endl;
		cin >> id;
		int result = ReturnP(id);

		if (result != -1) {
			for (int i = result; i < this->EmpNum - 1; i++) {
				this->EmpArray[i] = this->EmpArray[i + 1];
			}
			this->EmpNum--;	//更新整个数组中记录的人数
			cout << "删除成功" << endl;
			//数据同步更新到文件中
			this->safe();
		}
		else {
			cout << "查无此人" << endl;
		}
	}

	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		//cout << "暂无员工(名单存在)" << endl;	//测试
		//初始化记录的人数
		this->EmpNum = 0;
		//初始化数组的指针
		this->EmpArray = NULL;
		//初始化文件是否为空
		this->file_is_Empty = true;
		ifs.close();
		return;
	}
}

//功能4：修改员工信息
void WorkManage::Modify() {
	if (this->file_is_Empty) {
		cout << "暂无在职人员" << endl;
	}
	else {
		int id;
		cout << "请输入要修改的员工信息的工号:" << endl;
		cin >> id;
		int result = ReturnP(id);

		if (result != -1) {
			delete this->EmpArray[result];
			int m_id;
			int m_pos;
			string m_name;

			cout << "修改员工姓名：" << endl;
			cin >> m_name;
			cout << "修改员工工号：" << endl;
			cin >> m_id;
			cout << "修改员工职位：" << endl;
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
			cout << "修改成功!" << endl;
			this->safe();
		}
		else {
			cout << "查无此人" << endl;
		}
	}
	system("pause");
	system("cls");
}

//功能5：查找员工信息
void WorkManage::Search() {
	if (this->file_is_Empty) {
		cout << "暂无在职人员" << endl;
	}
	else {
		int id;
		cout << "请输入要查找的员工的工号:" << endl;
		cin >> id;
		int result = ReturnP(id);

		if (result != -1) {
			cout << "该员工信息为：" << endl;
			cout << "职工编号：" << this->EmpArray[result]->getNum()
				 << "\t部门编号：" << this->EmpArray[result]->getPos()
				 << "\t职工姓名：" << this->EmpArray[result]->getName() << endl;
		}
		else {
			cout << "查无此人" << endl;
		}
	}
	system("pause");
	system("cls");
}

//功能6：按工号大小顺序排列
void WorkManage::Sort() {
	if (this->file_is_Empty) {
		cout << "暂无在职人员" << endl;
	}
	else {
		//冒泡排序
		int choice;
		cout << "请选择排序方式：" << endl;
		cout << "1.升序"
			 << "\n2.降序" << endl;
		cin >> choice;
		if (choice == 1) {
			int num = this->get_empNum();
			for (int i = 0; i < num; i++) {
				for (int j = 0; j < num - i; j++) {
					if (this->EmpArray[j]->getNum() < this->EmpArray[j + 1]->getNum()) {
						int t_num = this->EmpArray[j]->getNum();
						int t_pos = this->EmpArray[j]->getPos();
						string t_name = this->EmpArray[j]->getName();
						//交换相邻两个员工之间的信息，完成排序
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
						//交换相邻两个员工之间的信息，完成排序
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

//功能7：清空职工信息
void WorkManage::Clear() {
	cout << "确认清空？" << endl;
	cout << "1.确认"
		 << "2.返回" << endl;
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
		cout << "清楚成功" << endl;
	}
	system("pause");
	system("cls");
}

//析构函数
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