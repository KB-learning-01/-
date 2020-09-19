#include <iostream>
using namespace std;
void buyhouse(int n,int k)
{
	int sum=0,a=0,i=1;
	float pay=200;
	for (;i<=20;i++)
	{
		sum+=n;
		if (sum>=pay) 
		{
			a=1;
			break;
		}
		pay=pay*(1+k/100.0);
	}
	if (a==1) cout<<i<<endl;
	else cout<<"Impossible"<<endl;
}
int main()
{
	int N,K;
    cin>>N>>K; 
    buyhouse(N,K);
    return 0;
 } 
