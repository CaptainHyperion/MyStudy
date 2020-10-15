#include"workerManager.h"

WorkerManager::WorkerManager()
{
	//1.文件不存在
	ifstream ifs;
	ifs.open(FILENAME,ios::in);

	if (!ifs.is_open())
	{
		//cout << "文件不存在" << endl;

		//初始化属性
		//初始化记录人数
		this->m_EmpNum = 0;
		//初始化数组指针
		this->m_EmpArray = NULL;
		//初始化文件是否为空
		this->m_FileIsEmp = true;
		ifs.close();
		return;
	}
	
	//2.文件存在 数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//文件为空
		//cout << "文件为空" << endl;

		//初始化记录人数
		this->m_EmpNum = 0;
		//初始化数组指针
		this->m_EmpArray = NULL;
		//初始化文件是否为空
		this->m_FileIsEmp = true;
		ifs.close();
		return;
	}


	//3.文件存在并且有数据
	int num = this->get_EmpNum();
	//cout << "职工的人数为：" << num << endl;
	this->m_EmpNum = num;

	//开辟空间
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//文件中的数据存放到数组中
	this->init_Emp();


	//测试代码
	//for (int i = 0; i < this->m_EmpNum;i++) {
	//	cout << " 工编号：" << this->m_EmpArray[i]->m_Id
	//		<< " 姓名：" << this->m_EmpArray[i]->m_Name
	//		<< " 部门编号" << this->m_EmpArray[i]->m_DeptId << endl;
	//}


}

//展示菜单
void WorkerManager::Show_Menu()
{
	cout << "***************************" << endl;
	cout << "***欢迎使用职工管理系统****" << endl;
	cout << "******0、退出管理系统******" << endl;
	cout << "******1、增加职工信息******" << endl;
	cout << "******2、显示职工信息******" << endl;
	cout << "******3、删除职工信息******" << endl;
	cout << "******4、修改职工信息******" << endl;
	cout << "******5、查找职工信息******" << endl;
	cout << "******6、按照编号排序******" << endl;
	cout << "******7、清空所有文档******" << endl;
	cout << "***************************" << endl;
	cout << endl;
}

void WorkerManager::ExitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

//添加职工
void WorkerManager::Add_Emp()
{
	cout << "请添加职工数量：" << endl;
	int addNum = 0;//保存用户输入数量
	cin >> addNum;

	if (addNum > 0)
	{
		//添加

		//计算添加空间大小
		int newSize = this->m_EmpNum + addNum;
		//开辟新空间
		Worker** newSpace = new Worker * [newSize];

		if (this->m_EmpArray!=NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//添加新数据
		for (int i=0;i<addNum;i++)
		{
			int id;//职工编号
			string name;//职工姓名
			int dSelect;//部分选择

			cout << "请输入第" << i + 1 << "个新职工的编号" << endl;
			cin >> id;

			cout << "请输入第" << i + 1 << "个新职工的姓名" << endl;
			cin >> name;

			cout << "请输入第" << i + 1 << "个新职工的岗位" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, dSelect);
				break;
			case 2:
				worker = new Manager(id, name, dSelect);
				break;
			case 3:
				worker = new Boss(id, name, dSelect);
				break;
			default:
				break;
			}

			//创建职工指针，保存到数组
			newSpace[this->m_EmpNum + i] = worker;

		}

		//删除原有空间
		delete[] this->m_EmpArray;
		//更改新空间指向
		this->m_EmpArray = newSpace;
		//更改职工人数
		this->m_EmpNum = newSize;

		this->m_FileIsEmp = false;
		//提示添加成功
		cout << "成功添加" << addNum << "名新职工";
		this->save();
	}
	else
	{
		cout << "输入有误" << endl;
	}

	//按任意键清屏 回到上级目录
	system("pause");
	system("cls");
}

//保存文件
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//输出的方式打开--写文件

	//每个人的数据写入文件
	for (int i = 0; i < this->m_EmpNum;i++) {
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << " " << endl;
	}

	ofs.close();
}


int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME,ios::in);//读文件

	int id;
	string name;
	int dId;

	//统计人数变量
	int num=0;
	while (ifs >> id && ifs >> name&&ifs>>dId)
	{
		num++;
	}
	
	return num;
}

//初始化员工
void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME,ios::in);

	int id;
	string name;
	int dId;

	int index=0;//索引
	while (ifs>>id && ifs>>name &&ifs>>dId)
	{
		Worker* worker = NULL;
		if (dId == 1)//普通职工
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2)//经理
		{
			worker = new Manager(id, name, dId);
		}
		else if (dId == 3)//老板
		{
			worker = new Boss(id, name, dId);
		}

		this->m_EmpArray[index] = worker;
		index++;
	}
	//关闭文件
	ifs.close();
}


//显示职工
void WorkerManager::Show_Emp()
{
	//判断文件是否为空
	if (this->m_FileIsEmp)
	{
		cout << "文件不存在记录为空！" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++) 
		{
			//利用多态调用程序接口
			this->m_EmpArray[i]->showInfo();
		}
	}
	//按任意键清屏
	system("pause");
	system("cls");
}

