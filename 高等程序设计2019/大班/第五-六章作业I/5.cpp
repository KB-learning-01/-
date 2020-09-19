#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int a[19][19]={0};
	int n;
	cin>>n;
	for (int i=0;i<n;i++)
	a[i][0]=1;
	for (int i=1;i<n;i++)
	for (int j=1;j<=i;j++)
	a[i][j]=a[i-1][j-1]+a[i-1][j];
	for (int i=0;i<n;i++)
	{
	for (int j=0;j<i;j++)
	{cout<<left<<setw(5)<<a[i][j]<<setfill(' ');
	}cout<<left<<setw(5)<<a[i][i]<<setfill(' ')<<endl;
	}
	return 0;
}
