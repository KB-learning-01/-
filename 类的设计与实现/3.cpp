#include <iostream>
#include <windows.h>
#include <cmath>
#include<stdlib.h>
using namespace std;
class Point{
	private:
		int X;//������ 
		int Y;//������ 
	public:
		Point();//��ʼ�� 
		void set(int x,int y);//�������� 
		void draw();//���� 
		int getX();//�õ�x 
		int getY();//�õ�y 
		friend float myDistance(Point a,Point b);//���� 
		friend void rectangle(Point a,Point b,bool flagd,bool flagr);//������ 
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
	hd = GetStdHandle(STD_OUTPUT_HANDLE);	/*��ȡ��׼����ľ��*/ 
	SetConsoleCursorPosition(hd, pos);		/*���ÿ���̨��������λ��*/
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
		//���µݹ� 
		if (flagd==true){
		tmp.set(a.getX()+1,a.getY());
		rectangle(tmp,b,true,false);}
		//���ҵݹ� 
		if (flagr==true){
		tmp.set(a.getX(),a.getY()+1);
		rectangle(tmp,b,false,true);}
	}
	//�����±� 
	if ((a.getX()<b.getX())&&(a.getY()==b.getY())) {
		a.draw();
		Point tmp;
		tmp.set(a.getX()+1,a.getY());
		rectangle(tmp,b,false,true);
	}
	//�����ұ� 
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
