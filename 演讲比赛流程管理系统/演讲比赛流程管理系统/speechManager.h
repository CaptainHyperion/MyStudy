#pragma once
#include<iostream>
#include<vector>
#include<map>
#include<deque>

#include<algorithm>
#include<numeric>

#include<fstream>
#include"speaker.h"

using namespace std;

class SpeechManager
{
public:
	//���캯��
	SpeechManager();


	//չʾ�˵�
	void show_Menu();

	//�˳�ϵͳ
	void exitSystem();

	//��������
	~SpeechManager();

	//��ʼ�����Ժ�����
	void initSpeech();


	//����ѡ��
	void createSpeaker();

	//��ʼ���� �����������̿��ƺ���
	void startSpeech();


	//��ǩ
	void speechDraw();

	//����
	void speechContest();

	//��ʾ�÷�
	void showScore();


	//�����¼
	void saveRecord();

	//��ȡ��¼
	void loadRecord();

	//�ж��ļ��Ƿ�Ϊ��
	bool fileIsEmpty;

	//��������¼������
	map<int, vector<string>> m_Record;

	//��ʾ�����¼
	void showRecord();

	//����ļ�
	void clearRecord();

	//��Ա����
	//�����һ�ֱ���ѡ������
	vector<int> v1;

	//�����һ�ֽ���ѡ�ֱ������
	vector<int> v2;

	//ʤ��ǰ����ѡ������
	vector<int> vVictory;

	//��ű�����Ӧѡ������
	map<int, Speaker> m_Speaker;

	//��ű�������
	int m_index;

};