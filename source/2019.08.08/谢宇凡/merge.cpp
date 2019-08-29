#include<bits/stdc++.h>
using namespace std;

int n,Q,m;
long long a[500010];
int f[500010];
int t[500010];

template <typename T> void read(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}

int find(int n){
	if (f[n]==n)	return n;
	if (a[n])	return find(f[n]);
		else return f[n]=find(f[n]);
}

int main(){
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	read(n);read(Q);
	for (int i=1;i<=n;++i)	f[i]=i;
	for (int i=1;i<=Q;++i){
		int p,x,y;
		read(p);read(x);read(y);
		if (p==1){
			m=0;
			int xr=find(x);
			int yr=find(y);
			if (xr!=yr)	if (t[xr]>t[yr])	f[xr]=yr;	else f[yr]=xr;
			continue;
		}
		a[find(x)]+=y;
		t[find(x)]=i;
	}
	for (int i=1;i<=n;++i){
		int k=i;
		m=t[i];
		while (f[k]!=k)	{
			if (t[f[k]]>m&&a[f[k]]){
				a[i]+=a[f[k]];
				m=t[f[k]];
			}
			k=f[k];
		}
		if (i==1)	printf("%lld",a[i]);
			else printf(" %lld",a[i]);
	}
	return 0;
}


