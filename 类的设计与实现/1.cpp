#include <iostream>
using namespace std;
bool jud(int,int,int,bool);
class Date
{
	private:
		int day;//日
		int month;//月
		int year;//年
	public:
		void input();//设置日期函数
		void delay();//天数加一的函数
		Date():day(0),month(0),year(0) {} //构造函数，初始化为0 0 0
		friend ostream &operator<<(ostream &out,Date a)//重载输出运算符，简化cout<<a
		{
			out<<a.day<<"/"<<a.month<<"/"<<a.year;//按“日/月/年”格式输出
			return out;
		}
};
int main()
{
	Date a;

	//输入初始日期
	a.input();
	cout<<"您输入的日期为: "<<a<<"\n";

	//日期向后推一天
	a.delay();
	cout<<"它的下一天是: "<<a<<endl;

	//日期后推多天
	cout<<"请输入后推天数: ";
	int n;
	cin>>n;
	for (int i=1; i<n; i++)
	{
		a.delay();
	}
	cout<<"现在的日期是: "<<a<<endl;

	//设置日期
	cout<<"您也可以设置日期,格式如下："<<endl;
	a.input();
	cout<<"您输入的日期为： "<<a<<endl;


	return 0;
}

//输入和设置日期
void Date::input()
{
	cout<<"请输入日期，按日-月-年格式，以空格隔开："<<endl; 
	int a,b,c;//a,b,c依次代表日月年 
	cin>>a>>b>>c;//读入日月年 
	while (jud(a,b,c,true)!=true)//如果日期输入错误则重新输入 
	{
		cout<<"请重新输入："<<endl;
		cin>>a>>b>>c;
	}
	//储存日月年 
	day=a; 
	month=b;
	year=c;
	return ;
}
//日期后推一天
void Date::delay()
{
	//天数加一 
	this->day++; 
	//如果后推一天后的日起不存在，检测是否到月末 
	if (jud(this->day,this->month,this->year,false)==false)
	{
		this->day=1;
		this->month++;
		//如果仍不存在，检测是否到年末 
		if (jud(this->day,this->month,this->year,false)==false)
		{
			this->month=1;
			this->year++;
		}
	}
}

//判断日期是否合理 
bool jud(int a,int b,int c,bool flag)//a,b,c以此表示日月年 
{									//flag为真时代表需要输出日期错误提示信息，为假时不需要 
	//判断天数是否合理 
	if ((a>31)||(a<0))
	{
		if (flag==true)
			cout<<"The day is wrong!Pleas enter the date again:\n";
		return false;
	}
	//判断月份是否合理 
	if ((b<0)||(b>12))
	{
		if (flag==true)
			cout<<"The month is wrong!Pleas enter the date again:\n";
		return false;
	}
	//判断日期和月份是否匹配 
	switch (b)
	{
		//大月 
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
		//小月 
		case 4:
		case 6:
		case 9:
		case 11:
		{
			if (a<=30) return true;
			break;
		}
		//平闰月 
		case 2:
		{
			if ((((c%4!=0)&&(a<=28))||((c%100==0)&&(c%400!=0)&&(a<=28)))||((((c%4==0)&&(4%100!=0))||(c%400==0))&&(a<=29))) return true;
		}
	}
	if (flag==true)
		cout<<"The day is wrong!Pleas enter the date again:\n";
	return false;
}
