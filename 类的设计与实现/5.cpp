#include <iostream>
using namespace std;
int MAXN=5000;//MAXN表示数组大小
class IntZhan//IntZhan类，包含一个指向数组的指针，一个指向栈顶的指针
{
	private:
		int *p,*top;
	public:
		//构造函数
		IntZhan();
		//push函数
		void push(int n);
		//get函数
		int get();
		//pop函数
		void pop();
		//print函数
		void print();
};
//构造函数 
IntZhan::IntZhan()
{
	//初始化数组大小
	p=new int[MAXN];
	//top指向栈顶
	top=p;
}
//push函数 
void IntZhan::push(int n)
{
	//栈达到最大值时，栈大小拓展为三倍 
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
	//推入数据，更新top 
	if (top==p) *this->p=n;
	else *this->top=n;
	top++;
}
//get函数 
int IntZhan::get()
{
	return *this->top-1;
}
//pop函数 
void IntZhan::pop()
{
	MAXN= 0 >=(this->top - this->p) ? 1 : (this->top) - (this->p);//重新统计栈内已有数据数-1 
	//作为中间栈，存储p内数据 
	int *temp=new int[MAXN];
	for (int i=0; i<MAXN; i++)
	{
		temp[i]=this->p[i];
	}
	//释放p的空间 
	delete[] this->p;
	//重新申请p的大小 
	this->p=new int[MAXN];
	//p复原同时去除原栈顶 
	for (int i=0; i<MAXN; i++)
	{
		this->p[i]=temp[i];
	}
	//top指向新栈顶 
	this->top=this->p+MAXN-1;
	//释放temp 
	delete[] temp;
}
//print函数 
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
