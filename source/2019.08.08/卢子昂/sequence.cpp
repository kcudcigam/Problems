#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int Maxn=500000+10;

int n,m;

int lowbit(int x){
	return x&(-x); 
}
ll a[Maxn],c[2][Maxn];

void add(int k,int x,ll d){
	for(;x<=n;x+=lowbit(x))c[k][x]+=d;
	return;
}
ll ask(int k,int x){
	ll cnt=0;
	for(;x;x-=lowbit(x))cnt+=c[k][x];
	return cnt;
}

template <typename T> void read(T &x){
	int f=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-f;
	for(;isdigit(c);c=getchar())x=x*10+c-'0';
	x*=f;
}

int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	int i,j,k,l,r;
	ll s,e,d;
	read(n);read(m);
	for(i=1;i<=m;i++){
		read(l);read(r);read(s);read(e);
		d=(e-s)/(r-l);
		add(0,l,s);add(0,r+1,-s);
		add(1,l+1,d);add(1,r+1,-d);	
	}
	ll ans=0,tot;
	for(i=1;i<=n;i++){
		tot=0;
		for(j=1;j<=i;j++){
			tot+=ask(1,j);
		}
		tot+=ask(0,i);
		ans^=tot;
	}
	printf("%d",ans);
	return 0;
}

