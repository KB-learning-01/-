#include <iostream>
#define for(i,j,n)  for(i=j;i<=n;i++)
using namespace std;
int main()
{
	int m=0,n=0,a[22]={0},i=0;
	cin>>m>>n;
	a[0]=0,a[1]=1;
	for (i,2,21) a[i]=a[i-1]+a[i-2];
	for (i,1,21) if ((a[i]>=m)&&(a[i]<=n)) cout<<a[i]<<' ';
//	for (i,m,n) cout<<a[i]<<' ';
	return 0;
}

