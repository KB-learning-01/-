#include <iostream>
using namespace std;
int Goldbach(int x)
{
	int array[x/2];
	int j=1,n=1,m=1;                //j����������������  n��m�����ж� 
	
	
	for (int i=3;i<=x-3;i+=2)       //������2��x-3
	{
		for (int k=2;k<=i-1;k++)    //������2��i 
			if (i%k==0) m=0;       //�ж��Ƿ���i������ 
		if (m==1) {
			array[j]=i;
			j++;
		}
		m=1;
	}
	
	n=0;
	m=0;


	for (int i=3;i<=x/2;i+=2)        //��3��ʼѰ������������� 
	{
		
		
		for (int k=1;k<=j-1;k++)    //�ж�i�Ƿ�����������array�� 
		 if (i==array[k]) {
		 	m=1;
		 	break;
		 }
		 
		 
		 
		for (int k=1;k<=j-1;k++)
		 if ((x-i)==array[k]) {
		 	n=1;
		 	break;
		 }
		 
		 
		if ((m==1)&&(n==1)) cout<<x<<'='<<i<<'+'<<x-i<<endl;
		m=0,n=0;
	}
	return 0;
}
int main()
{
	int number;  
	cin>>number; 
	Goldbach(number);  
	return 0;
}
