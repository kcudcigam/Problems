#include<bits/stdc++.h>
using namespace std;
int a[555555],b[555555],c[555555];
template <typename T> void read(T &x){
	int f=1;
	x=0;
	char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
int main(){
    freopen("sequence.in","r",stdin);
    freopen("sequence.out","w",stdout);
	int n,m;
	read(n);
	read(m);
	memset(a,0,sizeof(a));
	for (int i=1;i<=m;i++){
		int l,r,s,e;
		read(l);
		read(r);
		read(s);
		read(e);
		int dt=abs(s-e)/abs(l-r);
		if (dt){
			a[l]+=dt;
			a[r+1]-=dt*(abs(l-r)+1);
		}
		else {
			a[l]+=s;
			a[l+1]-=s;
			a[r+1]-=s;
		}
	}
	memset(b,0,sizeof(b));
	for (int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	memset(c,0,sizeof(c));
	for (int i=1;i<=n;i++){
		c[i]=c[i-1]+b[i];
	}
	int ans=c[n];
	for (int i=1;i<n;i++){
		ans^=c[i];
	}
	cout<<ans<<endl;
	return 0;
}


