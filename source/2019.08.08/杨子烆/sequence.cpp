#include<bits/stdc++.h>
using namespace std;
template <typename T> void read(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
long long a[500002];
long long b[500002];
long long c[500002];
long long n,m,l,r,s,e;
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	read(n);
	read(m);
	for(int i=1;i<=m;i++){
		read(l);
		read(r);
		read(s);
		read(e);
		a[l]+=s;
		a[r+1]-=e;
		a[r+1]-=s;
	}
	for(int i=1;i<=n;i++){
		b[i]=a[i]+b[i-1];
	}
	for(int i=1;i<=n;i++){
		c[i]=b[i]+b[i-1];
	}
	long long ans=c[1];
	for(int i=2;i<=n;i++){
		ans=ans^c[i];
	}
	cout<<ans;
	return 0;
}



