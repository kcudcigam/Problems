#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int M=100+(int)(6e5);
const int N=100+(int)(3e5);

int a[N],b[N],ans;
int n,m,q,k,x,y;
int tot;
int sta[N],v[M],nxt[M];
int st[N],vv[M],nx[M];
int opt;
int d[N];

int rd(){
	int re=0,f=1;char c=getchar();
	while ((c<'0')||(c>'9')) {if (c=='-') f=-f;c=getchar();}
	while ((c>='0')&&(c<='9')) {re=re*10+c-'0';c=getchar();}
	return re*f;
}

int main(){
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	n=rd();m=rd();q=rd();
	k=(int)(sqrt(m));
	tot=1;
	memset(sta,0,sizeof(sta));
	memset(d,0,sizeof(d));
	for (int i=1;i<=m;++i){
		x=rd();y=rd();
		v[++tot]=y;nxt[tot]=sta[x];sta[x]=tot;
		v[++tot]=x;nxt[tot]=sta[y];sta[y]=tot;
		++d[x];++d[y];
	}
	
	tot=0;
	memset(st,0,sizeof(st));
	for (int i=1;i<=n;++i){
		for (int j=sta[i];j>0;j=nxt[j])
			if (d[v[j]]>k){
				vv[++tot]=v[j];nx[tot]=st[i];st[i]=tot;
			}
	}
	
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	for (;q>0;--q){
		opt=rd();
		if (opt==0){
			x=rd();
			if (d[x]<=k){
				ans=a[x];
				for (int i=sta[x];i>0;i=nxt[i])
					ans+=a[v[i]];
			}else ans=a[x]+b[x];
			cout<<ans<<'\n';
		}else{
			x=rd();y=rd();
			a[x]+=y;
			for (int i=st[x];i>0;i=nx[i])
				b[vv[i]]+=y;
		}
	}
	return 0;
}
