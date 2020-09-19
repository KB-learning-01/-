#include <iostream>
#include <windows.h>
#include <cmath>
#include<stdlib.h>
using namespace std;
class Point{
	private:
		int X;//横坐标 
		int Y;//纵坐标 
	public:
		Point();//初始化 
		void set(int x,int y);//设置坐标 
		void draw();//画点 
		int getX();//得到x 
		int getY();//得到y 
		friend float myDistance(Point a,Point b);//距离 
		friend void rectangle(Point a,Point b,bool flagd,bool flagr);//画矩形 
};
Point::Point()
{
	this->X=0;
	this->Y=0;
}
void Point::set(int x,int y)
{
	this->X=x;
	this->Y=y;
}
void Point::draw()
{
	HANDLE hd;
	COORD pos;
	pos.X = this->X;
	pos.Y = this->Y;
	hd = GetStdHandle(STD_OUTPUT_HANDLE);	/*获取标准输出的句柄*/ 
	SetConsoleCursorPosition(hd, pos);		/*设置控制台光标输出的位置*/
	cout << "*";
}
int Point::getX()
{
	return this->X;
}
int Point::getY()
{
	return this->Y;
}
float myDistance(Point a,Point b)
{
	return (sqrt(pow(a.getX()-b.getX(),2)+pow(a.getY()-b.getY(),2)));
}
void rectangle(Point a,Point b,bool flagd,bool flagr)
{
	if ((a.getX()<b.getX())&&(a.getY()<b.getY())) {
		a.draw();
		Point tmp;
		//向下递归 
		if (flagd==true){
		tmp.set(a.getX()+1,a.getY());
		rectangle(tmp,b,true,false);}
		//向右递归 
		if (flagr==true){
		tmp.set(a.getX(),a.getY()+1);
		rectangle(tmp,b,false,true);}
	}
	//画最下边 
	if ((a.getX()<b.getX())&&(a.getY()==b.getY())) {
		a.draw();
		Point tmp;
		tmp.set(a.getX()+1,a.getY());
		rectangle(tmp,b,false,true);
	}
	//画最右边 
	if ((a.getX()==b.getX())&&(a.getY()<b.getY())) {
		a.draw();
		Point tmp;
		tmp.set(a.getX(),a.getY()+1);
		rectangle(tmp,b,true,false);
	}
	if ((a.getX()==b.getX())&&(a.getY()==b.getY())) {
		a.draw();
	}
	return ;
}
int main()
{
	Point p;
	int a,b;
	cin>>a>>b;
	p.set(a,b);
	system("cls");
	p.draw();
	cout<<endl<<"X="<<p.getX()<<" Y="<<p.getY()<<endl;
	system("pause");
	Point q;
	cin>>a>>b;
	q.set(a,b);
	cout<<"myDistance="<<myDistance(p,q);
	system("pause");
	system("cls");
	rectangle(p,q,true,true);	
	return 0;
}
