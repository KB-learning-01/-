#include <iostream>
using namespace std;
int Sum(int x)
{
	if (x==1) return 1;
	else return Sum(x-1)+x*x;
}
int main()  
{ 
   int number;  
   cin >> number; 
   cout << Sum(number);  
   return 0;
}
