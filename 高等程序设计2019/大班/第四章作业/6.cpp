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
	a[i]=0;                            //����һ���������ڴ������ÿһλ ������ʼ�� 
	int n=x;  						  //Ϊ�˷�����1~n��ʾ���λ�����λ 
	int num=1;                       //�����ж���λ 
	while (n/10!=0)                  //���num-1λ 
	{
		a[num]=n%10;
		n=n/10;
		num++;
	}
	a[num]=n;                       //�������һλ 
	int biao=0;                     //����Ƿ��в���ȵ�λ���ȼ������� 
	for (int i=1;i<=num/2;i++)      //�����λ���м�λ��ǰһλ 
	{
		if (a[i]!=a[num+1-i]) {
			biao=1;
			break;
		}                           //�ж��Ƿ���� 
	}
	if ((num==1)||(biao==0)) cout<<"true";   //���и�λ�����Ƿ�=0�����true 
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
