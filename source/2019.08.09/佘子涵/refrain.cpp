#include<cstdio>
#include<iostream>
using namespace std;
const long long N=200010;
const long long mod=1e9+7;
template <typename T> void read(T &x){
	long long f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f= -f;
	for (; isdigit(c);c=getchar()) x=x*10+c -'0';
	x*=f;
}
long long n,m,mm,x,y,nuh[N],nul[3][N],tot,hed[N],nxt[N*2],to[N*2],edg[N*2],nun,rd[N],ans,anss;
bool us1[N],us2[N];
void build(long long x,long long y,long long z){
	to[++tot]=y;
	edg[tot]=z;
	nxt[tot]=hed[x];
	hed[x]=tot;
}
long long dfs(long long x){
	long long re=1;us2[x]=1;
	for(long long i=hed[x];i;i=nxt[i]){
		long long y=to[i];
		if(!us2[y]) re+=dfs(y);
	}
	return re;
}
int main(){
	freopen("refrain.in","r",stdin);
	freopen("refrain.out","w",stdout);
	read(n);
	read(n);read(m);read(mm);
	if(!m&&!mm){
		printf("0\n");
		return 0;
	}
	nun=n;
	for(long long i=1;i<=m;i++){
		read(x);read(y);
		rd[x]++;rd[y]++;
		build(x,y,1);
		build(y,x,1);
		if(!us1[x]){
			us1[x]=1;nun--;
		}
		if(!us1[y]){
			us1[y]=1;nun--;
		}
	}
	for(long long i=1;i<=mm;i++){
		read(x);read(y);
		rd[x]++;rd[y]++;
		build(x,y,2);
		build(y,x,2);
		if(!us1[x]){
			us1[x]=1;nun--;
		}
		if(!us1[y]){
			us1[y]=1;nun--;
		}
	}
	ans=1;
	for(long long i=2;i<=nun;i++){
		ans=ans*i%mod;
	}
	for(long long i=1;i<=n;i++){
		if(us1[i]&&!us2[i]&&rd[i]==1){
			long long siz=dfs(i);
			nul[edg[hed[i]]][siz]++;
			if(siz%2){
				ans=ans*(nul[1][siz]+nul[2][siz])%mod;
				continue;
			}
			ans=ans*2%mod;
			ans=ans*nul[edg[hed[i]]][siz]%mod;
		}
	}
	for(long long i=1;i<=n;i++){
		if(us1[i]&&!us2[i]){
			long long siz=dfs(i);
			ans=ans*siz%mod;
			nuh[siz]++;
			ans=ans*nuh[siz]%mod;
		}
	}
	anss=1;
	for(long long i=2;i<=n;i++) anss=anss*i%mod;
	printf("%lld\n",(anss-ans+mod)%mod);
	return 0;
}
