#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
/*
void copy(int*A,int*B,int n) {
	for (int i=0; i<n; i++)
		B[i]=A[i];
}

void release(int *A,int n) {
	for (int i=0; i<n; i++)
		A[i]=0;
}

int num(int*A,int n,int number)
{
	for (int i=0;i<n;i++)
	i
	return number;
}*/

int main() {
	int n;
	cin>>n;
	int a[3][n]; 					//��һ�д�ɼ��� �ڶ��д������� �����д�ͬ�ָ���
	memset(a, 0, sizeof (a));
	for (int i=0; i<n; i++)  {
		cin>>a[0][i];
	}

	/*	for (int i=0; i<n; i++)  {
			cout<<a[0][i]<<' ';
		}cout<<endl;
	*/
	for (int i=0; i<n; i++) {    					//ͳ��ͬ��
		if (a[2][i]==0) {      //���������ͬ��û��ͳ��ʱ
			//	copy(a[0],b,n);
			a[2][i]=count(a[0],a[0]+n,a[0][i]);
		}
	}

	/*		for (int i=0; i<n; i++)  {
				cout<<a[2][i]<<' ';
			}
			cout<<endl;
	*/
	int max,rank=1,sum=0;							//��ʼ����max��¼��ǰ�е���߷�
	while(sum<=n-1) {					//rank������j����ѭ���ļ�����
		max=*max_element(a[0],a[0]+n);
		for (int j=0; j<n; j++)
			if (a[0][j]==max) {					//������������߷֣�
				a[0][j]=-1;						//����˵ĳɼ������
				a[1][j]=rank;					//����¼����
				//	place=j;
				sum++;
				//cout<<a[0][j]<<" "<<a[1][j]<<endl;
			}
		rank++;							//������Ϊͬ�ֲ���������
	}

	for (int i=0; i<n; i++) {
		cout<<a[1][i]<<' ';
	}
	return 0;
}

