#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
template<typename T> inline void read(T &t)
{
	t=0; int f=1,c;
	while(c=getchar(),(c<'0'||c>'9')&&c!='-');
	if(c!='-') t=c-'0';
	else f=-1;
	while(c=getchar(),'0'<=c&&c<='9') t=t*10+c-'0';
	t=t*f;
}
template<typename T,typename... Args> inline void read(T &t,Args&... args) { read(t); read(args...); }
const int maxn=300005;
vector<int> G[maxn];
int n,m,Q,deg[maxn];
struct Case1
{
	int tag[3005];
	int main()
	{
		memset(tag,0,sizeof(tag));
		int type,x,y;
		while(Q-->0)
		{
			read(type,x);
			if(type==0)
			{
				int res=0;
				for(int z:G[x]) res+=tag[z];
				printf("%d\n",res);
			}
			else
			{
				read(y);
				tag[x]+=y;
			}
		}
		return 0;
	}
};
struct Case3
{
	int tag[maxn],cn[maxn];
	int main()
	{
		memset(tag,0,sizeof(tag));
		for(int i=2;i<=n;i++)
		{
			cn[i]=0;
			for(int v:G[i]) if(v==1) { cn[i]=1; break; }
		}
		int type,x,y,res1=0;
		while(Q-->0)
		{
			read(type,x);
			if(type==0)
			{
				if(x==1) printf("%d\n",res1);
				else
				{
					int res=0;
					for(int z:G[x]) res+=tag[z];
					printf("%d\n",res);
				}
			}
			else
			{
				read(y);
				tag[x]+=y;
				if(cn[x]) res1+=y;
			}
		}
		return 0;
	}
};
struct XuanXue
{
	int main()
	{
		printf("byf ak ioi");
		return 0;
	}
};
int main()
{
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	read(n,m,Q);
	for(int i=0;i<m;i++)
	{
		int u,v; read(u,v);
		G[u].push_back(v);
		G[v].push_back(u);
		deg[u]++; deg[v]++;
	}
	if(n<=3000&&m<=3000&&Q<=3000) return (new Case1)->main();
	int flg1=1;
	for(int i=2;i<=n;i++) if(deg[i]>10) flg1=0;
	if(flg1) return (new Case3)->main();
	return (new XuanXue)->main();
}
