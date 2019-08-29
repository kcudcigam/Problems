#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	long long zh;
	int n,a[100001];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		zh+=a[i];
	}
	cout<<zh<<endl;
	return 0;
}

