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
	//��ʾ�˵�
	void Show_Menu();
	//�˳�
	void ExitSystem();

	//��¼ְ������
	int m_EmpNum;

	//ְ�������ָ��
	Worker ** m_EmpArray;

	//���ְ��
	void Add_Emp();

	//�����ļ�
	void save();
	

	//�ж��ļ��Ƿ�Ϊ�� ��־
	bool m_FileIsEmp;

	//ͳ���ļ�������
	int get_EmpNum();


	//��ʼ��Ա��
	void init_Emp();

	//��ʾְ��
	void Show_Emp();

	//ɾ��ְ��
	void Del_Emp();

	//�ж�ְ���Ƿ���� ������ڷ������� ���򷵻�-1
	int isExist(int id);

	//�޸�ְ��
	void Mod_Emp();

	//����ְ��
	void Find_Emp();

	//���ձ������
	void Sort_Emp();

	//����ļ�
	void Clean_File();


	~WorkerManager();
};