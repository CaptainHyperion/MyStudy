#pragma once
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
#include<map>
#include"globalFile.h"

//预约类
class OrderFile
{
public:
	//构造函数
	OrderFile();

	//更新预约记录
	void updateOrder();

	//记录的容器 key ---记录的条数  value--具体的记录信息
	map<int, map<string, string>> m_orderData;

	//预约记录条数
	int m_Size;
};