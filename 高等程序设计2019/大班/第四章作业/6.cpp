#include <iostream>
using namespace std;
int isHuiwen(int x)
{
	if (x<0) {
		cout<<"false";
		return 0;
	}
	int a[100];
	for (int i=0;i<=99;i++)
	a[i]=0;                            //定义一个数组用于存放数的每一位 ，并初始化 
	int n=x;  						  //为了方便用1~n表示最高位到最低位 
	int num=1;                       //计数有多少位 
	while (n/10!=0)                  //获得num-1位 
	{
		a[num]=n%10;
		n=n/10;
		num++;
	}
	a[num]=n;                       //补上最后一位 
	int biao=0;                     //标记是否有不相等的位，先假设均相等 
	for (int i=1;i<=num/2;i++)      //从最高位到中间位的前一位 
	{
		if (a[i]!=a[num+1-i]) {
			biao=1;
			break;
		}                           //判断是否回文 
	}
	if ((num==1)||(biao==0)) cout<<"true";   //若有个位数或标记符=0则输出true 
	else cout<<"false";
	return 0;
}
int main()
{	
	int number;  
	cin >> number; 
    isHuiwen(number);  
	return 0; 
}


//void isHuiwen(int x)
//{
//	int a[6];
//	int n=x,i=0;
//	for (int j=0;j<=5;j++)
//	a[j]=0;
//	while (n/10!=0)
//	{
//		a[i]=n%10;
//		n=n/10;
//		i++;
//	}
//	a[i]=n;
//	n=0;
//	i++;
////	cout<<a[0]<<' '<<a[1];
//	for (int j=0;j<=(i)/2-1;j++)
//	{
////		cout<<a[j]<<' '<<a[i-j]<<endl;
////		cout<<n<<endl;
//		if (a[j]!=a[i-j]) 
//		{
//			n=1;
//			break;	
//		}
//	}
//	if ((i==0)||(n==0)) cout<<"true";
//	else cout<<"false";
//}
