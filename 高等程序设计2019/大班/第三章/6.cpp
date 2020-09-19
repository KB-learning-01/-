#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int a,b;
	cin>>a;
	char ch;
	for (int i=1;i<=a;i++)
	 {
	 	if (i%7==0) {cout<<i<<endl; continue;}
	 	b=i;
	 	for (int j=1;j<=5;j++)
	 	if ((b%10)==7) {cout<<i<<endl; break;}
	 	   else b=b/10;
	 }
	 return 0;
}

