#include<bits/stdc++.h>
using namespace std;
int a[500001]={0};
template <typename T> void read(T &x){
	long long f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
long long n,m;
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	read(n);
	read(m);
	for(int i=1;i<=m;i++){
		long long l,r,s,e;
		read(l);
		read(r);
		read(s);
		read(e);
		int gc=(e-s)/(r-l);
		long long t=s;
		for(int j=l;j<=r;j++){
			a[j]+=t;
			t+=gc;
		}
	}
	int ans=a[1];
	for(int i=2;i<=n;i++){
		ans=ans^a[i];
	}
	cout<<ans<<endl;
	return 0;
}

