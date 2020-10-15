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
	//构造函数
	SpeechManager();


	//展示菜单
	void show_Menu();

	//退出系统
	void exitSystem();

	//析构函数
	~SpeechManager();

	//初始化属性和容器
	void initSpeech();


	//创建选手
	void createSpeaker();

	//开始比赛 比赛整个流程控制函数
	void startSpeech();


	//抽签
	void speechDraw();

	//比赛
	void speechContest();

	//显示得分
	void showScore();


	//保存记录
	void saveRecord();

	//读取记录
	void loadRecord();

	//判断文件是否为空
	bool fileIsEmpty;

	//存放往届记录的容器
	map<int, vector<string>> m_Record;

	//显示往届记录
	void showRecord();

	//清空文件
	void clearRecord();

	//成员属性
	//保存第一轮比赛选手容器
	vector<int> v1;

	//保存第一轮晋级选手编号容器
	vector<int> v2;

	//胜出前三名选手容器
	vector<int> vVictory;

	//存放编号与对应选手容器
	map<int, Speaker> m_Speaker;

	//存放比赛轮数
	int m_index;

};