#include<windows.h>	/*�����������ÿ⺯����ͷ�ļ�*/

#include <iostream>

using namespace std;

/*

*function: �ڿ���ָ̨����λ������ַ���

*������startX��startYΪ����̨��X��Y���� 

*/ 

void printStr(int startX, int startY)

{

	HANDLE hd;

	COORD pos;

	

	pos.X = startX;

	pos.Y = startY;

	hd = GetStdHandle(STD_OUTPUT_HANDLE);	/*��ȡ��׼����ľ��*/ 

	SetConsoleCursorPosition(hd, pos);		/*���ÿ���̨��������λ��*/

	cout << "*";

}



int main( )

{

	printStr(1,1);

	printStr(5,4);

	return 0;

}
