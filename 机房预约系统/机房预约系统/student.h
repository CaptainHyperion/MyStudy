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

//ѧ����
class Student :public Identity
{
public:
	//Ĭ�Ϲ���
	Student();

	//�вι���
	Student(int id, string name, string pwd);

	//ѡ��˵�
	virtual void operMenu();

	//����ԤԼ
	void applyOrder();

	//�鿴�ҵ�ԤԼ
	void showMyOrder();

	//�鿴����ԤԼ
	void showAllOrder();

	//ȡ��ԤԼ
	void cacelOrder();

	//ѧ��ѧ��
	int m_Id;

	//��������
	vector<ComputerRoom> vCom;
};