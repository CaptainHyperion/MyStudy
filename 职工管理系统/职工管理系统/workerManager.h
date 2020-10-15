#pragma once
#include<iostream>
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"

#include<fstream>
#define FILENAME "empFile.txt"

using namespace std;

class WorkerManager
{
public:
	WorkerManager();
	//显示菜单
	void Show_Menu();
	//退出
	void ExitSystem();

	//记录职工人数
	int m_EmpNum;

	//职工数组的指针
	Worker ** m_EmpArray;

	//添加职工
	void Add_Emp();

	//保存文件
	void save();
	

	//判断文件是否为空 标志
	bool m_FileIsEmp;

	//统计文件中人数
	int get_EmpNum();


	//初始化员工
	void init_Emp();

	//显示职工
	void Show_Emp();

	//删除职工
	void Del_Emp();

	//判断职工是否存在 如果存在返回索引 否则返回-1
	int isExist(int id);

	//修改职工
	void Mod_Emp();

	//查找职工
	void Find_Emp();

	//按照编号排序
	void Sort_Emp();

	//清空文件
	void Clean_File();


	~WorkerManager();
};