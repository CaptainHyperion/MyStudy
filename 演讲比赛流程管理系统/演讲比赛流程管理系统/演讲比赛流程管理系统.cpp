#include<iostream>
#include<string>
#include<ctime>
#include"speechManager.h"
using namespace std;

int main()
{
	//随机数种子
	srand((unsigned int)time(NULL));
	SpeechManager sm;
	int choice = 0;//存储用户选择
	while (true)
	{
		sm.show_Menu();

		cout << "请输入您的选项" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:	//开始比赛
			sm.startSpeech();
			break;
			
		case 2://查看往届记录
			sm.showRecord();
			break;

		case 3://清空记录
			sm.clearRecord();
			break;
	
		case 0://退出
			sm.exitSystem();
			break;
		default:
			system("cls");//清屏
			break;
		}
	}
	
	system("pause");
	return 0;
}