#include <iostream>
using namespace std;
int InCage(int n,int m)
{
	if (((m-2*n)%2==0)&&((4*n-m)%2==0)&&(m-2*n>=0)&&(4*n-m>=0)) cout<<(4*n-m)/2<<' '<<(m-2*n)/2;
	else cout<<"No answer";
}
int main()  
{  
   int heads,legs;  
   cin >> heads>>legs; 
   InCage(heads,legs);  
   return 0;  

} 
