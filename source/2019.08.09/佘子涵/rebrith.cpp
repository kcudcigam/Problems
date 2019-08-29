#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;
const int N=200010;
const int M=1000010;
const long long Ma=100000000000000000;
template <typename T> void read(T &x){
	long long f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f= -f;
	for (; isdigit(c);c=getchar()) x=x*10+c -'0';
	x*=f;
}
long long n,m,x,y,z,tot=1,hed[N],to[M],nxt[M],edg[M],d[N];
bool us[N],nop[M];
void build(int x,int y,int z){
	to[++tot]=y;
	edg[tot]=z;
	nxt[tot]=hed[x];
	hed[x]=tot;
}
priority_queue<pair<long long,long long> >q;
void dj(){
	for(int i=1;i<=n;i++) d[i]=Ma;
	d[1]=0;q.push(make_pair(0,1));
	while(q.size()){
		long long x=q.top().second;q.pop();
		if(us[x]) continue;
		for(long long i=hed[x];i;i=nxt[i]){
			if(nop[i]) continue;
			long long y=to[i];
			long long z=edg[i];
			if(d[y]>d[x]+edg[i]){
				d[y]=d[x]+edg[i];
				q.push(make_pair(-d[y],y));
			}
		}
	}
	return;
}
int main(){
	freopen("rebirth.in","r",stdin);
	freopen("rebirth.out","w",stdout);
	read(n);
	read(n);read(m);
	for(int i=1;i<=m;i++){
		read(x);read(y);read(z);
		if(x==y) continue;
		build(x,y,z);
		build(y,x,z);
	}
	dj();
	printf("0 ");
	for(int i=2;i<=n;i++){
		long long ans=d[i];
		for(int j=hed[i];j;j=nxt[j]){
			y=to[j];
			z=edg[j];
			if(d[y]+z==d[i]){
				nop[j]=nop[j^1]=1;
				dj();
				nop[j]=nop[j^1]=0;
				ans=max(ans,d[i]);
			}
		}
		if(ans==Ma) printf("-1 ");
		else printf("%lld ",ans);
	}
	return 0;
}
