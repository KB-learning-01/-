#include <iostream>
using namespace std;
int MAXN=5000;//MAXN��ʾ�����С
class IntZhan//IntZhan�࣬����һ��ָ�������ָ�룬һ��ָ��ջ����ָ��
{
	private:
		int *p,*top;
	public:
		//���캯��
		IntZhan();
		//push����
		void push(int n);
		//get����
		int get();
		//pop����
		void pop();
		//print����
		void print();
};
//���캯�� 
IntZhan::IntZhan()
{
	//��ʼ�������С
	p=new int[MAXN];
	//topָ��ջ��
	top=p;
}
//push���� 
void IntZhan::push(int n)
{
	//ջ�ﵽ���ֵʱ��ջ��С��չΪ���� 
	if (top==p+MAXN-1)
	{
		int *tmp=new int[MAXN];
		for (int i=0; i<MAXN; i++)
		{
			tmp[i]=p[i];
		}
		delete p;
		MAXN*=3;
		p=new int[MAXN];
		for (int i=0; i<MAXN/3; i++)
		{
			p[i]=tmp[i];
		}
		top=p+MAXN/3;
	}
	//�������ݣ�����top 
	if (top==p) *this->p=n;
	else *this->top=n;
	top++;
}
//get���� 
int IntZhan::get()
{
	return *this->top-1;
}
//pop���� 
void IntZhan::pop()
{
	MAXN= 0 >=(this->top - this->p) ? 1 : (this->top) - (this->p);//����ͳ��ջ������������-1 
	//��Ϊ�м�ջ���洢p������ 
	int *temp=new int[MAXN];
	for (int i=0; i<MAXN; i++)
	{
		temp[i]=this->p[i];
	}
	//�ͷ�p�Ŀռ� 
	delete[] this->p;
	//��������p�Ĵ�С 
	this->p=new int[MAXN];
	//p��ԭͬʱȥ��ԭջ�� 
	for (int i=0; i<MAXN; i++)
	{
		this->p[i]=temp[i];
	}
	//topָ����ջ�� 
	this->top=this->p+MAXN-1;
	//�ͷ�temp 
	delete[] temp;
}
//print���� 
void IntZhan::print()
{
	int *q=this->p;
	while (q<top)
	{
		cout<<*q<<" ";
		q++;
	}
}
int main()
{
	IntZhan list;
	list.push(3);
	list.push(4);
	list.push(5);
	list.push(6);
	list.push(7);
	list.push(8);
	list.push(9);
	list.push(10);
	list.push(11);
	list.push(12);
	list.print();
	cout<<endl;
	list.pop();
	list.pop();
	list.print();
	cout<<endl<<list.get();
	return 0;
}
