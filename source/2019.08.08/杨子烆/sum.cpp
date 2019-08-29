#include<bits/stdc++.h>
#define ll long long
using namespace std;
long long hz[100001];
long long hz1[100001];
long long qz[100001];
int a[100001];
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	long long sum=0;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=n;i>=1;i--){
		if(hz[i+1]>0)hz[i]=hz[i+1]+a[i];
		else hz[i]=a[i];
		hz1[i]=max(hz[i],hz1[i+1]);
	}
	for(int i=1;i<=n;i++){
		if(qz[i-1]>0)qz[i]=qz[i-1]+a[i];
		else qz[i]=a[i];
		sum=max(qz[i]+hz1[i+1],sum);
	}
	cout<<sum;
	return 0;
}

