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
	
	for (i,0,n) for (j,0,m) cin>>a[i][j];//���� 
	
	for (j,0,m) {     //ö�ٸ���
		aaaa=true;
			x=-1;
		for (i,0,n) {  //ö�ٵ�j�еĸ���
			if (a[i][j]>x) {
				x=a[i][j],y=i;
			}   //�ҳ���j���е����ֵ��������ֵ��x��������y
		//	cout<<"x="<<x<<" y="<<y;
			for (k,0,m) b[k]=a[y][k]; //��a�е�y�е����ᵽb��
		}
		//	for (k,0,m) {  //�ڵ�y�����ж��Ƿ��������ִ���x
		
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