//删除职工
void WorkerManager::Del_Emp()
{
	if (this->m_FileIsEmp)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		//按照编号删除
		cout << "请输入想要删除的员工编号：" << endl;
		int id = 0;
		cin >> id;

		int index = this->isExist(id);

		if (index != -1)//职工存在
		{
			//数据前移
			for (int i=index;i<this->m_EmpNum-1;i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;//跟新数组中人员个数

			this->save();

			cout << "删除成功！" << endl;
		}
		else {
			cout << "未找到该职工" << endl;
		}
	}
	system("pause");
	system("cls");

}

//判断职工是否存在 如果存在返回索引 否则返回-1
int WorkerManager::isExist(int id)
{
	int index = -1;
	for(int i=0;i<this->m_EmpNum;i++)
	{
		if (this->m_EmpArray[i]->m_Id==id) {
			//找到
			index = i;
			break;
		}
	}
	return index;
}

//修改职工
void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmp)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		cout << "请输入修改职工的编号：" << endl;
		int id;
		cin >> id;

		int ret=this->isExist(id);
		if (ret != -1)
		{
			//找到此员工

			delete this->m_EmpArray[ret];

			int newId = 0;
			string newName = "";
			int dSelect = 0;

			cout << "查到" << id << "号职工，请输入新职工号：" << endl;
			cin >> newId;

			cout << "请输入新的姓名：" << endl;
			cin >> newName;

			cout << "请输入岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(newId, newName, dSelect);
				break;
			case 2:
				worker = new Manager(newId, newName, dSelect);
				break;
			case 3:
				worker = new Boss(newId, newName, dSelect);
				break;
			default:
				break;
			}
			//更新数据 到数组中
			this->m_EmpArray[ret] = worker;

			cout << "修改成功！" << endl;

			//保存到文件
			this->save();
		}
		else
		{
			cout << "修改失败，查无此人！" << endl;
		}
	}

	//按任意键清屏
	system("pause");
	system("cls");
}

//查找职工
void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmp)
	{
		cout << "文件不存在或为空或记录为空！" << endl;
	}
	else
	{
		cout << "请输入查找的方式：" << endl;
		cout << "1、按照职工的编号查找" << endl;
		cout << "2、按照职工的编号查找" << endl;
		int select = 0;
		cin >> select;

		if (select == 1)
		{
			//按编号查找
			int id;
			cout << "请输入查找的职工编号：" << endl;
			cin >> id;

			int ret = isExist(id);
			if (ret != -1)
			{
				//找到职工
				cout << "查找成功！该职工信息如下：" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "查找失败，查无此人！" << endl;
			}

		}
		else if (select == 2)
		{
			//按姓名查找
			string name;
			cout << "请输入查找的职工姓名：" << endl;
			cin >> name;

			//查找到此人的标志
			bool flag = false;

			for (int i = 0; i < m_EmpNum; i++) 
			{
				if (this->m_EmpArray[i]->m_Name == name) 
				{
					flag = true;
					cout << "查找成功，职工编号为：" << this->m_EmpArray[i]->m_Id << "号职工信息如下：" << endl;
					this->m_EmpArray[i]->showInfo();	
				}
			}

			if (flag == false)
			{
				cout << "查找失败，查无此人！" << endl;
			}

		}
		else
		{
			cout << "输入选项有误!" << endl;

		}

	}
	//按任意键清屏
	system("pause");
	system("cls");
}

//按照编号排序
void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmp)
	{
		cout << "文件不存在或为空或记录为空！" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序方式：" << endl;
		cout << "1、按职工号进行升序" << endl;
		cout << "2、按职工号进行降序" << endl;

		int select = 0;
		cin >> select;
		for (int i=0;i<m_EmpNum;i++)
		{
			int minOrMax = i;//声明最小或最大值
			for (int j = i + 1; j < this->m_EmpNum; j++)
			{
				if (select == 1)//升序
				{
					if (this->m_EmpArray[minOrMax]->m_Id > this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
				else if (select == 2)//降序
				{
					if (this->m_EmpArray[minOrMax]->m_Id < this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
			}

			//判断一开始认定的最值是不是，如果不是，交换
			if (i!=minOrMax)
			{
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
				this->m_EmpArray[minOrMax] = temp;
			}

		
		}
		cout << "排序成功！排序后结果为：" << endl;
		this->save();//保存到文件中
		this->Show_Emp();
	}
}

void WorkerManager::Clean_File()
{
	cout << "确定清空？" << endl;
	cout << "1、确定" << endl;
	cout << "2、返回" << endl;

	int  select = 0;
	cin >> select;
	if (select == 1)
	{
		//清空文件
		ofstream ofs(FILENAME,ios::trunc);//删除后重新创建
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			//删除职工对象
			for (int i=0;i<this->m_EmpNum;i++)
			{
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}

			//删除堆区数组指针
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmp = true;

		}
			
		cout << "清空成功！" << endl;
	}
	system("pause");
	system("cls");
	

}

WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray!=NULL)
	{
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}