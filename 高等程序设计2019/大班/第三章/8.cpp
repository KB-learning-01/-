#include <iostream>          //以2 5为例，最高位是2*1；次高位是2*2；依次是2*3；2*4；2*5 
using namespace std;
int main()
{
	int a,n,sum;
	sum=0;
	cin>>a>>n;             //读入底数  a 和次数n 
	for (int i=1;i<=n;i++)
	{
		sum=sum+a*i;      //累加当前位与底数乘积 
		sum=sum*10;      //进位 
	}
	cout<<sum/10;          //退回多进的一位 
	return 0;
}
