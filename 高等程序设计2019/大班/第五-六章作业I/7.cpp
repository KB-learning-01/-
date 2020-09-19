#include <iostream>
#define for(i,j,n)  for(i=j;i<n;i++)
using namespace std;
int main()
{
	int n=0,m=0,i=0;
	cin>>n>>m;
	int a[n]={0};
	for (i,0,n) cin>>a[i];
	if (m==0) {
		for (i,0,n) cout<<a[i]<<' ';
	return 0;}
	for (i,n-m,n) cout<<a[i]<<' ';
	for (i,0,n-m) cout<<a[i]<<' ';
	return 0;
}

//0 1 2 n=3 m=1
