#include <iostream>
using namespace std;
static int title=0;//��¼Ŀ¼�� 
static int number=0;//��¼��Ŀ�� 
//Menu�࣬�����˵���Ŀ����Լ����ݣ���ſ��Լ�
class Menu
{
	protected:
		//������
		int number;//���
		string name;//����
		//ָ����
		Menu *next;//ָ����һ��
	public:
		//���캯��
		Menu();
		~Menu();
		//������һ��
		void SetNext(Menu *p)
		{
			this->next=p;
		}
		//�����һ���ĵ�ַ
		Menu *GetNext()
		{
			return this->next;
		}
		//��������
		void SetName()
		{
			cin>>this->name;
		}
		//��ñ��
		int Getnum()
		{
			return number;
		}
		//�������
		string Getname()
		{
			return name;
		}
};
//title1�࣬����ָ��˵���Ŀ��ָ���Լ���һ��Ŀ¼��ָ��
class title1: public Menu
{
	private:
		//������
		Menu *son;//ָ��˵���Ŀ
		//ָ����
		title1 *next_t;//ָ����һ���˵�
	public:
		//���캯��
		title1();
		//��������
		~title1();
		//�����˵�
		title1* Creat();
		//������Ŀ����
		void Input(int n);
		//����˵�
		void Display(int a,int b);
};
//��ʼ��Menu 
Menu::Menu()
{
	name="";
	number=++::number;
	next=NULL;
}
//��������
Menu::~Menu()
{
	this->next=NULL;
}
//�������� 
title1::~title1()
{
	this->son=NULL;
}
//��ʼ��title1 
title1::title1()
{ 
	::number=0;
	name="";
	number=++::title;
	next_t=NULL;
}
//����Ŀ¼ 
title1* title1::Creat()
{
	char ch=' ';
	int i=1;
	title1 *first=NULL,*prv=NULL;//ͷ�ڵ�͵�ǰ�ڵ� 
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
		p->Input(n);//������Ŀ 
		prv=p;
	}
	prv->next_t=NULL;
	return first;
}

void title1::Input(int n)
{
	cout<<"Please enter the title1 of this menu:";
	cin>>this->name;//�������� 
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
		p->SetName();//������Ŀ�� 
		prv=p;
	}
	this->son=first;
	prv->SetNext(NULL);
	return ;
}
//�����a����b��Ŀ¼ 
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
		cout<<str<<endl;//������ 
		Menu *p=son;
		//���� 
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
	cout<<"��������Ҫ�����Ŀ¼���䣬�Կո����:";
	cin>>a>>b;
	father->Display(a,b);
	return 0;
}

