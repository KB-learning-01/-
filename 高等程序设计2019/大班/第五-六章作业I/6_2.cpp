#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
/*
int maxx(int **p,int*q,const int n,int j,int*m) //数组a，最大值位置数组，一列的总数，第几列 ,几个最大的数
{										   //将数组内最大值的位置给位置数组
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

bool compare(int **p,int num,const int m,int i) //数组a，最大值，一行的总数，第i行内搜索
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

	int a[n][m];//储存数值的二维数组
	fill(a[0],a[0]+sizeof(a)/sizeof(int),0);
	for (i=0; i<n; i++)
		for (j=0; j<m; j++)
			cin>>a[i][j];
/*调试输出*/	for (i=0; i<n; i++) {
		for (j=0; j<m; j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}cout<<endl; 

	int b[n];//储存位置的二维数组
	memset(b,0,n*4);
/*调试输出*/	for (j=0; j<m; j++)
		cout<<b[j]<<" ";
	cout<<endl;

	bool label=false;   //标记是否有鞍点
	int hero=0,num=0,k=0;//hero：鞍点值  num：相同鞍点值得个数  k：相同鞍点位置数组的指针

	int x=a[i][0],k=0;//x:比较的中间变量，k数组指针 
	for (j=0; j<m; j++) {
		x=a[0][j];//x用来找出当前列最大值，place记录位置

		for (int i=1; i<n; i++) {   //找出最大数给hero，如果有相同的最大数，则记录位置存入数组b 
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


