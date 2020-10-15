#include<iostream>
#include<string>
#include<fstream>

#include"Identity.h"
#include"student.h"
#include"teacher.h"
#include"manager.h"
#include"globalFile.h"

using namespace std;

//进入管理员子菜单界面
void managerMenu(Identity* &manager)
{
	while (true)
	{
		//调用管理员子菜单
		manager->operMenu();

		//父类指针转为子类指针，调用子类其他接口
		Manager* man = (Manager*)manager;

		int select = 0;
		//接收用户选项
		cin >> select;

		if (select == 1)//添加账号
		{
			cout << "添加账号" << endl;
			man->addPerson();
		}
		else if (select == 2)//查看账号
		{
			cout << "查看账号" << endl;
			man->showPerson();
		}
		else if (select == 3)//查看机房信息
		{
			cout << "查看机房信息" << endl;
			man->showComputer();
		}
		else if (select == 4)//清空预约
		{
			cout << "清空预约" << endl;
			man->cleanFile();
		}
		else
		{
			delete manager;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//进入学生子菜单界面
void studentMenu(Identity*& student)
{
	while (true)
	{
		//学生菜单
		student->operMenu();

		Student* stu = (Student*)student;
		int select = 0;

		cin >> select;

		if (select == 1)//申请预约
		{
			stu->applyOrder();
		}
		else if (select == 2)//查看自身预约
		{
			stu->showMyOrder();
		}
		else if (select == 3)//查看所有预约
		{
			stu->showAllOrder();
		}
		else if (select == 4)//取消预约
		{
			stu->cacelOrder();
		}
		else
		{
			delete student;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}

	}
}

//进入教师子菜单界面
void teacherMenu(Identity*& teacher)
{
	while (true)
	{
		//调用子菜单界面
		teacher->operMenu();

		Teacher* tea = (Teacher*)teacher;

		int select = 0;//接收用户选择

		cin >> select;

		if (select == 1)//查看预约
		{
			tea->showAllOrder();
		}
		else if (select == 2)//审核预约
		{
			tea->validOrder();
		}
		else//注销登录
		{
			delete teacher;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
//登录功能 操作文件名，操作身份类型
void Login(string fileName,int type)
{
	//父类指针，指向子类对象
	Identity* person = NULL;

	//读文件
	ifstream ifs;
	ifs.open(fileName, ios::in);

	//判断文件是否存在
	if (!ifs.is_open())
	{
		cout << "文件不存在！" << endl;
		ifs.close();
		return;
	}

	//准备接收用户信息
	int id = 0;
	string name;
	string pwd;

	//判断身份
	if (type == 1) //学生登录
	{
		cout << "请输入你的学号：" << endl;
		cin >> id;
	}
	else if (type == 2)//教师登录
	{
		cout << "请输入您的职工号：" << endl;
		cin >> id;
	}

	cout << "请输如用户名：" << endl;
	cin >> name;

	cout << "请输入密码：" << endl;
	cin >> pwd;

	if (type == 1)
	{
		//学生验证
		int fId;//从文件中获取的id
		string fName;//从文件中获取的姓名
		string fPwd;//从文件中获取的密码
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			//与输入信息做比较
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "学生验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);

				//进入学生子菜单
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2)
	{
		//教师验证
		
		int fId;//从文件中获取的id
		string fName;//从文件中获取的姓名
		string fPwd;//从文件中获取的密码
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			//与输入信息做比较
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "教师验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);

				//进入教师子菜单
				teacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3)
	{
		//管理员验证
		
		string fName;//从文件中获取的姓名
		string fPwd;//从文件中获取的密码
		while ( ifs >> fName && ifs >> fPwd)
		{
			//与输入信息做比较
			if ( fName == name && fPwd == pwd)
			{
				cout << "验证登录成功！" << endl;
				//登陆成功，进入管理员界面
				system("pause");
				system("cls");
				//创建管理员对象
				person = new Manager(name, pwd);

				//进入管理员子菜单
				managerMenu(person);
				return;
			}
		}
	}

	cout << "验证登录失败！" << endl;

	system("pause");
	system("cls");
	return;
}

int main()
{
	int select = 0;//接收用户选择

	while (true)
	{
		cout << "================ 欢迎来到传智播客机房预约系统 ================"
				<< endl;
		cout << endl << "请输入您的身份" << endl;
		cout << "\t\t --------------------------- \n";
		cout << "\t\t|                           |\n";
		cout << "\t\t|        1.学生代表         |\n";
		cout << "\t\t|                           |\n";
		cout << "\t\t|        2.老    师         |\n";
		cout << "\t\t|                           |\n";
		cout << "\t\t|        3.管 理 员         |\n";
		cout << "\t\t|                           |\n";
		cout << "\t\t|        0.退    出         |\n";
		cout << "\t\t|                           |\n";
		cout << "\t\t --------------------------- \n";
		cout << endl << "请输入您的选择：" << endl;

		cin >> select;

		switch (select)//根据用户选择进行分支选择
		{
		case 1://学生身份
			Login(STUDENT_FILE, 1);
			break;
		case 2://老师身份
			Login(TEACHER_FILE, 2);
			break;
		case 3://管理员身份
			Login(ADMIN_FILE, 3);
			break;
		case 0://退出系统
			cout << "欢迎下一次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入有误，请重新选择！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	

	system("pause");
	return 0;
}
