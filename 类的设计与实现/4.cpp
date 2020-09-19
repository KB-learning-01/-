#include <iostream>
using namespace std;
static int title=0;//记录目录数 
static int number=0;//记录项目数 
//Menu类，包含菜单项目编号以及内容，编号可自加
class Menu
{
	protected:
		//数据域
		int number;//编号
		string name;//内容
		//指针域
		Menu *next;//指向下一条
	public:
		//构造函数
		Menu();
		~Menu();
		//设置下一条
		void SetNext(Menu *p)
		{
			this->next=p;
		}
		//获得下一条的地址
		Menu *GetNext()
		{
			return this->next;
		}
		//设置姓名
		void SetName()
		{
			cin>>this->name;
		}
		//获得编号
		int Getnum()
		{
			return number;
		}
		//获得姓名
		string Getname()
		{
			return name;
		}
};
//title1类，包括指向菜单项目的指针以及下一个目录的指针
class title1: public Menu
{
	private:
		//数据域
		Menu *son;//指向菜单项目
		//指针域
		title1 *next_t;//指向下一个菜单
	public:
		//构造函数
		title1();
		//析构函数
		~title1();
		//创建菜单
		title1* Creat();
		//读入项目数据
		void Input(int n);
		//输出菜单
		void Display(int a,int b);
};
//初始化Menu 
Menu::Menu()
{
	name="";
	number=++::number;
	next=NULL;
}
//析构函数
Menu::~Menu()
{
	this->next=NULL;
}
//析构函数 
title1::~title1()
{
	this->son=NULL;
}
//初始化title1 
title1::title1()
{ 
	::number=0;
	name="";
	number=++::title;
	next_t=NULL;
}
//创建目录 
title1* title1::Creat()
{
	char ch=' ';
	int i=1;
	title1 *first=NULL,*prv=NULL;//头节点和当前节点 
	while (1)
	{
		title1 *p=new title1;
		if (i++==1)
		{
			first=p;
		}
		else
		{
			prv->next_t=p;
		}
		cout<<"Pleasr enter the number of the members in this menu:\nYou can enetr a \"#\" to exit:";
		cin>>ch;
		if (ch=='#') break;
		int n=ch-'0';
		p->Input(n);//读书项目 
		prv=p;
	}
	prv->next_t=NULL;
	return first;
}

void title1::Input(int n)
{
	cout<<"Please enter the title1 of this menu:";
	cin>>this->name;//读入名字 
	cout<<"Please enter the name of the inclusion separated by a space:\n";
	Menu *prv=NULL,*first=NULL;
	for (int i=1; i<=n; i++)
	{
		Menu *p=new Menu;
		if (i==1)
		{
			first=p;
		}
		else
		{
			prv->SetNext(p);
		}
		p->SetName();//读入项目名 
		prv=p;
	}
	this->son=first;
	prv->SetNext(NULL);
	return ;
}
//输出从a，到b的目录 
void title1::Display(int a,int b)
{
	title1 *q=this;
	for (int i=1; i<a; i++)
	{
		q=q->next_t;
	}
	if (b>title) b=title;
	for (int i=1; i<title; i++)
	{
		string str="****";
		str+=q->number/10+'0';
		str+=q->number%10+'0';
		str+=' '+q->name;
		str+="****";
		cout<<str<<endl;//标题行 
		Menu *p=son;
		//内容 
		while (p!=NULL)
		{
			cout<<p->Getnum()<<"\t"<<p->Getname()<<endl<<endl;
			p=p->GetNext();
		}
		cout<<"********************"<<endl<<endl;
		q=q->next_t;
	}
}

int main()
{
	title1 *father=new title1;
	title=0;
	father=father->Creat();
	int a,b;
	cout<<"请输入想要输出的目录区间，以空格隔开:";
	cin>>a>>b;
	father->Display(a,b);
	return 0;
}

