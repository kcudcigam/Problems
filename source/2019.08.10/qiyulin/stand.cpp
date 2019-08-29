#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=510;

struct Data{
	int nu,wz;
}b[N];
struct Node{
	int l,r;
}c[N];
int n,m,k,nw,d[N][N];
LL f[N][N],ans,a[10],g[N];

int rd(){
	int re=0,f=1;char c=getchar();
	while ((c<'0')||(c>'9')) {if (c=='-') f=-f;c=getchar();}
	while ((c>='0')&&(c<='9')) {re=re*10+c-'0';c=getchar();}
	return re*f;
}

bool cpb(Data a,Data b){
	return (a.nu<b.nu);
}

LL Max(LL x,LL y){
	return ((x>y)?x:y);
}

LL Calc(LL x){
	LL y=x,re=0ll;
	for (int i=1;i<=5;++i,y*=x)
		re+=y*a[i];
	return re;
}

int main(){
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=5;++i) cin>>a[i];
	k=0;
	for (int i=1;i<=n;++i){
		++k;
		cin>>b[k].nu;
		b[k].wz=i;
		++k;
		cin>>b[k].nu;
		b[k].wz=i+n;
	}
	sort(b+1,b+k+1,cpb);
	m=0;nw=b[1].nu-1;
	for (int i=1;i<=k;++i){
		m+=(nw!=b[i].nu);
		if (b[i].wz<=n) c[b[i].wz].l=m;else
			c[b[i].wz-n].r=m;
		nw=b[i].nu;
	}
	
	memset(d,0,sizeof(d));
	for (int i=1;i<=n;++i)
		++d[c[i].l][c[i].r];
	for (int i=1;i<=m;++i)
		for (int j=1;j<=m;++j)
			d[i][j]+=d[i-1][j];
	
	for (int i=0;i<=n;++i) g[i]=Calc((LL)(i));
	memset(f,0,sizeof(f));
	for (int i=1;i<=m;++i){
		k=0;
		for (int j=i;j<=m;++j){
			k+=d[i][j];
			f[i][j]=g[k];
		}
	}
	for (int i=0;i<m;++i)
		for (int j=0;j<=m;++j){
			for (int l=i+1;l<=m;++l){
				k=0;
				for (int o=l;o<=m;++o){
					k+=(o<=j)?(d[l][o]-d[i][o]):(d[l][o]);
					//k+=d[l][o]-d[i][o];
					nw=(o<=j)?j:o;
					f[l][nw]=Max(f[l][nw],f[i][j]+g[k]);
				}
			}
		}
	
	ans=0ll;
	for (int i=0;i<=m;++i)
		for (int j=0;j<=m;++j)
			ans=Max(ans,f[i][j]);
	cout<<ans<<'\n';
	return 0;
}
