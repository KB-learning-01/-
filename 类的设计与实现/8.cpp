/*
ģ����ʵ�е������˻���
���ݰ������˻���ţ��˻����룬�˻��������У��������ڣ�
		 ������ϸ(�������͡����׽����˻����)��Ϊ��㣬������ϸ����Ϊ����� 
		 ��������Ϣ���������Ա𡢹�����ְҵ��ס���ػ��߹�����λ��ַ����ϵ�绰�����֤���������֤���ļ������ࡢ�����֤����Ч���� ��
���ܰ�������������������Ǯ��ȡǮ��ת�ˣ�֧������ӡ�굥���鿴��Ϣ 
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
		output<<"����:"<<a.name<<"\n�Ա�:"<<a.sex<<"\n����:"<<a.nation
			  <<"\nְҵ:"<<a.occupation<<"\n��ַ:"<<a.address<<"\n��ϵ��ʽ:" <<a.tel
			  <<"\n���֤���������֤���ļ������ࣺ"<<a.credentials_type<<"\n֤�����룺"<<a.credentials_num
			  <<"\n֤����Ч��:"<<a.credentials_dates<<endl;
		return output;
	}
};

class account
{
	private:
		string name_users;//���
		string PassWord;//����
		int surplus;//���
		string Bank_Opening;//������
		string Date_Opened;//��������
		transaction *details;//������ϸ��֧��10000� 
		owner information;//��������Ϣ
		string test_num(string str);//��ȫ����λ 
		void record(string str,int a);//��¼��Ϣ 
	public:
		account();//���캯�� 
		account(string PassWord1,int surplus1,string Bank_Opening1,string Date_Opened1,transaction details1,owner information1);//�����˻��ڲ� 
		account creat();//�����˻���� 
		friend void cancel(account*);//���� 
		void save(int a);//��� 
		void withdrew(int a);//ȡ�� 
		void pay(string str,int a);//֧�� 
		void print();//��ӡ�굥 
		void dispaly();//�����Ϣ 
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
	//��ʼ�� 
	fill(data,data+3,"");
}

owner::owner(int a)
{
	cout<<"\n�����뿪����������"; 
	cin>>name;
	cout<<"\n�����뿪�����Ա�"; 
	cin>>sex;
	cout<<"\n�����뿪���˹�����"; 
	cin>>nation; 
	cout<<"\n�����뿪����ְҵ��"; 
	cin>>occupation;
	cout<<"\n�����뿪����סַ��"; 
	cin>>address;
	cout<<"\n�����뿪������ϵ��ʽ��"; 
	cin>>tel;
	cout<<"\n������֤�����ࣺ"; 
	cin>>credentials_type;
	cout<<"\n������֤�����룺"; 
	cin>>credentials_num;
	cout<<"\n������֤����Ч���ޣ�"; 
	cin>>credentials_dates;
}

owner::owner()
{
	//��ʼ�� 
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
//��ȫ����λ
string account::test_num(string str)
{
	int a[15];
	int place=0;
	//��һ�� 
	for (int i=0; i<18; i++)
	{
		if (str[i]==' ') continue;
		a[place++]=str[i]-'0';
	}
	//�ڶ��� 
	int num=0;
	for (int i=0; i<15; i+=2)
	{
		num+=(a[i]*2)/10+(a[i]*2)%10;
	}
	//������ 
	num=abs(num/100+(num/10)%10+(num%10));
	if (num%10==0) num=0;
	else num=10-(num%10);
	str=num+'0';
	return str;
}
//�����˻����
account account::creat()
{
	string PassWord1;
	int surplus1;
	string Bank_Opening1;
	string Date_Opened1;
	cout<<"\n���������룺"; 
	cin>>PassWord1;
	cout<<"\n���������"; 
	cin>>surplus1;
	cout<<"\n�����뿪���У�"; 
	cin>>Bank_Opening1;
	cout<<"\n�����뿪�����ڣ�"; 
	cin>>Date_Opened1;
	transaction details1;
	owner information(1);
	//�����˻��ڲ� 
	account a(PassWord1,surplus1,Bank_Opening1,Date_Opened1,details1,information);
	return a;
}
//���� 
void cancel(account *p)
{
	p->record("����",0);
	delete p;
	cout<<"�����ɹ�";
}
//��� 
void account::save(int a)
{
	this->surplus+=a;
	this->record("���",a);
}
//ȡ�� 
void account::withdrew(int a)
{
	this->surplus-=a;
	this->record("ȡ��",a);
}
//��¼��Ϣ 
void account::record(string str,int a)
{
	//����details[]�ҵ�δ���� 
	int i=0;
	while ((this->details[i].data[0]!="")&&(this->details[i].data[1]!="")&&(this->details[i].data[2]!=""))i++;
	//���뽻������ 
	this->details[i].data[0]=str;
	//���뽻�׽�� 
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
	this->details[i].data[1]+="Ԫ\t��";
	this->details[i].data[2]="";
	//�����˻���� 
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
	this->details[i].data[2]+="Ԫ";
} 
//֧�� 
void account::pay(string str,int a)
{
	this->surplus-=a;
	this->record("��"+str+"����",a);
}
//��ӡ�굥 
void account::print()
{
		cout<<"�������� \t���׽�� \t�˻���� "<<endl; 
		int i=0;
	while ((this->details[i].data[0]!="")&&(this->details[i].data[1]!="")&&(this->details[i].data[2]!=""))
	{
		cout<<this->details[i].data[0]<<"\t"<<this->details[i].data[1]<<this->details[i].data[2]<<endl;
		i++;
	}
} 
//�鿴��Ϣ 
void account::dispaly()
{	
cout<<"���ţ�"<<this->name_users<<endl;
cout<<this->information<<endl;
this->print();
} 
//������ 
int main()
{
	//��� 
	Erial_Number="6227 6123 4567 8901";
	account *zhanghu;
	zhanghu=new account;
	*zhanghu=zhanghu->creat();
	cout<<endl; 
	for (int i=1;i<3;i++)
	{ 
	int a;
	cout<<"���������";
	cin>>a;
	zhanghu->save(a);
	cout<<"������ȡ���"; 
	cin>>a;
	zhanghu->withdrew(a);
	string str;
	cout<<"������ת�˶���:";
	cin>>str;
	cout<<"������ת�˽��:";
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
