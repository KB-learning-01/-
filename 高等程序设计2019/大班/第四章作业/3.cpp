#include<bits/stdc++.h> 
using namespace std;
void step(int x,char a,char b,char c)
{
	if (x==1) {
		cout<<a<<"-->"<<c<<endl;
	}
	else if (x==2) {
		cout<<a<<"-->"<<b<<endl
			<<a<<"-->"<<c<<endl
			<<b<<"-->"<<c<<endl;
	}
	else {
		step(x-1,a,c,b);
		cout<<a<<"-->"<<c<<endl;
		step(x-1,b,a,c);
	}
}
int Hanoi(int x)
{
	char A='A',B='B',C='C';    
	step(x,A,B,C);
/*
	A,B,C�������ӣ�AΪ��ʼ��BΪ���ɣ�CΪĿ�꣬n�����ӣ���С��������Ϊ1.2.3...n
	Ҫ�ѵ�n���Ƶ�Ŀ����������Ҫ��1��n-1�Ƶ������� 
	
	�������⣬��α���������� 
*/ 
}
int main()  
{
   int number;  
   cin >> number; 
   Hanoi(number);  
   return 0;  
}
