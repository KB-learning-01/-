#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	char a[50]={' '};
	int i=0;
	while (a[i]=getchar())
	{
		if (a[i]=='\n') {i--;break;}
		else if (a[i]==' ') {i--;}
		i++;
	}
	sort(a,a+i+1);
//	for (int k=0;k<i;k++)
//	cout<<a[k]<<' ';
	int m=0;
	while (a[m]=='0')
	{m++;}
	if (m!=0) cout<<a[m];
	for (int j=0;j<=i;j++)
	{if ((j==m)&&(m!=0)) continue;cout<<a[j];}
	return 0;
}
