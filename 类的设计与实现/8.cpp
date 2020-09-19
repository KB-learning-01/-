/*
模拟现实中的银行账户。
内容包括：账户编号，账户密码，账户余额，开户行，开户日期，
		 交易明细(交易类型、交易金额和账户余额)（为简便，交易明细缩减为此三项） 
		 开户人信息（姓名、性别、国籍、职业、住所地或者工作单位地址、联系电话、身份证件或者身份证明文件的种类、号码和证件有效期限 ）
功能包括：开户，销户，存钱，取钱，转账，支付，打印详单，查看信息 
*/
#include <iostream>
#include <cmath>
#include <string>
#include <cmath>
using namespace std;
const int MAXN=10000;
static string Erial_Number;
struct transaction
{
	string data[3];
	transaction();
};

struct owner
{
	string name;
	string sex;
	string nation;
	string occupation;
	string address;
	string tel;
	string credentials_type;
	string credentials_num;
	string credentials_dates;
	owner(int a);
	owner();
	friend ostream &operator <<(ostream &output,const owner a)
	{
		output<<"姓名:"<<a.name<<"\n性别:"<<a.sex<<"\n国籍:"<<a.nation
			  <<"\n职业:"<<a.occupation<<"\n地址:"<<a.address<<"\n联系方式:" <<a.tel
			  <<"\n身份证件或者身份证明文件的种类："<<a.credentials_type<<"\n证件号码："<<a.credentials_num
			  <<"\n证件有效期:"<<a.credentials_dates<<endl;
		return output;
	}
};

class account
{
	private:
		string name_users;//编号
		string PassWord;//密码
		int surplus;//余额
		string Bank_Opening;//开户行
		string Date_Opened;//开户日期
		transaction *details;//交易明细（支持10000项） 
		owner information;//开户人信息
		string test_num(string str);//补全测试位 
		void record(string str,int a);//记录信息 
	public:
		account();//构造函数 
		account(string PassWord1,int surplus1,string Bank_Opening1,string Date_Opened1,transaction details1,owner information1);//创建账户内层 
		account creat();//创建账户表层 
		friend void cancel(account*);//销户 
		void save(int a);//存款 
		void withdrew(int a);//取款 
		void pay(string str,int a);//支付 
		void print();//打印详单 
		void dispaly();//浏览信息 
};

account::account()
{
	//details
	this->details=new transaction[MAXN];
}

account::account(string PassWord1,int surplus1,string Bank_Opening1,string Date_Opened1,transaction details1,owner information1)
{ 
	//PassWord
	this->PassWord=PassWord1;
	//surplus
	this->surplus=surplus1;
	//Bank_Opening
	this->Bank_Opening=Bank_Opening1;
	//Date_Opened
	this->Date_Opened=Date_Opened1;
	//details
	this->details=new transaction[MAXN];
	//information
	this->information=information1;
	//Erial_Number
	int a=0,temp=0;
	for (int i=6; i<18; i++)
	{
		if (Erial_Number[i]==' ') continue;
		a=a*10+Erial_Number[i]-'0';
	}
	string str="6227 6";
	for (int i=9; i>0; i--)
	{
		temp=a/pow(10,i);
		str+=temp+'0';
		temp=(pow(10,i));
		a=a%temp;
	}
	str+=this->test_num(str);
	Erial_Number=str;
	this->name_users=str;	
}

transaction::transaction()
{
	//初始化 
	fill(data,data+3,"");
}

owner::owner(int a)
{
	cout<<"\n请输入开户人姓名："; 
	cin>>name;
	cout<<"\n请输入开户人性别："; 
	cin>>sex;
	cout<<"\n请输入开户人国籍："; 
	cin>>nation; 
	cout<<"\n请输入开户人职业："; 
	cin>>occupation;
	cout<<"\n请输入开户人住址："; 
	cin>>address;
	cout<<"\n请输入开户人联系方式："; 
	cin>>tel;
	cout<<"\n请输入证件种类："; 
	cin>>credentials_type;
	cout<<"\n请输入证件号码："; 
	cin>>credentials_num;
	cout<<"\n请输入证件有效期限："; 
	cin>>credentials_dates;
}

