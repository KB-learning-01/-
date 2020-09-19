#include <iostream>
using namespace std;
int Factorial_causes(int x)
{
	if (x==0)  return 1;
	 else  return x*Factorial_causes(x-1);
}
int main()
{
    int a,sum;
    cin>>a;
    for (int i=1;i<=a;i++)
     sum=Factorial_causes(i)+sum;
    cout<<sum;
    return 0;
    
}
