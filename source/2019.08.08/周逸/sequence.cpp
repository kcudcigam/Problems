#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
long long D[maxn];
int n,m;
template <typename T> void read(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	read(n);
	read(m);
	int i;
	long long d;
	unsigned long long k=0,w=0;
	int l,r,s,e;
	for(i=1;i<=m;i++){
		read(l);
		read(r);
		read(s);
		read(e);
		d=(long long)(e-s)/(r-l);
		D[l]+=s;
		D[l+1]+=d-s;
		D[r+1]-=d+e;
		D[r+2]+=e;
	}
	d=0;
	for(i=1;i<=n;i++){
		d+=D[i];
		if(d>0)
			k+=d;
		else
			k-=d;
		w=w^k;
//		cout<<w<<"  ";
	}
	printf("%lld",w);
	return 0;
}
