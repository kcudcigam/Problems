#include<bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T &FF)
{
	FF=0;int RR=1;char CH=getchar();
	while(!isdigit(CH)&&CH!='-') CH=getchar();
	if(CH=='-') RR=-1;else FF=(CH^48);CH=getchar();
	while(isdigit(CH)) FF=(FF<<1)+(FF<<3)+(CH^48),CH=getchar();FF*=RR;
}
#define maxn 100010
int n,m;
int lst[maxn<<1];
long long dis[maxn<<1];
int now,fst[maxn<<1],nxt[maxn*10],num[maxn*10],wi[maxn*10],flag[maxn<<1];
void add(int u,int v,int w)
{
	nxt[++now]=fst[u],fst[u]=now,num[now]=v,wi[now]=w;
	nxt[++now]=fst[v],fst[v]=now,num[now]=u,wi[now]=w;
}
struct point{
	int num,val,way;
	friend bool operator < (point x,point y) {return x.val>y.val;}
};
point make_point(int a,int b,int c) {point Ti=(point){a,b,c};return Ti;}
int W=0;
void di()
{
	priority_queue<point> qi;
	memset(dis,0x3f,sizeof(dis)),dis[1]=0;
	memset(flag,0,sizeof(flag));
	qi.push(make_point(1,0,0));
	while(!qi.empty())
	{
		point pi=qi.top();qi.pop();
		if(flag[pi.num]) continue;
		flag[pi.num]=1; 
		if(!lst[pi.num]) lst[pi.num]=pi.way;
		for(int i=fst[pi.num];i;i=nxt[i])
			if(i!=W&&i!=W+((W%2)?1:-1))
				if(dis[pi.num]+wi[i]<dis[num[i]])
					dis[num[i]]=dis[pi.num]+wi[i],qi.push(make_point(num[i],dis[num[i]],i));
	}
}
int main()
{
	freopen("rebirth.in","r",stdin);
	freopen("rebirth.out","w",stdout);
	int num,u,v,w;
	read(num);
	read(n),read(m);
	for(int i=1;i<=m;i++)
		read(u),read(v),read(w),add(u,v,w);
	di();
	putchar('0'),putchar('\n');
	for(int i=2;i<=n;i++)
	{
		W=lst[i];
		di();
		if(dis[i]==4557430888798830399) dis[i]=-1;
		printf("%lld\n",dis[i]);
	}
	return 0;
}

