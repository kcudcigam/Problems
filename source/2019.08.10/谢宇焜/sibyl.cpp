#include<bits/stdc++.h>
#define ll long long
#define fir(a, b, c) for(int a = b; a <= c; a ++)
#define in inline
using namespace std;

template <typename T> void read(T &xx){
int f=1;xx=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) xx=xx*10+c-'0';
xx*=f;
}

const int N = 3e+5;
int n, m, q, l;
int head[N+5], tans[N+5];
struct node
{
	int v, tnext;
} t[2*N+5];

in void build(int x, int y)
{
	l ++;
	t[l].v = y;
	t[l].tnext = head[x];
	head[x] = l;
} 

int ans = 0;
in void output(int x)
{
	ans = tans[x];
	for(int j = head[x]; j; j = t[j].tnext)
	{
		ans += tans[t[j].v];
	}
	cout<<ans<<endl;
}

int main()
{
    freopen("sibyl.in","r",stdin);
    freopen("sibyl.out","w",stdout);
	read(n), read(m), read(q);
	int x, y;
	fir(i, 1, m)
	{
		read(x), read(y);
		build(x, y);
		build(y, x);
	}
	
	int opt;
	fir(i, 1, q)
	{
		read(opt);
		if(opt == 1)
		{
			read(x);
			read(y);
			tans[x] += y;
		}
		else
		{
			read(x);
			output(x);
		}
	}
	return 0;
}


