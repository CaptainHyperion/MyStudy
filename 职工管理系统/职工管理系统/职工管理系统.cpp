#include<iostream>
#include<string>
#include<fstream>
#include"workerManager.h"
using namespace std;

int main()
{
	WorkerManager wm;
	//wm.Show_Menu();

	int choice = 0;

	while (true)
	{
		wm.Show_Menu();
		cout << "����������ѡ��" << endl;

		cin >> choice;

		switch (choice)
		{
		case 0://�˳�
			wm.ExitSystem();
			break;
		case 1://����
			wm.Add_Emp();
			break;
		case 2://��ʾ
			wm.Show_Emp();
			break;
		case 3://ɾ��
			wm.Del_Emp();
			break;
		case 4://�޸�
			wm.Mod_Emp();
			break;
		case 5://����
			wm.Find_Emp();
			break;
		case 6://����
			wm.Sort_Emp();
			break;
		case 7://���
			break;
		default:
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}
