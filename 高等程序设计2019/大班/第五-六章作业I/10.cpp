#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int n;
	cin>>n;
	int a[n]= {0},temp=0;
//	int sum=0;
	for (int i=0; i<n; i++) {
		cin>>a[i];
	//	if(a[i]<=0) sum++;
	}
	int max=*max_element(a,a+n);
//	if (sum==n) {
//		cout<<*max_element(a,a+n);
//		return 0;
//	}
	for (int i=0; i<n; i++) {
		temp+=a[i];
		if (temp<0) temp=0;
		else if (max<temp) max=temp;
	}
	cout<<max;
	return 0;
}
