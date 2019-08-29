#include<bits/stdc++.h>
using namespace std;
int n,m,l;
long long a[510002],h[510002],duck,ll,r,s,e,tou[510002],tot[510002],js;
template <typename T> void read(T &x){
long long f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m;
	l=floor(sqrt(n));
	memset(a,0,sizeof(a));
	for(int i=1;i<=n;i++) h[i]=(i-1)/l+1;
	for(int i=1;i<=m;i++) 
	{
		read(ll);read(r);read(s);read(e);
		int ll2=ll,r2=r;
		while(1){if(ll2%l==1) break;ll2++;}
		while(1){if(r2%l==0) break;r2--;} 
		js=(e-s)/(r-ll);
		long long ltot=s;
		for(int j=ll;j<ll2;j++) 
		{
			a[j]+=ltot;
			ltot+=js;
		}
		ltot=s+(r2+1-ll)*js;
		for(int j=r2+1;j<=r;j++) 
		{
			a[j]+=ltot;
			ltot+=js;
		}
	    ltot=s+(ll2-ll)*js;
	    for(int j=ll2;j<=r2;j+=l)
	    {
	    	tou[h[j]]+=ltot;
	    	tot[h[j]]+=js;
	    	ltot=ltot+js*l;
		}
	}
	for(int i=1;i<=h[n];i++)
	{
		for(int j=1;j<=l;j++)
			a[l*(i-1)+j]=a[l*(i-1)+j]+tou[i]+tot[i]*(j-1);
	}
	duck=a[1];
	for(int i=2;i<=n;i++) duck=duck^a[i];
	cout<<duck<<endl;
	return 0;
}

