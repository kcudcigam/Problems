#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=100+(int)(2e5);

LL a,b,c,d;
int n;
LL e[N];
LL g[N],h[N],mx[N];
LL ans,nw;
int top;

int rd(){
	int re=0,f=1;char c=getchar();
	while ((c<'0')||(c>'9')) {if (c=='-') f=-f;c=getchar();}
	while ((c>='0')&&(c<='9')) {re=re*10+c-'0';c=getchar();}
	return re*f;
}

LL Max(LL x,LL y){
	return ((x>y)?x:y);
}

LL Calc(LL x){
	return (a*x*x*x+b*x*x+c*x+d);
}

int main(){
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	n=rd();
	a=(LL)(rd());
	b=(LL)(rd());
	c=(LL)(rd());
	d=(LL)(rd());
	for (int i=1;i<=n;++i) e[i]=(LL)(rd());
	h[1]=Calc(e[1]);
	top=1;g[1]=e[1];mx[1]=0ll;
	for (int i=2;i<=n;++i){
		nw=h[top];
		while ((top>0)&&(e[i]<=g[top])){
			nw=Max(nw,mx[top]);
			--top;
		}
		g[++top]=e[i];
		mx[top]=nw;
		h[top]=(top==1)?(nw+Calc(e[i])):Max(h[top-1],nw+Calc(e[i]));
	}
	ans=h[top];
	cout<<ans<<'\n';
	return 0;
}
