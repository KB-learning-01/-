#include <iostream>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int a[n][m]={0};
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
		{
			cin>>a[i][j];	
		}
	}
	
	int temp1=-1,temp2=-1,x,y;
	bool label1=true,label2=true,The_end=false;
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<m;j++)
		{
			if (a[i][j]>temp1) {
				temp1=a[i][j];
				x=j;
			}else if (a[i][j]==temp1) {
			label1=false;	
			}
			for (int k=0;k<n;k++)
			{
				if (a[k][x]>temp2) {
					temp2=a[i][j];
					y=k;
			}
			}
			if ((y==i)&&(temp1==temp2)) The_end=true;
		}	
	}
	if (The_end==true) cout<<temp1;
	else cout<<"It does not exist!";
	return 0;
}
