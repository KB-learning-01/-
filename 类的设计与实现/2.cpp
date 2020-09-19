#include <iostream>
using namespace std;
class time
{
	private:
		string now;//用于记录时间的字符串 
		string timee;//记录AM和PM 
	public:
		int type;//判断读入的数据是12小时制还是24小时制 
		time():now(""),timee(""),type(24) {};//构造函数 默认0:0:0 24h 
		void show();//输出 
		void change(int a);//12h与24h互相转换 
		void set();//设置时间 
		void standard();//标准化格式（补0） 
		time &operator+(const time& time1)//重载加法运算符 
		{
			//读取小时 
			int hour1=(this->now[0]-'0')*10+this->now[1]-'0';
			int hour2=(time1.now[0]-'0')*10+time1.now[1]-'0';
			//读取分钟 
			int minute1=(this->now[3]-'0')*10+this->now[4]-'0';
			int minute2=(time1.now[3]-'0')*10+time1.now[4]-'0';
			//读取秒钟 
			int second1=(this->now[6]-'0')*10+this->now[7]-'0';
			int second2=(time1.now[6]-'0')*10+time1.now[7]-'0';
			//进行累加 
			int hour=hour1+hour2;
			int minute=minute1+minute2;
			int second=second1+second2;
			//判断是否合理 
			if (second>59)
			{
				second-=60;
				minute+=1;
			}
			if (minute>59)
			{
				minute-=60;
				hour+=1;
			}
			if (hour>23)
			{
				hour-=24;
			}
			//返回值给this 
			this->now=hour/10+'0';
			this->now+=hour%10+'0';
			this->now+=":"; 
			this->now+=minute/10+'0';
			this->now+=minute%10+'0';
			this->now+=":"; 
			this->now+=second/10+'0';
			this->now+=second%10+'0';
			this->now+='\0';
			//标准化 
			this->standard();
			//转换成24小时 
			this->change(24);
			//返回值 
			return *this;
		}
};
int main()
{
	//介绍格式 
	cout<<"Please enter the system of hour and the time:"<<endl
	    <<"12 equals to 12 hours system"<<endl
	    <<"24 equals to 24 hours system"<<endl
	    <<"\nFor example:\n12\t\t24\n8:1:1 AM\t19:19:19\n"<<endl;
	time time1;


	//设置时间
	time1.set();


	//标准化为00格式
	time1.standard();


	//输出时间
	cout<<"\nnow:";
	time1.show();
	cout<<endl;
	time timing=time1;


	//时间相加
	cout<<"\n";
	time time2,time3;
	time2.set();//设置时间time2
	time2.standard();//标准化time2 
	
	time1.change(24);//time1转为24小时 
	time1.show();//输出time1 
	
	cout<<"+ ";
	time2.show();//输出time2 
	
	time3=time1+time2;//相加 
	
	cout<<"= ";
	time3.show();//输出time3 
	cout<<endl<<endl;
	
	//调整为12小时制
	cout<<"12H:\n";
	timing.change(12);
	timing.standard();
	timing.show();
	cout<<endl;
	time2.change(12);
	time2.standard();
	time2.show();
	cout<<endl;
	time3.change(12);
	time3.standard();
	time3.show();
	cout<<endl<<endl;
	
	//调整为24小时制
	cout<<"24H:\n";
	timing.change(24);
	timing.standard();
	timing.show();
	cout<<endl;
	time2.change(24);
	time2.standard();
	time2.show();
	cout<<endl;
	time3.change(24);
	time3.standard();
	time3.show();
	cout<<endl<<endl;

	return 0;
}
void time::set()
{
	cout<<"Pleas enter your time:"<<endl;
	cin>>type>>now;
	if (type==12) cin>>timee;
	now+='\0';
	return ;
}
void time::standard()
{
	int i=0,a=0;
	for (i=0; i<now.length(); i++)
	{
		if (now.at(i)!=':')
		{
			a++;
		}
		else
		{
			if (a<2)
			{
				now.insert(i-a,"0");
				i++;
			}
			a=0;
		}
	}
	if (a<=2)
	{
		now.insert(i-a,"0");
		i++;
	}
}
void time::show()
{
	cout<<now;
	if (type==12) cout<<timee;
	return ;
}
void time::change(int a)
{
	string temp="";
	int hour=(now[0]-'0')*10+now[1]-'0';
	bool flag=false;
	if (hour>=13) flag=true;
	if ((a==24)&&(type==12)&&(timee=="PM"))
	{
		hour+=12;
		temp=hour/10+'0';
		temp+=hour%10+'0';
		this->now.replace(0,2,temp);
	}
	else if ((a==12)&&(type==24)&&(flag==true))
	{
		hour-=12;
		temp=hour/10+'0';
		temp+=hour%10+'0';
		this->now.replace(0,2,temp);
		this->timee="PM";
	}
	else if ((a==12)&&(type==24)&&(flag==false))
	{
		this->timee="AM";
	}
	this->type=a;
	return ;
}

