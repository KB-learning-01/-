#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
/*
int maxx(int **p,int*q,const int n,int j,int*m) //����a�����ֵλ�����飬һ�е��������ڼ��� ,����������
{										   //�����������ֵ��λ�ø�λ������
	int x=p[0][j],place=0;
	for (int i=0;i<n;i++)
	{
		if (p[i][j]>x) {
			x=p[i][j];
			fill(p[0],p[0]+sizeof(p)/sizeof(int),0);
			q[place]=i;
		}else if (p[i][j]==x){
			q[place++]=i;
		}
	}
	*m=--place;
	return p[q[--k]][j];
}

bool compare(int **p,int num,const int m,int i) //����a�����ֵ��һ�е���������i��������
{
	int x=p[i][0];
	for (int j=0;j<m;i++)
	{
		if (p[i][j]>x) {
			x=p[i][j];
		}
	}
	if (x==num) return true;
	else return false;
}
*/
int main() {
	int n,m,i,j;
	cin>>n>>m;

	int a[n][m];//������ֵ�Ķ�ά����
	fill(a[0],a[0]+sizeof(a)/sizeof(int),0);
	for (i=0; i<n; i++)
		for (j=0; j<m; j++)
			cin>>a[i][j];
/*�������*/	for (i=0; i<n; i++) {
		for (j=0; j<m; j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}cout<<endl; 

	int b[n];//����λ�õĶ�ά����
	memset(b,0,n*4);
/*�������*/	for (j=0; j<m; j++)
		cout<<b[j]<<" ";
	cout<<endl;

	bool label=false;   //����Ƿ��а���
	int hero=0,num=0,k=0;//hero������ֵ  num����ͬ����ֵ�ø���  k����ͬ����λ�������ָ��

	int x=a[i][0],k=0;//x:�Ƚϵ��м������k����ָ�� 
	for (j=0; j<m; j++) {
		x=a[0][j];//x�����ҳ���ǰ�����ֵ��place��¼λ��

		for (int i=1; i<n; i++) {   //�ҳ��������hero���������ͬ������������¼λ�ô�������b 
			if (a[i][j]>x) {
				fill(b,b+4*m,0);
				x=a[i][j];
				k=0;
				b[k]=i;
				k++; 
			} else if (a[i][j]==x) {
				b[k]=i;
				k++;
			}
		}
		num=k-1;
		hero=a[b[num]][j];


		//	hero=maxx(a,b,n,j,&num);
		k=0;
		while ((label==false)&&(k<=num)) {	//
			x=a[b[k]][0];
			for (int j=1; j<m; j++) {
				if (a[b[k]][j]>=x) {
					x=a[b[k]][j];
				}
			}
			if ((x==hero)) {
				label=true;
			}
			k++;
		}
		if (label==true) break; 
	}
	/*
			if (compare(a,hero,m,b[k])==true) {label=true;}
			k++;

	*/


	if (label==true) cout<<hero;
	else cout<<" It does not exist!";
	return 0;
}


