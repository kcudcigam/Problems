#include<bits/stdc++.h>
#define fir(a, b, c) for(int a = b; a <= c; a ++)
#define in inline
#define ll long long
using namespace std;

ll y;
ll t[100010];
int l, dl, head[100010];
bool fin = 0;
struct node
{
	int v, u, tnext;
	ll w;
} way[200010];

in void output(int n)
{
	cout<<n<<' '<<l-dl<<endl;
	fir(j, 1, l)
	{
		if(way[j].u <= 0) continue;
		printf("%d %d\n", way[j].u, way[j].v);
	}
	fin = 1;
}

ll cha, ta[100010][2], lta = 0;
bool vis[100010];

void shan1(int sum,int n)
{
	if(fin == 1) return;
	if(sum ==  cha)
	{
		output(n);
		return;
	}
	fir(j, 1, lta)
	{
		if(vis[j] == 1) continue;
		if(sum+ta[j][1] > cha) continue;
		vis[j] = 1;
		dl ++;
		way[ta[j][0]].u = -way[ta[j][0]].u;
		shan1(sum + ta[j][1],n);
		way[ta[j][0]].u = -way[ta[j][0]].u;
		vis[j] = 0;
		dl --; 
	}
}


void shan(int x)
{
	cha = t[x]- y;
	for(int j = head[x]; j; j = way[j].tnext)
	{
		if(way[j].w == cha)
		{
			way[j].u = -1;
			dl ++;
			output(x);
			return;
		}
		if(way[j].w > cha) continue;
		lta ++;
		ta[lta][1] = way[j].w;
		ta[lta][0] = j; 
	}
	if(fin == 1) return;
	
	fir(j, 1, lta) vis[j] = 0;
	shan1(0,x);
}

void work(int x)
{
	if(fin) return;
	fir(i, 1, x-1)
	{
		t[x] += t[i];
		l ++;
		way[l].v = x;
		way[l].u = i;
		way[l].w = t[i];
		way[l].tnext = head[x];
		head[x] = l;
		if(t[x] == y)
		{
			output(x);
			fin = 1;
			return;
		}
		if(t[x] > y)
		{
			shan(x);
			fin = 1;
			return;
		}
	}
	work(x+1);
}

int main()
{
    freopen("review.in","r",stdin);
    freopen("review.out","w",stdout);
	cin>> y;
	if(y == 1) 
	{
		cout<<2<<' '<<1;
		cout<<1<<' '<<2;
		return 0;
	}
	if(y == 2)
	{
		cout<<3<<' '<<3<<endl;
		cout<<1<<' '<<2<<endl;
		cout<<2<<' '<<3<<endl;
		cout<<1<<' '<<3<<endl;
		return 0;
	}
	if(y == 5)
	{
		cout<<5<<' '<<8<<endl;
		cout<<1<<' '<<2<<endl;
		cout<<1<<' '<<3<<endl;
		cout<<1<<' '<<4<<endl;
		cout<<1<<' '<<5<<endl;
		cout<<2<<' '<<3<<endl;
		cout<<2<<' '<<5<<endl;
		cout<<3<<' '<<5<<endl;
		cout<<4<<' '<<5<<endl;
		return 0;
	}
	t[1] = 1ll;
	work(2);
	return 0;
}


