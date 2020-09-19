#include <bits/stdc++.h>
using namespace std;
int hcf(int n,int m)
{
	int x=min(m,n);
	for (int i=x;i>=1;i--)
	{
		if ((m%i==0)&&(n%i==0)) {
			return i;
		}
	}
}
int lcd(int n,int m)
{
	int x=max(m,n);
	for (int i=x;;i++)
	{
		if ((i%m==0)&&(i%n==0)) {
			return i;
		}
	}
}
int main()
{
	int n,m;  
    cin>>n>>m; 
    cout<<"H.C.F="<<hcf(n,m)<<endl;  
    cout<<"L.C.D="<<lcd(n,m); 
	return 0;
}
