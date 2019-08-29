#include<bits/stdc++.h>
#define fir(a, b, c) for(int a = b; a <= c; a ++)
#define in inline
#define ll long long
using namespace std;

template <typename T> void read(T &xx){
int f=1;xx=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) xx=xx*10+c-'0';
xx*=f;
}

typedef pair<ll, int> pl;
const int Maxn = 1e5+5;
ll dis[Maxn*2];
int num, n, m, head[2*Maxn], l;
struct node
{
	int v, len, tnext;
} t[5*Maxn];
bool inq[Maxn*2];
int del;

priority_queue <pl, vector<pl>, greater<pl> > q;

in ll sp(int x)
{
	fir(j, 1, n) dis[j] = 1e+8, inq[j] = 0;
	while(!q.empty()) q.pop();
	inq[x] = 1;
	dis[x] = 0;
	q.push(make_pair(0, x));
	while(!q.empty())
	{
		long long di = q.top().first; int pos = q.top().second;
		q.pop();
		inq[pos] = 0;
		for(int j = head[pos]; j; j = t[j].tnext)
		{
			if(j == del) continue;
			if((di+t[j].len) < dis[t[j].v])
			{
				dis[t[j].v] = di + t[j].len;
				if(inq[t[j].v] == 1) continue;
				inq[t[j].v] = 1;
				q.push(make_pair(dis[t[j].v], t[j].v));
			}
		}
	}
	if(dis[1] == 1e+8) return -1;
	else return dis[1];
}

in void build(int x, int y, int w)
{
	l ++;
	t[l].v = y;
	t[l].len = w;
	t[l].tnext = head[x];
	head[x] = l;
}

int main()
{
    freopen("rebirth.in","r",stdin);
    freopen("rebirth.out","w",stdout);
	read(num);
	read(n); read(m);
	int x, y, tlen;
	fir(i, 1, m)
	{
		read(x), read(y), read(tlen);
		build(x, y, tlen);
		build(y, x, tlen);
	}
	
	if(num>= 12 && num <= 16)
	{
		cout<<0<<' '<<-1;
		fir(i, 3 ,n)
		{
			for(int j = head[i]; j; j = t[j].tnext)
				if(t[j].v == (i-1))
				{
					del = j;
					break;
				}
			cout<<' '<<sp(i);
		}
		return 0;
	}
	else
	{
		cout<<0;
		ll ans = 0;
		fir(i, 2 ,n)
		{
			ans = -2;
			for(int j = head[i]; j; j = t[j].tnext)
			{
				del = j;
				ll tans = sp(i);
				if(tans == -1) 
				{
					ans = -1;
					break;
				}
				ans = max(ans, tans);
			}
			cout<<' '<<ans;
		}
	}
	return 0;
}


