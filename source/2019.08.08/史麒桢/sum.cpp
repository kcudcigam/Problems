#include<bits/stdc++.h>
using namespace std;
long long a[111111],b[111111],x[111111];
long long ll[111111],rr[111111];
const long long INFI=1e16;
int reads(void){
	int x=0,f=1;
	char ch=getchar();
	for (;!isdigit(ch);ch=getchar()){
		if (ch=='-') f=-1;
	}
	for (;isdigit(ch);ch=getchar()){
		x*=10;
		x+=ch-'0';
	}
	return x*f;
}
int main(){
    freopen("sum.in","r",stdin);
    freopen("sum.out","w",stdout);
	int n=reads();
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	long long fla=-INFI,sla=-INFI;
	for (int i=1;i<=n;i++){
		x[i]=reads();
		if (fla<x[i]){
			sla=fla;
			fla=x[i];
		}
		else if (sla<x[i]){
			sla=x[i];
		}
		ll[i]=-INFI;
		rr[i]=-INFI;
	}
	if (sla<0){
		cout<<fla+sla<<endl;
		return 0;
	}
	long long lmin=min((long long)0,x[1]);
	a[1]=x[1];
	ll[1]=x[1];
	for (int i=2;i<=n;i++){
		a[i]=a[i-1]+x[i];
		ll[i]=max(a[i]-lmin,ll[i-1]);
		if (a[i]<lmin){
			lmin=a[i];
		}
	}
	long long rmin=min((long long)0,x[n]);
	b[n]=x[n];
	rr[n]=x[n];
	for (int i=n-1;i>=1;i--){
		b[i]=b[i+1]+x[i];
		rr[i]=max(b[i]-rmin,rr[i+1]);
		if (b[i]<rmin){
			rmin=b[i];
		}
	}
	long long ans=0;
	for (int i=1;i<n;i++){
		ans=max(ll[i]+rr[i+1],ans);
	}
	cout<<ans<<endl;
	return 0;
}


