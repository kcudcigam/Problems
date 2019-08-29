#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL n,x;
int m,a[10010],b[10010];

int rd(){
	int re=0,f=1;char c=getchar();
	while ((c<'0')||(c>'9')) {if (c=='-') f=-f;c=getchar();}
	while ((c>='0')&&(c<='9')) {re=re*10+c-'0';c=getchar();}
	return re*f;
}

int main(){
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	cin>>n;
	m=0;
	for (int i=1;i<63;++i)
		for (int j=i+1;j<=63;++j){
			a[++m]=i;b[m]=j;
		}
	for (int i=63;i>=2;--i){
		x=(1ll<<(LL)(i-2));
		if (n>=x){
			n-=x;
			a[++m]=i;b[m]=64;
		}
	}
	cout<<"64 "<<m<<'\n';
	for (int i=1;i<=m;++i) cout<<a[i]<<' '<<b[i]<<'\n';
	return 0;
}