owner::owner()
{
	//初始化 
	name="";
	sex="";
	nation="";
	occupation="";
	address="";
	tel="";
	credentials_num="";
	credentials_type="";
	credentials_dates="";
}
//补全测试位
string account::test_num(string str)
{
	int a[15];
	int place=0;
	//第一步 
	for (int i=0; i<18; i++)
	{
		if (str[i]==' ') continue;
		a[place++]=str[i]-'0';
	}
	//第二步 
	int num=0;
	for (int i=0; i<15; i+=2)
	{
		num+=(a[i]*2)/10+(a[i]*2)%10;
	}
	//第三步 
	num=abs(num/100+(num/10)%10+(num%10));
	if (num%10==0) num=0;
	else num=10-(num%10);
	str=num+'0';
	return str;
}
//创建账户表层
account account::creat()
{
	string PassWord1;
	int surplus1;
	string Bank_Opening1;
	string Date_Opened1;
	cout<<"\n请设置密码："; 
	cin>>PassWord1;
	cout<<"\n请输入存款金额："; 
	cin>>surplus1;
	cout<<"\n请输入开户行："; 
	cin>>Bank_Opening1;
	cout<<"\n请输入开户日期："; 
	cin>>Date_Opened1;
	transaction details1;
	owner information(1);
	//创建账户内层 
	account a(PassWord1,surplus1,Bank_Opening1,Date_Opened1,details1,information);
	return a;
}
//销户 
void cancel(account *p)
{
	p->record("销户",0);
	delete p;
	cout<<"销户成功";
}
//存款 
void account::save(int a)
{
	this->surplus+=a;
	this->record("存款",a);
}
//取款 
void account::withdrew(int a)
{
	this->surplus-=a;
	this->record("取款",a);
}
//记录信息 
void account::record(string str,int a)
{
	//遍历details[]找到未存项 
	int i=0;
	while ((this->details[i].data[0]!="")&&(this->details[i].data[1]!="")&&(this->details[i].data[2]!=""))i++;
	//存入交易类型 
	this->details[i].data[0]=str;
	//存入交易金额 
	int temp=0,num=1;
	string str1,str2;
	while (a/10!=0)
	{
		temp=a%10;
		str1=temp+'0';
		str2.insert(0,str1);
		a=a/10; 
		num++;
	}
	str2+=a+'0';
	for (int j=0;j<num;j++)
	{
		this->details[i].data[1]+=str2[num-j-1];
	}
	this->details[i].data[1]+="元\t余额：";
	this->details[i].data[2]="";
	//存入账户余额 
	temp=0;
	str1="";
	str2="";
	num=0;
	int a1=this->surplus;
	while (a1/10!=0)
	{
		temp=a1%10;
		str1=temp+'0';
		str2+=str1;
		a1=a1/10; 
		num++;
	}
	str2+=a1+'0';
	for (int j=0;j<=num;j++)
	{
		this->details[i].data[1]+=str2[num-j];
	}
	this->details[i].data[2]+="元";
} 
//支付 
void account::pay(string str,int a)
{
	this->surplus-=a;
	this->record("向"+str+"付款",a);
}
//打印详单 
void account::print()
{
		cout<<"交易类型 \t交易金额 \t账户余额 "<<endl; 
		int i=0;
	while ((this->details[i].data[0]!="")&&(this->details[i].data[1]!="")&&(this->details[i].data[2]!=""))
	{
		cout<<this->details[i].data[0]<<"\t"<<this->details[i].data[1]<<this->details[i].data[2]<<endl;
		i++;
	}
} 
//查看信息 
void account::dispaly()
{	
cout<<"卡号："<<this->name_users<<endl;
cout<<this->information<<endl;
this->print();
} 
//主函数 
int main()
{
	//编号 
	Erial_Number="6227 6123 4567 8901";
	account *zhanghu;
	zhanghu=new account;
	*zhanghu=zhanghu->creat();
	cout<<endl; 
	for (int i=1;i<3;i++)
	{ 
	int a;
	cout<<"请输入存款金额：";
	cin>>a;
	zhanghu->save(a);
	cout<<"请输入取款金额："; 
	cin>>a;
	zhanghu->withdrew(a);
	string str;
	cout<<"请输入转账对象:";
	cin>>str;
	cout<<"请输入转账金额:";
	cin>>a; 
	zhanghu->pay(str,a);
	} 
	cout<<endl;
	zhanghu->print();
	cout<<endl;
	zhanghu->dispaly();
	cout<<endl;
	cancel(zhanghu);
	return 0;
}
