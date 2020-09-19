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
	A,B,C三根柱子，A为初始，B为过渡，C为目标，n个盘子，从小到大依次为1.2.3...n
	要把第n个移到目标柱，就需要把1到n-1移到过渡柱 
	
	现在问题，如何变幻三根柱子 
*/ 
}
int main()  
{
   int number;  
   cin >> number; 
   Hanoi(number);  
   return 0;  
}
