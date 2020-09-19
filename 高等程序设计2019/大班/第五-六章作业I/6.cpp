#include <iostream>
#include <algorithm>
#define for(i,j,n) for (i=j;i<n;i++)
using namespace std;
int main() {
	int n=0,m=0;
	int i=0,j=0;
	int x=-1;
	int k=0,y=0;
	bool aaaa=true;
	cin>>n>>m;
	int a[n][m]= {0},b[m]= {0};
	
	for (i,0,n) for (j,0,m) cin>>a[i][j];//输入 
	
	for (j,0,m) {     //枚举各列
		aaaa=true;
			x=-1;
		for (i,0,n) {  //枚举第j列的各行
			if (a[i][j]>x) {
				x=a[i][j],y=i;
			}   //找出第j列中的最大值，并将其值给x，行数给y
		//	cout<<"x="<<x<<" y="<<y;
			for (k,0,m) b[k]=a[y][k]; //将a中第y行的数搬到b中
		}
		//	for (k,0,m) {  //在第y行中判断是否有有数字大于x
		
		if (*max_element(b,b+m)>x) {
			aaaa=false;
		}
		//	}
//	if (x==*max_element(b,b+m)) {
//		aaaa=true;
//		break;
//	}
	}
	if (aaaa==true) cout<<x;
	else cout<<"It does not exist! ";
	return 0;
}
//	int a[2*n][2*m]=0;
//	for (int i=0; i<n; i++) {
//		cin>>a[i][0];
//		a[i][m]=a[i][0];
//		for (int j=1; j<m; j++) {
//			cin>>a[i][j];
//			if (a[i][j]>a[i][y]){
//				a
//			}
//		}
//
//	}
