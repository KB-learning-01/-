#include <iostream>
using namespace std;
int main()
{
	char c;
	int a,s,d,o;
	a=0;s=0;d=0;o=0;
	while (c=getchar())
	{
		if (c=='\n') break;
		if (( (c>=65) && (c<=90) ) || ( (c>=97) && (c<=122) ))  a++;
		   else  if ((c>=48)&&(c<=57)) d++;
		           else if (c==32) s++;
		                else o++;	                
	}
	cout<<"alpha:"<<a<<endl
        <<"space:"<<s<<endl
        <<"digit:"<<d<<endl
        <<"other:"<<o<<endl;
     return 0;
}
