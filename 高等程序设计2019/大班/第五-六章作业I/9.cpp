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
	int a[3][n]; 					//第一行存成绩， 第二行存排名， 第三行存同分个数
	memset(a, 0, sizeof (a));
	for (int i=0; i<n; i++)  {
		cin>>a[0][i];
	}

	/*	for (int i=0; i<n; i++)  {
			cout<<a[0][i]<<' ';
		}cout<<endl;
	*/
	for (int i=0; i<n; i++) {    					//统计同分
		if (a[2][i]==0) {      //当这个数的同分没有统计时
			//	copy(a[0],b,n);
			a[2][i]=count(a[0],a[0]+n,a[0][i]);
		}
	}

	/*		for (int i=0; i<n; i++)  {
				cout<<a[2][i]<<' ';
			}
			cout<<endl;
	*/
	int max,rank=1,sum=0;							//开始排名max记录当前行的最高分
	while(sum<=n-1) {					//rank排名，j用作循环的计数器
		max=*max_element(a[0],a[0]+n);
		for (int j=0; j<n; j++)
			if (a[0][j]==max) {					//如果这个人是最高分，
				a[0][j]=-1;						//这个人的成绩清除，
				a[1][j]=rank;					//将记录排名
				//	place=j;
				sum++;
				//cout<<a[0][j]<<" "<<a[1][j]<<endl;
			}
		rank++;							//补上因为同分产生的排名
	}

	for (int i=0; i<n; i++) {
		cout<<a[1][i]<<' ';
	}
	return 0;
}

