#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;
#include"identity.h"
#include"computerRoom.h"
#include"globalFile.h"
#include"OrderFile.h"

//学生类
class Student :public Identity
{
public:
	//默认构造
	Student();

	//有参构造
	Student(int id, string name, string pwd);

	//选择菜单
	virtual void operMenu();

	//申请预约
	void applyOrder();

	//查看我的预约
	void showMyOrder();

	//查看所有预约
	void showAllOrder();

	//取消预约
	void cacelOrder();

	//学生学号
	int m_Id;

	//机房容器
	vector<ComputerRoom> vCom;
};