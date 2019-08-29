#include <bits/stdc++.h>
#define swap(a,b) a^=b, b^=a, a^=b
using namespace std;

const int inf = 0x3f3f3f3f;
const int N = 200001;
const int M = 500001;

template <typename _Tp> _Tp read ()
{
	register int f=1; register _Tp num=0; register char c;
	while( !isdigit( c=getchar() ) ) if( c == '-' ) f=-1;
	while( isdigit(c) ) num= (num<<1) + (num<<3) +(c&15), c=getchar();
	return num*f;
}

struct node
{
	int x, y, z;
}dian[M];
bool v[N];
int qi, n, m, nw, ct;
int d[N], num[N], ui[M];
int tot=1, head[N], to[M], dis0[M], next0[M];

inline bool comp (const node &a, const node &b)
{
    if( a.x!=b.x ) return a.x < b.x;
    if( a.y!=b.y ) return a.y < b.y;
    if( a.z!=b.z ) return a.z < b.z;
}

inline void add (int x, int y, int z)
{
	next0[++tot]=head[x], to[tot]=y, dis0[tot]=z, head[x]=tot;
	if( x!=y )
	  next0[++tot]=head[y], to[tot]=x, dis0[tot]=z, head[y]=tot;
}
inline void add0 (int x, int y, int z)
{
	next0[++tot]=head[x], to[tot]=y, dis0[tot]=z, head[x]=tot;
	next0[++tot]=head[y], to[tot]=x, dis0[tot]=z, head[y]=tot;
}

priority_queue < pair <int, int> > q;
void dijkstra ()
{
	int x, y, z;
	memset(d, inf, sizeof(d));
	d[1]=0;
	q.push( make_pair(0,1) );
	while( !q.empty() )
	{
	    x=q.top().second;
		q.pop();
		if( v[x] ) continue;
		v[x]=1;
		for(int i=head[x]; i; i=next0[i])
		{
			y=to[i], z=dis0[i];
			if( d[y] > d[x]+z )
			{
				d[y]= d[x]+z;
				q.push( make_pair(-d[y],y) );
			}
		}
	}
}

priority_queue < pair <int, int> > q0;
void dijkstra0 ()
{
	int x, y, z;
	memset(d, 0x3f, sizeof(d));
	memset(v, 0, sizeof(v));
	d[1]=0;
	q0.push( make_pair(0,1) );
	while( !q0.empty() )
	{
	    x=q0.top().second;
		q0.pop();
		if( v[x] ) continue;
		v[x]=1;
		for(int i=head[x]; i; i=next0[i])
		{
			if( i == ct || i == (ct^1) ) continue; 
			y=to[i], z=dis0[i];
			if( d[y] > d[x]+z )
			{
				d[y]= d[x]+z;
				q0.push( make_pair(-d[y], y) );
			}
		}
	}
}

int main ()
{
	freopen("rebirth.in","r",stdin);
	freopen("rebirth.out","w",stdout);
	int x, y;
	scanf("%d%d%d", &qi,&n,&m);
	if(n<=20)
	{
		int z;
		for(register int i=1; i<=m; ++i)
		{
			x=read<int>(), y=read<int>(), z=read<int>();
			add0(x, y, z);
		}
		printf("0");
		for(register int i=2; i<=n; ++i)
	    {
			int qwe=0;
			for(register int j=head[i]; j; j=next0[j])
				if( to[j] != i ) ++qwe;
			if( qwe == 1 ) printf(" -1");
			else
			{
				int ans=0;
				for(register int j=head[i]; j; j=next0[j])
				{
					ct=j;
					dijkstra0();
//					cout<<endl;
//					for(register int i=1; i<=n; ++i) cout<<d[i]<<" ";
//					return 0;
					ans=max(ans, d[i]);
				}
				printf(" %d", ans);
			}
	    }
	}
	else{
	for(register int i=1; i<=m; ++i)
	{
		dian[i].x=read<int>(),
		dian[i].y=read<int>(),
		dian[i].z=read<int>();
	}
	sort(dian+1, dian+m+1, comp);
//	for(register int i=1; i<=m; ++i)
//	  cout<<dian[i].x<<" "<<dian[i].y<<" "<<dian[i].z<<endl;
//	return 0;
	for(register int i=1; i<=m; ++i)
	{
		add(dian[i].x, dian[i].y, dian[i].z);
		++num[dian[i].x];
		if( dian[i].x != dian[i].y ) ++num[dian[i].y];
	}
	dijkstra();
//	for(register int i=1; i<=n; ++i) cout<<num[i]<<" ";
//	return 0;
//	for(register int i=1; i<=n; ++i)
//	cout<<d[i]<<" ";
//	return 0;
	printf("0");
//	cout<<endl;
//	for(register int i=head[4]; i; i=next0[i])
//	  cout<<to[i]<<" "<<dis0[i]<<endl;
//	  return 0;
	for(register int i=2; i<=n; ++i)
	{
		if( num[i] == 1 ) printf(" -1");
		else
		{
			int nu=0, qwe=0;
			for(register int j=head[i]; j; j=next0[j])
			{
				ui[++nu]= d[to[j]] + dis0[j];
				if( to[j] != i ) ++qwe;
			}
			if( !ui[2] || qwe == 1 ) printf(" -1"), ui[1]=0;
			else
			{
				sort(ui+1, ui+nu+1);
//				if(i==4){
//					cout<<endl;
//				for(register int l=1; l<=nu; ++l) cout<<ui[l]<<" ";
//				return 0;
//			    }
				printf(" %d", ui[2]);
				for(register int l=1; l<=nu; ++l) ui[l]=0;
			}
		}
	}
}
	return 0;
}
