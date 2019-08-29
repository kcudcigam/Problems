#include<bits/stdc++.h>
using namespace std;
long long a[10010],f[10010];
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	long long n,ma,s=0,m=INT_MIN/2;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=2;i<=n;i++){
		ma=INT_MIN/2;
		for(int j=1;j<i;j++){
			if(f[j-1]>0)f[j]=f[j-1]+a[j];
			else f[j]=a[j];
			f[j-1]=0;
			ma=max(ma,f[j]);
		}
		s=ma;
		ma=INT_MIN/2;
		f[i-1]=0;
		for(int j=i;j<=n;j++){
			if(f[j-1]>0)f[j]=f[j-1]+a[j];
			else f[j]=a[j];
			f[j-1]=0;
			ma=max(ma,f[j]);
		}
		f[n]=0;
		s+=ma;
		m=max(m,s);
	}
	cout<<m<<endl;
	return 0;
}
