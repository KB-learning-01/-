#include <iostream>          //��2 5Ϊ�������λ��2*1���θ�λ��2*2��������2*3��2*4��2*5 
using namespace std;
int main()
{
	int a,n,sum;
	sum=0;
	cin>>a>>n;             //�������  a �ʹ���n 
	for (int i=1;i<=n;i++)
	{
		sum=sum+a*i;      //�ۼӵ�ǰλ������˻� 
		sum=sum*10;      //��λ 
	}
	cout<<sum/10;          //�˻ض����һλ 
	return 0;
}
