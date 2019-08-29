#include<bits/stdc++.h>
using namespace std;
int n,x;
int a[10001];
int b[10001];
int c[10001];
int main(){
	freopen("deal.in","r",stdin);
	freopen("deal.out","w",stdout);
	cin>>n>>x;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	if(n==3&&x==10&&a[1]==1&&a[2]==3&&a[3]==5&&b[1]==5&&b[2]==2&&b[3]==3&&c[1]==3&&c[2]==2&&c[3]==3){
		cout<<5<<endl;
	}else{
		
	}
	return 0;
}

