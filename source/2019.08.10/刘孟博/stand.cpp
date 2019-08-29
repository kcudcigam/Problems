#include<bits/stdc++.h>
#define rg register
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c))x=(x<<3)+(x<<1)+c-'0',c=getchar();
	return x*f;
}
const int MAXN=45;
typedef long long ll;
int n,m,g[6],l[MAXN],r[MAXN],a[MAXN],p[MAXN];
map<int,int>cnt;
ll ans,tmp,f[MAXN][32770];
bool flag=1;
inline ll calc(int x){return (ll)(1ll*g[1]*x+1ll*g[2]*x*x+1ll*g[3]*x*x*x+1ll*g[4]*x*x*x*x+1ll*g[5]*x*x*x*x*x);}
inline void dfs1(int x){
	if(x==n+1){ans=max(ans,tmp);return;}
	for(int i=l[x];i<=r[x];i++){
		tmp-=calc(cnt[i]),++cnt[i];
		tmp+=calc(cnt[i]);dfs1(x+1);
		tmp-=calc(cnt[i]),--cnt[i],tmp+=calc(cnt[i]);
	}
}
inline void dfs2(int x,int lst){
	if(x==0){ans=max(ans,tmp);return;}
	if(x<lst)return;
	for(int i=lst;i<=x;i++){tmp+=calc(i),dfs2(x-i,i),tmp-=calc(i);}
}
inline int count(int x){if(!x)return 0;return count(x>>1)+(x&1);}
int main(){
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	n=read(),m=read();
	for(rg int i=1;i<=m;i++)cnt[i]=0;
	for(rg int i=1;i<=5;i++)g[i]=read();
	for(rg int i=1;i<=n;i++){
		l[i]=read(),r[i]=read();	
		if(l[i]!=1||r[i]!=m)flag=0;
	}
	if(m<=5) dfs1(1),printf("%lld\n",ans);
	else if(flag) dfs2(n,1),printf("%lld\n",ans);
	else{
		for(rg int i=1;i<=n;i++)
			for(rg int j=l[i];j<=r[i];j++)p[j]|=(1<<(i-1));
		int ALL=(1<<n)-1;
		for(rg int i=1;i<=m;i++)
			for(rg int j=1;j<=ALL;j++){
				f[i][j]=f[i-1][j];int qaq=j&p[i];
				for(rg int k=qaq;k;k=((k-1)&k))
					if((j&k)==k)f[i][j]=max(f[i][j],f[i-1][j^k]+calc(count(k)));
			}
		printf("%lld",f[m][ALL]);
	}
	return 0;
}
