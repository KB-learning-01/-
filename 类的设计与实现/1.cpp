#include <iostream>
using namespace std;
bool jud(int,int,int,bool);
class Date
{
	private:
		int day;//��
		int month;//��
		int year;//��
	public:
		void input();//�������ں���
		void delay();//������һ�ĺ���
		Date():day(0),month(0),year(0) {} //���캯������ʼ��Ϊ0 0 0
		friend ostream &operator<<(ostream &out,Date a)//����������������cout<<a
		{
			out<<a.day<<"/"<<a.month<<"/"<<a.year;//������/��/�ꡱ��ʽ���
			return out;
		}
};
int main()
{
	Date a;

	//�����ʼ����
	a.input();
	cout<<"�����������Ϊ: "<<a<<"\n";

	//���������һ��
	a.delay();
	cout<<"������һ����: "<<a<<endl;

	//���ں��ƶ���
	cout<<"�������������: ";
	int n;
	cin>>n;
	for (int i=1; i<n; i++)
	{
		a.delay();
	}
	cout<<"���ڵ�������: "<<a<<endl;

	//��������
	cout<<"��Ҳ������������,��ʽ���£�"<<endl;
	a.input();
	cout<<"�����������Ϊ�� "<<a<<endl;


	return 0;
}

//�������������
void Date::input()
{
	cout<<"���������ڣ�����-��-���ʽ���Կո������"<<endl; 
	int a,b,c;//a,b,c���δ��������� 
	cin>>a>>b>>c;//���������� 
	while (jud(a,b,c,true)!=true)//������������������������ 
	{
		cout<<"���������룺"<<endl;
		cin>>a>>b>>c;
	}
	//���������� 
	day=a; 
	month=b;
	year=c;
	return ;
}
//���ں���һ��
void Date::delay()
{
	//������һ 
	this->day++; 
	//�������һ�������𲻴��ڣ�����Ƿ���ĩ 
	if (jud(this->day,this->month,this->year,false)==false)
	{
		this->day=1;
		this->month++;
		//����Բ����ڣ�����Ƿ���ĩ 
		if (jud(this->day,this->month,this->year,false)==false)
		{
			this->month=1;
			this->year++;
		}
	}
}

//�ж������Ƿ���� 
bool jud(int a,int b,int c,bool flag)//a,b,c�Դ˱�ʾ������ 
{									//flagΪ��ʱ������Ҫ������ڴ�����ʾ��Ϣ��Ϊ��ʱ����Ҫ 
	//�ж������Ƿ���� 
	if ((a>31)||(a<0))
	{
		if (flag==true)
			cout<<"The day is wrong!Pleas enter the date again:\n";
		return false;
	}
	//�ж��·��Ƿ���� 
	if ((b<0)||(b>12))
	{
		if (flag==true)
			cout<<"The month is wrong!Pleas enter the date again:\n";
		return false;
	}
	//�ж����ں��·��Ƿ�ƥ�� 
	switch (b)
	{
		//���� 
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
		{
			if (a<=31) return true;
			break;
		}
		//С�� 
		case 4:
		case 6:
		case 9:
		case 11:
		{
			if (a<=30) return true;
			break;
		}
		//ƽ���� 
		case 2:
		{
			if ((((c%4!=0)&&(a<=28))||((c%100==0)&&(c%400!=0)&&(a<=28)))||((((c%4==0)&&(4%100!=0))||(c%400==0))&&(a<=29))) return true;
		}
	}
	if (flag==true)
		cout<<"The day is wrong!Pleas enter the date again:\n";
	return false;
}
