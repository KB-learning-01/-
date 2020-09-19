#include<iostream>
using namespace std;
int main()
{
	int sum=0,a=0;
	for (int i=0;i<3;i++)
	for (int j=0;j<3;j++)
	{
	cin>>a;
	if (i==j) sum+=a;
}
	cout<<sum; 
	return 0;
}
