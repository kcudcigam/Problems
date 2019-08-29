#include<bits/stdc++.h>

using namespace std;
const int MAXN=300005;
const int MAXM=300005;
const int MAXX=20;


int n,m,Q,fa[MAXN][25],dist[MAXN][25],dep[MAXN],tail,head[MAXN],diss[MAXN];

struct Edge
{
	int x,y,c,nex;
}e[MAXM*2];

struct Node
{
	int x,dis,disst;
	bool operator <(const Node &b)
	const{
		if(dis==b.dis) return disst>b.disst;
		return dis>b.dis;
	}
};

priority_queue<Node> q;

void read(int &p)
{
	p=0;int flag=1;char s=getchar();
	while(!isdigit(s))
	{
		if(s=='-') flag=-1;
		s=getchar();
	}
	for(;isdigit(s);s=getchar()) p=p*10+s-'0';
	p*=flag;
}

void add(int x,int y,int c)
{
	e[++tail].x=x;e[tail].y=y;e[tail].c=c;
	e[tail].nex=head[x];head[x]=tail;
}

Node make_node(int x,int dis,int disst)
{
	Node tem;
	tem.x=x;tem.dis=dis;tem.disst=disst;
	return tem;
}

bool check(int x,int y)
{
	while(fa[x][0]!=x) 
	{
		if(x==y) return 0;
		x=fa[x][0];
	}
	return 1;
}

void dij(int st)
{
	q.push(make_node(st,0,0));
	fa[st][0]=st;diss[st]=0;
	for(int i=0;i<=MAXX;i++) dist[st][i]=0;
	while(q.size())
	{
		int x=q.top().x,dis=q.top().dis,disst=q.top().disst;q.pop();
		if(dis>diss[x]&&disst>fa[x][0]) continue;
		for(int i=head[x];i;i=e[i].nex)
		{
			int y=e[i].y;
			int tem=max(diss[x],e[i].c);
			
			if(diss[y]>tem)
			{
				diss[y]=tem;
				fa[y][0]=x;dist[y][0]=e[i].c;
				q.push(make_node(y,tem,dist[y][0]));
			}
			else
			if(diss[y]==tem)
			{
				if(e[i].c<dist[y][0]&&check(x,y))
				{
					fa[y][0]=x;dist[y][0]=e[i].c;
					q.push(make_node(y,tem,dist[y][0]));
				}
			}
			
		}
	}
}

void build(int x)
{
	//cout<<x<<endl;
	for(int i=1;i<=MAXX;i++)
	{
		fa[x][i]=fa[fa[x][i-1]][i-1];
		dist[x][i]=max(dist[x][i-1],dist[fa[x][i-1]][i-1]);
	}
	for(int i=head[x];i;i=e[i].nex)
	{
		if(!fa[e[i].y][1]&&fa[e[i].y][0]==x) {dep[e[i].y]=dep[x]+1;build(e[i].y);}
	}
}

void build_fa(int x)
{
	while(fa[x][0]!=x) {x=fa[x][0];cout<<x<<" "<<fa[x][0]<<endl;}
	dep[x]=1;build(x);
	
}

int askk(int x,int y)
{
	if(dep[x]>dep[y]) swap(x,y);
	int ans=0;
	if(dep[y]>dep[x])
	for(int i=MAXX;i>=0;i--)
	{
		
		if(dep[fa[y][i]]>=dep[x]) ans=max(ans,dist[y][i]),y=fa[y][i];
		if(dep[y]==dep[x]) break;
	}
	if(x==y) return ans;
	for(int i=MAXX;i>=0;i--)
	{
		int fx=fa[x][i],fy=fa[y][i];
		if(fx!=fy) 
		{
			ans=max(ans,dist[x][i]);
			ans=max(ans,dist[y][i]);
			x=fa[x][i];y=fa[y][i];
		}
	}
	//cout<<x<<" "<<y<<" "<<fa[x][0]<<endl;
	ans=max(ans,max(dist[x][0],dist[y][0]));
	x=fa[x][0];y=fa[y][0];
	if(x!=y) return -1;
	else return ans;
}

int main()
{
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	memset(dist,0x3f,sizeof(dist));memset(diss,0x3f,sizeof(diss));
	read(n);read(m);read(Q);
	int x,y,c;
	for(int i=1;i<=m;i++)
	{
		read(x);read(y);read(c);
		add(x,y,c);add(y,x,c);
	}
//	for(int i=1;i<=n;i++) fa[i][0]=i;

	for(int i=1;i<=n;i++)
	{
		if(!fa[i][0]) dij(i);
	}
	//cout<<"A";
	
	for(int i=1;i<=n;i++)
	{
		if(!dep[i]) build_fa(i);
	}
/*
	for(int i=1;i<=n;i++) 
	{
		cout<<"dep:"<<dep[i]<<" ";
		for(int j=0;j<=MAXX;j++) cout<<fa[i][j]<<" "<<dist[i][j]<<" |";
		cout<<endl;
	}
	cout<<endl;
*/
	for(int i=1;i<=Q;i++)
	{
		read(x);read(y);
		printf("%d\n",askk(x,y));
	}
	return 0;
}
