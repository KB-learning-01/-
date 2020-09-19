#include<windows.h>	/*包含的所调用库函数的头文件*/

#include <iostream>

using namespace std;

/*

*function: 在控制台指定的位置输出字符串

*参数：startX、startY为控制台的X，Y坐标 

*/ 

void printStr(int startX, int startY)

{

	HANDLE hd;

	COORD pos;

	

	pos.X = startX;

	pos.Y = startY;

	hd = GetStdHandle(STD_OUTPUT_HANDLE);	/*获取标准输出的句柄*/ 

	SetConsoleCursorPosition(hd, pos);		/*设置控制台光标输出的位置*/

	cout << "*";

}



int main( )

{

	printStr(1,1);

	printStr(5,4);

	return 0;

}
