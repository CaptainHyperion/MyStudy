#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;
#include"identity.h"

#include"globalFile.h"
#include"OrderFile.h"
class Teacher :public Identity
{
public:
	//Ĭ�Ϲ���
	Teacher();

	//�вι��죨ְ����ţ����������룩
	Teacher(int empId, string name, string pwd);

	//�˵�����
	virtual void operMenu();

	//�鿴����ԤԼ
	void showAllOrder();

	//���ԤԼ
	void validOrder();

	int m_EmpId;//��ʦ���
};