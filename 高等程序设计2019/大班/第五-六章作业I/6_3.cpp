#include <iostream>
using namespace std;
int main() {
//	for (int aaaa=1;aaaa<=2;aaaa++){
	int	n,m,i,j,k;
	cin>>n>>m;
	int a[n][m];
	fill(a[0],a[0]+sizeof(a)/sizeof(int),0);
	for (i=0; i<n; i++)
		for (j=0; j<m; j++)
			cin>>a[i][j];

	int temp1=a[0][0],temp2=a[0][0],x=0;
	bool label=false;
	i=0,j=0;

	while ((label==false)&&(i<n)) {
		temp1=a[i][0];
		temp2=a[i][0];
		x=0;
		for (j=1; j<m; j++)
			if (a[i][j]>temp1) {
				temp1=a[i][j];
				x=j;
			}
		//	cout<<"x="<<x<<" temp1="<<temp1<<" temp2="<<temp2<<endl;
		temp2=temp1;
		for (k=0; k<n; k++) {
			if (a[k][x]<temp2) {
				temp2=a[k][x];
			}
		}
		//	cout<<"x="<<x<<" temp1="<<temp1<<" temp2="<<temp2<<endl;
		//	cout<<endl;
		if (temp1==temp2) label=true;
		i++;
	}

	if (label==true) cout<<temp1;
	else cout<<" It does not exist!";
//	cout<<endl<<endl;
//}
	return 0;
}
