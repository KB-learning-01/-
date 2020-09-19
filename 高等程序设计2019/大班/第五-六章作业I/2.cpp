#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int a[10]={0};
	void in(int*);
	void deal(int*);
	void out(int*);
	in(a);
	deal(a);
	out(a);
	return 0;
}
void in(int *a)
{
	for (int i=0;i<10;i++){
	cin>>a[i];//cout<<a[i]<<' ';
}//cout<<endl;
}
void deal(int *a)
{
	int temp1=a[0],temp2=a[0],min=0,max=0;
	for (int i=1;i<10;i++)
	{
		if (a[i]>temp1) {temp1=a[i];max=i;
	//	cout<<"temp1="<<temp1<<" max="<<max<<endl;
		}
		else if (a[i]<temp2) {temp2=a[i];min=i;
	//	cout<<"temp2="<<temp2<<" min="<<min<<endl;
		}
	}
	if ((max==0)&&(min==9)) {
		swap(a[0],a[9]);goto label1;
	}
	int x;
	x=a[9];a[9]=a[max];a[max]=x;
	x=a[0];a[0]=a[min];a[min]=x;
	label1:;
}
void out(int *a)
{
	for (int i=0;i<9;i++)
	cout<<a[i]<<' ';
	cout<<a[9];
}
